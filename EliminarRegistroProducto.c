#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Datosproducto.h"

void EliminarRegistroProducto()
{
    struct productos dproductos;
    int idproductos;
    FILE *fptr;

    if ((fptr = fopen("C:\\Users\\sayer\\OneDrive\\Escritorio\\Maskoteando\\inventario.dat", "r+")) == NULL)
    {
        printf("\nEl archivo no se pudo abrir");
        return;
    }

    printf("\nIngrese el id del producto a eliminar (1-100): ");
    scanf("%d", &idproductos);

    fseek(fptr, (idproductos - 1) * sizeof(struct productos), SEEK_SET);
    fread(&dproductos, sizeof(struct productos), 1, fptr);

    if (dproductos.idproducto == 0)
    {
        printf("\nNo se encontro ningun producto con el id %d", idproductos);
        fclose(fptr);
        printf("\n");
        system("pause");
        return;
    }

    printf("\nRegistro a eliminar:");
    printf("\nID: %d", dproductos.idproducto);
    printf("\nNombre: %s", dproductos.nombre);
    printf("\nPrecio: %.2f", dproductos.precio);
    printf("\nCantidad: %d", dproductos.cantidadproducto);
    printf("\nDescripcion: %s", dproductos.descproducto);

    char confirmacion;
    printf("\n\nDesea eliminar este registro? (s/n): ");
    scanf(" %c", &confirmacion);

    if (confirmacion == 's' || confirmacion == 'S')
    {
        dproductos.idproducto = 0;
        strcpy(dproductos.nombre, "");
        dproductos.precio = 0.0;
        dproductos.cantidadproducto = 0;
        strcpy(dproductos.descproducto, "");

        fseek(fptr, (idproductos - 1) * sizeof(struct productos), SEEK_SET);
        fwrite(&dproductos, sizeof(struct productos), 1, fptr);

        printf("\nEl registro se ha eliminado correctamente.");
        printf("\n");
       system("pause");
    }
    else
    {
        printf("\nNo se realizo ninguna eliminacion.");
        printf("\n");
       system("pause");
    }

    fclose(fptr);
    return;
}

