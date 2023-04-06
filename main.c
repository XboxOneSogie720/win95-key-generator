#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int randomNumber(int upper, int lower);
void usage() {
    printf("Usage:\n\n-h, --help, -help - Displays the help\n-o, -oem - Generates a Windows 95 OEM Key\n-cd, -cdkey - Generates a Windows 95 CD Key\n");
}

int win95cdkey() {
    srand(time(0));
    int chunk1 = (rand() % (998 - 100 +1)) + 100;
    if(chunk1 == 333 || chunk1 == 444 || chunk1 == 555 || chunk1 == 666 || chunk1 == 777 || chunk1 == 888 || chunk1 == 999) {
        chunk1 = 635;
    }
    int chunk2[7];
    for(int i = 0; i <= 7; i++) {
        chunk2[i] = (rand() % (7 - 1 +1)) + 1;
    }

    while((chunk2[0] + chunk2[1] + chunk2[2] + chunk2[3] + chunk2[4] + chunk2[5] + chunk2[6]) % 7 !=  0) {
        printf("Brute Forcing...\n");
        printf("DEBUG\nchunk2[0]: %d\nchunk2[1]: %d\nchunk2[2]: %d\nchunk2[3]: %d\nchunk2[4]: %d\nchunk2[5]: %d\nchunk2[6]: %d\n",chunk2[0], chunk2[1], chunk2[2], chunk2[3], chunk2[4], chunk2[5], chunk2[6]);
        for(int i = 0; i <= 5; i++) {
            
            chunk2[i] = (rand() % (9 - 1 +1)) + 1;
        }
        chunk2[6] = (rand() % (7 - 1 +1)) + 1;
    }

    printf("FINAL DEBUG\nchunk2[0]: %d\nchunk2[1]: %d\nchunk2[2]: %d\nchunk2[3]: %d\nchunk2[4]: %d\nchunk2[5]: %d\nchunk2[6]: %d\n",chunk2[0], chunk2[1], chunk2[2], chunk2[3], chunk2[4], chunk2[5], chunk2[6]);
    printf("\nKey: %d-%d%d%d%d%d%d%d\n\nThanks for using my program!\n\n", chunk1, chunk2[0], chunk2[1], chunk2[2], chunk2[3], chunk2[4], chunk2[5], chunk2[6]);
}

int win95oem(){
    srand(time(NULL));
    int chunk1 = (rand() % (365 - 100 +1)) + 365;
    int chunk2 = (rand() % (99 - 95 +1)) + 95;
    /* there used to be a chunk3 here, was not needed so it was removed */
    int chunk4[6];
    for(int i = 0; i <= 4; i++) {
        chunk4[i] = 4;
    }
    chunk4[5] = 2;
    int chunk5 = (rand() % (99999 - 10000 +1)) + 10000;


    
    while((chunk4[0] + chunk4[1] + chunk4[2] + chunk4[3] + chunk4[4] + chunk4[5]) % 7 !=  0) {
        
        printf("Brute Forcing...\n");
        printf("DEBUG\nchunk4[0] = %d\nchunk4[1] = %d\nchunk4[2] = %d\nchunk4[3] = %d\nchunk4[4] = %d\nchunk4[5] = %d\n", chunk4[0], chunk4[1], chunk4[2], chunk4[3], chunk4[4], chunk4[5]);
        for(int i = 0; i<= 5; i++) {
            chunk4[i] = (rand() % (9 - 1 +1)) + 1;
        }
        chunk4[5] = (rand() % (7 - 1 +1)) + 1;
        
    }

    printf("FINAL DEBUG\nchunk4[0] = %d\nchunk4[1] = %d\nchunk4[2] = %d\nchunk4[3] = %d\nchunk4[4] = %d\nchunk4[5] = %d\n\n", chunk4[0], chunk4[1], chunk4[2], chunk4[3], chunk4[4], chunk4[5]);
    printf("Key: %d%d-OEM-0%d%d%d%d%d%d-%d\n\nThanks for using my program!\n\n\n", chunk1, chunk2, chunk4[0], chunk4[1], chunk4[2], chunk4[3], chunk4[4], chunk4[5], chunk5);
    return 0;
}

int randomNumber(int upper, int lower) {
    int seed;
    int randomm, finalValue;
        srand(time(NULL));
        randomm = rand();
        finalValue = (randomm % (upper - lower +1) ) + lower;
    return finalValue;
}


int main(int argc, char *argv[]) {
    if(argc >= 3){
        printf("Too many arguments. Try again.\n");
        return 0;
    } else if(argc < 2) {
        usage();
    }

    if(strcasecmp(argv[1], "--help") == 0 || strcasecmp(argv[1], "-help") == 0 || strcasecmp(argv[1], "-h") == 0 ) {
        usage();
        return 0;
    }
    else if(strcasecmp(argv[1], "-o") == 0 || strcasecmp(argv[1], "-oem") == 0) {
        win95oem();
    }
    else if(strcasecmp(argv[1], "-cd") == 0 || strcasecmp(argv[1], "-cdkey") == 0) {
        win95cdkey();
    }
    else {
    printf("Too few / incorrect arguments supplied. Please try again.\n");
    }
    return 0;
}

