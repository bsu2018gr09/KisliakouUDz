#define _CRT_SECURE_NO_WARNINGS
//После каждого слова строки, оканчивающегося заданной подстрокой, вставить указанный символ.

#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

const int _Max = 10000;
const int N = 10;

void printString(char* pointer);
void mainTask(char* start, char* subStart, char sym);

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char buff[_Max];
	char buff2[N];
	char sym;
	cout << "Print your string: \n";
	cin.getline(buff, _Max);
	cout << "Print your subString: \n";
	cin.getline(buff2, _Max);
	cout << "Print symbol you want to push: ";
	cin >> sym;

	char * start1 = new(nothrow) char[strlen(buff) + 1];
	if (!start1) {
		cout << "No memory\n";
		exit(1);
	}
	strcpy(start1, buff);

	char * start2 = new(nothrow) char[strlen(buff2) + 1];
	if (!start2) {
		cout << "No memory\n";
		exit(1);
	}
	strcpy(start2, buff2);
	
	mainTask(start1, start2, sym);
	cout << '\n';

	delete[]start1;
	start1 = nullptr;
	delete[]start2;
	start2 = nullptr;

	system("pause");
	return 0;
}



void printString(char* pointer) {
	int i = 0;
	while (pointer[i]) {
		cout << pointer[i++];
	}
	cout << ' ';
}

void mainTask(char* start, char* subStart, char sym) {
	const int N = 500;
	char *tmp = strtok(start, " ");
	char **arr = new(nothrow) char *[N];
	int counter = 0;
	while (tmp) {
		arr[counter] = new(nothrow) char[strlen(tmp)];
		strcpy(arr[counter], tmp);
		counter++;
		tmp = strtok(NULL, " ");
	}
	for(int i = 0; i < counter; i++) {
		char* tmp = arr[i];
		tmp += strlen(arr[i]) - strlen(subStart);
		if (strstr(tmp, subStart)) {
			strcat(arr[i], " ");
			arr[i][strlen(arr[i]) - 1] = sym;
		}
		printString(arr[i]);
	}
}

