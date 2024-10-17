#include <iostream>
#include <omp.h>

#define SIZE 900000000

using namespace std;

int main (){

    long *c = new long[SIZE];
    long i;

    c[0] = 107;

    #pragma omp parallel for
    for(i=1;i<SIZE;++i){
        c[i]= c[i] + 7355 * 3131;

    }
    delete [] c;


    return 0;
}
