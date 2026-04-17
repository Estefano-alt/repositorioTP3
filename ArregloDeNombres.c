#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//CONSTANTES
#define CANT_NOM 5
#define MAX 30
//FUNCIONES
void mostrarPersonas(char *arre[], int longitud);
int main(){
    char *arre_nombres[CANT_NOM];
    char nombre[MAX];
    int longitud;
    for(int i=0; i<CANT_NOM; i++){
        printf("\nIngrese el nombre de la %d persona ",i+1);
        scanf("%s",nombre);
        longitud=strlen(nombre);
        arre_nombres[i]=malloc((longitud+1)*sizeof(char)); //Reservar espacio para caracter nulo
        strcpy(arre_nombres[i],nombre);
    }
    mostrarPersonas(arre_nombres,CANT_NOM);
    return 0;
}

void mostrarPersonas(char *arre[], int longitud){
    for(int i=0; i<longitud; i++){
        printf("\n%s",arre[i]);
    }
}