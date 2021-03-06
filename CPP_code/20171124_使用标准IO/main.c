#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int ch;
    FILE * fp;
    unsigned long count=0;
    /*if(argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }*/
    char fs[20];
    printf("Please enter filename:\n");
    gets(fs);
    if((fp=fopen(fs, "r")) == NULL) {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while((ch=getc(fp)) != EOF) {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("\nFile %s has %lu characters\n", argv[1], count);
    return 0;
}
