#include<iostream>
#include<fstream>  
#include <clocale>
using namespace std;
struct color { unsigned char r; unsigned char g; unsigned char b; } c;

int main() {
	setlocale(LC_ALL, "Russian");
	ifstream fff("d:\\1.bmp", ios::binary); //  ios::binary влияет ТОЛЬКО на endl.
	ofstream ggg("d:\\rez.bmp", ios::binary);//сюда пишем (поток типа ofstream= output file stream)
	if (!fff) { cout << "No file d:\\1.bmp. Can't open\n"; exit(1); }
	if (!ggg) { cout << "   file d:\\rez.bmp. Can't create\n"; exit(1); }

	unsigned char rr, gg, bb; // конечный цвет
	unsigned char r, g, b; // начальный цвет;
	float steps(0);
	float sr, sg, sb;
	char buf[30];// Куда читать байты
	color c;
	float tr, tg, tb;
	unsigned int w, h;//Надеемся, что тут 4 байта

	r = 65;
	g = 211;
	b = 175;

	rr = 200;
	gg = 112;
	bb = 50;

	cout << "Enter count of steps: "; cin >> steps;


	fff.read((char *)&buf, 18);   //Чтение 18 байт заголовка bmp
	ggg.write((char *)&buf, 18);    //Запись 18 байт заголовка bmp
	fff.read((char *)&w, 4); cout << "w=" << w;   //Чтение width из заголовка bmp
	fff.read((char *)&w, 4); cout << ", h=" << w; //Чтение height из заголовка bmp
	w = 800; h = 400;
	ggg.write((char *)&w, 4);    //Запись width в заголовок bmp ( w кратно 4, обязательно для нас, чтобы не делать выравнивание)
	ggg.write((char *)&h, 4);    //Запись height в заголовок bmp
	fff.read((char *)&buf, 28);   //Чтение 28 байт заголовка bmp
	ggg.write((char *)&buf, 28);    //Запись 28 байт заголовка bmp

	if (steps > w)
		steps = w;

	float colorSteps = w / steps;
	float tmpSteps = colorSteps;
	sr = (float)(rr - r) / steps;  
	sg = (float)(gg - g) / steps;
	sb = (float)(bb - b) / steps;
	tr = (float)r;
	tg = (float)g;
	tb = (float)b;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (j == colorSteps) {
				colorSteps += tmpSteps;
				tr += sr;
				tg += sg;
				tb += sb;
			}
			c.r = (unsigned char)tr;
			c.g = (unsigned char)tg;
			c.b = (unsigned char)tb;
			ggg.write((char *)&c.b, 1);
			ggg.write((char *)&c.g, 1);
			ggg.write((char *)&c.r, 1);
		}
		tr = (float)r;
		tg = (float)g;
		tb = (float)b;
		colorSteps = tmpSteps;
	}




	fff.close();//закрыли файл
	ggg.close();//закрыли файл
	return 0;
