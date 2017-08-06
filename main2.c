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
#include <time.h>

struct tarih
{
	int gun;
	int ay;
	int yil;
	
}bitis[100];


void baslik_degistir(char * baslik);
void menu();
void listele();
void ekle();
void sil();
void yapilacaklar();
void bitenler();
void gecikenler();

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

	switch (numara)	
	{
		case 1: listele(); break;
		case 2: ekle(); break;
		case 3: sil(); break;
		default: main(); break;	
	}
	

}

/* Kayýt Listeleme */
void listele() 
{
	int numara;
	
	char * baslik = "Yapilacaklar ve Yapilanlar Listesi";
	baslik_degistir(baslik);

	printf("1.Yapilacaklar\n");
	printf("2.Bitenler\n");
	printf("3.Gecikenler\n");
	printf("Lutfen yapmak istediginiz seceneginin numarasini giriniz\n");
	scanf_s("%d", &numara);
	system("cls");
	switch(numara)
	{
		case 1: yapilacaklar(); break;
		case 2: bitenler(); break;
		case 3: gecikenler(); break;
		default: menu(); break;
	}	
}

/* Kayýt Ekleme */
void ekle() 
{
	char * baslik = "Ekleme Yap";
	baslik_degistir(baslik);

	printf("Ekleme");
}

/* Kayýt Silme */
void sil() 
{
	char * baslik = "Silme Yap";
	baslik_degistir(baslik);

	printf("Silme");
}
void yapilacaklar() 
{
	int i;
	char line[50],gorev[50],tarih[10];
	printf("Yapilacak is ----- Bitis tarihi\n");
	FILE *dosya;
	dosya = fopen("deneme.txt","r");
	if(dosya==NULL)
	{
	printf("Dosya bulunamadi.!");	
	}
	else
	{
	
	int c=0;
	char ch = getc ( dosya );
    int index = 0;
    
    while ( ch != EOF )
	 {
        if ( ch != '\n')
		{
            line[index++] = ch;
        }
		else
		 {
            line[index] = '\0';
			
			int a = strlen(line);
			
			if( (c % 2) == 0 )
			{
				for(i = 0; i <= a; i++)
				{
					*(gorev + i) = *(line + i);
				}
				printf("%s   ",gorev);
				
				for(i = 0; i <= a; i++)
				{
					*(gorev + i) = "\0";
				}
            }
            else
            {
        		for(i = 0; i <= a; i++)
				{
					*(tarih + i) = *(line + i);
				}
				printf("%s  \n", tarih);
				
				for(i = 0; i <= a; i++)
				{
					*(tarih + i) = "\0";
				}
			}
			c++;
			index = 0;
        }
        ch = getc ( dosya );
    }

	
	}
	
}
void bitenler()
{
	
}
void gecikenler()
{
	
}
