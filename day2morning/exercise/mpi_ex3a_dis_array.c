#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

#define N 6

int main(int argc, char ** argv)
{
    int rank, psize, root = 0;
    int i,*x,*xl;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &psize);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank==root) {

        MPI_Datatype vct;
        //TODO: complete the following user defined type
        MPI_Type_vector( , , ,MPI_INT,&vct);
        MPI_Type_commit(&vct);

        x = (int*)malloc(N*psize*sizeof(int));
        for (i=0;i<N*psize;i++)
            x[i]=i;
        for (i=0;i<psize;i++)
            //TODO: complete the following MPI_Send call
            MPI_Send( , , , ,0,MPI_COMM_WORLD);
        MPI_Type_free(&vct);
    }

    xl=(int*)malloc(N*sizeof(int));


    //TODO:an MPI_Recv is need here to receive the local copy
    MPI_Recv( , , ,root,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

    for (i=0;i<N;i++)
        printf("%d,%d\t",rank,xl[i]);
    printf("\n");

    if (rank==root)
        free(x);

    free(xl);

    MPI_Finalize();
    return 0;
}
