#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void main(int argc, char *argv[]){
	char *archivo = argv[1];
	char *cuenta = argv[2];
	char *tiempo = argv[3];
	char str;
	int c;
	int n1;
	int n12;
	int n123;
	int n1234;
	int value;
	int array[100000000];
	int count = 0;
 

	FILE *file1;
	file1 = fopen(archivo,"r");
	//while(!feof(file1)){
    //    fscanf(file1, "%ls", &array[count]);
    //    count++;
    //}

	while((c = getc(file1))!=EOF){
    	printf("%d",c);
		putchar(c);
		str = getchar();
	}
	printf("%c",c);

}
