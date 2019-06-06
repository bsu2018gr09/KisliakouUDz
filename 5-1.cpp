#include<iostream>
#include<fstream>  

using namespace std;
struct color { unsigned char r; unsigned char g; unsigned char b; };

int main() {
	ifstream fff("d:\\1.bmp", ios::binary); //  ios::binary влияет ТОЛЬКО на endl.
	ofstream ggg("d:\\rez.bmp", ios::binary);//сюда пишем (поток типа ofstream= output file stream)
	if (!fff) { cout << "No file d:\\1.bmp. Can't open\n"; exit(1); }
	if (!ggg) { cout << "   file d:\\rez.bmp. Can't create\n"; exit(1); }

	char buf[30];// куда читать байты
	unsigned char r_start, g_start, b_start;
	unsigned char r_end, g_end, b_end;
	unsigned int steps;
	color tmp;
	float r, g, b;
	unsigned int w, h;//надеемся. что тут 4 байта

	fff.read((char *)&buf, 18);   //чтение 18 байт заголовка bmp
	ggg.write((char *)&buf, 18);    //запись 18 байт заголовка bmp
	fff.read((char *)&w, 4); cout << "w=" << w;   //чтение width из заголовка bmp
	fff.read((char *)&h, 4); cout << ", h=" << h; //чтение height из заголовка bmp
	w = 800; h = 200;
	ggg.write((char *)&w, 4);    //запись width в заголовок bmp ( w кратно 4, обязательно для нас, чтобы не делать выравнивание)
	ggg.write((char *)&h, 4);    //запись height в заголовок bmp
	fff.read((char *)&buf, 28);   //чтение 28 байт заголовка bmp
	ggg.write((char *)&buf, 28);    //запись 28 байт заголовка bmp

	cout << "Enter count of steps: "; cin >> steps;
	float p = (float)(w / steps);
	r_start = 0;  
	g_start = 0;
	b_start = 255;


	r_end = 150; 
	g_end = 255; 
	b_end = 50;


	r = (float)((r_end - r_start)/ steps);
	g = (float)((g_end - g_start) / steps);
	b = (float)((b_end - b_start) / steps);

	tmp.r = (unsigned char)r;
	tmp.g = (unsigned char)g;
	tmp.b = (unsigned char)b;

	for(int i = 1; i <= h; ++i){
		for(int j = 1; j <= w; ++j){
			if (j == (int)p) {
				p += (float)(w / steps);
				tmp.r += r;
				tmp.g += g;
				tmp.b += b;
			}
			ggg.write((char *)&tmp.r, 1);
			ggg.write((char *)&tmp.g, 1);
			ggg.write((char *)&tmp.b, 1);
		}

		tmp.r = (unsigned char)r_start;
		tmp.g = (unsigned char)g_start;
		tmp.b = (unsigned char)b_start;
		p = (float)(w / steps);
	}

	fff.close();//закрыли файл
	ggg.close();//закрыли файл
	system("pause");
	return 1;
}
