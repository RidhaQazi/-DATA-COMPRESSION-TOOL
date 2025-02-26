#include <stdio.h>
#include <stdlib.h>

void compress(const char*, const char*);
void decompress(const char*, const char*);

int main() {
    int choice;
    char inputFile[100], outputFile[100];

    while (1) {
        printf("\n Run-Length Encoding Compression Tool \n");
        printf("1. Compress a file \n");
        printf("2. Decompress a file \n");
        printf("3. Exit \n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                    printf("\n Input File Name (.txt) : ");
                    scanf("%s", inputFile);
                    printf("\n Output File Name (.txt) : ");
                    scanf("%s", outputFile);
                    compress(inputFile, outputFile);
                    break;
            case 2:
                    printf("\n Input File Name (.txt) : ");
                    scanf("%s", inputFile);
                    printf("\n Output File Name (.txt) : ");
                    scanf("%s", outputFile);
                    decompress(inputFile, outputFile);
                    break;
            case 3:
                    printf("\n Exiting...\n");
                    return 0;
            default:
                    printf("\n Invalid Option selected! Try Again! \n");

        }
    }
}


void compress(const char *inputFile, const char *outputFile) { //compression

    FILE *input = fopen(inputFile, "r");
    if (input == NULL) {
        printf("\n Error! Can't open %s file \n", inputFile);
        return;
    }

    fseek(input, 0, SEEK_END);
    if (ftell(input) == 0) {
        printf("\n Error %s file is Empty! \n", inputFile);
        fclose(input);
        return;
    }
    rewind(input);

    FILE *output = fopen(outputFile, "w");
    if (output == NULL) {
        printf("\n Error! Can't open %s file \n", outputFile);
        fclose(input);
        return;
    }

    char ch, prev;
    int count = 1;

    prev = fgetc(input);
    while ((ch = fgetc(input)) != EOF) {
        if (ch == prev) {
            count++;
        } 
        else {
            fprintf(output, "%d|%c,", count, prev);
            prev = ch;
            count = 1;
        }
    }
    fprintf(output, "%d|%c", count, prev);
    

    fclose(input);
    fclose(output);
    printf("\n RLE compression applied to %s file and output saved in %s file \n", inputFile, outputFile);

}


void decompress(const char *inputFile, const char *outputFile) {   //decompression

    FILE *input = fopen(inputFile, "r");
    if (input == NULL) {
        printf("\n Error! Can't open %s file \n", inputFile);
        return;
    }

    fseek(input, 0, SEEK_END);
    if (ftell(input) == 0) {
        printf("\n Error %s file is Empty! \n", inputFile);
        fclose(input);
        return;
    }
    rewind(input);

    FILE *output = fopen(outputFile, "w");
    if (output == NULL) {
        printf("\n Error! Can't open %s file \n", outputFile);
        fclose(input);
        return;
    }

    int count;
    char ch;

    while (fscanf(input, "%d|%c,", &count, &ch) == 2 || fscanf(input, "%d|%c", &count, &ch) == 2) {
        for (int i = 0; i< count; i++) {
            fputc(ch, output);
        }
    }

    fclose(input);
    fclose(output);
    printf("\n RLE decompression applied to %s file and output saved in %s file \n", inputFile, outputFile); 
}