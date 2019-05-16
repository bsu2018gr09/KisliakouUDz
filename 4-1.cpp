//Отсортировать строки по количеству слов заданной длины
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream> 	
#include<cstring>

using namespace std;

char* getNextWordStart(char* pointer);
int lettersInWord(char* pointer);
int mainTask(char* start, int count);
void sort(char**, int*, int);

ifstream input("d:\\WarAndPiece.txt");
ofstream output("d:\\result.txt");

int main() {
	cout << "Enter count of letters in words: ";
	int count; cin >> count;

	const int N = 300;
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
		wordsInRowCount[rowsCount] = mainTask(rows[rowsCount], count);
		rowsCount++;
		if (input.eof()) { break; }
	}
	
	bool flag = true;
	while (flag) {
		for (int g = 0; g < rowsCount - 1; g++) {
			if (wordsInRowCount[g] > wordsInRowCount[g + 1]) {
				int tmp = wordsInRowCount[g];
				char* tmp1 = rows[g];

				wordsInRowCount[g] = wordsInRowCount[g + 1];
				wordsInRowCount[g + 1] = tmp;

				rows[g] = rows[g + 1];
				rows[g + 1] = tmp1;
			}
		}
		if (flag) { break; }
		else { flag = true; }
	}

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

char* getNextWordStart(char* pointer) {
	int i = 0;
	while (pointer[i] != ' ') {
		if (!pointer[i])
			return nullptr;
		i++;
	}
	while (pointer[i] == ' ') {
		if (!pointer[i + 1])
			return nullptr;
		i++;
	}
	return (pointer + i);
}

int lettersInWord(char* pointer) {
	int i = 0, counter = 0;
	while ((pointer[i] >= 65 && pointer[i] <= 90) || (pointer[i] >= 97 && pointer[i] <= 122)) {
		counter++;
		i++;
	}
	return counter;
}

int mainTask(char* start, int count) {
	int counter = 0;
	while(start){
		if (lettersInWord(start) == count) { counter++; }
		start = getNextWordStart(start);
	}
	return counter;
}

