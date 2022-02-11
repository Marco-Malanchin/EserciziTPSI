#include <stdio.h>

int a,b;
int somma(int, int);
valori()
{
     while(a == 0)
     {
         printf("Inserisci il primo valore");
         scanf("%d",&a);
         if (a == 0)
         {
         	system("cls");
		 	printf("erorre il numero non puo' essere 0 \n");
		 }
     }
     while (b == 0)
     {
         printf("Inserisci il secondo valore");
         scanf("%d",&b);
         if (b == 0)
         {
         	system("cls");
		 	printf("erorre il numero non puo' essere 0 \n");
		 }
     }
}

int somma(int a, int b)
{
    int somma =  a + b;
    return somma;
}

main()
{
    valori();
    system("cls");
    printf("La somma tra i due numeri e': %d",somma(a, b));

}
