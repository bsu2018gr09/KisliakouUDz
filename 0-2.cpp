/*
В массиве размера N, заполненного случ.числами от 0 до 10,
определить максимальную длину последовательности равных элементов.
*/

#include <iostream>
#include <random>
#include <time.h>
#include <iomanip>

using namespace std;

int* give_memory(int N);
void init_array(int* p, int N);
int searching(int* p, int N);
void print_array(int* p, int N);

int main() {
	cout << "Enter number of elements: ";
	int N; cin >> N;
	
	int* p = give_memory(N);
	if (!p) { cout << "No memory!"; }

	init_array(p, N);
	print_array(p, N);
	cout << "Count of repeating elements: ";
	int out = searching(p, N);
	(out == 1) ? cout << "No repeatings!\n" : cout << out << '\n';

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

int searching(int* p, int N) {
	int counter = 0, c = 1;
	for (int i = 0; i < N; i++) {
		if (p[i + 1] == p[i]) { c++; }
		else { c = 1; }
		if (counter < c) { counter = c; }
	}
	return counter;
}
