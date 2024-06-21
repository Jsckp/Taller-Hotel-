#include <stdio.h>
#include "funcionest.h"
#include <string.h>

int nombresingresados=0;
void ingresarClientes( char clientes[][2][40], int tamanoclien){
    int i, cantidad;
    printf("Ingrese la cantidad de clientes que desea ingresar:\n ");
    scanf("%d", &cantidad);
    if (nombresingresados + cantidad > tamanoclien) {
        printf("Error: No hay suficiente espacio en la matriz para almacenar %d clientes.\n", cantidad);
        fflush(stdin);
        return;
    }
    for ( i = nombresingresados; i < nombresingresados + cantidad ; i++)
    {
        printf("Ingrese el nombre del cliente %d: \n", i+1);
        fflush(stdin);
        scanf("%s", &clientes[i][0]);
        printf("Ingrese la cedula del cliente %d: \n", i+1);
        scanf("%s", &clientes[i][1]);
        fflush(stdin);
        int existe = 0;
        for (int j = 0; j < nombresingresados; j++) {
            if (strcmp(clientes[j][1], clientes[i][1]) == 0) {
                existe = 1;
                break;
            }
        }
        if (existe) {
            printf("La cedula ya se ha ingresado anteriormente.\n");
            i--;
            fflush (stdin);
        }
    }
    nombresingresados+=2;
}

void buscarPorTamano(int *numHabitacion,char habitaciones[][3][40],double precios[]){
    char tipo[40];
    printf("Ingrese el tamano de habitacion que dese buscar: ");
    scanf("%s",tipo);
    printf("#\t\tTamano\t\tHotel\t\tPrecio\n");
    int encontrado=0;
    for (int i = 0; i < 9; i++)
    {
        if (strcmp(habitaciones[i][1],tipo)==0)
        {
            printf("%s\t\t%s\t\t%s\t\t%lf\n",habitaciones[i][0],habitaciones[i][1],habitaciones[i][2],precios[i]);
            encontrado=1;
        }
    } 
    if (!encontrado)
        {
            printf("No se encontro ese tipo de habitacion\n");
        }else {
        printf("Elija la habitacion que desea reservar: ");
        scanf("%d", numHabitacion);
        
        
    }
}

void buscarHotel(int *numHabitacion, char habitaciones[][3][40], double precios[]){
    char hotel[40];
    printf("Ingrese el nombre del hotel que desea buscar: ");
    scanf("%s",hotel);
    printf("#\t\tTamano\t\tHotel\t\tPrecio\n");
    int encontrado=0;
    for (int i = 0; i < 9; i++)
    {
        if (strcmp(habitaciones[i][2],hotel)==0)
        {
            printf("%s\t\t%s\t\t%s\t\t%lf\n",habitaciones[i][0], habitaciones[i][1], habitaciones [i][2], precios[i]);
            encontrado=1;
        }
    }
        if (!encontrado) 
        {
            printf("\nNo se encontro el hotel que deseas buscar\n");
        }else
        {
            printf("Elija la habitacion que desea reservar: ");
            scanf("%d",numHabitacion); 
        }
}
   
void realizarReserva(int numHabitacion, char habitaciones[9][3][40], char clientes[][2][40], int reservas[10][4], int tamanoclien) {
    int clienteIndex;
    char cedula[40];
    printf("Ingrese la cedula del cliente: ");
    scanf("%s", cedula);
    clienteIndex = -1;

    for (int i = 0; i < tamanoclien; i++) {
        if (strcmp(clientes[i][1], cedula) == 0) {
            clienteIndex = i;
            break;
        }
    }
    
    if (clienteIndex == -1) {
        printf("Cliente no encontrado.\n");
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (reservas[i][0] == numHabitacion && reservas[i][1] != -1) {
            printf("La habitacion %d ya esta reservada por otro cliente.\n", numHabitacion);
            return;
        }
    }

    for (int i = 0; i < 10; i++) {
        if (reservas[i][0] == -1) {
            reservas[i][0] = numHabitacion; 
            reservas[i][1] = clienteIndex; 
            reservas[i][2] = 0; 
            printf("Reserva realizada con exito para la habitacion %d.\n", numHabitacion);
            return;
        }
    }

    
    printf("No hay espacio para mas reservas.\n");
}


void buscarReservaPorCedula(int *numReserva, char clientes[][2][40], int reservas[10][4], int tamanoclien) {
    char cedula[40];
    int clienteIndex = -1;
    printf("Ingrese la cedula del cliente: ");
    scanf("%s", cedula);
    for (int i = 0; i < tamanoclien; i++) {
        if (strcmp(clientes[i][1], cedula) == 0) {
            clienteIndex = i;
            break;
        }
    }

    if (clienteIndex == -1) {
        printf("Cliente no encontrado.\n");
        *numReserva = -1;
        return;
    }


    for (int i = 0; i < 10; i++) {
        if (reservas[i][1] == clienteIndex) {
            *numReserva = i;
            return;
        }
    }

    printf("No se encontro ninguna reserva para el cliente con cedula %s.\n", cedula);
    *numReserva = -1;
}

void imprimirReserva(int numReserva, int reservas[10][4], char habitaciones[9][3][40], double precios[9], char clientes[][2][40], int tamanoclien) {
    if (numReserva == -1) {
        printf("No hay reservas para mostrar.\n");
        return;
    }

    int clienteIndex = reservas[numReserva][1];

    if (clienteIndex < 0 || clienteIndex >= tamanoclien) {
        printf("Cliente de reserva invalido.\n");
        return;
    }

    printf("Reservas para el cliente con cedula %s:\n", clientes[clienteIndex][1]);

    int encontrado = 0;
    for (int i = 0; i < 10; i++) {
        if (reservas[i][1] == clienteIndex) {
            int habitacionIndex = reservas[i][0] - 1; 

            if (habitacionIndex >= 0 && habitacionIndex < 9) {
                printf("Reserva #%d:\n", i + 1);
                printf("Habitacion: %s\n", habitaciones[habitacionIndex][0]);
                printf("Tipo: %s\n", habitaciones[habitacionIndex][1]);
                printf("Hotel: %s\n", habitaciones[habitacionIndex][2]);
                printf("Precio: %.2f\n", precios[habitacionIndex]);
                printf("Estado: %s\n", reservas[i][3] == 1 ? "Pagada" : "Pendiente");
                printf("\n");
                encontrado = 1;
            }
        }
    }

    if (!encontrado) {
        printf("No se encontraron reservas para este cliente.\n");
    }
}

void pagarReserva(int numReserva, int reservas[10][4], char habitaciones[9][3][40], double precios[9], char clientes[][2][40], int tamanoclien) {
    if (numReserva == -1) {
        printf("No hay reservas para pagar.\n");
        return;
    }

    int clienteIndex = reservas[numReserva][1];
    printf("Reservas pendientes para el cliente con cedula %s:\n", clientes[clienteIndex][1]);
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (reservas[i][1] == clienteIndex && reservas[i][3] == 0) {
            int habitacionIndex = reservas[i][0] - 1; 
            printf("%d. Habitacion %s - Precio: %.2f\n", count + 1, habitaciones[habitacionIndex][0], precios[habitacionIndex]);
            count++;
             fflush (stdin);
        }
    }

    if (count == 0) {
        printf("No hay reservas pendientes para pagar.\n");
        return;
    }

    int opcion;
    do {
        printf("Seleccione la reserva que desea pagar (1-%d): ", count);
        scanf("%d", &opcion);
        if (opcion < 1 || opcion > count) {
            printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion < 1 || opcion > count);

    int seleccion = 0;
    for (int i = 0; i < 10; i++) {
        if (reservas[i][1] == clienteIndex && reservas[i][3] == 0) {
            seleccion++;
            if (seleccion == opcion) {
                int habitacionIndex = reservas[i][0] - 1;
                double precio = precios[habitacionIndex];

                printf("El precio de la reserva seleccionada es de: %.2f\n", precio);

                printf("Ingrese el monto para pagar: ");
                double montoPagado;
                scanf("%lf", &montoPagado);

                if (montoPagado >= precio) {
                    reservas[i][3] = 1;
                    printf("Reserva pagada exitosamente. Su cambio es: %.2f\n", montoPagado - precio);
                } else {
                    printf("Monto insuficiente. Falta: %.2f\n", precio - montoPagado);
                    fflush (stdin);
                }
                return;
            }
        }
    }
}


//lo logramos tilin 
