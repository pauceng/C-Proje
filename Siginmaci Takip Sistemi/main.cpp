/* Sýðýnmacý Takip Sistemi
*  No: 11253804
*  Mehemmed Þxiyev
* */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
//Global tanimlamalar
#define MAX 150
//Fonksiyon Protipler.
int d_control();
void Siginmaci_Kayit();
bool d_sayi_control(char* x);
void Bubble_sort(struct User siginmaci[], int num);
int d_count(char dizi[]);
void menu_Giris();
void menu_Admin();
void menu_Memur();
void Memur_Kayit();
void dosya_S_Ekle(int); //Siginmaci dosya kayit
void dosya_M_Ekle(int); //Memur dosya kayit

//Grup uye tanimlamalari
struct User{
	int  no;
	char ad[15];
	char soyad[15];
	char dogum_tarihi[15];
	char dogum_yeri[15];
	char cinsiyet[5];
	char uyruk[10];
	char meslek[10];
	char egitim_durumu[10];
	char telefon[10];
	char geldigi_sehir[10];
	char gelis_tarihi[11];
	char eposta[20];
	char tc[11];
	char kullanici_adi[10];
	char sifre[15];
	char yetki_turu[10];
	char adres[20];
}siginmaci[150], Memur[50];


//Main fonksiyon
int main() {
	printf("==================================================================\n");
	printf("\t\t\tSiginmaci Takip SisTemi\n");
	printf("==================================================================\n");
	menu_Giris();
	return 0;
}
//Giris menusu sifre kontrolu
void menu_Giris() {
	char secim[10], k_ad[50], k_sifre[50];
	int i = 0, indis;
	indis = d_control();
	if (indis < 0) {
		printf("\tListe Dolu!\n");
	}
	printf("\tGiris Yapiniz (1/2)\n\t'\n");
	printf("\t'--> Admin : 1 \n");
	printf("\t'--> Memur : 2 \n");

	do {
		printf("Seciminiz: ");
		gets_s(secim);
		if (secim[i] == '1' ) {
			printf("\nAdminseniz Lutfen Giris Yapiniz...!\n");
			do {
			
				printf("\tKullanici adi: ");
				gets_s(k_ad);
				printf("\tSifre Giriniz: ");
				gets_s(k_sifre); 
				if (strcmp(k_ad, "root") || strcmp(k_sifre, "toor")) {
					printf("\n\nKullanici adi ve ya Sifre Yalnis...!\n");
				}
			} while(strcmp(k_ad, "root") || strcmp(k_sifre, "toor"));	
			menu_Admin();
		}
		else if	(!(strcmp(secim, "q")) || !(strcmp(secim, "Q"))){
			exit(EXIT_SUCCESS);
		}
		else if (!d_sayi_control(secim) || secim[i] != '2' || secim[i] != '1') {
			printf("\tHatali Giris...!\nCikis icin q giriniz...!\n");
		}
		if (secim[i] == '2') {
			printf("\nSiginmaci Memuru iseniz Giris yapiniz...!\n");
			do {
				printf("\tKullanici adi: ");
				scanf("%s", Memur[indis].kullanici_adi);
				printf("\tSifre Giriniz: ");
				gets(Memur[indis].sifre);
				if (strcmp(Memur[indis].kullanici_adi, "root") || strcmp(Memur[indis].sifre, "toor")) { //Kayýtlý kullanýcýlar ile karþýlaþtýrýlacak týr
					printf("\n\nKullanici adi ve ya Sifre Yalnis...!\n");
				}
			} while (strcmp(Memur[indis].kullanici_adi, "root") || strcmp(Memur[indis].sifre, "toor"));
			menu_Memur();
		} 
	} while (!d_sayi_control(secim) || secim[i] != '2' || secim[i] != '1');

}
//Siginmaci Kayit
void Siginmaci_Kayit() {
int i=0; int indis=0;
	char secim[10];
	
		
	//	indis = d_control();
	//	if (indis < 0) {
	//		printf("\tListe Dolu!\n");
	//		return;
	//} else {
	do {	
		printf("Siginmaci Kayit Sistemi...\n====================================================>\n");
		printf("Siginmaci Ad              : ");
		scanf("%15s",siginmaci[indis].ad);
		printf("Siginmaci Soyad           : ");
		scanf("%15s",siginmaci[indis].soyad);
		printf("\n%d\n",indis);
		/*
		printf("Dogum tarihi.(gun.ay.yil) : ");
		do {
			gets(siginmaci[indis].dogum_tarihi);
		} while (!d_sayi_control(siginmaci[indis].dogum_tarihi) && !strpbrk(siginmaci[indis].dogum_tarihi, "."));
		
		printf("Siginmaci Dogum Yeri       : ");
		gets( siginmaci[indis].dogum_yeri);
		printf("Siginmaci Cinsiyyet        : ");
		gets(siginmaci[indis].cinsiyet);
		printf("Siginmaci Uyruk            : ");
		gets(siginmaci[indis].uyruk);
		printf("Siginmaci Meslegini        : ");
		scanf("%10s",siginmaci[indis].meslek);
		printf("Siginmaci Egitim Durumu    : ");
		scanf("%10s",siginmaci[indis].egitim_durumu);
		printf("Siginmaci Yerlesdigi Yer   : ");
		gets(siginmaci[indis].adres);
		printf("Siginmaci Geldigi Sehir    : ");
		scanf("%20s",+
			siginmaci[indis].geldigi_sehir);
		
		do { //tarih formatinda oldugunu kontrol ediyoruz
			printf("S.Gelis Tarihi (gun.ay.yil): ");
			gets(siginmaci[indis].gelis_tarihi);
		} while (!d_sayi_control(siginmaci[indis].gelis_tarihi) && !strpbrk(siginmaci[indis].gelis_tarihi, "."));

		do {
			printf("Siginmaci email adress    : ");
			gets(siginmaci[indis].eposta);
		} while (!strpbrk(siginmaci[indis].eposta, "@"));
		do {
			printf("Siginmaci Telefon(10 Hane!): ");
			gets(siginmaci[indis].telefon);
			if (! (d_sayi_control(siginmaci[indis].telefon) && sizeof(siginmaci[indis].telefon) == d_count(siginmaci[indis].telefon))) {
				printf("\t\tHatali Giris...!\n\tLutfen 10 Haneli Rakam Girdiniz...!\n");
			}
		} while (!d_sayi_control(siginmaci[indis].telefon) || d_count(siginmaci[indis].telefon) != sizeof(siginmaci[indis].telefon));
		*/
		do {
			printf("\tBaska Kayit Yapilacak mi? (E/h): ");
			//scanf("%s", secim);
			getchar();
			secim[i] = (char) getchar();
			/*if (secim[i] != 'E' && secim[i] != 'e') {
				printf("\tHatali Giris...!\nSeciminiz: ");
			}*/
			if (secim[i] ==  'h' || secim[i] == 'H') {
				dosya_S_Ekle(indis);
				exit(false);
			}
		} while (secim[i] != 'E' && secim[i] != 'e');
		indis++;
	} while (secim[i] == 'E' || secim[i] == 'e' || secim[i] != 'h' || secim[i] != 'H');

}
//
void Memur_Kayit() {
	int  indis,i=0;
	char secim[10];

	do {
		
		indis = d_control();
		if (indis < 0) {
			printf("\tListe Dolu!\n");
			return;
		}
		printf("\t...Kullanici Kayit Sistemi...\n=============================================>\n");
		printf("Kullanici Ad              : ");
		scanf("%15s",Memur[indis].ad);
		printf("Kullanici Soyad           : ");
		scanf("%15s", Memur[indis].soyad);
		printf("Kullanici Adress          : ");
		scanf("%15s", Memur[indis].adres);
		do {
			printf("Kullanici TC (11 Hane): ");
			scanf("%13s", Memur[indis].tc);
			if (d_count(Memur[indis].tc) != sizeof(Memur[indis].tc) || ! d_sayi_control(Memur[indis].tc)) {
				printf("\t\tHatali Giris...!\n\tLutfen 11 Haneli Rakam Girdiniz...!\n");
			}
		} while (!d_sayi_control(Memur[indis].tc) || d_count(Memur[indis].tc) != sizeof(Memur[indis].tc));
		printf("Kullanici kullanici adi   : ");
		scanf("%10s",Memur[indis].kullanici_adi);
		printf("Kullanici sifre          : ");
		scanf("%10s",Memur[indis].sifre);
		printf("Kullanici Yetki Turu     : ");
		scanf("%10s",Memur[indis].yetki_turu);
		do {
			printf("Kullanici Telefon(10 Hane!): ");
			//getchar();
			//siginmaci[indis].telefon[i] = getchar();
			scanf("%12s",Memur[indis].telefon);
			if (d_count(Memur[indis].telefon) != sizeof(Memur[indis].telefon) || !d_sayi_control(Memur[indis].telefon)) {
				printf("\t\tHatali Giris...!\n\tLutfen 10 Haneli Rakam Girdiniz...!\n");
			}
		} while (!d_sayi_control(Memur[indis].telefon) || d_count(Memur[indis].telefon) != sizeof(Memur[indis].telefon));
		do { //tarih formatýný doðruluðunu kontrol ediyoruz
			printf("S.Gelis Tarihi(gun.ay.yil): ");
			scanf("%10s",Memur[indis].gelis_tarihi);
		} while (Memur[indis].gelis_tarihi[2] != '.' && Memur[indis].gelis_tarihi[5] !='.' && !d_sayi_control(Memur[indis].gelis_tarihi));
		do {
			printf("Kullanici email adress    : ");
			scanf("%15s",Memur[indis].eposta);
			//getchar();
			//Memur[indis].eposta = getchar();
		} while (!strpbrk(Memur[indis].eposta, "@")); //@ karakterinin dizi icinde kontrol
		
		do {
			printf("\tBaska Kayit Yapilacak mi? (E/h): ");
			//scanf("%s", secim);
			getchar();
			secim[i] = (char) getchar();
			/*
			if (secim[i] != 'E' && secim[i] != 'e') {
				printf("\tHatali Giris...!\nSeciminiz: ");
			}*/
		
			if (secim[i] ==  'h' || secim[i] == 'H')
				exit(false);
		} while (secim[i] != 'E' && secim[i] != 'e');

	} while (secim[i] == 'E' || secim[i] == 'e' || secim[i] != 'h' || secim[i] != 'H');
}
//
void Bubble_sort(struct User siginmaci[], int num) {
	int i, j;
	struct User temp;
	for (i = 1; i < num; i++) {
		for (j = 0; j < num - 1; j++) {
			if (siginmaci[j].gelis_tarihi > siginmaci[j + 1].gelis_tarihi) {
				temp = siginmaci[j];
				siginmaci[j]= siginmaci[j + 1];
				siginmaci[j + 1] = temp;
			}
		}
	}
}
//Dizi kontrol

int d_control() {
	int bos;
	for (bos = 0; siginmaci[bos].ad[0] && Memur[bos].ad[0] && bos < MAX; bos++);
	if (bos < MAX) {
		return bos;
	}
	else {
		return - 1;
	}
}
//Dizi eleman sayimi
int d_count(char dizi[]) {
	int count = 0,i=0;
	while (dizi[i] != '\0') {
		count += 1;
		i ++;
	}
	return count;
}
//Girilenin sayi olup olmadýðýný kontrol eder.
bool d_sayi_control(char* x) {
	bool Checked = true;
	int i = 0;
	do
	{   //girilen sayi mi?
		if (isdigit(x[i])) {
			i++;
			Checked = true;
		}
		else {
			i++;
			Checked = false;
			break;
		}
	} while (x[i] != '\0');
	return Checked;
}
//
void menu_Admin( ){
	char secim[15]; int i = 0;
	system("cls");
	printf("==================================================================\n");
	printf("\t\t\t\tADMIN\n");
	printf("==================================================================\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("|    Kullanici Islemleri       |   Siginmaci Islemleri         |\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\t'                               ' \n");
	printf("\t'-->Kullanici Islemleri (k)     '--> Siginmaci Islemleri (s)\n");
	printf("\t\t'-->  1. Ekle.                '-->  1. Ekle.\n");
	printf("\t\t'-->  2. Silme.               '-->  2. Silme.\n");
	printf("\t\t'-->  3. Guncelle.            '-->  3. Guncelleme.\n");
	printf("\t\t'-->  4. Listele.             '-->  4. Listeleme.\n");
	printf("\t\t'-->  5. Arama.               '-->  5. Arama.\n\n");
	printf("\n---------------------------------------------------------------\n");
	printf("Kullanici I. icin < k >, Siginmaci I. icin <s>, Cikis icin <q>\n");
	printf("\n---------------------------------------------------------------\n");
	do {
		printf("Seciminiz: ");
		gets(secim);
		if (secim[i] == 'k') {
			do {
				printf("Kullanici Islemleri icin Seciminiz: ");
				gets(secim);
				switch (secim[i]) {
				case '1':
					system("cls");
					Memur_Kayit();
					break;
				default:
					break;
				}
			} while (secim[i] != 'k');
		}//if 1
		//Siginmaci islemleri menu secimi
		if (secim[i] == 's') {
		do {
			printf("Siginmaci Islemleri icin Seciminiz: ");
			gets_s(secim);
			switch (secim[i]) {
			case '1':
				system("cls");
				Siginmaci_Kayit();
				break;
			default:
				printf("Hatali secim\n");
				break;
			}//switch
		} while (secim[i] != 'k');
	} // if 2
		
	} while (!d_sayi_control(secim) ||secim[i] != '1' || secim[i] != '2' || secim[i] != '3' || secim[i] != '4' || secim[i] != '5' );
}
//
void menu_Memur() {
	char secim[15]; int i = 0;
	system("clear");
	printf("==================================================================\n");
	printf("\t\t\tSiginmaci MEMUR\n");
	printf("==================================================================\n");
	printf("- - - - - - - - - - - - - - - - - -\n");
	printf("|    Siginmaci Islemleri          |\n");
	printf("- - - - - - - - - - - - - - - - - -\n");
	printf("\t'  \n");
	printf("\t'-->  1. Yeni Kayit.\n");
	printf("\t'-->  2. Silme.\n");
	printf("\t'-->  3. Guncelle.\n");
	printf("\t'-->  4. Listele.\n");
	printf("\t'-->  5. Arama.\n");
	printf("\t'-->  6. Bilgilerimi goster, Sifre degis.\n\n");

	do {
		printf("Seciminiz: ");
		scanf_s("%s", secim);
		switch (secim[i]) {
			case '1':
				system("cls");
				Siginmaci_Kayit();
		        break;
			case '2':
				system("cls");

		        break;
			case '3':
				system("cls");

		        break;
			case '4':
				system("cls");

		        break;
			case '5':
				system("cls");

		        break;
			case '6':
				system("cls");

			default:
				printf("\tHatali Secim...!\n");
		}
	} while (!d_sayi_control(secim) ||secim[i] != '1' || secim[i] != '2' || secim[i] != '3' || secim[i] != '4' || secim[i] != '5' || secim[i] != '6');

}
//
void dosya_S_Ekle(int Sayi) {
	FILE *di;
	int i =0, count = 1; siginmaci[i].no = 1;
	if((di = fopen("Siginmaci.txt", "a")) == NULL){
		printf("Dosya acilamadi...!!!!!!\n");	
		return;
	}
		puts("Kayit zamani...!\n");
		for (i = 0; i < Sayi; i++){
			if (siginmaci[i].ad[0])
				fprintf(di, "%3.d. %.10s %10s \n", count, siginmaci[i].ad, siginmaci[i].soyad);
				count++;
				siginmaci[i].no = count;
				//printf(" Count: %d - NO: %d\n",count,siginmaci[i].no);
		}
		
	fclose(di);
}
//
void dosya_S_Ekle(int Sayi) {
	FILE *di;
	int i =0, count = 1; siginmaci[i].no = 1;
	if((di = fopen("Kullanici.txt", "a")) == NULL){
		printf("Dosya acilamadi...!!!!!!\n");	
		return;
	}
		puts("Kayit zamani...!\n");
		for (i = 0; i < Sayi; i++){
			if (Memur[i].ad[0])
				fprintf(di, "%3.d. %.10s %10s \n", count, Memur[i].ad, Memur[i].soyad);
				count++;
				Memur[i].no = count;
				//printf(" Count: %d - NO: %d\n",count,Memur[i].no);
		}
	fclose(di);
}