#include <stdlib.h>
#include <stdio.h>
#include <math>

int main(int argc, char *argv[]){

	int size, rank;
	
	/*Iniciar*/
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_COMM_rank(MPI_COMM_WORLD, &rank);

	int num_p = N/size;
	int N = argv[1];
	int i;
	double f[num_p];
	double res;
	double res_final;

	

	for(i=0, i<num_p, i++){
		double x = (double)rand() / (double)RAND_MAX;
		f[i] = exp(x);
		res += f[i];
	}

	res = res / (double)num_p;

	MPI_Reduce(&res, &res_final, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

	if(rank == 0){
		printf("El valor de la integral es de: %.10f", res_final/rank);
	}
	
	MPI_Finalize();

}
