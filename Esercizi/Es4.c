#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

typedef struct
{
    char nome[100];
    char cognome[100];
}persona_t;

persona_t salvaPersona()
{
    persona_t persona;
    printf("inserisci nome:\n");
    scanf("%s", persona.nome);
    printf("inserisci cognome:\n");
    scanf("%s", persona.cognome);
    return persona;
}
void minMaiu(char parola[100])
{
    for(int i = 0; i < strlen(parola); i++)
    {
        if(i == 0)
        {
            parola[i] = toupper(parola[i]);
        }
        else
        {
            parola[i] = tolower(parola[i]);
        }
    }
}
void maiuscolo(char parola[100])
{
    for(int i = 0; i < strlen(parola); i++)
    {
        parola[i] = toupper(parola[i]);
    }
}
int main()
{
    int pid;
    persona_t persona;
    FILE *file = fopen("es4.txt", "w+");
    pid = fork();
    if(pid == 0)
    {
        sleep(7);
        rewind(file);
        fscanf(file, "%s %s", persona.nome, persona.cognome);
        maiuscolo(persona.nome);
        maiuscolo(persona.cognome);
        printf("%s %s\n",persona.nome, persona.cognome);
        exit(1);
    }
    else
    {
        persona = salvaPersona();
        minMaiu(persona.nome);
        minMaiu(persona.cognome);
        fprintf(file,"%s %s", persona.nome, persona.cognome);
        fclose(file);
        remove("es4.txt");
        wait(&pid);
    }
    
    return 0;
}