#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

#define M 3

int main(int argc, char ** argv)
{
    int rank, psize, root = 0;
    int i,j;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &psize);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    float a[M][M];

    if (rank==root){
        int idx=0;
        for (i=0;i<M;i++)
            for (j=0;j<M;j++)
                a[i][j]=++idx;
    }

    MPI_Datatype one_col,sub_mat_tran;  
    MPI_Aint lb,ext_float;          
    MPI_Type_vector(M,1,M,MPI_FLOAT,&one_col);
    MPI_Type_get_extent(MPI_FLOAT,&lb,&ext_float);
    MPI_Type_create_hvector(M,1,ext_float,one_col,&sub_mat_tran);
    // only need to commit the last type
    MPI_Type_commit(&sub_mat_tran); 

    if (rank==0)
        MPI_Send(a,M*M,MPI_FLOAT,1,0,MPI_COMM_WORLD);
    else //rank==1
        MPI_Recv(a,1,sub_mat_tran,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

    printf("rank=%d\n",rank);
    for (i=0;i<M;i++) {
        for (j=0;j<M;j++)
            printf("%4.1f\t",a[i][j]);
        printf("\n");
    }

    MPI_Type_free(&sub_mat_tran);
    MPI_Finalize();
    return 0;
}
