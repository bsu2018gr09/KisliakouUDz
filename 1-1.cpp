#include <iostream>
#include <random>
#include <time.h>
#include <iomanip>
#include <math.h>

using namespace std;

int* give_memory(int N);
void init_array(int* p, int N, int);
float findDistance(int x, int y, int A, int B, int C);
void print_array(int* p, int N);

int main() {
  srand(time(NULL));
	cout << "Enter number of elements: ";
	int N; cin >> N;
	cout << "Enter A, B and C: ";
	int A, B, C;
	cin >> A >> B >> C;

	int* p1 = give_memory(N);
	if (!p1) { cout << "No memory!"; }

	int* p2 = give_memory(N);
	if (!p2) { cout << "No memory!"; }

	cout << "X-coordinates:\n";
	init_array(p1, N, rand());
	print_array(p1, N);
	cout << '\n';


	cout << "Y-coordinates:\n";
	init_array(p2, N, rand());
	print_array(p2, N);
	cout << '\n';

	for (int i = 0; i < N; i++) {
		cout << "Distance to the line from the point (" << p1[i] << ", " << p2[i] << "): ";
		cout << findDistance(p1[i], p2[i], A, B, C) << '\n';
	}

	delete[]p1;
	p1 = nullptr;
	delete[]p2;
	p2 = nullptr;
	system("pause");
	return 0;
}

int* give_memory(int N) {
	int* p = new(nothrow) int[N];
	if (p == nullptr) { return nullptr; }
	return p;
}

void init_array(int* p, int N, int base){
	srand(base);
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

float findDistance(int x, int y, int A, int B, int C) {
	float distance = abs(A*x + B*y + C) / sqrt(A*A + B*B);
	return distance;
}
