#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double * linspace(double min, double max, double N);

double * zeros(int N);

double * initial_1(double delta_x=0.05);

double * initial_2(double delta_x=0.05);

int main (){


}

double * initial_1(double delta_x=0.05){
	double L = 4.0;
	double N = L/delta_x + 1.0;
	double * x = linspace(0.0, L, N);
	double * u =  zeros(N);
	int i;
	return * x;
}

double * initial_2(double delta_x=0.05){
	double L = 4.0;
	double N = L/delta_x + 1.0;
	double * x = linspace(0.0, L, N);
	double * u =  zeros(N);
	int i;
	for(i=0;i<N;i++){
		if(*(x + i) < 2.0){
			*(u+i) = 1.0;
		}
	}
	return * u;
}

double * linspace(double min, double max, double N){
	double delta = (max - min)/(N - 1.0);
	int i;
	double range[int(N)]; 
	for(i=0;i<N;i++){
		range[i] = (min + i*delta);
	}
	return range;
}

double * zeros(int N){
	double range[N];
	int i;
	for(i=0;i<N;i++){
		range[i] = 0.0
	}
	return range;
}
