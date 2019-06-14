#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <cstring>



using namespace std;

class Book {
private:
	char* theme;		// Тэма кнігі
	string author;		// Імя і прозвішча аўтара
	string title;		// Назва кнігі
	int publYear;		// Год выдання
	int copies;			// Колькасць экземпляраў
	float cost;			// Кошт аднаго экземпляра

public:
	Book(): theme(nullptr), author(), title(), publYear(0),	copies(0), cost(0){};				// Канструктар па змаўчанні
	Book(string tit) {	// Канструктар з параметрам назвы//а чаму не iнiцыалiзацыя????
		setTitle(tit);
	}

	Book(string tit, string auth) {	// Канструктар з параметрамі назвы і аўтара //а чаму не iнiцыалiзацыя????
		setTitle(tit);
		setAuthor(auth);
	}

	Book(string tit, string auth, const char* th) {	// Канструктар з параметрамі назвы, аўтара і тэмы
		setTitle(tit);
		setAuthor(auth);
		setTheme(th);
	}

	Book(string tit, string auth, const char* th, int year) {	// Канструктар з параметрамі назвы, аўтара, тэмы і году выдання
		setTitle(tit);
		setAuthor(auth);
		setTheme(th);
		setYear(year);
	}

	Book(Book &from) {	// copy constructor // а што ён вяртае?????? чаму не указана????
		setTheme(from.theme);
		setAuthor(from.author);
		setTitle(from.title);
		setYear(from.publYear);
		setCopies(from.copies);
		setCost(from.cost);
	}
	Book(Book&& other){ // move constructor а што ён вяртае?????? чаму не указана????
		if (&tmp == this) return *this;//чо?????????? откуда tmp????? Может все таки other
        this = tmp;
        tmp.theme = nullptr; //следующие 6 строк не нужны ))) кроме = nullptr!!! Зачем лишняя работа, если сейчас tmp умрет  
        tmp.author = "";
        tmp.title = "";
        tmp.publYear = 0;
        tmp.copies = 0;
        tmp.cost = 0;
        return *this;
	}


	Book& operator = (const Book& other) { //copy assignment
		Book tmp(other);
		my_swap(tmp);
		return *this;
	}

	
	~Book() {};			// Дэструктар Оппа!!!!!!!!! Учечка памяти в theme!!!!

	// Праверка на не нулявое значэнне і на добры указальнік для тэмы
	void setTheme(const char* th) { 
		if (th != nullptr) { 
			theme = new(nothrow) char[strlen(th) + 1]; 
			theme = strcpy(theme, th);
			for (int i = 0; i < strlen(theme); i++)
				theme[i] = (char)tolower(theme[i]);
		} 
	}
	const char* getTheme() { return theme; }

	// Праверка на не пустое значэнне для аўтара 
	void setAuthor(string auth) { 
		if (!auth.empty()) { 
			author = auth; 
			author = to_lowercase(author);
		} 
	}
	string getAuthor() { return author; }

	// Праверка на не пустое значэнне для назвы 
	void setTitle(string tit) { 
		if (!tit.empty()) { 
			title = tit; 
			title = to_lowercase(title);
		} 
	}
	string getTitle() { return title; }

	// Год выдання можа быць любой цэлай лічбай, так як не абмежаваны
	// Таму ў сэттары няма ніякіх праверак
	void setYear(int year) { publYear = year; }
	int getYear() { if(publYear > -1000) return publYear; }

	//Відавочна, што колькасць копій можа быць толькі больш за 0
	void setCopies(int copies) { if (copies >= 0) { this->copies = copies; } }
	int getCopies() { return copies; }

	//Відавочна, што кошт за экземпляр можа быць толькі больш за 0
	void setCost(float cost) { if (cost >= 0) { this->cost = cost; } }
	float getCost() { return cost; }



	friend ostream& operator << (ostream &out, const Book &b) {
		out << '\n';
		if (!b.title.empty()) { out << "Title: " << b.title; }
		else { out << "Title: none"; }
		if (!b.author.empty()) { out << "\nAuthor: " << b.author; }
		else { out << "\nAuthor: none"; }
		if (b.theme) { out << "\nTheme: " << b.theme; }
		else { out << "\nTheme: none"; }
		if (b.publYear > -1000) { out << "\nPublish year: " << b.publYear; }
		else { out << "\nPublish year: none"; }
		if (b.copies >= 0) { out << "\nCopies: " << b.copies; }
		else { out << "\nCopies: undefined"; }
		if (b.cost >= 0) { out << "\nCost: " << b.cost; }
		else { out << "\nCost: undefined"; }
		out << '\n';
		out << "\n**************\n";
		return out;
	}
	friend istream& operator >> (istream &in, Book &b) {		
		cin.clear();
		while (cin.get() != '\n');
		const int N = 100;
		char buff[N];
		in.getline(buff, N);
		char* tmp = strtok(buff, ",");
		int i = 0;
		while (tmp) {
			while (*tmp == ' ') { tmp++; }
			switch (i) {
			case 0: {
				string s(tmp);
				b.setTitle(s);
				break;
			}
			case 1: {
				string s(tmp);
				b.setAuthor(s);
				break;
			}
			case 2: {
				b.setTheme(tmp);
				break;
			}
			case 3: {
				b.setYear(stoi(tmp));
				break;
			}
			case 4: {
				b.setCopies(stoi(tmp));
				break;
			}
			case 5: {
				b.setCost(stoi(tmp));
				break;
			}
			}
			tmp = strtok(NULL, ",");
			i++;
		}
		
		return in;
	}

	bool operator == (const Book& other) {
		if( this->author == other.author &&
			this->title == other.title &&
			this->theme == other.theme &&
			this->publYear == other.publYear &&
			this->copies == other.copies &&
			this->cost == other.cost) { return true; }
		else { return false; }
	}

private:
	string to_lowercase(string c){
		for (char &c1 : c) {
			if (c1 >= 'A' && c1 <= 'Z') { c1 += 32; }	
		}
		return c;
	}

	void my_swap(const Book& other){
		std::swap(theme, other.theme);
		std::swap(author, other.author);
		std::swap(title, other.title);
		std::swap(publYear, other.publYear);
		std::swap(copies, other.copies);
		std::swap(cost, other.cost);
	}
};
