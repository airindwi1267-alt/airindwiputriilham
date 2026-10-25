#include <stdio.h>

#define BARIS 3
#define KOLOM 3

void inisialisasiPapan(char (*papan)[KOLOM]) {
    int i, j;

    for (i = 0; i < BARIS; i++) {
        for (j = 0; j < KOLOM; j++) {
            *(*(papan + i) + j) = ' ';
        }
    }
}

void tampilkanPapan(char (*papan)[KOLOM]) {
    int i;

    printf("\n");

    for (i = 0; i < BARIS; i++) {
        printf(" %c | %c | %c \n", 
               *(*(papan + i) + 0), 
                *(*(papan + i) + 1),
                *(*(papan + i) + 2));

        if (i < BARIS - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int cekMenang(char (*papan)[KOLOM], char pemain) {
    int i;

    for (i = 0; i < BARIS; i++) {
        if (*(*(papan + i) + 0) == pemain && 
            *(*(papan + i) + 1) == pemain && 
            *(*(papan + i) + 2) == pemain) {
            return 1;
        }
    }

    for (i = 0; i < 3; i++) {
        if (*(*(papan + 0) + i) == pemain && 
            *(*(papan + 1) + i) == pemain && 
            *(*(papan + 2) + i) == pemain) {
            return 1;
        }
    }

    if ((*(*(papan + 0) + 0) == pemain && 
         *(*(papan + 1) + 1) == pemain && 
         *(*(papan + 2) + 2) == pemain)) {
        return 1;
    }

    if (*(*(papan + 0) + 2) == pemain && 
         *(*(papan + 1) + 1) == pemain && 
         *(*(papan + 2) + 0) == pemain) {
        return 1;
    }

    return 0;
}

int papanPenuh(char (*papan)[KOLOM]) {
    int i, j;

    for (i = 0; i < BARIS; i++) {
        for (j = 0; j < KOLOM; j++) {
            if (*(*(papan + i) + j) == ' ') {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    char papan[BARIS][KOLOM];
    char pemain = 'X';
    int pilihan;
    int baris, kolom;

    inisialisasiPapan(papan);

    printf("==== Permainan Tic Tac Toe ===\n");
    printf("Pemain X dan O bergantian.\n");
    printf("Masukkan angka 1 sampai 9.\n");

    while (1) {
        tampilkanPapan(papan);

        printf("Giliran %c. pilih kotak: ", pemain);
        scanf("%d", &pilihan);

        if (pilihan < 1 || pilihan > 9) {
            printf("Pilihan harus 1 sampai 9.\n");
            continue;
        }

        baris = (pilihan - 1) / KOLOM;
        kolom = (pilihan - 1) % KOLOM;

        if (*(*(papan + baris) + kolom) != ' ') {
            printf("Kotak sudah terisi.\n");
            continue;
        }

        *(*(papan + baris) + kolom) = pemain;

        if (cekMenang(papan, pemain)) {
            tampilkanPapan(papan);
            printf("Permainan %c MENANG!\n", pemain);
            break;
        }

        if (papanPenuh(papan)) {
            tampilkanPapan(papan);
            printf("Permainan SERI!\n");
            break;
        }

        pemain = (pemain == 'X') ? 'O' : 'X';
    }

    return 0;
}