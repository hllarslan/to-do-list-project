/*

	To Do List Project
	Authors:	Hasan Eren Keskin	@erenkeskin
			Burak Can Fazla		@burakcanfazla

	Date: 06.08.2017
	Description: Yapmamiz gereken, yapmayi istedigimiz ancak unuttugumuz seyleri
			not alabilebilecegimiz bir konsol uygulamasi.
			
	Version: 0.1


*/ 

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "functions.h"

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
void menu(void) {

	int numara;

	char * baslik = "To Do List Projesine Hosgeldiniz";
	baslik_degistir(baslik);

	printf("1 - Listele\n");
	printf("2 - Ekle\n");
	printf("3 - Arama Yap\n");
	printf("4 - Cikis Yap\n");

	printf("Lutfen yapmak istediginiz seceneginin numarasini giriniz\n");
	scanf_s("%d", &numara);

	system("cls");

	switch (numara) {
		case 1: listele(); break;
		case 2: ekle(); break;
		case 3: arama_yap(); break;
		case 4: exit(1); break;
		default: menu(); break;
	}

}

/* Kayyt Listeleme */
void listele(void) {

	char * baslik = "Yapilacaklar ve Yapilanlar Listesi";
	baslik_degistir(baslik);

	int numara;
	
	printf("1. Yapilacaklar\n");
	printf("2. Bitenler\n");
	printf("3. Gecikenler\n");
	
	printf("Lutfen yapmak istediginiz seceneginin numarasini giriniz\n");
	scanf_s("%d", &numara);
	
	system("cls");
	
	switch(numara)
	{
		case 0: menu(); break;
		case 1: yapilacaklar(); break;
		case 2: bitenler(); break;
		case 3: gecikenler(); break;
		default: menu(); break;
	}	
}

/* Kayyt Ekleme */
void ekle(void) {
	
	char * baslik = "Ekleme Yapiliyor";
	baslik_degistir(baslik);

	FILE * dosya;
	dosya = fopen(dosya_adi, "a");

	fflush(stdin);

	char * eklenecekPtr = (char * )malloc(100);
	char * tarihPtr = (char * )malloc(10);
	char * cevap = (char * )malloc(5);
	
	while(1) {
		printf("Ne Eklenecek: "); 
		gets(eklenecekPtr);
		
		if((!strcmp(eklenecekPtr, "")) || (!strcmp(cevap, " "))){
			printf("\nLutfen bos birakmayiniz\n");
			while((!strcmp(eklenecekPtr, "")) || (!strcmp(cevap, " "))){
				printf("Ne Eklenecek: "); 
				gets(eklenecekPtr);
			}
		}
		
		printf("Ne zamana kadar yapilmasi gerek? Format: Gun.Ay.Yil "); 
		gets(tarihPtr);
		
		int *p;
		p = parcalama(tarihPtr);
		
		/* Zaman Kontrolü */
		SYSTEMTIME str_t;
		GetSystemTime(&str_t);
		
		int kalanGun, kalanAy, kalanYil;
		
		kalanGun = 	p[0] - str_t.wDay; 
		kalanAy = 	p[1] - str_t.wMonth; 
		kalanYil = 	p[2] - str_t.wYear; 
		
		printf("%d - %d - %d\n", kalanGun, kalanAy, kalanYil);
		
		if( ((p[0] < 32) && (p[0] > 0)) && ((p[1] < 13) && (p[1] > 0)) ) {
			
			if( (kalanYil < 0) ){
				
				while(1){
					
					printf("Yil veriniz hatali\n");
					printf("Lutfen gecerli bir tarih giriniz\n");
					printf("Ne zamana kadar yapilmasi gerek? Format: Gun.Ay.Yil "); 
					gets(tarihPtr);
					
					p = parcalama(tarihPtr);
					kalanYil = 	p[2] - str_t.wYear;
					
					if(kalanYil >= 0){
						break;
					}
				}
				
				p = parcalama(tarihPtr);
				kalanYil 	= 	p[2] - str_t.wYear;
				kalanAy 	= 	p[1] - str_t.wMonth;
				
			} else if( (kalanYil == 0) ){
				
				if( (kalanAy < 0) ) {
					
					while(1) {
						
						printf("Ay veriniz hatali\n");
						printf("Lutfen gecerli bir tarih giriniz\n");
						printf("Ne zamana kadar yapilmasi gerek? Format: Gun.Ay.Yil "); 
						gets(tarihPtr);
						
						p = parcalama(tarihPtr);
						kalanAy = 	p[1] - str_t.wMonth;
						
						if(kalanAy >= 0){
							break;
						}
						
					}
					
					p = parcalama(tarihPtr);
					kalanAy 	= 	p[1] - str_t.wMonth;
					kalanGun 	= 	p[0] - str_t.wDay;
					
				} else if( kalanAy == 0 ){
					
					if( (kalanGun < 0) )  {
						
						while(1) {
							printf("Gun veriniz hatali\n");
							printf("Lutfen gecerli bir tarih giriniz\n");
							printf("Ne zamana kadar yapilmasi gerek? Format: Gun.Ay.Yil "); 
							gets(tarihPtr);
							
							p = parcalama(tarihPtr);
							kalanGun = 	p[0] - str_t.wDay; 
							
							if(kalanGun >= 0){
								break;
							}
						}
						
					}
					
				}
			}
		} else {
			system("cls");
			printf("Hatali tarih girisi yapildi\n");
			printf("Tekrar Deneyiniz\n");
			printf("\n");
			ekle();
		}
		
		printf("\nYapilacak olan: %s -- %d.%d.%d\n\n", eklenecekPtr, p[0], p[1], p[2]);

		fputs(eklenecekPtr, dosya);
		fputs("\n", dosya);
		fprintf(dosya, "%02d.%02d.%02d", p[0], p[1], p[2]);
		fputs("\n", dosya);
		
		printf("Devam Etmek istiyor musunuz? E veya H: ");
		gets(cevap);
		
		if((!strcmp(cevap, "H")) || (!strcmp(cevap, "h")) || (!strcmp(cevap, "Hayir")) || (!strcmp(cevap, "hayir"))){
			break;
		}else {
			printf("\n----------------------------------------------------------\n\n");
		}
		
	}
	
	free(eklenecekPtr);
	free(tarihPtr);
	free(cevap);
	
	fclose(dosya);
	
	system("cls");
	menu();

}

/* Kayyt Silme */
void sil(void) {

	char * baslik = "Silme Yap";
	baslik_degistir(baslik);
	
	int silinecek;
	printf("Lutfen silmek istediginiz gorevin numarasini giriniz: ");
	scanf("%d", &silinecek);
	
	printf("Silinecek olan indis: %d\n", silinecek);
	
}

/* Yapylacaklar Listesi */
void yapilacaklar(void){
	
	int i = 0, c = 0, x = 0, index = 0;
	char satir[50], gorev[50], tarih[10];
	
	FILE *dosya;
	dosya = fopen(dosya_adi, "r");
	
	if(dosya == NULL)
	{
		printf("\n\nDosya bulunamadi.!\n\n");	
		menu();
	}
	else
	{
		printf("   Yapilacaklar ------------------------------------- Bitis tarihi\n\n");
		char karakter = getc ( dosya );

		while ( karakter != EOF )
		{
			if ( karakter != '\n'){
				satir[index++] = karakter;
			} else {
				satir[index] = '\0';
				
				int a = strlen(satir);
				
				if( (c % 2) == 0 ){
					printf("%d. ", x + 1);
					for(i = 0; i <= a; i++){
						*(gorev + i) = *(satir + i);
					}
					
					printf("%s", gorev);
					
					for(i = 0; i <= a; i++){
						*(gorev + i) = "\0";
					}
					
					for(i = 0; i <= 50 - a; i++){
						printf(" ");
					}
					x++;
				} else {
					for(i = 0; i <= a; i++){
						*(tarih + i) = *(satir + i);
					}
					
					printf("%s ----- ", tarih);
					int *p;
					int i, stra;

					p = parcalama(tarih);
					stra = strlen(&p);

						/* Zaman Kontrolü */
					SYSTEMTIME str_t;
					GetSystemTime(&str_t);

					int kalanGun, kalanAy, kalanYil;

					kalanGun = 	p[0] - str_t.wDay; 
					kalanAy = 	p[1] - str_t.wMonth; 
					kalanYil = 	p[2] - str_t.wYear; 

					if (kalanGun > 0){
						kalanGun += (kalanAy * 30) + (kalanYil * 365);
					} else {
						kalanGun = (kalanAy * 30) + (kalanYil * 365);
					} 

					printf("Kalan gun sayisi: %d\n", kalanGun);

					for(i = 0; i <= a; i++){
						*(tarih + i) = "\0";
					}
				}
				c++;
				index = 0;
			}

			karakter = getc ( dosya );
		}

		int numara;

		printf("\n\n-------------------------------------------------\n\n");
		printf("0. Menu\n");
		printf("1. Sil\n");
		printf("2. Yapildi isaretle\n");
		printf("3. Degistir\n");
		
		printf("\nLutfen yapmak istediginiz seceneginin numarasini giriniz\n");
		scanf("%d", &numara);
		printf("\n");
		
		switch(numara)
		{
			case 0: system("cls"); menu(); break;
			case 1: sil(); break;
			case 2: yapildi_isaretle(); break;
			case 3: degistir(); break;
			default: system("cls"); menu(); break;
		}	

	}
}

/* Bitenler Listesi */
void bitenler(void){
	
}

/* Gecikenler Listesi */
void gecikenler(void){
	
}

/* Yapyldy Olarak Y?aretle Listesi */
void yapildi_isaretle(){
	
}

/* De?i?tir Listesi */
void degistir() {
	
}

/* Arama Yap Listesi */
void arama_yap() {
	
	char * baslik = "Arama Yap";
	baslik_degistir(baslik);
	
	char * aramaPtr = (char * )malloc(50);
	
	printf("Gorevler arasinda arama yapmak istediginiz kelimeyi giriniz: ");
	scanf("%s", aramaPtr);
	
	printf("Aranacak kelime: %s", aramaPtr);
	
	free(aramaPtr);
	
}

/* Tarih Parçalama */
int * parcalama(char * parcalanacak){
	
	int i = 0;
	char * parcaliTarih = strtok (parcalanacak, ".");
	char * stringTarih[3];
	static int intTarih[3];

	while (parcaliTarih != NULL){
		stringTarih[i++] = parcaliTarih;
		parcaliTarih = strtok (NULL, ".");
	}

	for (i = 0; i < 3; ++i) {
		intTarih[i] = atoi(stringTarih[i]);
	}
	
	return intTarih;
}
