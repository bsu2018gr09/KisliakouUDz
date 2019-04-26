/*
	Исправлены принимаемые значения операторов
	Добавлены проверки в сеттеры
	Доработана функция check
*/
#include <iostream>
#include <random>
#include <time.h>

using namespace std;



class Money {//нигде не вижу const!!!!
private:
	int roub;
	int coins;

	// я думаю надо что -то типа check вместо твоих почему то  roubPlus и roubMinus или обоснуй!!!!
public:
	//Constructors
	Money() : roub(0), coins(0) {}//плохо!!!!
	~Money() { /*cout << "Destructor is woking!\n"; */ }
	Money(int r, int c = 0) : roub(r), coins(c) {

		//Case if count of roubs is less than 0
		if (r < 0) { cout << "The very little of roubles!"; roub = 0; coins = 0; }

		check();
	}

	Money(const Money& m) {
		this->roub = m.roub;
		this->coins = m.coins;
	}

	//Getter and setter for Roubles
	void setRoub(int roub) {
		if (roub > 0)
			this->roub = roub;
		else
			this->roub = 0;
	}// и никаких проверок? Плохо

	int getRoub() { return roub; }

	//Getter and setter for coins
	void setCouns(int coins) {
		if (coins > 0)
			this->coins = coins;
		else
			this->coins = 0;
	}// и никаких проверок? Плохо

	int getCoins() { return coins; }


	void operator = (const Money& m) {// точно так передавать ты хочешь m? Почему???? 
		this->roub = m.roub;
		this->coins = m.coins;
	}

	Money operator + (const Money& m) {// точно так передавать ты хочешь m? Почему???? 
		return Money(this->roub + m.roub, this->coins + m.coins);
	}

	void operator += (const Money& m) {// точно так передавать ты хочешь m? Почему???? 
		this->roub += m.roub;
		this->coins += m.coins;
		check();
	}

	Money operator - (const Money& m) {// точно так передавать ты хочешь m? Почему???? 
		return Money(this->roub - m.roub, this->coins - m.coins);
	}

	void operator -= (const Money& m) {// точно так передавать ты хочешь m? Почему???? 
		roub -= m.roub;
		if (roub < 0) { roub = 0; coins = 0;  cout << "The very little of roubles"; }
		coins -= m.coins;
		check();
	}

	Money operator ++ () {
		return Money(++this->roub, this->coins);
	}

	Money operator -- () {
		if (!this->roub) { return Money(0, this->coins); cout << "The very little of roubles"; }
		else { return(--this->roub, this->coins); }
	}

	bool operator == (const Money& m) {// точно так передавать ты хочешь m? Почему???? 
		if (roub == m.roub && coins == m.coins) { return true; }
		else { return false; }
	}

	bool operator > (const Money& m) {// точно так передавать ты хочешь m? Почему???? 
		if (roub > m.roub) { return true; }
		else
			return(coins > m.coins);//можно обойтись только return(coins > m.coins)
			//Исправлено!

	}

	bool operator >= (const Money& m) {// точно так передавать ты хочешь m? Почему???? 
		if (roub >= m.roub) { return true; }
		else
			return(coins >= m.coins);

	}

	bool operator < (const Money& m) {// точно так передавать ты хочешь m? Почему???? 
		if (roub < m.roub) { return true; }
		else
			return(coins < m.coins);

	}

	bool operator <= (const Money& m) {// точно так передавать ты хочешь m? Почему???? 
		if (roub <= m.roub) { return true; }
		else
			return(coins <= m.coins);

	}

	friend ostream& operator << (ostream & stream, const Money& m) {
		stream << "Roubs: " << m.roub << "\nCoins: " << m.coins << '\n';
		return stream;
	}

private:
	//Function working with least or most values
	void check() {
		if (coins < 0) {
			while (coins < 0) {
				--roub;
				coins += 100;
			}
		}
		else if (coins > 100) {
			while (coins > 100) {
				++roub;
				coins -= 100;
			}
		}
		else { return; }
	}
};

//Functions
Money randInit(int);


int main() {
	int N;
	cout << "Enter count of elements: "; cin >> N;
	Money* p = new (nothrow) Money[N];
	for (int i = 0; i < N; i++) {
		p[i] = randInit(i);
		cout << p[i] << '\n';
	}
	Money m1 = randInit(N), m2 = randInit(N - 1),	// the parameteres of functions
		m3 = randInit(N - 2), m4 = randInit(N - 3);		// are seeds only just for first-class random 

	Money *p1 = &m3, *p2 = &m4;
	cout << "\n*************************";
	cout << "\nWorking of operators:\n";
	cout << "The first: \n" << m1 << "\nThe second: \n" << m2 << '\n';
	cout << "m1 + m2 :\n" << m1 + m2 << '\n';
	cout << "\nm1 - m2 :\n" << m1 - m2 << '\n';
	m1 += m2;
	cout << "\nm1 += m2 : \n" << m1 << '\n';
	m1 -= m2;
	cout << "\nm1 -= m2 : \n" << m1 << '\n';


	cout << "\n*************************";
	cout << "\nWorking of operators with pointers:\n";
	cout << "The first: \n" << *p1 << "\nThe second: \n" << *p2 << '\n';
	cout << "m1 + m2 :\n" << *p1 + *p2 << '\n';
	cout << "\nm1 - m2 :\n" << *p1 - *p2 << '\n';
	*p1 += *p2;
	cout << "\nm1 += m2 : \n" << *p1 << '\n';
	*p1 -= *p2;
	cout << "\nm1 -= m2 : \n" << *p1 << '\n';

	Money m5(1, 5), m6(1, 6);
	cout << "\n*************************";
	cout << "\nWorking of bool operators:\n";
	cout << "The first: \n" << m5 << "\nThe second: \n" << m6 << '\n';
	cout << "m5 > m6: " << (bool)(m5 > m6) << '\n';
	cout << "m5 == m6: " << (bool)(m5 == m6) << '\n';
	cout << "m5 < m6: " << (bool)(m5 < m6) << '\n';
	system("pause");
	return 0;
}

Money randInit(int seed) {
	srand(seed);
	int tmp = 100;
	Money m(rand() % tmp, rand() % tmp);
	return m;
}
