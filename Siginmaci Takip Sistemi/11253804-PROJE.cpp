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
//Fonksiyon Protipler.
int d_control();
void Siginmaci_Kayit();
bool d_sayi_control(char* x);
bool d_harf_control(char* x);
void Bubble_sort(struct User siginmaci[], int num);
int d_count(char dizi[]);
void menu_Giris();
void menu_Admin();
void menu_Memur();
void Memur_Kayit();
void dosya_S_Ekle();		//Siginmaci dosya kayit
void dosya_M_Ekle();		//Memur dosya kayit
void dosya_S_OKU();			//Dosyada Siginmacilari kayýtlarýn diziye okur
void dosya_M_OKU();			//Dosyada Kullanýcý kayýtlarýn diziye okur
void dosya_S_ARAMA();
void dosya_M_ARAMA();
void menu_S_Arama();
void menu_M_Arama();
void dosya_M_OKU();	
void dosya_S_Silme();
void dosya_M_Silme();
int varmi_S(char isim[]);
int varmi_M(char isim[]);
void Listele_M();
void Listele_S();

//Global tanimlamalar
#define MAX BUFSIZ
//Siginmaci Grup tanýmlamasý
typedef struct S{
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
}S_KAYIT;
//Kullanici Grup tanýmlamasý
typedef struct M {
	int  no;
	char ad[15];
	char soyad[15];
	char telefon[10];
	char eposta[20];
	char tc[11];
	char kullanici_adi[10];
	char sifre[15];
	char yetki_turu[10];
	char adres[20];
}M_KAYIT;
//Grup dizi tanimlamalari
S_KAYIT siginmaci[MAX] = {0},temp_S;
M_KAYIT Memur[MAX],temp_M;
//Main fonksiyon
int main() {
	printf("===============================================================================\n");
	printf("\t\t\t\tSiginmaci Takip SisTemi\n");
	printf("===============================================================================\n");
	menu_Giris();
	return 0;
}
//Giris menusu sifre kontrolu
void menu_Giris() {
	char secim[10], k_ad[50], k_sifre[50];
	int i = 0,indis =0;
	printf("\tGiris Yapiniz (1/2)\n\t'\n");
	printf("\t'--> Admin : 1 \n");
	printf("\t'--> Memur : 2 \n");
	printf("\t'--> Cikis : q \n");
	do {
		printf("Seciminiz: ");
		secim[i] = getch();
		if (secim[i] == '1' ) {
			printf("\nAdminseniz Lutfen Giris Yapiniz...!\n");
			while(strcmp(k_ad, "root") || strcmp(k_sifre, "toor")) {
			
				printf("\tKullanici adi: ");
				gets(k_ad);
				printf("\tSifre Giriniz: ");
				gets(k_sifre); 
				if (strcmp(k_ad, "root") || strcmp(k_sifre, "toor")) {
					printf("\n\nKullanici adi ve ya Sifre Yalnis...!\n");
				}
			}	
			menu_Admin();
		}
		if (secim[i] == '2') {
				printf("\nSiginmaci Memuru iseniz Giris yapiniz...!\n");
			do {	
				printf("\tKullanici adi: ");
				gets(k_ad);
				printf("\tSifre Giriniz: ");
				gets(k_sifre); 
				if (strcmp(k_ad, "root") || strcmp(k_sifre, "toor")) {
					printf("\n\nKullanici adi ve ya Sifre Yalnis...!\n");
				}
			} while(strcmp(k_ad, "root") || strcmp(k_sifre, "toor"));
			menu_Memur();
		}
		if	(secim[i] == 'Q' || secim[i] == 'q'){
				exit(EXIT_SUCCESS);
		}
		//Hatali secim mesaji
		if (!d_sayi_control(secim) || secim[i] != '2' || secim[i] != '1') {
			printf("\tHatali Giris...!\nCikis icin q giriniz...!\n");
		}
	} while (!d_sayi_control(secim) || secim[i] != '2' || secim[i] != '1');
}
//Siginmaci Kayit fonksiyonu
void Siginmaci_Kayit() {
	int i=0; int indis;
	char secim[15];
	indis = d_control();
	if (indis < 0) {
		printf("\tListe Dolu!\n");
		return; 
	} 
	printf("\t\tSiginmaci Kayit Sistemi...\n");
	do {
		printf("\n==================={ Yeni Siginmaci icin bilgileri giriniz }===================\n\n");
		do {
			printf("Siginmaci Ad              : ");
			scanf("%15s", siginmaci[indis].ad);
		} while (!d_harf_control(siginmaci[indis].ad));
		do {
			printf("Siginmaci Soyad           : ");
			scanf("%15s",siginmaci[indis].soyad);
		} while (!d_harf_control(siginmaci[indis].soyad));
		do {
			printf("Dogum tarihi.(gun.ay.yil) : ");

			scanf("%15s",siginmaci[indis].dogum_tarihi);
		} while (!d_sayi_control(siginmaci[indis].dogum_tarihi) && !strpbrk(siginmaci[indis].dogum_tarihi, "."));
		do {
			printf("Siginmaci Dogum Yeri       : ");
			scanf("%15s",siginmaci[indis].dogum_yeri);
		} while (!d_harf_control(siginmaci[indis].dogum_yeri));
		do
		{
			printf("Siginmaci Cinsiyyet        : ");
			scanf("%15s",siginmaci[indis].cinsiyet);
		} while (!d_harf_control(siginmaci[indis].cinsiyet));
		do
		{
			printf("Siginmaci Uyruk            : ");
			scanf("%15s",siginmaci[indis].uyruk);
		} while (!d_harf_control(siginmaci[indis].uyruk));
		do
		{
			printf("Siginmaci Meslegini        : ");
			scanf("%15s",siginmaci[indis].meslek);
		} while (!d_harf_control(siginmaci[indis].meslek));
		do
		{
			printf("Siginmaci Egitim Durumu    : ");
			scanf("%15s",siginmaci[indis].egitim_durumu);
		} while (!d_harf_control(siginmaci[indis].egitim_durumu));
		do
		{
			printf("Siginmaci Geldigi Sehir    : ");
			scanf("%15s",siginmaci[indis].geldigi_sehir);
		} while (!d_harf_control(siginmaci[indis].geldigi_sehir));
		do { //tarih formatinda oldugunu kontrol ediyoruz
			printf("S.Gelis Tarihi (gun.ay.yil): ");
			scanf("%15s",siginmaci[indis].gelis_tarihi);
		} while (!d_sayi_control(siginmaci[indis].gelis_tarihi) && !strpbrk(siginmaci[indis].gelis_tarihi, "."));
		do {
			printf("Siginmaci Telefon(10 Hane!): ");
			scanf("%15s",siginmaci[indis].telefon);
		} while (!d_sayi_control(siginmaci[indis].telefon) || d_count(siginmaci[indis].telefon) != sizeof(siginmaci[indis].telefon));
		while (!strpbrk(siginmaci[indis].eposta, "@") || !strpbrk(siginmaci[indis].eposta, ".")) {
			printf("Siginmaci email adress    : ");
			gets(siginmaci[indis].eposta);
		} 
		printf("\n============\nToplam : %d\n============\n",indis+1);
		do {
			printf("\n> Diske Kayd etmek icin -->{ k }\n> Baska Kayit Yapilacak mi--> { e }\n> Ana Menu--> { a }\n");
			secim[i] = getch();
			if (secim[i] != 'E' || secim[i] != 'e') {
				printf("\tHatali Secim...!\n");
			}
			if (secim[i] == 'k' ||secim[i] == 'K') {
				system("cls");
				dosya_S_Ekle();
			}
			if (secim[i] == 'a' || secim[i] == 'A')	{
				system("cls");
				printf("\nYetki kontrol Nedeni ile once Giris Yapiniz...!\n");
				menu_Giris();
			}
		} while (secim[i] != 'E' && secim[i] != 'e');
		indis++;
		system("cls");
	} while (secim[i] == 'E' || secim[i] == 'e');
}
//Kullanici kayit fonksiyonu
void Memur_Kayit() {
	int  indis,i=0;
	char secim[10];
	indis = d_control();
	if (indis < 0) {
		printf("\tListe Dolu!\n");
		return; 
	} else {
		printf("\t...Kullanici Kayit Sistemi...\n");
		do {
			printf("\n==================={ Yeni Kullanici icin bilgileri giriniz }===================\n\n");
			do
			{
				printf("Kullanici Ad              : ");
				scanf("%s",Memur[indis].ad);
			} while (!d_harf_control(Memur[indis].ad));
			do
			{
				printf("Kullanici Soyad           : ");
				scanf("%s", Memur[indis].soyad);
			} while (!d_harf_control(Memur[indis].soyad));
			do
			{
				printf("Kullanici Adress          : ");
				scanf("%s",Memur[indis].adres);
			} while (!d_harf_control(Memur[indis].adres));
			do {
				printf("Kullanici TC (11 Hane)    : ");
				scanf("%s", Memur[indis].tc);
				if (d_count(Memur[indis].tc) != sizeof(Memur[indis].tc) || ! d_sayi_control(Memur[indis].tc)) {
					printf("\t\tHatali Giris...!\n\tLutfen 11 Haneli Rakam Girdiniz...!\n");
				}
			} while (!d_sayi_control(Memur[indis].tc) || d_count(Memur[indis].tc) != sizeof(Memur[indis].tc));
			printf("Kullanici kullanici adi   : ");
			scanf("%s",Memur[indis].kullanici_adi);
			printf("Kullanici sifre           : ");
			scanf("%s",Memur[indis].sifre);
			do 
			{
				printf("Kullanici Yetki Turu      : ");
				scanf("%10s",Memur[indis].yetki_turu);
				if ( (strcmp(Memur[indis].yetki_turu,"admin")) && (strcmp(Memur[indis].yetki_turu,"memur"))) {
					printf("\nHatali ...! { admin ve ya memur }\n\n");
				}
			} while((strcmp(Memur[indis].yetki_turu,"admin")) && (strcmp(Memur[indis].yetki_turu,"memur")));
			do 
			{
				printf("Kullanici Telefon(10 Hane): ");
				scanf("%12s",Memur[indis].telefon);
				if (d_count(Memur[indis].telefon) != sizeof(Memur[indis].telefon) || !d_sayi_control(Memur[indis].telefon)) {
					printf("\t\tHatali Giris...!\n\tLutfen 10 Haneli Rakam Girdiniz...!\n");
				}
			} while (!d_sayi_control(Memur[indis].telefon) || d_count(Memur[indis].telefon) != sizeof(Memur[indis].telefon));
			do {
				printf("Kullanici email adress    : ");
				scanf("%15s",Memur[indis].eposta);
				if (strpbrk(Memur[indis].eposta, "\n")) {
					break;
				}
			} while (!strpbrk(Memur[indis].eposta, "@") || !strpbrk(Memur[indis].eposta, ".")); //@ karakterinin dizi icinde kontrol
			printf("\n===========\nToplam: %d\n===========\n",indis+1);
			do {
				printf("\n> Diske Kayd etmek icin -->{ k }\n> Baska Kayit Yapilacak mi--> { e }\n> Ana Menu--> { a }\n");
				secim[i] = getch();
				if (secim[i] != 'E' || secim[i] != 'e') {
					printf("\tHatali Secim...!\n ");
				}
				if (secim[i] == 'a' || secim[i] == 'a')	{
					system("cls");
					menu_Admin();
				}
				if (secim[i] == 'k' ||secim[i] == 'K') {
					system("cls");
					dosya_M_Ekle();
				}
			} while (secim[i] != 'E' && secim[i] != 'e');
			system("cls");
		} while (secim[i] == 'E' || secim[i] == 'e');
	}
}
//siralama

//Siralama 
//void Bubble_sort(struct User siginmaci[], int num) {
//	int i, j;
//	struct User temp;
//	for (i = 1; i < num; i++) {
//		for (j = 0; j < num - 1; j++) {
//			if (siginmaci[j].gelis_tarihi > siginmaci[j + 1].gelis_tarihi) {
//				temp = siginmaci[j];
//				siginmaci[j]= siginmaci[j + 1];
//				siginmaci[j + 1] = temp;
//			}
//		}
//	}
//}
//Dizi kontrol 

//Dizide bos yer kontrolu
int d_control() {
	int bos;
	for (bos = 0; (siginmaci[bos].no ||Memur[bos].no) && bos < MAX; bos++);
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
		i++;
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
//Girilenin Harf olup olmadýðýný kontrol eder.
bool d_harf_control(char* x) {
	bool Checked = true;
	int i = 0;
	for (i = 0; i < sizeof(x); i++) {
		do {	  //girilen harf mi?
			if (isalpha(x[i])) {
				i++;
				Checked = true;
			}
			else {
				i++;
				Checked = false;
				break;
			}
		} while (x[i] != '\0');
	}
	return Checked;
}
//
void menu_Admin( ){
	char secim[15]; int i = 0;
	system("cls");
	printf("===============================================================================\n");
	printf("\t\t\t\t\tADMIN\n");
	printf("===============================================================================\n");
	printf("----------------------------------------------------------------\n");
	printf("|    Kullanici Islemleri       |   Siginmaci Islemleri         |");
	printf("\n----------------------------------------------------------------\n");
	printf("  '                                  ' \n");
	printf("  '-->Kullanici Islemleri (k)        '--> Siginmaci Islemleri (s)\n");
	printf("\t'-->  1. Ekle.                \t\t'-->  1. Ekle.\n");
	printf("\t'-->  2. Silme.               \t\t'-->  2. Silme.\n");
	printf("\t'-->  3. Guncelle.            \t\t'-->  3. Guncelleme.\n");
	printf("\t'-->  4. Listele.             \t\t'-->  4. Listeleme.\n");
	printf("\t'-->  5. Arama.               \t\t'-->  5. Arama.\n\n");
	printf("\n-------------------------------------------------------------------------------\n");
	printf(" Kullanici I. icin { k } | Siginmaci I. icin { s } | Cikis { q } | Iptal { x } ");
	printf("\n-------------------------------------------------------------------------------\n");
	do {
	//	printf("Seciminiz: ");
		secim [i] = getch();
		if (secim[i] == 'q' || secim[i] == 'Q')	{
			exit(EXIT_SUCCESS);
		}
		if (secim[i] == 'k' || secim[i] == 'K') {
			do {
				printf("\nKullanici Islemleri icin Seciminiz: ");
				gets(secim);
				if (secim[i] == 'x' || secim[i] == 'X')	{
					menu_Admin();
				}
				if (secim[i] == 'q' || secim[i] == 'Q')	{
					exit(EXIT_SUCCESS);
				}
				switch (secim[i]) {
				case '1':
					system("cls");
					Memur_Kayit();
					break;
				case '2':
					system("cls");
					dosya_M_Silme();
					break;
				case '3':
					system("cls");
				
					break;
				case '4':
					system("cls");
					Listele_M();
					break;
				case '5':
					system("cls");
					dosya_S_ARAMA();
					break;
				default:
					break;
				}
			} while (secim[i] != 'k' || secim[i] != 'K');
		}//if 1
		//Siginmaci islemleri menu secimi
		if (secim[i] == 's'||secim[i] == 'S') {
			do {
				printf("\nSiginmaci Islemleri icin Seciminiz: ");
				gets_s(secim);
				if (secim[i] == 'x' || secim[i] == 'X')	{
						menu_Admin();
				}
				if (secim[i] == 'q' || secim[i] == 'Q')	{
					exit(EXIT_SUCCESS);
				}
				switch (secim[i]) {
				case '1':
					system("cls");
					Siginmaci_Kayit();
					break;
				case '2':
					system("cls");
					dosya_S_Silme();
					break;
				case '3':
					system("cls");
				
					break;
				case '4':
					system("cls");
					Listele_S();
					break;
				case '5':
					system("cls");
					dosya_S_ARAMA();
					break;
				default:
					printf("Hatali secim\n");
					break;
				}//switch
			} while (secim[i] != 's' || secim[i] != 'S');
		} // if 2
		
	} while (!d_sayi_control(secim) ||secim[i] != '1' || secim[i] != '2' || secim[i] != '3' || secim[i] != '4' || secim[i] != '5' );
}
//
void menu_Memur() {
	char secim[15]; int i = 0;
	system("cls");
	printf("===============================================================================\n");
	printf("\t\t\t\t...Siginmaci MEMUR...\n");
	printf("===============================================================================\n");
	printf("-----------------------------------\n");
	printf("|    Siginmaci Islemleri          |\n");
	printf("-----------------------------------\n");
	printf("   '  \n");
	printf("   '-->  1. Yeni Kayit.\n");
	printf("   '-->  2. Silme.\n");
	printf("   '-->  3. Guncelle.\n");
	printf("   '-->  4. Listele.\n");
	printf("   '-->  5. Arama.\n");
	printf("   '-->  6. Bilgilerimi goster, Sifre degis.\n");
	printf("   '-->  7. Cikis.\n");

	do {
		printf("Seciminiz: ");
		gets(secim);
		switch (secim[i]) {
			case '1':
				system("cls");
				Siginmaci_Kayit();
		        break;
			case '2':
				system("cls");
				dosya_S_Silme();
		        break;
			case '3':
				system("cls");

		        break;
			case '4':
				system("cls");

		        break;
			case '5':
				system("cls");
				dosya_S_ARAMA();
		        break;
			case '6':
				system("cls");
				break;
			case '7':
				exit(EXIT_SUCCESS);
			default:
				printf("\tHatali Secim...!\n");
		}
	} while (!d_sayi_control(secim) ||secim[i] != '1' || secim[i] != '2' || secim[i] != '3' || secim[i] != '4' || secim[i] != '5' || secim[i] != '6'|| secim[i] != '7');

}
//
void dosya_S_Ekle() {
	FILE *di;
	int i,count=1;
	if((di = fopen("Siginmaci.txt", "a")) == NULL){
		printf("Dosya acilamadi...!!!!!!\n");	
		return;
	} else {
		for (i = 0; i < MAX; i++){
			if (siginmaci[i].ad[0]) 
				fwrite(&siginmaci[i], sizeof(S_KAYIT), i+1, di);
				fprintf(di,"\n");
			//	fprintf(di,"\n");
				//fprintf(di, "%d|%15s |%15s| %15s|%15s|%15s|%15s|%15s|%15s|%15s|%15s|%15s|%15s|%15s|\n", 
				//	siginmaci[i].no, siginmaci[i].ad, siginmaci[i].soyad, siginmaci[i].dogum_tarihi,siginmaci[i].dogum_yeri,
				//	siginmaci[i].cinsiyet,siginmaci[i].uyruk,siginmaci[i].meslek,siginmaci[i].egitim_durumu,siginmaci[i].adres,
				//	siginmaci[i].geldigi_sehir,siginmaci[i].gelis_tarihi,siginmaci[i].eposta,siginmaci[i].telefon);
		} 
		fclose(di);
		printf("\n\tBasarili Kayit, Tesekkurler...!\n");
	}
}
//Memur yeni kayit islemi
void dosya_M_Ekle() {
	FILE *di;
	int i =0, count; Memur[i].no = 1;
	if((di = fopen("Kullanici.txt", "a")) == NULL){
		printf("Dosya acilamadi...!!!!!!\n");	
		return;
	} else {
		for (i = 0; i <= MAX; i++){
		if (Memur[i].ad[0])
			fwrite(&Memur[i], sizeof(M_KAYIT), 1, di);
			fprintf(di,"\n");
		}
		fclose(di);
		printf("\n\tBasarili Kayit, Tesekkurler...!\n");
	}
}
//Dosyada siginmacilari kayýtlarýn diziye okur
void dosya_S_OKU() {
	FILE *di;
	unsigned int tane;
	int i, k;
	if ((di=fopen("Siginmaci.txt","r")) == NULL)
	{
		puts("Dosya Acilamadi...!");
		exit(EXIT_SUCCESS);
	} else {
	fseek(di,0,2);
	tane = ftell(di)/sizeof(S_KAYIT);
	fseek(di, 0, 0);
	puts("Yukluyorum...");
	for (k = 0; k < MAX; k++)
	{
		i = d_control();
		if (i == -1)
		{
			printf("Dizide yer kalmadi...!");
			break;
		}
		fread(&siginmaci[k], sizeof(S_KAYIT),1,di);
	}
	fclose(di);
	}
}
//Dosyada Kullanýcý kayýtlarýn diziye okur
void dosya_M_OKU() {
	FILE *di;
	//unsigned int tane;
	int i, k;
	if ((di=fopen("Kullanici.txt","r")) == NULL)
	{
		puts("Dosya Acilamadi...!");
		return;
	} else {/*
	fseek(di,0,2);
	tane = ftell(di)/sizeof(M_KAYIT);
	fseek(di, 0, 0);*/
	puts("Yukluyorum...");
	for (k = 0; k < MAX; k++)
	{
		/*i = d_control();
		if (i == -1)
		{
			printf("Dizide yer kalmadi...!");
			break;
		}*/
		fread(&Memur[k], sizeof(M_KAYIT),1,di);
	}
	fclose(di);
	}
}
//
void dosya_S_ARAMA() {
	int i = 0; char secim[15], secimArarnan[15];
	dosya_S_OKU();
	menu_S_Arama();
	do
	{
		printf("Aranacak Eleman: ");
		scanf("%s",secimArarnan);
		printf("Secim Yapiniz: ");
		scanf("%s",secim);

	

	
		if (siginmaci[i].ad[0]) {
			switch (secim[0])
			{
			case '1':
				for (int i = 0; i < 2; i++)
				if (strcmp(siginmaci[i].ad, secimArarnan)) {
					printf("%d . Socuc %s \n",i+1,siginmaci[i].ad);
				}
				break;
			case '2':
				for (int i = 0; i < 2; i++)
				if (strcmp(siginmaci[i].soyad, secimArarnan)) {
					printf("%d . Sonuc %s \n",i+1,siginmaci[i].soyad);
				}
				break;
			case '3':
				for (int i = 0; i < 2; i++)
				if (strcmp(siginmaci[i].dogum_yeri, secimArarnan)) {
					printf("%d . Socuc %s \n",i+1,siginmaci[i].dogum_yeri);
				}
				break;
			case '4':
				for (int i = 0; i < 2; i++)
				if (strcmp(siginmaci[i].uyruk, secimArarnan)) {
					printf("%d . Socuc %s \n",i+1,siginmaci[i].uyruk);
				}
				break;
			case '5':
				for (int i = 0; i < 2; i++)
				if (strcmp(siginmaci[i].cinsiyet, secimArarnan)) {
					printf("%d . Socuc %s \n",i+1,siginmaci[i].cinsiyet);
				}
				break;
			case '6':
				for (int i = 0; i < 2; i++)
				if (strcmp(siginmaci[i].meslek, secimArarnan)) {
					printf("%d . Socuc %s \n",i+1,siginmaci[i].meslek);
				}
				break;
			case '7':
				for (int i = 0; i < 2; i++)
				if (strcmp(siginmaci[i].egitim_durumu, secimArarnan)) {
					printf("%d . Socuc %s \n",i+1,siginmaci[i].egitim_durumu);
				}
				break;
			case '8':
				menu_Admin();
				break;
			default:
				printf("Hatali Islem...!\n");
				break;
			}
		}
		} while (!d_sayi_control(secim) && secim[0] != '1'&& secim[0] != '2'&& secim[0] != '3'&& secim[0] != '4'&& secim[0] != '5'&& secim[0] != '6'&& secim[0] != '7');
	
}
//
void dosya_M_ARAMA() {
	int i = 0; char secim[5], secimArarnan[15];
	dosya_M_OKU();
	menu_M_Arama();
	do
	{
		printf("Aranacak Eleman: ");
		scanf("%s",secimArarnan);
		printf("Secim Yapiniz: ");
		secim[i] = getch();

	

		if (Memur[i].ad[0]) {
			switch (secim[0])
			{
			case '1':
				for (int i = 0; i < 2; i++)
				if (!strcmp(Memur[i].ad, secimArarnan)) {
					printf("%d . Socuc %s \n",i+1,Memur[i].ad);
				}
				break;
			case '2':
				for (int i = 0; i < 2; i++)
				if (!strcmp(Memur[i].soyad, secimArarnan)) {
					printf("%d . Socuc %s \n",i+1,Memur[i].soyad);
				}
				break;
			case '3':
				for (int i = 0; i < 2; i++)
				if (!strcmp(Memur[i].tc, secimArarnan)) {
					printf("%d . Socuc %s \n",i+1,Memur[i].tc);
				}
				break;
			case '4':
				for (int i = 0; i < 2; i++)
				if (!strcmp(Memur[i].kullanici_adi, secimArarnan)) {
					printf("%d . Socuc %s \n",i+1,Memur[i].kullanici_adi);
				}
				break;
			case '5':
				for (int i = 0; i < 2; i++)
				if (!strcmp(Memur[i].yetki_turu, secimArarnan)) {
					printf("%d . Socuc %s \n",i+1,Memur[i].yetki_turu);
				}
				break;
			case '6':
				menu_Memur();
			default:
				printf("Hatali Islem...!\n");
				break;
			}
		}
		} while (!d_sayi_control(secim) && secim[0] != '1'&& secim[0] != '2'&& secim[0] != '3'&& secim[0] != '4'&& secim[0] != '5'&& secim[0] != '6'&& secim[0] != '7');
}
//
void menu_S_Arama() {
	printf("Siginmaci Arama yapilacak tip seciniz.\n-------------------------------------------------------\n");
	printf("\t'\n\t'--> 1. Ad'a gore Arama.\n");
	printf("\t'--> 2. Soyad'a gore Arama\n");
	printf("\t'--> 3. Dogum yerine gore Arama\n");
	printf("\t'--> 4. Uyrug'a gore Arama\n");
	printf("\t'--> 5. Cinsiyet'e gore Arama\n");
	printf("\t'--> 6. Mesleg'e gore Arama\n");
	printf("\t'--> 7. Egitim durumuna gore Arama\n");
		printf("\t'--> 8. Ana menu\n");
	
}
void menu_M_Arama() {
	printf("Siginmaci Arama yapilacak tip seciniz.\n");
	printf("\t'\n\t'--> 1. Ad'a gore Arama.\n");
	printf("\t'--> 2. Soyad'a gore Arama\n");
	printf("\t'--> 3. TC'ye gore Arama\n");
	printf("\t'--> 4. Kullanici ad'a gore Arama\n");
	printf("\t'--> 5. Yetki ture gore Arama\n");
		printf("\t'--> 6. Ana menu\n");
}
//
void dosya_S_Silme() {
	dosya_S_OKU();
	int k, indis;
	char ad[15];
	printf("Silmek istediginiz Ad: ");
	scanf("%s",ad);
	indis = varmi_S(ad);
	if (indis== -1)
	{
		printf("Boyle kayit yok");
		return;
	} else {
		puts("Sildim..");
		siginmaci[indis].ad[0] = '\0';
	}
	dosya_S_Ekle();
}
void dosya_M_Silme() {
	dosya_M_OKU();
	int k, indis;
	char ad[15];
	printf("Silmek istediginiz Ad: ");
	scanf("%s",ad);
	indis = varmi_M(ad);
	if (indis== -1)
	{
		printf("Boyle kayit yok");
		return;
	} else {
		puts("Sildim..");
		Memur[indis].ad[0] = '\0';
	}
	dosya_M_Ekle();
}
//
int varmi_S(char isim[]) {
	int k;
	for ( k = 0; k < MAX; k++)
		if (siginmaci[k].ad[0])
			if (!strcmp(siginmaci[k].ad,isim))
				return k;
	return -1;
}
int varmi_M(char isim[]) {
	int k;
	for ( k = 0; k < MAX; k++)
		if (Memur[k].ad[0])
			if (!strcmp(Memur[k].ad,isim))
				return k;
	return -1;
}
//
void Listele_S() {
	int i,j;
	S_KAYIT temp_S;
	for (i = 1; i < MAX; i++) {
		for (j = 0; j < MAX - 1; j++) {
			if (siginmaci[j].ad > siginmaci[j + 1].ad) {
				temp_S = siginmaci[j];
				siginmaci[j]= siginmaci[j + 1];
				siginmaci[j + 1] = temp_S;
			}
		}
		printf("Ad: %15s\n Soyad: %15s\nDogum Tarihi: %15s \n Dogum yeri: %15s\n Cinsiyyet: %15s\n Uyruk: %15s\n Meslek %15s \n Egitim Durumu: %15s\n Geldigi sehir: %15s\n Geldigi Tarih : %15s\n email: %15s\n Telefon: %15s\n", 
					siginmaci[i].ad, siginmaci[i].soyad, siginmaci[i].dogum_tarihi,siginmaci[i].dogum_yeri,
					siginmaci[i].cinsiyet,siginmaci[i].uyruk,siginmaci[i].meslek,siginmaci[i].egitim_durumu,
					siginmaci[i].geldigi_sehir,siginmaci[i].gelis_tarihi,siginmaci[i].eposta,siginmaci[i].telefon);
	}
}
//
void Listele_M() {
	int i,j;
	M_KAYIT temp_M;
	for (i = 1; i < MAX; i++) {
		for (j = 0; j < MAX - 1; j++) {
			if (Memur[j].ad > Memur[j + 1].ad) {
				temp_M = Memur[j];
				Memur[j]= Memur[j + 1];
				Memur[j + 1] = temp_M;
			}
		}
		printf("Ad: %15s\n Soyad: %15s \nAdress : %15s\n email: %15s\n Telefon: %15s\n", Memur[i].ad, Memur[i].soyad,Memur[i].adres,Memur[i].eposta,Memur[i].telefon);
	}
}