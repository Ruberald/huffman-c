#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define LETTERS 26

void read_file(char * file_name, int * freq) {
    FILE * fp;

    fp = fopen(file_name, "r");

    if (!fp) {
        perror("Can't open file!");
    }

    char ch;
    while((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch)) freq[ch - 'a']++;
    }

    fclose(fp);
}

int main(int argc, char ** argv) {

    int freq[LETTERS];
    memset(freq, 0, sizeof freq);

    if (argc != 2) {
        printf("USAGE: ./main [file]");
        exit(EXIT_FAILURE);
    }

    read_file(argv[1], freq);

    printf("Letters with their frequencies -\n");
    for (int i = 0; i < LETTERS; i++) {
        printf("%c : %d\n", i+('a'), freq[i]);
    }

    return 0;
}
