#include <stdlib.h>
#include <stdio.h>
#include "Datosproducto.h"

int MostrarMenu();
void CrearArchivoProductos();
void AgregarRegistroProducto();
void ActualizarRegistroProducto();
void EliminarRegistroProducto();
void ConsultarRegistroProducto();
/* Faltan los void de
comprarproductos
imprimir registro de productos
calcular total de productos comprados
imprimir factura de productos comprados */

int main()
{
    int opcion;

    while (1) {
        opcion = MostrarMenu();
        switch (opcion)
        {
        case 1:
            CrearArchivoProductos();
            break;
        case 2:
            AgregarRegistroProducto();
            break;
        case 3:
            ConsultarRegistroProducto();
            break;
        case 4:
            ActualizarRegistroProducto();
            break;
        case 5:
            EliminarRegistroProducto();
            break;
        /*case 6: ConsultarRegistroCuenta();
                 system("cls");
                 Menu();
                 //break;
        case 7: OrdenarRegistrosCuenta();
                 system("cls");
                 Menu();
                 //break;
        case 8: Imprimir_a_Pantalla();
                 system("cls");
                 Menu();
                 //break;
        case 9: Imprimir_a_Archivo();
                 system("cls");
                 Menu();
                 //break;
        case 10: Ayuda();
                 system("cls");
                 Menu();
                 //break;*/
        case 9:
            return 0; // Salir del programa
        default:
            printf("Opción inválida. Introduce un número válido.\n");
            break;
        }

        // Limpiar la pantalla antes de mostrar el menú nuevamente
        system("cls");
    }

    return 0;
}
