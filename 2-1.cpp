//В массиве А(N,N) найти первую строку, не содержащую отрицательных элементов, и поменять её с последней строкой.
//Из "Полечгче"
#include <iostream>
#include <time.h>
#include <random>
#include <iomanip>

using namespace std;

int** give_memory(int, int);
void init_array(int **, int, int);
void mainTask(int **, int, int);
void print_array(int **, int, int);
void free_array(int **, int);


int main() {
	int N = -1, M = -1;
	while (N < 0 || M < 0) {
		system("cls");
		cout << "Enter count of rows and count of columns: ";
		cin >> N >> M;
	}
	int** p = give_memory(N, M);
	if(!p){
		cout << "No memory!";
		exit(1);
	}
	init_array(p, N, M);
	print_array(p, N, M);
	mainTask(p, N, M);
	print_array(p, N, M);
	free_array(p, N);
	system("pause");
	return 0;
}

int** give_memory(int N, int M) {
	int** p = new(nothrow) int* [N];
	if(p == nullptr)
		return nullptr;
	for (int i = 0; i < N; ++i) {
		int* p1 = new(nothrow) int[M];
		p[i] = p1;
	}
	return p;
}

void init_array(int** p, int N, int M) {
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		int* p1 = p[i];
		for (int g = 0; g < M; g++) {
			p1[g] = -10 + (rand() % 100);
		}
	}
}

void print_array(int** p, int N, int M) {
	for (int i = 0; i < N; i++) {
		int* p1 = p[i];
		for (int g = 0; g < M; g++) {
			cout << setw(5) << p1[g];
		}
		cout << '\n';
	}
	cout << '\n';
}

void free_array(int** p, int N) {
	for (int i = 0; i < N; i++) {
		p[i] = nullptr;
	}
	delete[]p;
	p = nullptr;
}

void mainTask(int** p, int N, int M) {
	bool flag;
	for (int i = 0; i < N; i++) {
		int* p1 = p[i];
		int g;
		for (flag = true, g = 0; g < M; g++) {
			if (p1[g] < 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			int* temp = p[i];
			p[i] = p[N - 1];
			p[N - 1] = temp;
			break;
		}
	}
}
