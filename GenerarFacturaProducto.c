#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Datosproducto.h"

void GenerarFacturaProducto()
{
    struct productos dproductos;
    int idproductos, cantidad;
    float subtotal = 0, total = 0;
    char continuar = 's';
    FILE *fptr;

    if ((fptr = fopen("C:\\Users\\sayer\\OneDrive\\Escritorio\\Maskoteando\\inventario.dat", "r+")) == NULL)
    {
        printf("\nEl archivo no se pudo abrir");
        printf("\n");
        system("pause");
        return;
    }

    printf("\n=== MENU DE PRODUCTOS ===\n");

    fseek(fptr, 0, SEEK_SET);
    while (fread(&dproductos, sizeof(struct productos), 1, fptr))
    {
        if (dproductos.idproducto != 0)
        {
            printf("\nID: %d", dproductos.idproducto);
            printf("\nNombre: %s", dproductos.nombre);
            printf("\nPrecio: %.2f", dproductos.precio);
            printf("\nCantidad disponible: %d", dproductos.cantidadproducto);
            printf("\n---------------------------------\n");
        }
    }

    fclose(fptr);

    fptr = fopen("C:\\Users\\sayer\\OneDrive\\Escritorio\\Maskoteando\\inventario.dat", "r+");

    // Generar ID único para la factura
    srand(time(0));
    int facturaID = rand() % 1000 + 1;

    FILE *factura;
    char facturaFileName[50];
    snprintf(facturaFileName, sizeof(facturaFileName), "factura%d.txt", facturaID);
    factura = fopen(facturaFileName, "w");

    fprintf(factura, "=== FACTURA DE VENTA ===\n");
    fprintf(factura, "ID Factura: %d\n", facturaID);
    fprintf(factura, "\nID\tNombre\t\tPrecio\tCantidad\tSubtotal\n");
    fprintf(factura, "---------------------------------\n");

    // printf("\n=== FACTURA DE VENTA ===\n");
    // printf("ID Factura: %d\n", facturaID);
    // printf("\nID\tNombre\t\tPrecio\tCantidad\tSubtotal\n");
    // printf("---------------------------------\n");

    while (continuar == 's' || continuar == 'S')
    {
        printf("\nIngrese el id del producto que desea comprar: ");
        scanf("%d", &idproductos);

        fseek(fptr, (idproductos - 1) * sizeof(struct productos), SEEK_SET);
        fread(&dproductos, sizeof(struct productos), 1, fptr);

        if (dproductos.idproducto == 0)
        {
            printf("\nNo se encontro ningun producto con el id %d", idproductos);
            printf("\n");
            system("pause");
            continue;
        }

        printf("\nProducto seleccionado:");
        printf("\nID: %d", dproductos.idproducto);
        printf("\nNombre: %s", dproductos.nombre);
        printf("\nPrecio: %.2f", dproductos.precio);
        printf("\nCantidad disponible: %d", dproductos.cantidadproducto);

        printf("\nIngrese la cantidad que desea comprar: ");
        scanf("%d", &cantidad);

        if (cantidad > dproductos.cantidadproducto)
        {
            printf("\nLa cantidad solicitada excede la disponibilidad del producto.");
            printf("\n");
            system("pause");
            continue;
        }

        subtotal = dproductos.precio * cantidad;

        printf("\nProducto comprado:");
        printf("\nID: %d", dproductos.idproducto);
        printf("\nNombre: %s", dproductos.nombre);
        printf("\nPrecio unitario: %.2f", dproductos.precio);
        printf("\nCantidad comprada: %d", cantidad);
        printf("\nSubtotal: %.2f", subtotal);

        fprintf(factura, "%d\t%s\t\t%.2f\t%d\t\t%.2f\n", dproductos.idproducto, dproductos.nombre, dproductos.precio, cantidad, subtotal);

        total += subtotal;

        // Actualizar la cantidad en el inventario
        dproductos.cantidadproducto -= cantidad;
        fseek(fptr, (idproductos - 1) * sizeof(struct productos), SEEK_SET);
        fwrite(&dproductos, sizeof(struct productos), 1, fptr);

        printf("\nDesea seguir comprando? (s/n): ");
        scanf(" %c", &continuar);
    }

    fclose(fptr);
    fclose(factura);

    fprintf(factura, "---------------------------------\n");
    fprintf(factura, "Total: %.2f\n", total);

    printf("\n---------------------------------");
    printf("\nTotal de la factura: %.2f", total);
    printf("\n---------------------------------");
    printf("\nLa factura de venta se ha generado correctamente (Archivo: %s).\n", facturaFileName);
    printf("\n");
    system("pause");
}
