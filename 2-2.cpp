#include <iostream>
#include <random>
#include <time.h>
#include <iomanip>
#include <math.h>

using namespace std;

int* give_memory(int N);
void init_array(int* p, int N);
void sort(int*, int);
void print_array(int* p, int N);

int main() {
	cout << "Enter number of elements: ";
	int N; cin >> N;

	int* p = give_memory(N);
	if (!p) { cout << "No memory!"; }

	init_array(p, N);
	print_array(p, N);
	sort(p, N);
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
	int a = 20;
	for (int i = 0; i < N; i++) {
		p[i] = - 10 + rand() % a;
	}
}

void print_array(int* p, int N) {
	for (int i = 0; i < N; i++) {
		cout << setw(5) << p[i];
	}
	cout << '\n';
}

void sort(int* p, int N) {
	//positive sort
	int tmp = 0, g = 0, pos;
	if (p[N - 1] > 0) { pos = 1; }
	else { pos = 0; }
	for (int i = N - 1; i >= 0; i--) {
		if (p[i] > 0 && i < N - 1) {
			g = i;
			while (g != (N - 1 - pos)) {
				tmp = p[g];
				p[g] = p[g + 1];
				p[g + 1] = tmp;
				g++;
			}
			pos++;
		}
	}

	//negative sort
	bool flag = false;
	while (!flag) {
		flag = true;
		for (int g = 0; p[g] < 0; g++) {
			if (p[g] < p[g + 1] && p[g + 1] < 0) {
				tmp = p[g];
				p[g] = p[g + 1];
				p[g + 1] = tmp;
				flag = false;
			}
		}
	}
}
