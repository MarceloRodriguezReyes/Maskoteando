#include <stdio.h>
#include "Datosproducto.h"

struct productos dproductos, bproductos = {0, "", 0.0, 0, ""};

/* Crear un archivo de acceso directo en forma secuncial */

void CrearArchivoProductos()
{
 FILE *fptr1, *fptr2;

 if((fptr1 = fopen("C:\\Users\\sayer\\OneDrive\\Escritorio\\Maskoteando\\inventario.dat", "w")) == NULL)
      printf("\nEl archivo no se pudo crear");

 else
  {
    for(int i=1; i<=100; i++)
      fwrite(&bproductos, sizeof(struct productos), 1, fptr1);

    fclose(fptr1);
    printf("\nEl archivo se creó correctamente");
  }

/*Guardar datos directamente a un archivo de acceso directo */

 if((fptr2 = fopen("G:\\inventario.dat", "r+")) == NULL)
      printf("\nEl archivo no se pudo abrir");
 else
  {
    printf("\nIngrese el id del producto (1-100 ó 0 para finalizar entrada): ");
    scanf("%d", &dproductos.idproducto);

    while(dproductos.idproducto != 0)
    {
     printf("\nIngrese el nombre del producto: ");
     scanf(" %[^\n]", &dproductos.nombre);
     printf("\nIngrese el precio del producto: ");
     scanf("%d", &dproductos.precio);
     printf("\nIngrese la cantidad del producto: ");
     scanf("%d", &dproductos.cantidadproducto);
     printf("\nIngrese la descripcion del producto: ");
     scanf("%f", &dproductos.descproducto);

     fseek(fptr2, (dproductos.idproducto - 1) * sizeof(struct productos), SEEK_SET);
     fwrite(&dproductos, sizeof(struct productos), 1, fptr2);

     printf("\n\nIngrese el id del producto: ");
     scanf("%d", &dproductos.idproducto);
    }
  }
     fclose(fptr2);
     printf("\nPresione cualquier tecla para continuar...");
    getchar(); // Capturar el salto de línea anterior
    getchar(); // Esperar a que el usuario presione una tecla
 return;
}
