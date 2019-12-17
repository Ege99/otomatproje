// OTOMAT.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.

#include <iostream>
using namespace std;

class Kullanici // Kullanici class ı oluşturuldu. Para ve numara içeren. ve public olan
{
public:
	double para;
	int numara;
};

string urunler[9] = { "Su","Biskuvi","Cikolata","Cubuk Kraker","Kek","Kola","Meyve Suyu","Soda","Gofret" };		// urunlerimiz bunlardır
double fiyatlar[9] = { 1,2,1.25,0.75,0.5,5,4.75,2.25,1 };		// urunlerin fiyatlarını bu şekilde ayarladık
double otomat(Kullanici para2);		// otomat fonksiyonumuza Kullanici class lı param adında olan bir parametre atadık
void display_menu(); // menuyu daha sonra kullanmak icin burada tanımını yaptık

int main()
{
	Kullanici param;		// Kullanici class ında param isimli bir degisken tanımlar
	double sonuc;			// double tipinde bir sonuc tanımlar

	display_menu();			// menuyu ekrana yazdırır
	int* b;					// 

	cout << "\nKac para: ";	// kaç para oldugunu sorar ve karsılıgında girilen degeri ekrandan alır ve param degiskenindeki paraya atar
	cin >> param.para;
	cout << "\nHangi numara: ";	// hangi numara oldugunu sorar ve karsılıgında ekrandan girilen degeri alır ve param degiskenindeki numaraya atar. Boylece Classımızda bilgilerin ikiside alınmış olur.
	cin >> param.numara;
	b = &param.numara;		//
	sonuc = otomat(param);	// az once aldıgımız iki (numara ve para) bilgileri otomat fonksiyonuna gonderir ve ordan donen cevabıda sonuc degiskenine ata
	cout << "\nKalan para: ";
	cout << sonuc;		// Kalan parayı hesap edip kendisi ekrana yazdırır
	cout << "\n";
	return 0;
}
double otomat(Kullanici param)
{

	double islem;	// double tipinde bir islem tanımladık
	if (param.para > fiyatlar[param.numara - 1] || param.para == fiyatlar[param.numara - 1])	
	// Eger parametre olan param > fiyatlar dizisindeki  parametre olan numaradan buyukse. (Yani param > fiyatsa.  alabilecegimiz bir ürün varsa)
	// veya eşitse
	{
		islem = param.para - fiyatlar[param.numara - 1];		// paramdan ürünün fiyatını cıkar ve bunu islem olarak tanımladıgım aslında para üstü hesaplayan islem adında tut.
	}
	else
	{
		cout << "HATA! Lutfen (0 - 9) araliginda bir numara giriniz..";
	}
	return islem;  // islemi (yani paraüstünü) döndür.

}
void display_menu()
{
	cout << " Otomat'a hosgeldiniz!" << endl;
	cout << "Lutfen (0 - 9) araliginda bir numara giriniz.." << endl;
	for (int i = 0; i < 9; i++)		// i = 0 olsun ve i < 9 iken ;	i+1 - urun - fiyat - tl olarak bir cıktı versin 
		// Bu da su demek olur ==     1- Su 1 tl
		cout << i + 1 << "- " << urunler[i] << " : " << fiyatlar[i] << " tl" << endl;
	//cout << fiyatlar << endl;
}