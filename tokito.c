#include <stdio.h>
#include "funcionest.h"

int tamanoclien=30;
int main (int argc, char *argv[]) {

    char clientes[tamanoclien][2][40];

    char habitaciones[9][3][40]={{"1","simple","Dan Carlton"},
                                  {"2","doble","Dan Carlton"},
                                  {"3","triple","Dan Carlton"},
                                  {"4","simple","Swissotel"},
                                  {"5","doble","Swissotel"},
                                  {"6","triple","Swissotel"},
                                  {"7","simple","Sheraton"},
                                  {"8","doble","Sheraton"},
                                  {"9","triple","Sheraton"}};

    double precios[9]={90,120,160,65,100,140,85,110,150};

    int reservas[10][4]={{-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0}};

    int opcion,numHabitacion,numReserva;
    do
    {   
        printf("Escoja una opcion:\n1.Ingresar clientes\n2.Buscar Habitacion\n3.Realizar reserva\n4.Ver reservas\n5.Pagar Reserva\n>>");
        scanf("%d",&opcion);
        switch (opcion)
        {
        case 1: 
        ingresarClientes(clientes,tamanoclien);
        break;
        case 2:
            printf("1.Por tamano\n2.Por Hotel\n>>");
            scanf("%d",&opcion);
            switch (opcion)
            {
            case 1:
                buscarPorTamano(&numHabitacion,habitaciones,precios);
                break;
            case 2:
                buscarHotel(&numHabitacion,habitaciones,precios);      
            default:
                break;
            }
            break;
        case 3:
            realizarReserva(numHabitacion,habitaciones,clientes,reservas,tamanoclien);
            break;
        case 4:
            buscarReservaPorCedula(&numReserva,clientes,reservas,tamanoclien);
            imprimirReserva(numReserva,reservas,habitaciones,precios,clientes,tamanoclien);
            break;
        case 5:
            buscarReservaPorCedula(&numReserva,clientes,reservas, tamanoclien);
            pagarReserva(numReserva,reservas,habitaciones,precios,clientes,tamanoclien);
            break;
        default:
            break;
        }
        printf("Desea elegir otra opcion \n1 = si \t\t2 = no\n");
        scanf("%d",&opcion);
    } while (opcion==1);
    

    return 0;
}
