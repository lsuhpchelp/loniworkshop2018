#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"


int main(int argc, char ** argv)
{
    int pid, p, root = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    int n=13;
    int my_start=0,my_end=0;
    int base_size,extra_size,my_size,remainder;

    base_size = n/p;
    extra_size=base_size+1;
    remainder = n%p;

    //FIXME, complete the if-else so that each process get roughly the same load:
    if ( pid < remainder ) {
        my_size = ;
        my_start = ;
        my_end   = ;
    }
    else {
        my_size = ;
        my_start = ;
        my_end   = ;
    }

    printf("pid:%d,\tmy_start=%d,\tmy_size=%d,\tmy_end=%d\n",pid,my_start,my_size,my_end);

    MPI_Finalize();
    return 0;
}
