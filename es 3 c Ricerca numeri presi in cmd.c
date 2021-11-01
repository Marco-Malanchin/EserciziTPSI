#include <stdio.h>
#include <stdlib.h>
int numeroDaCercare;
int ricerca(int argc, char *argv[],int numeroDaCercare)
{
	for (int i = 1; i < argc; i++)
	{
		if(numeroDaCercare == atoi(argv[i]))
		{
			printf("numero trovato in posizione: %d", i);
			return 0;
		}
	}	
	printf("Numero non presente");
			return -1;
}
int main(int argc, char *argv[]) {
	printf("Quale numero vuoi cercare?");
	scanf("%d", &numeroDaCercare);
	ricerca(argc, argv, numeroDaCercare);
}
