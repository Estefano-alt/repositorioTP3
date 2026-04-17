#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//CONSTANTES
#define CANT_NOM 5
#define MAX 30
//FUNCIONES
void mostrarPersonas(char *arre[], int longitud);
int buscarNombrePorPalabraClave(char *arre[], int longitud, char clave[]);
void buscarNombrePorID(char *arre[], int buscado);
int main(){
    char *arre_nombres[CANT_NOM];
    char nombre[MAX];
    int numero;
    int longitud;
    int retorno;
    for(int i=0; i<CANT_NOM; i++){
        printf("\nIngrese el nombre de la %d persona ",i+1);
        scanf("%s",nombre);
        longitud=strlen(nombre);
        arre_nombres[i]=malloc((longitud+1)*sizeof(char)); //Reservar espacio para caracter nulo
        strcpy(arre_nombres[i],nombre);
    }
    mostrarPersonas(arre_nombres,CANT_NOM);
    int opcion;
    printf("\nDesea encontrar una persona por ID o palabra clave (1_ID,2_Palabra clave) ");
    do{
        scanf("%d",&opcion);
        if(opcion!=1 && opcion!=2){
            printf("\nIngrese una opcion valida ");
        }
    }while(opcion!=1 && opcion!=2);
    
    if(opcion==1){
        printf("\nIngrese el ID de la persona a buscar(0-4): ");
        scanf("%d",&numero);
        if(numero>4 || numero<0){
            printf("\nNo se encontro la persona con ese ID");
        }
        else{
            buscarNombrePorID(arre_nombres,numero);
        }
    }
    else{
        char clave[MAX];
        printf("\nIngrese la palabra clave para encontrar su persona: ");
        scanf("%s",clave);
        retorno=buscarNombrePorPalabraClave(arre_nombres,CANT_NOM,clave);
        if(retorno==-1){
            printf("\nNo se encontro ninguna persona");
        }
        else{
            printf("\nPersona buscada: %s",arre_nombres[retorno]);
        }
    }
    return 0;
}

void mostrarPersonas(char *arre[], int longitud){
    for(int i=0; i<longitud; i++){
        printf("\n%s",arre[i]);
    }
}

int buscarNombrePorPalabraClave(char *arre[], int longitud, char clave[]){
    for(int i=0; i<longitud; i++){
        if(strstr(arre[i], clave)!=NULL){
            return i;
        }
    }
    return -1;
}

void buscarNombrePorID(char *arre[], int buscado){
    printf("\nPersona buscada: %s",arre[buscado]);
}