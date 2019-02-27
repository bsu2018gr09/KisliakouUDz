/*В массиве размера N, заполненного случ.числами от 0 до 10, 
подсчитать количество элементов, 
встречающихся более одного раза*/

#include <iostream>
#include <random>
#include <time.h>

void initRandomArr(int* p, int N);
int howManyCopies(int* p, int N);
void bubbleSort(int* p, int N);
void outputArray(int* p, int N);

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "Введите количество элементов массива: "; cin >> N;
	int* p;
	p = new int[N];
	initRandomArr(p, N);
	outputArray(p, N);
	cout << '\n';
	cout << "Количество повторов: " << howManyCopies(p, N);
	cout << '\n';
	delete[]p;
	system("pause");
	return 0;
}

void initRandomArr(int* p, int N) {
	srand(time(NULL));
	for (int i = 0; i < N; ++i)
		*(p + i) = rand() % 10;
}

void bubbleSort(int* p, int N) {
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int g = i + 1; g < N; g++) {
			if (*(p + i) > *(p + g)) {
				temp = *(p + i);
				*(p + i) = *(p + g);
				*(p + g) = temp;
			}
		}
	}
}

int howManyCopies(int* p, int N) {
	bubbleSort(p, N);
	int g = 0, counter = 0;
	for (int i = 0; i < N; ++i) {
		while (p[i] == p[i + 1]) {
			++g;
			++i;
		}
		if (g > 0) {
			++counter;
			g = 0;
		}
	}
	return counter;
}

void outputArray(int* p, int N) {
	for (int i = 0; i < N; ++i)
		cout << *(p + i) << ' ';
}
