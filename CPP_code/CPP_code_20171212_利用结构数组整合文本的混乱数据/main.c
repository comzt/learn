#include <stdio.h>
#include <stdlib.h>

struct man {
    int a;
    char fname[10];
    char lname[10];
    int b;
    float c;
    float d;
    float e;
};

int main()
{
    struct man temp1, temp2;
    long pos=0;
    int count=1, count2=0;
    FILE * pbook;

    if((pbook=fopen("ball.txt", "r+")) == NULL) {
        fputs("Can't open ball.txt file\n", stderr);
        exit(1);
    }
    for(int i=0; i<10; i++) {
        float  ca=0, da=0, ea=0;
        int ba=0, count3=0;
        count=count2+1;
        count2=1;
        printf("%d %d\n", count, count2);
        if(pos != 0) {
        rewind(pbook);
        fseek(pbook, pos, SEEK_SET);
        }
        if(fscanf(pbook, "%d %s %s %d %f %f %f", &temp1.a, &temp1.fname, &temp1.lname, &temp1.b, &temp1.c, &temp1.d, &temp1.e) != 7) {
            fputs("temp1 error", stderr);
            exit(2);
        }
        ba=temp1.b;
        ca=temp1.c;
        //puts(temp1.fname);
        while(fscanf(pbook, "%d %s %s %d %f %f %f", &temp2.a, &temp2.fname, &temp2.lname, &temp2.b, &temp2.c, &temp2.d, &temp2.e) == 7) {
            if(temp1.a == temp2.a) {
                printf("%d %.2f %.2f %.2f\n", temp2.b, temp2.c, temp2.d, temp2.e);
                ++count;
                ba+=temp2.b;
                ca+=temp2.c;
            } else if(count3 == 0) {
                count2=count;
                count3++;
            }
            printf("%d %d %d %d %d\n", sizeof(temp2.fname), sizeof(temp2.lname), sizeof(temp2.b), sizeof(temp2.c), sizeof(temp2.e));
        }
        printf("%d %d %d\n", count, count2, count3);
        printf("%d\n", pos=(long)count2*(sizeof(struct man)/2-1));
        printf("The %s is %.2f\n", temp1.fname, ca/ba);
        //break;
    }
    fclose(pbook);
    return 0;
}
