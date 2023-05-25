#include <stdio.h>
#include "Datosproducto.h"

struct productos dproducto, bproducto = {0, "", 0.0 , 0 , ""};

/* Crear un archivo de acceso directo en forma secuncial */

void AgregarRegistroProducto(void)
{
 FILE *fptr1, *fptr2;

//Recordar cambiar la direccion del archivo
 if((fptr1 = fopen("C:\\_I Semestre 2023\\MP\\Clase 34 - (15May)\\TransaccionesBanco\\credito.dat", "w")) == NULL)
      printf("\nEl archivo no se pudo crear");

 else
  {
    for(int i=1; i<=100; i++)
      fwrite(&bproducto, sizeof(struct productos), 1, fptr1);

    fclose(fptr1);
  }

/*Guardar datos directamente a un archivo de acceso directo */

 if((fptr2 = fopen("G:\\producto.dat", "r+")) == NULL)
      printf("\nEl archivo no se pudo abrir");
 else
  {
    printf("\nIngrese la id del producto (1-100 ó 0 para finalizar entrada): ");
    scanf("%d", &dproducto.idproducto);

    while(dproducto.idproducto != 0)
    {
     printf("\nIngrese el nombre del producto: ");
     scanf(" %[^\n]", &dproducto.nombre); 
     printf("\nIngrese el precio del producto: ");
     scanf("%f", &dproducto.precio);  
     printf("\nIngrese la cantidad disponible del producto: ");
     scanf("%d", &dproducto.cantidadproducto);
     printf("\nIngrese una descripcion sobre el producto: ");
     scanf(" %[^\n]", &dproducto.descproducto); 

     fseek(fptr2, (dproducto.idproducto - 1) * sizeof(struct productos), SEEK_SET);
     fwrite(&dproducto, sizeof(struct productos), 1, fptr2);

     printf("\n\nIngrese la id del producto: ");
     scanf("%d", &dproducto.idproducto);
    }
  }
     fclose(fptr2);
 return;
}