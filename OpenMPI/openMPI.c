#include <stdio.h>
#include <mpi.h>

#define SIZE 1200

long int fibonacci(long start, long end) {
    long int count = 0;
    long double antp, pen, aux;
    for (long int i = start; i <= end; i++) {
        antp = 0;
        pen = 1;
        for (long j = 1; j < SIZE; j++) {
            aux = pen;
            pen += antp;
            antp = aux;
        }
        count++;
    }
    return count;
}

int main(int argc, char **argv) {

    int size, rank;
    long int start, end;
    long int index = 0, allIndex = 0;
    long int VarFib = 0, allFib = 0;

    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    long REP = 15000000;

    long nuc = REP / size;
    long resto = REP % size;

    start = rank * nuc + 1;
    end = start + nuc - 1;

    
    if (rank < resto) {
        start += rank;
        end += rank + 1;
    } else {
        start += resto;
        end += resto;
    }

    VarFib = fibonacci(start, end);

    
    MPI_Reduce(&VarFib, &allFib, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

    // master
    if (rank == 0) {
        printf("Repeticoes Desejadas: %ld | Feitas: %ld \n", REP, allFib);
    }

    MPI_Finalize();

    return 0;
}
