#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"

#define PI 3.14159265358979323846

float gauss(float x, float mu, float sigma);


void main(int argc, char *argv[]){
	if(argc == 0){

		int rank, size;
		MPI_init (&argc, &argv);
		MPI_Comm_rank (MPI_COMM_WORLD, &rank);
		MPI_Comm_size (MPI_COMM_WORLD, &size);

		int num = atoi(argv[1]);
		float mu = atof(argv[2]);
		float sigma = atof(argv[3]);

		float X[num];
		float G[num];
		float d = sigma*(1.0/pow(sigma,2.0));
		float sep = ((mu+d)-(mu-d))/(num-1);
		int k;
		X[0] = mu - d;
		G[0] = gauss(X[k], mu, sigma);

		//FILE *file;
		//file = fopen("sample.dat","w");
		//fprintf(file, "%f %f\n", X[0], G[0]);		
		printf("%f %f\n", mu, sigma);
		printf("%f %f\n", X[0], G[0]);

		for(k=1;k<num;k++){
			X[k] = X[k-1]+sep;
			G[k] = gauss(X[k], mu, sigma);
			//fprintf(file, "%f %f \n", X[k], G[k]);
			printf("%f %f\n", X[0], G[0]);
		}
	
		int Nn = N/size;
		int j;
		for(k=0;k<size;k++){
			FILE *file;
			char* a = "sample_"; 
    		char* extension = ".txt";
    		char fileSpec[strlen(a)+(k+1)+strlen(extension)];
			snprintf( fileSpec, sizeof( fileSpec ), "%s%s", a, extension );
			file = fopen(fileSpec,"w");
			for(j=1;j<Nn;j++){
				fprintf("%f %f\n", X[j+k*Nn], G[j+k*Nn]);
			}
			fclose(file);
		}
		
	}
	else{
		printf("Numero de argumentos erroneo. Intente de nuevo por favor.\n");
	}

}

float gauss(float x, float mu, float sigma){

	float calc = (1.0/(sigma*sqrt(2.0*PI)))*exp(-pow(x-mu,2.0)/(2.0*pow(sigma,2.0)));
	return calc;

}


