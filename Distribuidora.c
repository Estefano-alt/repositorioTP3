#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//CONSTANTES
#define MAX 20

//ARREGLOS
char *TiposProductos[] = {
    "Galletas",
    "Snack",
    "Cigarrillos",
    "Caramelos",
    "Bebidas"
};

//ESTRUCTURAS
typedef struct
{
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
}Producto;

typedef struct
{
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *productos;
}Cliente;

//FUNCIONES
void cargarClientes(Cliente *cliente, int cantidad);
void cargarProductos(Producto *productos,int cantidad);
void mostrarClientes(Cliente *cliente, int cantidad);
float costoTotalProducto(Producto *p);
void liberarMemoria(Cliente *cliente, int cantidad);

int main(){

    srand(time(NULL));

    int cantidad_clientes;
    Cliente *clientes;

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d",&cantidad_clientes);

    clientes = malloc(cantidad_clientes * sizeof(Cliente));

    cargarClientes(clientes, cantidad_clientes);

    mostrarClientes(clientes, cantidad_clientes);

    liberarMemoria(clientes,cantidad_clientes);
    return 0;
}

void cargarProductos(Producto *productos,int cantidad){

    int aleatorio;

    for(int i=0; i<cantidad; i++){

        productos[i].ProductoID = i;
        productos[i].Cantidad = 1 + rand() % 10;

        aleatorio = rand() % 5;
        productos[i].TipoProducto = TiposProductos[aleatorio];

        productos[i].PrecioUnitario =
        10.0f + ((float)rand()/RAND_MAX) * (100.0f - 10.0f);
    }
}

void cargarClientes(Cliente *cliente, int cantidad){

    char nombre[MAX];

    for(int i=0; i<cantidad; i++){

        cliente[i].ClienteID = i;

        printf("\nIngrese el nombre del cliente %d: ", i+1);
        scanf("%s", nombre);

        cliente[i].NombreCliente =
        malloc(strlen(nombre) + 1);

        strcpy(cliente[i].NombreCliente, nombre);

        cliente[i].CantidadProductosAPedir =
        1 + rand() % 5;

        cliente[i].productos =
        malloc(cliente[i].CantidadProductosAPedir *
        sizeof(Producto));

        cargarProductos(cliente[i].productos,
        cliente[i].CantidadProductosAPedir);
    }
}

void mostrarClientes(Cliente *cliente, int cantidad){

    float total_producto;
    float total_cliente;

    for(int i=0; i<cantidad; i++){

        printf("\n\n====== CLIENTE %d ======", i+1);
        printf("\nID Cliente: %d", cliente[i].ClienteID);
        printf("\nNombre: %s", cliente[i].NombreCliente);
        printf("\nCantidad de productos pedidos: %d",
        cliente[i].CantidadProductosAPedir);

        total_cliente = 0.0;

        for(int j=0; j<cliente[i].CantidadProductosAPedir; j++){

            total_producto =
            costoTotalProducto(
            &cliente[i].productos[j]);

            printf("\n\n--- Producto %d ---", j+1);
            printf("\nID Producto: %d",
            cliente[i].productos[j].ProductoID);

            printf("\nTipo: %s",
            cliente[i].productos[j].TipoProducto);

            printf("\nCantidad: %d",
            cliente[i].productos[j].Cantidad);

            printf("\nPrecio Unitario: %.2f",
            cliente[i].productos[j].PrecioUnitario);

            printf("\nCosto Total Producto: %.2f",
            total_producto);

            total_cliente += total_producto;
        }

        printf("\n\nTOTAL A PAGAR CLIENTE: %.2f",
        total_cliente);
    }
}

float costoTotalProducto(Producto *p){

    return p->Cantidad * p->PrecioUnitario;
}

void liberarMemoria(Cliente *cliente, int cantidad){
    for(int i=0; i<cantidad; i++){
        free(cliente[i].productos);
        free(cliente[i].NombreCliente);
    }
    free(cliente);
    printf("\n=====Memoria Liberada=====");
}