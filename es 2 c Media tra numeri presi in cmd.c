#include <stdio.h>
#include <stdlib.h>
double totale = 0;
double somma (int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        double num = atof(argv[i]);
		totale += num;
    }
    return totale;
}

int main(int argc, char *argv[]) 
{
	double media = somma(argc, argv)/(argc - 1);
	printf("La media e' %f\n",media);
	
}
