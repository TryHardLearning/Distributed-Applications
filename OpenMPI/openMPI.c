#include <stdio.h>
#include <mpi.h>

#define REP 100000000
#define SIZE 1000

long int fibonacci (long start, long end){
    long int i;        
    long double antp, pen , aux;
    for(i = start; i <= end;i++){
        antp = 0;
        pen = 1;
        for(j=1;j<SIZE;j++){
            aux = pen;
            pen += antp;
            antp = aux;
        }
    }
    return (i - start);
}

int main(int argc, char **argv)
{

    /*long double sum = 0, accum = 0;*/
    int size, rank;
    long int start, end;
    long int index=0, allIndex=0;   

    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    start = REP * rank / size + 1;
    end = REP * (rank + 1) / size;
   

    // slaves
    if (rank != 0){
        prinf("Core %d | Inicio: %ld | Fim: %ld\n",&rank,start,end)
        long int fib = fibonacci(start,end)
        //Variavel Enviada - tamanho - tipo - processo de destino - tag - comunicardor
        MPI_Send(&fib, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD);
    }
    // master
    else{
        for (long j = 1; j < size; j++){
            //Variavel recebida - tamanho - tipo - processo de origem - tag - comunicardor - status-de-erro
            MPI_Recv(&index, 1, MPI_LONG_DOUBLE, j, 1, MPI_COMM_WORLD, &status);
            allIndex += index;
        }
    }

    // master
    if (rank == 0){
        printf("Repetiçoes Desejadas %ld | Feitas %ld\n",REP, allIndex);
    }

    MPI_Finalize();

    return 0;
}