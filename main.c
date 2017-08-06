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

/* Kullanýlan Fonksiyonlar */
void baslik_degistir(char * baslik);
void menu(void);
void listele(void);
void ekle(void);
void sil(void);
void yapilacaklar(void);
void bitenler(void);
void gecikenler(void);
void yapildi_isaretle(void);
void degistir(void);
void arama_yap(void);

// Dosya Isimleri
const char dosya_adi[100] = "yapilacak.txt";

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

/* Kayýt Listeleme */
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

/* Kayýt Ekleme */
void ekle(void) {
	
	char * baslik = "Ekleme Yapiliyor";
	baslik_degistir(baslik);
	 
	FILE * dosya;
	dosya = fopen(dosya_adi, "a");
		
	fflush(stdin);
		
	char * eklenecekPtr = (char * )malloc(100);
	char * tarihPtr = (char * )malloc(10);
	char cevap[5];
	
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
		
		printf("Ne zamana kadar yapilmasi gerek?  "); 
		gets(tarihPtr);
	
		printf("\nYapilacak olan: %s -- %s\n\n", eklenecekPtr, tarihPtr);
			
		fputs(eklenecekPtr, dosya);
		fputs("\n", dosya);
		fputs(tarihPtr, dosya);
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
	
	fclose(dosya);
	
	system("cls");
	menu();

}

/* Kayýt Silme */
void sil(void) {

	char * baslik = "Silme Yap";
	baslik_degistir(baslik);
	
	int silinecek;
	printf("Lutfen silmek istediginiz gorevin numarasini giriniz: ");
	scanf("%d", &silinecek);
	
	printf("Silinecek olan indis: %d\n", silinecek);
	
}

/* Yapýlacaklar Listesi */
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
					
					printf("%s",gorev);
					
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
					
					printf("%s\n", tarih);
					
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
			case 0: menu(); break;
			case 1: sil(); break;
			case 2: yapildi_isaretle(); break;
			case 3: degistir(); break;
			default: menu(); break;
		}	
	    
	}
}

/* Bitenler Listesi */
void bitenler(void){
	
}

/* Gecikenler Listesi */
void gecikenler(void){
	
}

/* Yapýldý Olarak Ýþaretle Listesi */
void yapildi_isaretle(){
	
}

/* Deðiþtir Listesi */
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


