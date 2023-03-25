#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

bool search(char *buff, char *search_term, int cnt);

int main() { //int argc, char *argv[]
    // if (argc > 1) {
    //     int r = strtol(argv[1], NULL, 10), c = strtol(argv[2], NULL, 10);
    //     printf("%d, %d\n", r, c);
    //     char *mikasa[r];
    //     for(int i = 0; i < r; i++) {
    //         mikasa[i] = (char*)malloc(c*sizeof(char));
    //         mikasa[i] = argv[i + 3];
    //         if(i < (argc-3)) {
    //             printf("Mikasa(%d) %s\n", i, mikasa[i]);
    //         }
    //     }
    // } else {
    //     printf("%i", __LINE__);
    // }
    int cnt =0;
    FILE *fp;
    char search_term[30] = "int";
    char buff[255];

    // scanf("Term to search: %s", search_term);
    fp = fopen("touch.txt", "r");

    while(fgets(buff, 255, fp) != NULL) {
        // printf("%s\n", buff);
        search(buff, search_term, cnt);
    }
    if(feof(fp)) {
        printf("Putang\n");
    }
    fclose(fp);
    return 0;
}

bool search(char *buff, char *search_term, int cnt) {
    int word_cnt = 0;
    char word[20];
    printf("%s\n", buff);

    // search(buff, search_term, cnt);

    return false;
}
