#include<iostream>
#include<fstream>  
using namespace std;
//struct color { unsigned char r; unsigned char g; unsigned char b; } c;

int main() {
	ifstream fff("d:\\1.bmp", ios::binary); //  ios::binary влияет ТОЛЬКО на endl.
	ofstream ggg("d:\\rez.bmp", ios::binary);//сюда пишем (поток типа ofstream= output file stream)
	if (!fff) { cout << "No file d:\\1.bmp. Can't open\n"; exit(1); }
	if (!ggg) { cout << "   file d:\\rez.bmp. Can't create\n"; exit(1); }

	char buf[30];// куда читать байты
	unsigned char color = 252;//что это????? И как это будет работать???? Тут сразу ТРИ цвета????
	unsigned int w, h;//надеемся. что тут 4 байта

	fff.read((char *)&buf, 18);   //чтение 18 байт заголовка bmp
	ggg.write((char *)&buf, 18);    //запись 18 байт заголовка bmp
	fff.read((char *)&w, 4); cout << "w=" << w;   //чтение width из заголовка bmp
	fff.read((char *)&w, 4); cout << ", h=" << w; //чтение height из заголовка bmp
	w = 1024;  h = 400;
	ggg.write((char *)&w, 4);    //запись width в заголовок bmp ( w кратно 4, обязательно для нас, чтобы не делать выравнивание)
	ggg.write((char *)&h, 4);    //запись height в заголовок bmp
	fff.read((char *)&buf, 28);   //чтение 28 байт заголовка bmp
	ggg.write((char *)&buf, 28);    //запись 28 байт заголовка bmp

	//c.r=c.g=c.b=0;
	for(int i = 1; i <= h; ++i, color = 255){
		while(color > 0){
		    ggg.write((char *)&color, 255);//что это????
			color -= 3;
		}
	}
	fff.close();//закрыли файл
	ggg.close();//закрыли файл
	return 1;
}
