#include<stdio.h>


void leggi (int *n1, int vett1[])
{ int i;

 do{
     printf("Quanti numeri vuoi inserire: \n");
     scanf("%d",n1);
    }while(*n1<=0);
    
 for(i=0;i<*n1;i++){
     printf("Inserisci il %d numero",(i+1));
     scanf("%d",&vett1[i]);
    }
  
}

float mini(int n1, int vett1[])
{ int i,min;
  min=vett1[0];
  for(i=0;i<n1;i++){
      if(min>vett1[i])
       min=vett1[i];
   }
    return min;
}   

float maxi(int n1, int vett1[])
{ int i,mas;
  mas=vett1[0];
  for(i=0;i<n1;i++){
      if(mas<vett1[i])
       mas=vett1[i];
   }
    return mas;
}   
      
int main()
{
  int n,vett[100];
  leggi(&n,vett);
  printf("Il minimo e': %f \n",mini(n,vett));
  printf("Il massimo e': %f \n",maxi(n,vett));
  //system("pause");
  return 0;
  
}