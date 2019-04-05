//Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента.

#include <iostream>
#include <random>
#include <time.h>
#include <iomanip>

using namespace std;

int* give_memory(int N);
void init_array(int* p, int N);
void sortFromPosition(int* p, int N, int k);
void print_array(int* p, int N);

int main() {

	cout << "Enter number of elements: ";
	int N; cin >> N;
	cout << "Enter number K: ";
	int k; cin >> k;

	int* p = give_memory(N);
	if (!p) { cout << "No memory!"; }

	init_array(p, N);
	print_array(p, N);
	sortFromPosition(p, N, k);
	print_array(p, N);

	delete[]p;
	p = nullptr;
	system("pause");
	return 0;
}

int* give_memory(int N) {
	int* p = new(nothrow) int[N];
	if (p == nullptr) { return nullptr; }
	return p;
}

void init_array(int* p, int N){
	srand(time(NULL));
	int a = 10;
	for (int i = 0; i < N; i++) {
		p[i] = rand() % a;
	}
}

void print_array(int* p, int N) {
	for (int i = 0; i < N; i++) {
		cout << setw(5) << p[i];
	}
	cout << '\n';
}

void sortFromPosition(int* p, int N, int k) {
	int tmp = 0;
	bool flag = false;
	while (!flag){
		flag = true;
		for (int i = k; i < N - 1; i++) {
			if (p[i] > p[i + 1]) {
				tmp = p[i];
				p[i] = p[i + 1];
				p[i + 1] = tmp;
				flag = false;
			}
		}
	}
}
