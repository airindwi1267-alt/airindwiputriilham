#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *nama1 = "Ade" ;
    char *nama2 = "Kaka" ;

    if (argc < 3) {
        printf("Argumen program kurang!\n");
        printf("Gunakan seperti ini: \n");
        printf("%s <nama_pertama> <nama_kedua>\n", argv[0]);
        printf("Contoh: \n");
        printf("%s Budi Siti\n", argv[0]);
        return -1;
    }

    printf("hello, %s!\n", argv[1]);
    printf("hello juga %s\n", argv[2]);

    printf("\nNama bawaaan dari program:\n");
    printf("nama1 = %s\n", nama1);
    printf("nama2 = %s\n", nama2);

    
    return 0;
}