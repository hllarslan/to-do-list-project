/*

	To Do List Project
	Authors:	Hasan Eren Keskin	@erenkeskin
			Burak Can Fazla		@burakcanfazla

	Date: 06.08.2017
	Description: Yapmamýz gereken, yapmayý istediðimiz ancak unuttuðumuz þeyleri
			not alabilebileceðimiz bir konsol uygulamasý.


*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void baslik_degistir(char * baslik);
void menu();
void listele();
void ekle();
void sil();

/* To Do List Projesi */
int main(void) {

	menu();

	_getch();
	return 0;
}


/* Baslik Degistirme */
void baslik_degistir(char * baslik) {

	printf("/*--------------------------");
	printf("  %s  ", baslik);
	printf("--------------------------*/");
	printf("\n\n\n");

}

/* Menu Fonksiyonu */
void menu() {

	int numara;

	char * baslik = "To Do List Projesine Hosgeldiniz";
	baslik_degistir(baslik);

	printf("1 - Listele\n");
	printf("2 - Ekle\n");
	printf("3 - Sil\n");

	printf("Lutfen yapmak istediginiz seceneginin numarasini giriniz\n");
	scanf_s("%d", &numara);

	system("cls");

	switch (numara) {
	case 1: listele(); break;
	case 2: ekle(); break;
	case 3: sil(); break;
	default: main(); break;
	}

}

/* Kayýt Listeleme */
void listele() {

	char * baslik = "Yapilacaklar ve Yapilanlar Listesi";
	baslik_degistir(baslik);

	printf("Listeleme");
}

/* Kayýt Ekleme */
void ekle() {

	char * baslik = "Ekleme Yap";
	baslik_degistir(baslik);

	printf("Ekleme");
}

/* Kayýt Silme */
void sil() {

	char * baslik = "Silme Yap";
	baslik_degistir(baslik);

	printf("Silme");
}