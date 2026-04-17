#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//CONSTANTES
#define CANT_NOM 5
#define MAX 30
//FUNCIONES
void mostrarPersonas(char *arre[], int longitud);
void buscarNombre(char *arre[], int buscado);
int main(){
    char *arre_nombres[CANT_NOM];
    char nombre[MAX];
    int numero;
    int longitud;
    for(int i=0; i<CANT_NOM; i++){
        printf("\nIngrese el nombre de la %d persona ",i+1);
        scanf("%s",nombre);
        longitud=strlen(nombre);
        arre_nombres[i]=malloc((longitud+1)*sizeof(char)); //Reservar espacio para caracter nulo
        strcpy(arre_nombres[i],nombre);
    }
    mostrarPersonas(arre_nombres,CANT_NOM);
        printf("\nIngrese un numero del 0-4 para encontrar a la persona ");
        scanf("%d",&numero);
        if(numero<0 || numero>4){
            printf("\nPersona no encontrada");
        }
        else{
            buscarNombre(arre_nombres,numero);
        }
    
    return 0;
}

void mostrarPersonas(char *arre[], int longitud){
    for(int i=0; i<longitud; i++){
        printf("\n%s",arre[i]);
    }
}

void buscarNombre(char *arre[], int buscado){
    printf("\nPersona buscada: %s",arre[buscado]);
}