#include <stdio.h>
#include <mpi.h>

#define REP 100000000.0

int main(int argc, char **argv)
{

    long double sum = 0, accum = 0;
    int size, rank;
    long start, end;

    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    start = REP * rank / size + 1;
    end = REP * (rank + 1) / size;
    /*
    for (long i = start; i <= end; i++){
        sum = sum + i;
    }
    */
    
    for(long i = start; i <= end;i++){
        antp = 0;
        pen = 1;
        for(j=1;j<SIZE;j++){
            aux = pen;
            pen += antp;
            antp = aux;
        }
    }

    // slaves
    if (rank != 0)
    {
        //Variavel Enviada - tamanho - tipo - processo de destino - tag - comunicardor
        MPI_Send(&sum, 1, MPI_LONG_DOUBLE, 0, 1, MPI_COMM_WORLD);
    }
    else // master
    {
        for (long j = 1; j < size; j++)
        {
            //Variavel recebida - tamanho - tipo - processo de origem - tag - comunicardor - status-de-erro
            MPI_Recv(&accum, 1, MPI_LONG_DOUBLE, j, 1, MPI_COMM_WORLD, &status);
            sum = sum + accum;
        }
    }

    // master
    if (rank == 0)
        printf("Soma dos numeros ... : %llf\n", sum);

    MPI_Finalize();

    return 0;
}
