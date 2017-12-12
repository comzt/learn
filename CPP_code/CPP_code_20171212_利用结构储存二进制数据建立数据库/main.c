#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test1a.h"
#define MAXTITL  40
#define MAXAUTL 40
#define MAXBKS 10

char * s_gets(char * st, int n);
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(int argc, char * argv[])
{
    struct book library[MAXBKS];
    int count=0;
    int index, filecount;
    FILE * pbooks;
    int size=sizeof(struct book);

    if((pbooks=fopen("book.dat", "a+b")) == NULL) {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }
    rewind(pbooks);
    while(count<MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
        if(count == 0) puts("Current contents of book.dat");
        printf("%s by %s:$%.2f\n", library[count].title, library[count].author, library[count].value);
        count++;
    }
    filecount=count;
    puts("");
    for(int n=0; n<count-1; n++) {
        for(int m=1; m<count-n; m++) {
            struct book temp;
            if(strcmp(library[n].title, library[m+n].title)>0) {
                temp=library[n];
                library[n]=library[m+n];
                library[m+n]=temp;
            }
        }
        printf("%s by %s:$%.2f\n", library[n].title, library[n].author, library[n].value);
    }
    printf("%s by %s:$%.2f\n", library[count-1].title, library[count-1].author, library[count-1].value);
    puts("");
    for(int n=0; n<count-1; n++) {
        for(int m=1; m<count-n; m++) {
            struct book temp;
            if(library[n].value>library[n+m].value) {
                temp=library[n];
                library[n]=library[m+n];
                library[m+n]=temp;
            }
        }
        printf("%s by %s:$%.2f\n", library[n].title, library[n].author, library[n].value);
    }
    printf("%s by %s:$%.2f\n", library[count-1].title, library[count-1].author, library[count-1].value);
    puts("");

    if(count == MAXBKS) {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }
    puts("Please add new book titles.");
    puts("Please [enter] at the start of a line to stop.");
    while(count<MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0') {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count++].value);
        while(getchar() != '\n') continue;
        if(count<MAXBKS) puts("Enter the next title.");
    }

    if(count>0) {
        puts("Here is the list of your books:");
        for(index=0; index<count; index++) {
            printf("%s by %s:$%.2f\n", library[index].title, library[index].author, library[index].value);
        }
        fwrite(&library[filecount], size, count-filecount, pbooks);
    } else puts("No books? Too bad.\n");
    puts("Bye.\n");
    fclose(pbooks);
    return 0;
}


