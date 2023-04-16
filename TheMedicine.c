#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

struct{
	char namaobat[30], dosis[30], nama[30],kode[30];
	int harga;
}dataobat, temp[30],temp2, bank;
struct{
	char uname[30], pass[30], nama[50], alamat[30], hp[30];
}pembeli;

FILE*f_pembeli, *f_pembeli2;
FILE*f_demam, *f_demam2;
FILE*f_pernapasan, *f_pernapasan2;
FILE*f_batuk, *f_batuk2;
FILE*f_code;

char uname[30], pass[30], cari[30], hapus[30], update[30];
int pilih, i,n;
int j,k;
bool berhasil;

void bacabatuk();
void bacademam();
void bacaobat();
void bacapembeli();
void bacapernapasan();
void bayarcod();
void bayartransfer();
void hapusbatuk();
void hapusdemam();
void hapusobat();
void hapuspembeli();
void hapuspernapasan();
void keluar();
void kodevirtual();
void listbatuk();
void listdemam();
void listobat();
void listpernapasan();
void loginpembeli();
void masukadmin();
void masukpembeli();
void menuadmin();
void menubatuk();
void menudemam();
void menupembeli();
void menupernapasan();
void pembayaran();
void registpembeli();
void updatebatuk();
void updatedemam();
void updateobat();
void updatepembeli();
void updatepernapasan();

int main(){
	system("color 06");
	system("cls");
	printf(" ____________________________________________\n\n");
	printf("                                            \n");
	printf("        Selamat Datang Di D'Medicine        \n");
	printf("                                             \n");
	printf(" ____________________________________________\n");
	printf("\n");
	printf("      SILAHKAN LOGIN UNTUK MELANJUTKAN \n\n");
	printf("1. Login Sebagai Admin\n");
	printf("2. Login Sebagai Pembeli\n");
	printf("3. EXIT\n\n");
	printf("Pilih [1-3]: "); scanf("%d",&pilih);getchar();
	switch(pilih){
		case 1: i=2; masukadmin(); break;
		case 2: loginpembeli(); break;
		case 3: keluar(); break;
		default: printf("\ntidak ada pilihan\n\n");
		system("pause");
		main();
		break;
	}
}

// MASUK ADMIN //

void masukadmin(){
	system("cls");
	printf("=============================================\n");
	printf("=                                           =\n");
	printf("=                LOGIN ADMIN                =\n");
	printf("=                                           =\n");
	printf("=============================================\n");
	printf("\nUsername	: ");gets(uname);
	printf("Password	: ");gets(pass);

	if(strcmp(uname,"admin")==0 && strcmp(pass,"admin")==0)
	{
		printf("\nLogin Berhasil!\n\n");
		system("pause");
		menuadmin();
	}
	else if(i>0){
		i--;
		printf("\n       Maaf username/password salah");
		printf("\n    Kesempatan login tinggal %d kali lagi\n", i+1);
		printf("=============================================\n");
		system("pause");
		masukadmin();
	}
	else {
		printf("\n      Kesempatan Login Sudah Habis\n\n");
		printf("=============================================\n");
		system("pause");
		main();
	}
}

// MENU ADMIN//

void menuadmin(){
	system("cls");

	printf("=============================================\n");
	printf("=                                           =\n");
	printf("=                  MENU ADMIN               =\n");
	printf("=                                           =\n");
	printf("=============================================\n");
	printf("= 1. Daftar Obat                            =\n");
	printf("= 2. Menambah Obat                          =\n");
	printf("= 3. Update Informasi Obat                  =\n");
	printf("= 4. Hapus Obat                             =\n");
	printf("= 5. Update Virtual Akun                    =\n");
	printf("= 6. Update Akun Pembeli                    =\n");
	printf("= 7. Daftar Akun Pembeli                    =\n");
	printf("= 8. Hapus Akun Pembeli                     =\n");
	printf("= 9. Log out                                =\n");
	printf("=============================================\n");
	printf("\nPilih [1-8] : "); scanf("%d",&pilih);getchar();
	switch(pilih){
		case 1: bacaobat(); break;
		case 2: listobat(); break;
		case 3: updateobat(); break;
		case 4: hapusobat(); break;
		case 5: kodevirtual(); break;
		case 6: updatepembeli(); break;
		case 7: bacapembeli(); break;
		case 8: hapuspembeli();break;
		case 9: main(); break;
		default: printf("Maaf, pilihan tidak tersedia.");
		system("pause");
		main();
		break;
	}
}

void bacaobat(){
	system("cls");
	printf("**************************************\n");
	printf("*  Daftar Obat Berdasarkan Kategori  *");
	printf("\n*                                    *");
	printf("\n* 1. Demam                           *");
	printf("\n* 2. Pernapasan                      *");
	printf("\n* 3. Batuk                           *");
	printf("\n* 4. Menu Admin                      *");
	printf("\n*                                    *");
	printf("\n**************************************\n");
	printf("Pilih [1-4] : "); scanf("%d",&pilih);getchar();
	switch(pilih){
		case 1: bacademam(); break;
		case 2: bacapernapasan(); break;
		case 3: bacabatuk(); break;
		case 4: menuadmin(); break;
		default: printf("tidak ada pilihan");
		system("pause");
		bacaobat();
		break;
	}
}

void bacademam(){
	system("cls");

	i=1;
	printf("----- List Obat Demam -----\n");
	f_demam=fopen("DataDemam.dat","rb");
	while(fread(&dataobat,sizeof(dataobat),1,f_demam)==1){
		printf("\n Obat Ke %d\n",i);
		printf(" Nama Obat  : %s\n",dataobat.namaobat);
		printf(" Dosis Obat : %s\n",dataobat.dosis);
		printf(" Harga Obat : %d\n",dataobat.harga);
		i++;
	}
	fclose(f_demam);
	printf("\n");
	system("pause");
	bacaobat();
}

void bacapernapasan(){
	system("cls");

	i=1;
	printf("----- List Obat Pernapasan -----\n");
	f_pernapasan=fopen("DataPernapasan.dat","rb");
	while(fread(&dataobat,sizeof(dataobat),1,f_pernapasan)==1){
		printf("\n Obat Ke %d\n",i);
		printf(" Nama Obat  : %s\n",dataobat.namaobat);
		printf(" Dosis Obat : %s\n",dataobat.dosis);
		printf(" Harga Obat : %d\n",dataobat.harga);
		i++;
	}
	fclose(f_pernapasan);
	printf("\n");
	system("pause");
	bacaobat();
}

void bacabatuk(){
	system("cls");

	i=1;
	printf("----- List Obat Batuk -----\n");
	f_batuk=fopen("DataBatuk.dat","rb");
	while(fread(&dataobat,sizeof(dataobat),1,f_batuk)==1){
		printf("\n Obat Ke %d\n",i);
		printf(" Nama Obat  : %s\n",dataobat.namaobat);
		printf(" Dosis Obat : %s\n",dataobat.dosis);
		printf(" Harga Obat : %d\n",dataobat.harga);
		i++;
	}
	fclose(f_batuk);
	printf("\n");
	system("pause");
	bacaobat();
}

void listobat(){
	system("cls");
	printf("**************************************\n");
	printf("*  Tambah Obat Berdasarkan Kategori  *");
	printf("\n*                                    *");
	printf("\n* 1. Demam                           *");
	printf("\n* 2. Pernapasan                      *");
	printf("\n* 3. Batuk                           *");
	printf("\n* 4. Menu Admin                      *");
	printf("\n*                                    *");
	printf("\n**************************************\n");
	printf("Pilih [1-4] : "); scanf("%d",&pilih);getchar();
	switch(pilih){
		case 1: listdemam(); break;
		case 2: listpernapasan(); break;
		case 3: listbatuk(); break;
		case 4: menuadmin(); break;
		default: printf("tidak ada pilihan");
		system("pause");
		listobat();
		break;
	}
}

void listdemam(){
	system("cls");

	f_demam=fopen("DataDemam.dat","ab");
		printf("----- Menambah Data Obat Demam -----\n");
		printf("\nJumlah data yang ingin dimasukkan : "); scanf("%d", &k);getchar();

		for(j=1;j<=k;j++){
		printf("\nObat ke %d\n", j);
		printf(" Nama Obat  : "); fflush(stdin);gets(dataobat.namaobat);
		printf(" Dosis Obat : "); gets(dataobat.dosis);
		printf(" Harga Obat : "); scanf("%d", &dataobat.harga);getchar();
		fwrite(&dataobat,sizeof(dataobat),1,f_demam);
		}
		printf("\ntekan enter untuk kembali ke menu admin\n");
		system("pause");
		fclose(f_demam);
		menuadmin();
}

void listpernapasan(){
	system("cls");

	f_pernapasan=fopen("DataPernapasan.dat","ab");
		printf("----- Menambah Data Obat Pernapasan -----\n");
		printf("\nJumlah data yang ingin dimasukkan : "); scanf("%d", &k);getchar();

		for(j=1;j<=k;j++){
		printf("\n Obat ke %d\n", j);
		printf(" Nama Obat  : "); fflush(stdin); gets(dataobat.namaobat);
		printf(" Dosis Obat : "); gets(dataobat.dosis);
		printf(" Harga Obat : "); scanf("%d", &dataobat.harga);getchar();
		fwrite(&dataobat,sizeof(dataobat),1,f_pernapasan);
		}
		printf("\ntekan enter untuk kembali ke menu admin\n");
		fclose(f_pernapasan);
		system("pause");
		menuadmin();
}

void listbatuk(){
	system("cls");

	f_batuk=fopen("DataBatuk.dat","ab");
		printf("\n**** Menambah Data Obat Batuk ****\n");
		printf("\nJumlah data yang ingin dimasukkan : "); scanf("%d", &k);getchar();

		for(j=1;j<=k;j++){
		printf("\n Obat ke %d\n", j);
		printf(" Nama Obat  : "); fflush(stdin); gets(dataobat.namaobat);
		printf(" Dosis Obat : "); gets(dataobat.dosis);
		printf(" Harga Obat : "); scanf("%d", &dataobat.harga);getchar();
		fwrite(&dataobat,sizeof(dataobat),1,f_pernapasan);
		}
		printf("\ntekan enter untuk kembali ke menu admin\n");
		fclose(f_batuk);
		system("pause");
		menuadmin();
}

void updateobat(){
	system("cls");

	printf("**************************************\n");
	printf("*  Update Obat Berdasarkan Kategori  *");
	printf("\n*                                    *");
	printf("\n* 1. Demam                           *");
	printf("\n* 2. Pernapasan                      *");
	printf("\n* 3. Batuk                           *");
	printf("\n* 4. Menu Admin                      *");
	printf("\n*                                    *");
	printf("\n**************************************\n");
	printf("\nPilih [1-4] : "); scanf("%d",&pilih);getchar();
	switch(pilih){
		case 1: updatedemam(); break;
		case 2: updatepernapasan(); break;
		case 3: updatebatuk(); break;
		case 4: menuadmin(); break;
		default: printf("tidak ada pilihan");
		system("pause");
		updateobat();
		break;
	}
}

void updatedemam(){
	system("cls");

    printf("----- Update Informasi Obat Demam -----\n");
    printf("\nKetik nama obat : "); gets(cari);
	printf("\n");
	berhasil=false;
	f_demam=fopen("DataDemam.dat","rb+");
	while(fread(&dataobat,sizeof(dataobat),1,f_demam)==1){
		if(strcmp(cari,dataobat.namaobat)==0){
            printf("*Data Ditemukan");
		    printf("\n Nama Obat  : %s", dataobat.namaobat);
            printf("\n Dosis Obat : %s", dataobat.dosis);
            printf("\n Harga Obat : %d\n", dataobat.harga);

            printf("\n*Masukkan Data Baru");
		    printf("\n Nama Obat  : "); fflush(stdin); gets(dataobat.namaobat);
            printf(" Dosis Obat : "); gets(dataobat.dosis);
            printf(" Harga Obat : "); scanf("%d", &dataobat.harga);getchar();
            fseek(f_demam, -(long)sizeof(dataobat),1);
            fwrite(&dataobat,sizeof(dataobat),1,f_demam);
            break;
		}
	}
	fclose(f_demam);
	system("pause");
	updateobat();
}

void updatepernapasan(){
	system("cls");
	printf("----- Update Informasi Obat Pernapasan -----\n");
	printf("\nKetik nama obat : "); gets(cari);
	printf("\n");

	berhasil=false;
	f_pernapasan=fopen("DataPernapasan.dat","rb+");
	while(fread(&dataobat,sizeof(dataobat),1,f_pernapasan)==1){
		if(strcmp(cari,dataobat.namaobat)==0){
			printf("*Data Ditemukan");
			printf("\n Nama Obat  : %s", dataobat.namaobat);
			printf("\n Dosis Obat : %s", dataobat.dosis);
			printf("\n Harga Obat : %d\n", dataobat.harga);

			printf("\n*Masukkan Data Baru");
			printf("\n Nama Obat  : "); fflush(stdin); gets(dataobat.namaobat);
			printf(" Dosis Obat : "); gets(dataobat.dosis);
			printf(" Harga Obat : "); scanf("%d", &dataobat.harga);getchar();
			fseek(f_pernapasan, -(long)sizeof(dataobat),1);
			fwrite(&dataobat,sizeof(dataobat),1,f_pernapasan);

			break;
		}
	}
	fclose(f_pernapasan);
	system("pause");
	updateobat();
}

void updatebatuk(){
	system("cls");

	printf("----- Update Informasi Obat Batuk -----\n");
	printf("\nKetik nama obat : "); gets(cari);
	printf("\n");
	berhasil=false;
	f_batuk=fopen("DataBatuk.dat","rb+");
	while(fread(&dataobat,sizeof(dataobat),1,f_batuk)==1){
		if(strcmp(cari,dataobat.namaobat)==0){
			printf("*Data Ditemukan");
			printf("\n Nama Obat  : %s", dataobat.namaobat);
			printf("\n Dosis Obat : %s", dataobat.dosis);
			printf("\n Harga Obat : %d\n", dataobat.harga);

			printf("\n*Masukkan Data Baru");
			printf("\n Nama Obat  : "); fflush(stdin); gets(dataobat.namaobat);
			printf(" Dosis Obat : "); gets(dataobat.dosis);
			printf(" Harga Obat : "); scanf("%d", &dataobat.harga);getchar();
			fseek(f_batuk, -(long)sizeof(dataobat),1);
			fwrite(&dataobat,sizeof(dataobat),1,f_batuk);
			break;
		}
	}
	fclose(f_batuk);
	system("pause");
	updateobat();
}

void hapusobat(){
	system("cls");

	printf("**************************************\n");
	printf("*  Hapus Obat Berdasarkan Kategori   *");
	printf("\n*                                    *");
	printf("\n* 1. Demam                           *");
	printf("\n* 2. Pernapasan                      *");
	printf("\n* 3. Batuk                           *");
	printf("\n* 4. Menu Admin                      *");
	printf("\n*                                    *");
	printf("\n**************************************\n");
	printf("\nPilih [1-4] : "); scanf("%d",&pilih);getchar();
	switch(pilih){
		case 1: hapusdemam(); break;
		case 2: hapuspernapasan(); break;
		case 3: hapusbatuk(); break;
		case 4: menuadmin(); break;
		default: printf("tidak ada pilihan");
		system("pause");
		listobat();
		break;
	}
}

void hapusdemam(){
	system("cls");

	i = 1;
	printf("----- Menghapus Obat Demam -----\n\n");
	printf("*List Obat Demam\n");
	f_demam=fopen("DataDemam.dat","rb");
	while(fread(&dataobat,sizeof(dataobat),1,f_demam)==1){
		printf("\n Obat Ke %d\n",i);
		printf(" Nama Obat  : %s\n",dataobat.namaobat);
		printf(" Dosis Obat : %s\n",dataobat.dosis);
		printf(" Harga Obat : %d\n",dataobat.harga);
		i++;
	}
	fclose(f_demam);
	printf("\n");

	printf("----- Menghapus Obat Demam -----\n\n");
	printf("Masukkan nama obat yang akan dihapus : ");
	gets(hapus);
	f_demam=fopen("DataDemam.dat", "rb");
	f_demam2=fopen("DataDemam2.dat", "wb");
	while(fread(&dataobat,sizeof(dataobat),1,f_demam)==1){
		if(strcmp(dataobat.namaobat, hapus)!=0)
		{
			fwrite(&dataobat, sizeof(dataobat),1,f_demam2);
		}
	}
	fclose(f_demam);
	fclose(f_demam2);
	remove("DataDemam.dat");
	rename("DataDemam2.dat", "DataDemam.dat");

	printf("\nData Berhasil dihapus !!!\n");
	system("pause");
	hapusobat();
}

void hapuspernapasan(){
	system("cls");

	i = 1;
	printf("----- Menghapus Obat Pernapasan -----\n\n");
	printf("*List Obat Pernapasan\n");
	f_demam=fopen("DataPernapasan.dat","rb");
	while(fread(&dataobat,sizeof(dataobat),1,f_demam)==1){
		printf("\n Obat Ke %d\n",i);
		printf(" Nama Obat  : %s\n",dataobat.namaobat);
		printf(" Dosis Obat : %s\n",dataobat.dosis);
		printf(" Harga Obat : %d\n",dataobat.harga);
		i++;
		}
	fclose(f_pernapasan);
	printf("\n");

	printf("----- Menghapus Obat Pernapasan -----\n\n");
	printf("Masukkan nama obat yang akan dihapus : ");
	gets(hapus);
	f_pernapasan=fopen("DataPernapasan.dat", "rb");
	f_pernapasan2=fopen("DataPernapasan2.dat", "wb");
	while(fread(&dataobat,sizeof(dataobat),1,f_pernapasan)==1){
		if(strcmp(dataobat.namaobat, hapus)!=0)
		{
			fwrite(&dataobat, sizeof(dataobat),1,f_pernapasan2);
		}
	}
	fclose(f_pernapasan);
	fclose(f_pernapasan2);
	remove("DataPernapasan.dat");
	rename("DataPernapasan2.dat", "DataPernapasan.dat");

	printf("\nData Berhasil dihapus !!!\n");
	system("pause");
	hapusobat();
}

void hapusbatuk(){
	system("cls");

	i = 1;
	printf("----- Menghapus Obat Batuk -----\n\n");
	printf("*List Obat Batuk\n");
	f_demam=fopen("DataBatuk.dat","rb");
	while(fread(&dataobat,sizeof(dataobat),1,f_demam)==1){
		printf("\n Obat Ke %d\n",i);
		printf(" Nama Obat  : %s\n",dataobat.namaobat);
		printf(" Dosis Obat : %s\n",dataobat.dosis);
		printf(" Harga Obat : %d\n",dataobat.harga);
		i++;
	}
	fclose(f_batuk);
	printf("\n");

	printf("----- Menghapus Obat Batuk -----\n\n");
	printf("\nMasukkan nama obat yang akan dihapus : ");gets(hapus);
	f_batuk=fopen("DataBatuk.dat", "rb");
	f_batuk2=fopen("DataBatuk2.dat", "wb");
	while(fread(&dataobat,sizeof(dataobat),1,f_batuk)==1){
		if(strcmp(dataobat.namaobat, hapus)!=0)
		{
			fwrite(&dataobat, sizeof(dataobat),1,f_batuk2);
		}
	}
	fclose(f_batuk);
	fclose(f_batuk2);
	remove("DataBatuk.dat");
	rename("DataBatuk2.dat", "DataBatuk.dat");

	printf("\nData Berhasil dihapus !!!\n");
	system("pause");
	hapusobat();
}

void kodevirtual(){
	system("cls");

	f_code=fopen("KodeVirtual.dat","wb");
	printf("----- Update Kode Virtual -----\n");
	printf("\nJumlah data yang ingin dimasukkan : "); scanf("%d", &k);getchar();
	for(j=1;j<=k;j++){
		printf("Nama Bank : "); fflush(stdin);gets(bank.nama);
		printf("Kode Bank : "); gets(bank.kode);
		fwrite(&bank,sizeof(bank),1,f_code);
	}
	printf("\ntekan enter untuk kembali ke menu admin\n");
	system("pause");
	fclose(f_code);
	menuadmin();
}

void updatepembeli(){
	system("cls");

	printf("----- Update Informasi Pembeli -----\n");
	printf("\nKetik nama pembeli : "); gets(cari);
	printf("\n");
	f_pembeli=fopen("DataPembeli.dat","rb+");
	while(fread(&pembeli,sizeof(pembeli),1,f_pembeli)==1){
		if(strcmp(cari,pembeli.nama)==0){
			printf("*Data Ditemukan");
			printf("\n Nama     : %s", pembeli.nama);
			printf("\n Alamat   : %s", pembeli.alamat);
			printf("\n Nomor Hp : %d\n", pembeli.hp);

			printf("\n*Masukkan Data Baru*");
			printf("\n Nama     : "); fflush(stdin); gets(pembeli.nama);
			printf(" Alamat   : "); gets(pembeli.alamat);
			printf(" Nomor Hp : "); scanf("%d", &pembeli.hp);getchar();
			fseek(f_pembeli, -(long)sizeof(pembeli),1);
			fwrite(&pembeli,sizeof(pembeli),1,f_pembeli);
			break;
		}
	}
	fclose(f_pembeli);
	system("pause");
	menuadmin();
}

void hapuspembeli(){
	system("cls");

    printf("----- Hapus Data Member -----\n");
	printf("\nMasukkan nama pembeli yang akan dihapus : ");
	gets(hapus);
	f_pembeli=fopen("DataPembeli.dat", "rb");
	f_pembeli2=fopen("DataPembeli2.dat", "wb");
	while(fread(&pembeli,sizeof(pembeli),1,f_pembeli)==1)
	{
		if(strcmp(pembeli.nama, hapus)!=0)
		{
			fwrite(&pembeli, sizeof(pembeli),1,f_pembeli2);
		}
	}
	fclose(f_pembeli);
	fclose(f_pembeli2);
	remove("DataPembeli.dat");
	rename("DataPembeli2.dat", "DataPembeli.dat");
	system("pause");
	menuadmin();
}

void bacapembeli(){
    system("cls");
 	i=1;
 	printf("----- Data Pembeli -----\n");
	f_pembeli=fopen("DataPembeli.dat","rb");
	while(fread(&pembeli,sizeof(pembeli),1,f_pembeli)==1){
		printf("\n Daftar Ke %d\n",i);
		printf(" Nama     : %s\n",pembeli.nama);
		printf(" Alamat   : %s\n",pembeli.alamat);
		printf(" Nomor HP : %d\n",pembeli.hp);
		i++;
		}
	fclose(f_pembeli);
	system("pause");
	menuadmin();
}

// MASUK PEMBELI //

void loginpembeli(){
	system("cls");

	printf("=============================================\n");
	printf("=                                           =\n");
	printf("=           Sudah Memiliki Akun?            =\n");
	printf("=                                           =\n");
	printf("=============================================\n\n");
	printf("1. Login\n");
	printf("2. Registrasi\n");
	printf("3. Menu Awal\n");
	printf("   Registrasi jika belum memiliki akun !!!\n");
	printf("=============================================");
	printf("\nPilih [1-2]: "); scanf("%d",&pilih);getchar();
	switch(pilih){
		case 1:i=2; masukpembeli(); break;
		case 2: registpembeli(); break;
		case 3: main();
		default: printf("\ntidak ada pilihan\n\n");
		system("pause");
		masukpembeli();
		break;
	}
}

// registrasi Member//

void registpembeli(){
	system("cls");
	f_pembeli=fopen("DataPembeli.dat","ab");

	printf("=============================================\n");
	printf("=                                           =\n");
	printf("=            Halaman Registrasi             =\n");
	printf("=                                           =\n");
	printf("=============================================\n\n");
	printf("            Buat Username & Password\n");
	printf("Username : " ,i);gets(pembeli.uname);
	printf("Password : " ,i);gets(pembeli.pass);
	printf("\nMasukkan Data Diri :\n\n");
	printf("Nama     : ");gets(pembeli.nama);
	printf("Alamat   : ");gets(pembeli.alamat);
	printf("Nomor HP : ");gets(pembeli.hp);
	fwrite(&pembeli, sizeof(pembeli), 1, f_pembeli);
	fclose(f_pembeli);
	masukpembeli();
}

// Log in Member //

void masukpembeli(){
	system("cls");
	printf("=============================================\n");
	printf("=                                           =\n");
	printf("=              LOG IN PEMBELI               =\n");
	printf("=                                           =\n");
	printf("=============================================\n");
	printf("Masukkan Akun Anda\n");

	berhasil=false;
	f_pembeli=fopen("DataPembeli.dat","rb");
	printf("Username : " ,i);gets(uname);
	printf("Password : " ,i);gets(pass);
	while(fread(&pembeli,sizeof(pembeli),1,f_pembeli)==1){
		if(strcmp(uname,pembeli.uname)==0 && strcmp(pass,pembeli.pass)==0){
			berhasil=true;
			break;
		}
	}
	fclose(f_pembeli);

	if (berhasil){
		printf("Log in berhasil\n");
		system("pause");
		menupembeli();
	}

	else if(i>0){
		i--;
		printf("\nUsername atau Password Salah");
		printf("\nKesempatan login tinggal %d kali lagi\n\n", i+1);
		system("pause");
		masukpembeli();
	}

	else {
		printf("\nKesempatan Login Sudah Habis\n\n");
		system("pause");
		loginpembeli();
	}
}


void menupembeli(){
	system("cls");

	printf("=============================================\n");
	printf("=                                           =\n");
	printf("=               MENU PEMBELI                =\n");
	printf("=                                           =\n");
	printf("=============================================\n");
	printf("Pilih Obat Berdasarkan Kategori Penyakit : ");
	printf("\n1. Demam");
	printf("\n2. Pernapasan");
	printf("\n3. Batuk");
	printf("\n4. Log Out");
	printf("\n\nPilih [1-4] : "); scanf("%d",&pilih);getchar();
	switch(pilih){
		case 1: menudemam(); break;
		case 2: menupernapasan(); break;
		case 3: menubatuk(); break;
		case 4: main(); break;
		default: printf("tidak ada pilihan");
		system("pause");
		main();
		break;
	}
}

void menudemam(){
	system("cls");

	printf("---------------------------------\n\n");
	printf("    Obat dalam Kategori Demam\n");
	printf("---------------------------------\n\n");
	int i=0,j=0,n;
	f_demam=fopen("DataDemam.dat","rb");
	while(fread(&dataobat,sizeof(dataobat),1,f_demam)==1){
		strcpy(temp[i].namaobat, dataobat.namaobat);
		strcpy(temp[i].dosis, dataobat.dosis);
		temp[i].harga=dataobat.harga;
		i++;
		n=i;
	}
	fclose(f_demam);

	for(i=n-1;i>=1;i--){
		for(j=1;j<=i;j++){
			if(strcmp(temp[j-1].namaobat,temp[j].namaobat)>0){
				temp2=temp[j-1];
				temp[j-1]=temp[j];
				temp[j]=temp2;
			}
		}
	}

	for(i=0;i<n;i++){
		printf("\n Nama  : %s",temp[i].namaobat);
		printf("\n Dosis : %s",temp[i].dosis);
		printf("\n Harga : %d",temp[i].harga);
		printf("\n");
	}

	printf("\nKetik nama obat yang mau dibeli : "); gets(cari);
	printf("\n");

	berhasil=false;
	f_demam=fopen("DataDemam.dat","rb");
	while(fread(&dataobat,sizeof(dataobat),1,f_demam)==1){
		if(strcmp(cari,dataobat.namaobat)==0){
			berhasil=true;
			break;
		}
	}
	fclose(f_demam);
	if(berhasil){
		printf("Input Berhasil Tekan Enter ke Menu Pembayaran");getchar();
		pembayaran();
	}

	else{
		printf("Input Ulang");
		getchar();
		menudemam();

	}
}

void menupernapasan(){
	system("cls");
	printf("----------------------------------\n\n");
	printf("  Obat dalam Kategori Pernapasan\n");
	printf("----------------------------------\n\n");
	int i=0,j=0,n;
	f_pernapasan=fopen("DataPernapasan.dat","rb");
	while(fread(&dataobat,sizeof(dataobat),1,f_pernapasan)==1){
		strcpy(temp[i].namaobat, dataobat.namaobat);
		strcpy(temp[i].dosis, dataobat.dosis);
		temp[i].harga=dataobat.harga;
		i++;
		n=i;
	}
	fclose(f_pernapasan);
	for(i=n-1;i>=1;i--){
		for(j=1;j<=i;j++){
			if(strcmp(temp[j-1].namaobat,temp[j].namaobat)>0){
				temp2=temp[j-1];
				temp[j-1]=temp[j];
				temp[j]=temp2;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("\n Nama  : %s",temp[i].namaobat);
		printf("\n Dosis : %s",temp[i].dosis);
		printf("\n Harga : %d",temp[i].harga);
		printf("\n");
	}
	printf("\n Ketik nama obat yang mau dibeli : ");gets(cari);
	printf("\n");

	berhasil=false;
	f_pernapasan=fopen("DataPernapasan.dat","rb");
	while(fread(&dataobat,sizeof(dataobat),1,f_pernapasan)==1){
		if(strcmp(cari,dataobat.namaobat)==0){
			berhasil=true;
			break;
		}
	}
	fclose(f_pernapasan);
	if (berhasil){
		printf("Input Berhasil Tekan Enter ke Menu Pembayaran");getchar();
		pembayaran();
	}

	else {
		printf("Input Ulang");
		getchar();
		menupernapasan();

	}
}

void menubatuk(){
	system("cls");
	printf("----------------------------------\n\n");
	printf("     Obat dalam Kategori Batuk\n");
	printf("----------------------------------\n\n");

	int i=0,j=0,n;
	f_batuk=fopen("DataBatuk.dat","rb");
	while(fread(&dataobat,sizeof(dataobat),1,f_batuk)==1){
		strcpy(temp[i].namaobat, dataobat.namaobat);
		strcpy(temp[i].dosis, dataobat.dosis);
		temp[i].harga=dataobat.harga;
		i++;
		n=i;
	}
	fclose(f_batuk);
	for(i=n-1;i>=1;i--){
		for(j=1;j<=i;j++){
			if(strcmp(temp[j-1].namaobat,temp[j].namaobat)>0){
				temp2=temp[j-1];
				temp[j-1]=temp[j];
				temp[j]=temp2;
			}
		}
	}
		for(i=0;i<n;i++){
			printf("\n Nama : %s",temp[i].namaobat);
			printf("\n Dosis : %s",temp[i].dosis);
			printf("\n Harga : %d",temp[i].harga);
			printf("\n");
		}

	printf("\nKetik nama obat yang mau dibeli : "); gets(cari);
	printf("\n");

	berhasil=false;
	f_batuk=fopen("DataBatuk.dat","rb");
	while(fread(&dataobat,sizeof(dataobat),1,f_batuk)==1){
		if(strcmp(cari,dataobat.namaobat)==0){
			berhasil=true;
			break;
		}
	}
	fclose(f_batuk);
	if (berhasil){
		printf("Input Berhasil Tekan Enter ke Menu Pembayaran");getchar();
		pembayaran();
	}

	else {
		printf("Input Ulang");
		getchar();
		menubatuk();
	}
}

void pembayaran(){
	system("cls");

	printf("=============================================\n");
	printf("=                                           =\n");
	printf("=             METODE PEMBAYARAN             =\n");
	printf("=                                           =\n");
	printf("=============================================\n");
	printf("Pilihan :\n 1. COD\n 2. Transfer Bank\n 3. Menu");
	printf("\n\nPilih [1-2] : "); scanf("%d",&pilih);getchar();
	switch(pilih){
		case 1: bayarcod(); break;
		case 2: bayartransfer(); break;
		case 3: menupembeli(); break;
		default: printf("tidak ada pilihan");
		system("pause");
		pembayaran();
		break;
	}
}

void bayarcod(){
	printf("=============================================\n");
	printf("=                                           =\n");
	printf("=        BARANG AKAN SEGERA DIKIRIM         =\n");
	printf("=                                           =\n");
	printf("=============================================\n");
	system("pause");
	menupembeli();
}

void bayartransfer(){
	printf("=============================================\n");
	printf("=                                           =\n");
	printf("=       TRANSFER DENGAN VIRTUAL AKUN        =\n");
	printf("=                                           =\n");
	printf("=============================================\n");
	printf("Konfirmasi No HP : ");gets(cari);
	printf("\n");

	berhasil=false;
	f_pembeli=fopen("DataPembeli.dat","rb");
	while(fread(&pembeli,sizeof(pembeli),1,f_pembeli)==1){
		if(strcmp(cari,pembeli.hp)==0){
			berhasil=true;
			break;
		}
	}
	fclose(f_pembeli);

	if(berhasil){
		system("cls");
		printf("----- Daftar Bank -----\n");
		f_code = fopen("KodeVirtual.dat","rb");

		while(fread(&bank,sizeof(bank),1,f_code) == 1){
			printf("\nBank/Kode : %s\t\t %s", bank.nama, bank.kode);
		}
		fclose(f_code);

		printf("\n\nInput Kode Bank : ");
		f_code = fopen(" KodeVirtual.dat","rb");gets(cari);
		while(fread(&bank, sizeof(bank),1,f_code)==1){
			if(strcmp(cari,bank.kode)==0){
				berhasil=true;
				break;
     		}
     	}

		if(berhasil){
			printf("=============================================\n");
			printf("=                                           =\n");
			printf("=              SILAHKAN TRANSFER            =\n");
			printf("=                                           =\n");
			printf("=============================================\n");
     		printf("\nVIRTUAL AKUN %s%s\n",bank.kode,pembeli.hp);
     		system("pause");
			menupembeli();
		}

		else{
			printf("=============================================\n");
			printf("=                                           =\n");
			printf("=              PEMBAYARAN GAGAL!!!          =\n");
			printf("=                                           =\n");
			printf("=============================================\n");
     		printf("Kembali ke menu pembayaran\n\n");
          	system("pause");
          	pembayaran();
     	}

     	fclose(f_code);
	}

	else {
		system("cls");
		printf("=============================================\n");
		printf("=                                           =\n");
		printf("=            NOMOR TIDAK TERDAFTAR          =\n");
		printf("=                                           =\n");
		printf("=============================================\n");
		printf("Kembali ke menu pembayaran\n\n");
		system("pause");
		pembayaran();
	}
}

void keluar(){
	system("cls");
	printf(" ____________________________________________\n\n");
	printf("                                            \n");
	printf("        TERIMAKASIH SUDAH MENGUNJUNGI        \n");
	printf("                  D'MEDICINE                 \n");
	printf("                                             \n");
	printf(" ____________________________________________\n");
	system("exit");
}
