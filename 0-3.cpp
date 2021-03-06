/*
Массив чисел размера N проинициализировать случайными числами из промежутка от -N до N. 
Написать функцию циклического сдвига элементов массива вправо на k элементов.
*/

#include <iostream>
#include <random>
#include <time.h>
#include <iomanip>

using namespace std;

int* give_memory(int N);
void init_array(int* p, int N);
void shifting(int* p, int N, int k);
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
	shifting(p, N, k);
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
	for (int i = 0; i < N; i++) {
		p[i] = -N + rand() % (N * 2);
	}
}

void print_array(int* p, int N) {
	for (int i = 0; i < N; i++) {
		cout << setw(5) << p[i];
	}
	cout << '\n';
}

void shifting(int* p, int N, int k) {
	int tmp = 0;
	for (int i = 0; i < k; i++) {
		tmp = p[N - 1];
		for (int g = N - 2; g >= 0; g--) { p[g + 1] = p[g]; }
		p[0] = tmp;
	}
}
