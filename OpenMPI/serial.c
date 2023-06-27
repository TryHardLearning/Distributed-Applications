#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

#define REP 2

int main (){
    long i,j;
    long double antp , pen = 1 , aux;

    for(i=0;i<REP;i++){
        antp = 0;
        pen = 1;
        for(j=1;j<SIZE;j++){
            aux = pen;
            pen += antp;
            antp = aux;
            printf("%llf\n",pen);
        }
    }
    return 0;
}
