//Отсортировать строки по количеству слов заданной длины

#include<iostream>
#include<fstream> 	

using namespace std;

char* getNextWordStart(char* pointer);
void printWordinFile(char* pointer); 
void printWordOnScreen(char* pointer);
int lettersInWord(char* pointer);
char* mainTask(char* start, int count);

ifstream input("d:\\WarAndPiece.txt");
ofstream output("d:\\result.txt");

int main() {
	cout << "Enter count of letters in words: ";
	int count; cin >> count;

	const int N = 400;
	char *start = new char[N];

	if (!input) cout << "No file d:\\date1.txt. Can't open\n"; 
	if (!output) cout << "File d:\\date2.txt. Can't create\n";

	char* tmp = start;
	while (true) {
		input.getline(start, N - 1);
		tmp = start;
		while(tmp)
			tmp = mainTask(tmp, count);
		if (input.eof()) 
			break;
	}
	cout << '\n';
	delete[]start;
	delete[]tmp;
	input.close();
	output.close();

	system("pause");
	return 0;
}

char* getNextWordStart(char* pointer) {
	int i = 0;
	while (pointer[i] != ' ') {
		if (pointer[i] == 0)
			return 0;
		i++;
	}
	while (pointer[i] == ' ') {
		if (pointer[i] == 0)
			return 0;
		i++;
	}
	return (pointer + i);
}

void printWordinFile(char* pointer) {
	int i = 0;
	while (pointer[i] >= 65) {
		output << pointer[i];
		i++;
	}
}

void printWordOnScreen(char* pointer) {
	int i = 0;
	while (pointer[i] >= 65) {
		cout << pointer[i];
		i++;
	}
}

int lettersInWord(char* pointer) {
	int i = 0, counter = 0;
	while (pointer[i] >= 65) {
		counter++;
		i++;
	}
	return counter;
}

char* mainTask(char* start, int count) {
	if (lettersInWord(start) == count) {
		printWordOnScreen(start);
		cout << ' ';
		printWordinFile(start);
		output << ' ';
	}
	return getNextWordStart(start);
}
