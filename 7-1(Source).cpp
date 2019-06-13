#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Book.h"
#include <random>
#include <time.h>

using namespace std;

int arrLength(Book* arr);
void addBook(Book book, Book* arr);
Book* findTitle(Book* arr, string auth);
Book* findAuthor(Book* arr, string auth);
Book* findTheme(Book* arr, string th);
Book* findYear(Book* arr, int year);
Book* findCost(Book* arr, int cost);
string to_lowercase(string c);
Book* initLib(int N);
int getAllCopies(Book* arr);
int getAllCost(Book* arr);
void orderArr(Book* arr, int param);
void print(ostream &out, Book* arr);
void edit(Book b);


string Surnames[] = { "Grant", "Reynolds", "Preston", "Fields", "Black",
"Cameron", "Hall", "Flowers", "Fleming", "Bell",
"Richardson", "Perry", "Curtis", "White", "Williams",
"Sanders", "Horn", "Horton", "Strickland", "Simpson",
"Greer", "Marshall", "Parker" };

string Titles[] = { "In Search of Lost Time", "Don Quixote", "Ulysses",
"The Great Gatsby", "Moby Dick", "Hamlet", "War and Peace", "The Odyssey",
" One Hundred Years of Solitude", "The Divine Comedy", "The Brothers Karamazov",
"Madame Bovary", "The Adventures of Huckleberry Finn" };

const char* Themes[] = { "Tales", "Detectives", "Dramas", "Comedies", "Adventures", "Fantastics" };

ofstream out("d:\\Library.txt", ios::trunc);

int main() {
	if (!out) { cout << "Can't create\n"; exit(1); }
	int N; int param;
	setlocale(LC_ALL, "Russian");
	cout << "Добро пожаловать в библиотеку!\n";
	cout << "Введите количество книг, которые будут исопльзоваться: "; cin >> N;
	Book* arr = new(nothrow) Book[N];

	while (true) {
		cout << "\n\nВыберите операцию: \n\n";
		cout << "1) Заполнить библиотеку автоматически;\n";
		cout << "2) Вывод в файл всех данных про книги;\n";
		cout << "3) Упорядочить список книг по заданному критерию;\n";
		cout << "4) Поиск книги по критериям;\n";
		cout << "5) Ввести и добавить книгу;\n";
		cout << "6) Изменить книгу;\n\n";
		cout << "Ваш выбор: "; cin >> param;

		switch (param){
		case 1: {
			arr = initLib(N);
			cout << "У вас готова заполненная библиотека!\n";
			break;
		}
		case 2: {
			print(out, arr);
			cout << "Ваши книги в файле!\n";
			system("pause");
			return 0;
			break;
		}
		case 3: {
			int par;
			cout << "Выберите критерий упорядочивания: \n";
			cout << "1) По году издания;\n";
			cout << "2) По количеству копий;\n";
			cout << "3) По стоимости за копию;\n\n";
			cout << "Ваш выбор: "; cin >> par;

			orderArr(arr, par);
			cout << "Ваш список отсортирован!\n\n";
			break;
		}
		case 4: {
			int par;
			cout << "Выберите параметр поиска: \n";
			cout << "0) Вывести в консоль отсортированные книги;\n";
			cout << "1) Одинаковый автор;\n";
			cout << "2) Название;\n";
			cout << "3) Тема;\n";
			cout << "4) Год издания;\n";
			cout << "5) Количество копий;\n";
			cout << "6) Одинаковая цена;\n\n";
			cout << "Ваш выбор: "; cin >> par;
			switch (par) {
			case 0: {
				print(cout, arr);
				break;
			}
			case 1: {
				string auth;
				cout << "\nВведите желаемого автора: "; cin >> auth;
				arr = findAuthor(arr, auth);
				cout << "\nВ списке книги тольки с одинаковым автором!\n";
				break;
			}
			case 2: {
				string titl;
				cout << "\nВведите желаемое название: "; cin >> titl;
				arr = findTitle(arr, titl);
				cout << "\nВ списке книги тольки с одинаковым названием!\n";
				break;
			}
			case 3: {
				char* theme = new(nothrow) char[100];
				cout << "\nВведите желаемую тему: "; cin.getline(theme, 100);
				arr = findTheme(arr, theme);
				cout << "\nВ списке книги тольки с одинаковой темой!\n";
				break;
			}
			case 4: {
				int year;
				cout << "\nВведите желаемую год: "; cin >> year;
				arr = findYear(arr, year);
				cout << "\nВ списке книги тольки с одинаковым годом!\n";
				break;
			}
			default:
				cout << "Неправильный ввод!\n";
				break;
			}
			break;
		}
		case 5: {
			Book b;
			cout << "Введите книгу в формате: \n" << " Название, автор, тема, год издания, количество копий, стоимость\n";
			cin >> b;
			addBook(b, arr);
			break;
		}
		case 6: {
			Book* b = new(nothrow) Book[N];
			string tmp1;
			cout << "Введите название книги: ";
			cin >> tmp1;
			b = findTitle(b, tmp1);
			cout << "Введите автора: ";
			cin >> tmp1;
			b = findAuthor(b, tmp1);
			print(out, b);
			cout << "Книга изменена!";
			break;
		}
		default:
			cout << "Неправильный выбор, попробуйте ещё раз!\n\n";
			break;
		}
	}
	cout << "\nMain time: " << (float)clock() / 1000 << '\n';
	system("pause");
	return 0;
}


//Функцыя вяртае колькасць кніг у масіве
int arrLength(Book* arr) {
	int counter = 0;
	while (!arr[counter].getTitle().empty()) {
		counter++;
	}
	return counter;
}

//Функцыя дадае кнігу ў канец масіву, правяраючы крытэрый "Назва"
void addBook(Book book, Book* arr) {
	int pos = 0;
	if (arr[pos].getTitle().empty()) {
		arr[pos] = book;
		return;
	}
	else {
		while (!arr[pos].getTitle().empty()) { pos++; }
		arr[pos] = book;
		return;
	}
}

//Вяртаем указальнік на масіў кніг з аднолькавай назвай
Book* findTitle(Book* arr, string title) {
	int l = arrLength(arr);
	title = to_lowercase(title);
	Book* same = new(nothrow) Book[l];
	for (int i = 0; i < l; i++) {
		if (arr[i].getTitle() == title) {
			addBook(arr[i], same);
		}
	}
	return same;
}

//Вяртаем указальнік на масіў кніг з аднолькавым аўтарам
Book* findAuthor(Book* arr, string auth) {
	int l = arrLength(arr);
	auth = to_lowercase(auth);
	Book* same = new(nothrow) Book[l];
	for (int i = 0; i < l; i++) {
		if (arr[i].getAuthor() == auth) {
			addBook(arr[i], same);
		}
	}
	return same;
}

//Вяртаем указальнік на масіў кніг з аднолькавай тэмай
Book* findTheme(Book* arr, string th) {
	int l = arrLength(arr);
	th = to_lowercase(th);
	Book* same = new(nothrow) Book[l];
	for (int i = 0; i < l; i++) {
		if (arr[i].getTheme() == th) {
			addBook(arr[i], same);
		}
	}
	return same;
}

//Вяртаем указальнік на масіў кніг з аднолькавым годам выдання
Book* findYear(Book* arr, int year) {
	int l = arrLength(arr);
	Book* same = new(nothrow) Book[l];
	for (int i = 0; i < l; i++) {
		if (arr[i].getYear() == year) {
			addBook(arr[i], same);
		}
	}
	return same;
}

//Вяртаем указальнік на масіў кніг з аднолькавым коштам за копію
Book* findCost(Book* arr, int cost) {
	int l = arrLength(arr);
	Book* same = new(nothrow) Book[l];
	for (int i = 0; i < l; i++) {
		if (arr[i].getYear() == cost) {
			addBook(arr[i], same);
		}
	}
	return same;
}

//Упарадкоўвае кнігі па дадзеным крытэрыі
void orderArr(Book* arr, int param) {
	bool flag = true;
	int l = arrLength(arr) - 1;
	switch (param) {
	case 1:
		//Упарадкоўванне па годзе выдання
		while (flag) {
			for (int i = 0; i < l; i++) {
				if (arr[i].getYear() > arr[i + 1].getYear()) {
					Book tmp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = tmp;
					flag = false;
				}
			}
			if (flag) { break; }
			flag = true;
		}
		break;
	case 2:
		//Упарадкоўванне па колькасці копіяў 
		while (flag) {
			for (int i = 0; i < l; i++) {
				if (arr[i].getCopies() > arr[i + 1].getCopies()) {
					Book tmp1 = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = tmp1;
					flag = false;
				}
			}
			if (flag) { break; }
			flag = true;
		}
		break;
	case 3:
		//Упарадкоўванне па кошце
		while (flag) {
			for (int i = 0; i < l; i++) {
				if (arr[i].getCost() > arr[i + 1].getCost()) {
					Book tmp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = tmp;
					flag = false;
				}
			}
			if (flag) { break; }
			flag = true;
		}
		break;
	}
}

//Вяртае радок цалкам у ніжнім рэгістры
string to_lowercase(string c) {
	for (char &c1 : c) {
		if (c1 >= 'A' && c1 <= 'Z') { c1 += 32; }
	}
	return c;
}

//Функцыя запаўняе бібліятэку фэйкавымі дадзенымі
Book* initLib(int N) {
	srand(time(NULL));
	Book* arr = new(nothrow) Book[N + 100];
	Book tmp;
	for (int i = 0; i < N; i++) {
		tmp.setTheme(Themes[rand() % 6]);
		tmp.setAuthor(Surnames[rand() % 23]);
		tmp.setTitle(Titles[rand() % 13]);
		tmp.setYear(rand() % 10);
		tmp.setCopies(rand() % 1000);
		tmp.setCost(rand() % 50);
		arr[i] = tmp;
	}
	return arr;
}

//Функцыя вяртае колькасць УСІХ кніжак у бібліятэцы
int getAllCopies(Book* arr) {
	int counter = 0;
	for (int i = 0; i < arrLength(arr); i++) { counter += arr[i].getCopies(); }
	return counter;
}

//Функцыя вяртае кошт УСІХ кніжак у бібліятэцы
int getAllCost(Book* arr) {
	int counter = 0;
	for (int i = 0; i < arrLength(arr); i++) { counter += arr[i].getCost(); }
	return counter;
}

//Друкуе дадзены масіў кніжак
void print(ostream &out, Book* arr) {
	int l = arrLength(arr);
	for (int i = 0; i < l; i++) { out << arr[i]; }
	out << '\n';
}
