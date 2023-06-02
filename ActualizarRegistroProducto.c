#include <stdio.h>
#include <stdlib.h>
#include "Datosproducto.h"

void ActualizarRegistroProducto()
{
    struct productos dproductos;
    int idproductos;
    FILE *fptr;

    if((fptr = fopen("C:\\Users\\sayer\\OneDrive\\Escritorio\\Maskoteando\\inventario.dat", "r+")) == NULL)
    {
        printf("\nEl archivo no se pudo abrir");
        return;
    }

    printf("\nIngrese el id del producto a modificar (1-100): ");
    scanf("%d", &idproductos);

    fseek(fptr, (idproductos - 1) * sizeof(struct productos), SEEK_SET);
    fread(&dproductos, sizeof(struct productos), 1, fptr);

    if(dproductos.idproducto == 0)
    {
        printf("\nNo se encontro ningun producto con el id %d", idproductos);
        fclose(fptr);
        return;
    }

    printf("\nRegistro actual:");
    printf("\nID: %d", dproductos.idproducto);
    printf("\nNombre: %s", dproductos.nombre);
    printf("\nPrecio: %.2f", dproductos.precio);
    printf("\nCantidad: %d", dproductos.cantidadproducto);
    printf("\nDescripcion: %s", dproductos.descproducto);

    printf("\n\nIngrese el nuevo nombre: ");
    scanf("%s", dproductos.nombre);
    printf("\nIngrese el nuevo precio del producto: ");
    scanf("%f", &dproductos.precio);
    printf("\nIngrese la nueva cantidad del producto: ");
    scanf("%d", &dproductos.cantidadproducto);
    printf("\nIngrese la nueva descripcion del producto: ");
    scanf("%s", dproductos.descproducto);

    fseek(fptr, (idproductos - 1) * sizeof(struct productos), SEEK_SET);
    fwrite(&dproductos, sizeof(struct productos), 1, fptr);

    printf("\nEl registro se ha actualizado correctamente.");

    fclose(fptr);
    return;
}
