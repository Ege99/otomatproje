// OTOMAT.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.

#include <iostream>
using namespace std;

struct Kullanici
{
	double para;
	int numara;
};
string urunler[9] = { "Su","Bisküvi","Cikolata","Cubuk Kraker","Kek","Kola","Meyve Suyu","Soda","Gofret" };
double fiyatlar[9] = { 1,2,1.25,0.75,0.5,5,4.75,2.25,1 };
double otomat(Kullanici para2);
void display_menu();
int main()
{
	Kullanici param;
	double sonuc;

	display_menu();

	cout << "Kac para: ";
	cin >> param.para;

	cout << "\nHangi numara: ";
	cin >> param.numara;

	sonuc = otomat(param);
	cout << "\nKalan para: ";
	cout << sonuc;

	return 0;
}
double otomat(Kullanici param)
{

	double islem;
	if (param.para > fiyatlar[param.numara - 1])
	{
		islem = param.para - fiyatlar[param.numara - 1];
	}
	else
	{
		cout << "HATA! Lutfen (0 - 9) aralıgında bir numara giriniz..";
	}

	return islem;
}
void display_menu()
{
	cout << " Otomat'a hosgeldiniz!" << endl;
	cout << "Lutfen (0 - 9) aralıgında bir numara giriniz.." << endl;
	for (int i = 0; i < 9; i++)
		cout << i + 1 << "- " << urunler[i] << "  " << fiyatlar[i] << " tl" << endl;
	//cout << fiyatlar << endl;
}