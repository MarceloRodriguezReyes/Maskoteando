#include <stdlib.h>
#include <stdio.h>
#include "Datosproducto.h"

int MostrarMenu();
void CrearArchivoProductos();
void AgregarRegistroProducto();
void ActualizarRegistroProducto();
void EliminarRegistroProducto();
void ConsultarRegistroProducto();
void GenerarFacturaProducto();

//gcc principal.c Menu.c AgregarRegistroProducto.c ConsultarRegistroProducto.c ActualizarRegistroProducto.c EliminarRegistroProducto.c CrearArchivoProductos.c Datosproducto.h GenerarFacturaProducto.c -o programa.exe


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
        case 6: 
            GenerarFacturaProducto();
            break;
        case 7:
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
