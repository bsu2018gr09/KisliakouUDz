

#include <iostream>
#include <random>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

bool isPrime(int a);
void mainTask(int* p, int N);
int* give_memory(int N);
void init_array(int* p, int N);
void print_array(int* p, int N);

int main() {
	cout << "Enter number of elements: ";
	int N; cin >> N;

	int* p = give_memory(N);
	if (!p) { cout << "No memory!"; }

	init_array(p, N);
	print_array(p, N);
	mainTask(p, N);
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

void init_array(int* p, int N) {
	srand(time(NULL));
	int a = 20;
	int b = 0;
	for (int i = 0; i < N; i++) {
		p[i] = b + rand() % a;
	}
}

void print_array(int* p, int N) {
	for (int i = 0; i < N; i++) {
		cout << setw(5) << p[i];
	}
	cout << '\n';
}

bool isPrime(int a) {
	if (a > 1) {
		for (int i = 2; i <= sqrt(a); i++)
			if (!(a % i)) { return false; }
		return true;
	}
	else 
		if (a == 1) { return true; }
		else { return false; }
}

void mainTask(int *p, int N) {
	bool flag = false;
	int tmp = 0;
	while (!flag) {
		flag = true;
		for (int i = 0; i < N; i++) {
			for (int g = i + 1; g < N; g++) {
				if (p[i] > p[g] && isPrime(p[g]) && isPrime(p[i])) {
					tmp = p[i];
					p[i] = p[g];
					p[g] = tmp;
					flag = false;
				}
			}
		}
	}
}
