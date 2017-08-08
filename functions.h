/*

	To Do List Project
	main.h
	Authors:	Hasan Eren Keskin	@erenkeskin
			Burak Can Fazla		@burakcanfazla

	Date: 06.08.2017
	Description: Yapmamyz gereken, yapmayy istedi?imiz ancak unuttu?umuz ?eyleri
			not alabilebilece?imiz bir konsol uygulamasy.


*/ 

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Dosya Isimleri
const char dosya_adi[100] = "yapilacak.txt";

/* Kullanilan Fonksiyonlar */
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
int * parcalama(char * parcalanacak);

#endif
