//Отсортировать строки по количеству слов заданной длины
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream> 	
#include<cstring>
#include <clocale>
#include <Windows.h>

using namespace std;

int mainTask(char* start, int count);
void sort(char**, int*, int);
bool testPunct(const char* p);

ifstream input("d:\\WarAndPiece.html");
ofstream output("d:\\result.txt");

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	cout << "Enter count of letters in words: ";
	int count; cin >> count;

	const int N = 10500;
	int rowsCount = 0;

	char* start = new char[N];
	char** rows = new char*[N];
	int *wordsInRowCount = new(nothrow) int[N];

	if (!input) cout << "No file d:\\WarAndPiece.txt. Can't open\n";
	if (!output) cout << "File d:\\result.txt. Can't create\n";
	
	while (true) {
		input.getline(start, N + 1);
		rows[rowsCount] = new(nothrow) char[strlen(start) + 1];
		strcpy(rows[rowsCount], start);
		wordsInRowCount[rowsCount] = mainTask(start, count);
		rowsCount++;
		if (input.eof()) { break; }
	}

	sort(rows, wordsInRowCount, rowsCount);

	for (int g = 0; g < rowsCount; g++) {
		output << wordsInRowCount[g] << ' ' << rows[g] << '\n';
	}


	for (int g = 0; g < rowsCount; g++) {
		cout << rows[g] << " ";
		cout << wordsInRowCount[g] << '\n';
	}


	delete[]rows;
	delete[]wordsInRowCount;

	input.close();
	output.close();
	
	system("pause");
	return 0;
}

void sort(char** rows, int* wordsInRowCount, int rowsCount) {
	bool flag = false;
	do {
		flag = false;
		for (int g = 0; g < rowsCount - 1; g++) {
			if (wordsInRowCount[g] < wordsInRowCount[g + 1]) {
				int tmp = wordsInRowCount[g];
				char* tmp1 = rows[g];

				wordsInRowCount[g] = wordsInRowCount[g + 1];
				wordsInRowCount[g + 1] = tmp;

				rows[g] = rows[g + 1];
				rows[g + 1] = tmp1;
				flag = true;
			}
		}
	} while (flag);
}

int mainTask(char* start, int count) {
	char* tmp = strtok(start, " ");
	int counter = 0;
	while (tmp) {
		if ((strlen(tmp) == count) && testPunct(tmp)) {
			counter++;
		}
		tmp = strtok(NULL, " ");
	}
	return counter;
}

bool testPunct(const char* p) {
	const char* signs = ".,-_*\"()!?";
	for (int i = 0; i < strlen(signs); i++) {
		if (p[0] == signs[i] || p[strlen(p) - 1] == signs[i]) { return false; }
	}
	return true;
}
