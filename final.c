#include <stdio.h>
#include <stdlib.h>
#include "final.h"
//pengelolaan data mahasiswa, mata kuliah, dan KRS menggunakan array
int jumlah_mahasiswa = 0;
int jumlah_matakuliah = 0;
int jumlah_krs = 0;

#define MAX 100 //membatasi jumlah data yang bisa diinput

Mahasiswa mahasiswa[MAX];
Matakuliah matakuliah[MAX];
KRS krs[MAX];

void input_mahasiswa() { //mengambil input data mahasiswa dari pengguna dan menyimpannya ke dalam array mahasiswa
    printf("    INPUT DATA MAHASISWA     \n");
    printf("Masukkan NIM: ");
    scanf("%19s", mahasiswa[jumlah_mahasiswa].nim); //mengambil input NIM mahasiswa, mahasiswa[jumlah_mahasiswa] mengacu pada indeks terakhir dari array mahasiswa
    printf("Masukkan Nama: ");
    scanf(" %49[^\n]", mahasiswa[jumlah_mahasiswa].nama); //mengambil input nama mahasiswa
    printf("Masukkan Program Studi: ");
    scanf(" %49[^\n]", mahasiswa[jumlah_mahasiswa].prodi); //mengambil input program studi mahasiswa
    jumlah_mahasiswa++; //menambahkan jumlah mahasiswa
    if (jumlah_mahasiswa >= MAX) {
        printf("Jumlah mahasiswa sudah mencapai batas\n");
    }
    FILE *file = fopen("mahasiswa.txt", "a"); //membuka file
    if (file != NULL) {
        fprintf(file, "NIM: %s\n", mahasiswa[jumlah_mahasiswa - 1].nim); //menampikan file
        fprintf(file, "Nama: %s\n", mahasiswa[jumlah_mahasiswa - 1].nama); //menampilkan file
        fprintf(file, "Program Studi: %s\n", mahasiswa[jumlah_mahasiswa - 1].prodi); //menampilkan file
        fclose(file); //menutup file
    } else {
        printf("Ada kesalahan dalam file mahasiswa.txt\n");
    }
}

void input_matakuliah() {
    printf("    INPUT DATA MATAKULIAH     \n");
    printf("Masukkan Kode Mata Kuliah: ");
    scanf("%19s", matakuliah[jumlah_matakuliah].kode_mk);
    printf("Masukkan Nama Mata Kuliah: ");
    scanf(" %49[^\n]", matakuliah[jumlah_matakuliah].nama_mk);
    printf("Masukkan SKS: ");
    scanf("%d", &matakuliah[jumlah_matakuliah].sks);
    jumlah_matakuliah++;
    if (jumlah_matakuliah >= MAX) {
        printf("Jumlah mata kuliah sudah mencapai batas\n");
    }
    FILE *file = fopen("matakuliah.txt", "a");
    if (file != NULL) {
        fprintf(file, "Kode Mata Kuliah: %s\n", matakuliah[jumlah_matakuliah - 1].kode_mk);
        fprintf(file, "Nama Mata Kuliah: %s\n", matakuliah[jumlah_matakuliah - 1].nama_mk);
        fprintf(file, "SKS: %d\n", matakuliah[jumlah_matakuliah - 1].sks);
        fclose(file);
    } else {
        printf("Ada kesalahan dalam file matakuliah.txt\n");
    }
}

void input_krs() {
    printf("    INPUT DATA KRS     \n");
    printf("Masukkan NIM Mahasiswa: ");
    scanf("%19s", krs[jumlah_krs].nim);
    printf("Masukkan Kode Mata Kuliah: ");
    scanf("%19s", krs[jumlah_krs].kode_mk);
    jumlah_krs++;
    if (jumlah_krs >= MAX) {
        printf("Jumlah KRS sudah mencapai batas\n");
    }
    FILE *file = fopen("krs.txt", "a");
    if (file != NULL) {
        fprintf(file, "NIM: %s\n", krs[jumlah_krs - 1].nim);
        fprintf(file, "Kode Mata Kuliah: %s\n", krs[jumlah_krs - 1].kode_mk);
        fclose(file);
    } else {
        printf("Ada kesalahan dalam file krs.txt\n");
    }
}

void data_mhs() { //menampilkan data mahasiswa
    printf("     DATA MAHASISWA     \n");
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        printf("Nama: %s\n", mahasiswa[i].nama);
        printf("NIM: %s\n", mahasiswa[i].nim);
        printf("Program Studi: %s\n", mahasiswa[i].prodi);
    }
}

void data_mk() { //menampilkan data mata kuliah
    printf("     DATA MATA KULIAH     \n");
    for (int i = 0; i < jumlah_matakuliah; i++) {
        printf("Kode Mata Kuliah: %s\n", matakuliah[i].kode_mk);
        printf("Nama Mata Kuliah: %s\n", matakuliah[i].nama_mk);
        printf("SKS: %d\n", matakuliah[i].sks);
    }
}

void data_krs() { //menampilkan data krs
    printf("     DATA KRS     \n");
    for (int i = 0; i < jumlah_krs; i++) {
        printf("NIM: %s\n", krs[i].nim);
        printf("Kode Mata Kuliah: %s\n", krs[i].kode_mk);
    }
}

int main() { //menu utama
    int choice;
    do { //loop do while agar menu terus muncul sampai user memilih exit
        printf("\n   MENU   \n");
        printf("1. Input Data Mahasiswa\n");
        printf("2. Input Data Mata Kuliah\n");
        printf("3. Input Data KRS\n");
        printf("4. Tampilkan Data Mahasiswa\n");
        printf("5. Tampilkan Data Mata Kuliah\n");
        printf("6. Tampilkan Data KRS\n");
        printf("7. Exit\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);
        switch (choice) { //switch case untuk memilih menu
            case 1:
                input_mahasiswa();
                break;
            case 2:
                input_matakuliah();
                break;
            case 3:
                input_krs();
                break;
            case 4:
                data_mhs();
                break;
            case 5:
                data_mk();
                break;
            case 6:
                data_krs();
                break;
            case 7:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (choice != 7);
    return 0;
}