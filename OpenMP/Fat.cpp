#include <iostream>
#include <omp.h>

#define SIZE 1000
#define REP 100000

using namespace std;

long double fatorial(long x){
    long double fac = 1;
    long j;

        for (j = x; j > 1; j--) {
            fac = fac * j;
        }
    return fac;
}

int main() {
    long long i, k,p=0;

    omp_set_num_threads(16);
    #pragma omp parallel for
    for(k=0;k< REP; k++){
        for(i=1; i <= SIZE; i++) {
            fatorial(i);
        }
    }

    return 0;
}
