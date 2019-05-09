#define _CRT_SECURE_NO_WARNINGS
//После каждого слова строки, оканчивающегося заданной подстрокой, вставить указанный символ.


/*
Всё работает без ошибок!
Если слово, содержащее указанную подстроку, стоит в конце строки, пожалуйста, в конце строки поставьте пробел!
Сложность возникает при работе с нулем-терминатором
*/
#include <iostream>
#include <cstring>

using namespace std;

const int _Max = 1000;
const int N = 10;

char* getNextWordStart(char* pointer);
void shiftString(char* start);
void printString(char* pointer);
char* mainTask(char* start, char* subStart, char sym);

int main() {
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

	char* tmp = start1;
	while (tmp != nullptr)
		tmp = mainTask(tmp, start2, sym);
	printString(start1);

	/*delete[]start1;
	start1 = nullptr;
	delete[]start2;
	start2 = nullptr;*/

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
	while (pointer[i++] == ' ') {
		if (pointer[i] == 0)
			return 0;
		i++;
	}
	return (pointer + i - 1);
}

void shiftString(char* start) {
	for (int i = strlen(start) + 1; i >= 0; i--) {
		start[i + 1] = start[i];
		start[i] = ' ';
	}
}

void printString(char* pointer) {
	int i = 0;
	while (pointer[i]) {
		cout << pointer[i++];
	}
	cout << '\n';
}

char* mainTask(char* start, char* subStart, char sym) {
	start = strstr(start, subStart);
	if (start == nullptr)
		return nullptr;

	for (int i = 0; i < strlen(subStart); i++) {
		if (start[i] != subStart[i])
			return getNextWordStart(start);

		if (start[i + 1] != ' ' && subStart[i + 1] == 0)
			return getNextWordStart(start);
	}

	shiftString(start + strlen(subStart));
	start[strlen(subStart)] = sym;

	return getNextWordStart(start);
}
