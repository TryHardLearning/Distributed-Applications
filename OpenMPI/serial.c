#include <stdio.h>

#define SIZE 300

#define REP 1

int main (void){
    long i,j;
    long double antp , pen = 1 , aux;

    for(i=0;i<REP;i++){
        antp = 0;
        pen = 1;
        for(j=1;j<SIZE;j++){
            aux = pen;
            pen += antp;
            antp = aux;
        }
    }

}
