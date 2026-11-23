#ifndef final.h
#define final.h

typedef struct mahasiswa_t {
    char nim[20];
    char nama[50];
    char prodi[50];
} Mahasiswa;

typedef struct matakuliah_t {
    char kode_mk[20];
    char nama_mk[50];
    int sks;
} Matakuliah;

typedef struct krs_t {
    char nim[20];
    char kode_mk[20];
} KRS;


#endif
