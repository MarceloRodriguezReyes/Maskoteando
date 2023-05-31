#include <stdio.h>
#include <stdlib.h>
#include "Datosproducto.h"

void AgregarRegistroProducto()
{
  struct productos dproductos;
  int idproductos;
  FILE *fptr;

  if((fptr = fopen("C:\\Users\\sayer\\OneDrive\\Escritorio\\Maskoteando\\inventario.dat", "r+")) == NULL)
      printf("\nEl archivo no se pudo abrir");
  else
   {
     printf("\nIngrese el id del producto (1-100): ");
     scanf("%d", &idproductos);
     fseek(fptr, (idproductos - 1) * sizeof(struct productos), SEEK_SET);
     fread(&dproductos, sizeof(struct productos), 1, fptr);

     if(dproductos.idproducto != 0)
      {
       printf("\nEl id de ese producto %d ya contiene información", dproductos.idproducto);
       printf("\n");
       system("pause");
      }
     else
      {
        printf("\nIngrese el nombre: ");
        scanf("%s",&dproductos.nombre);
        printf("\nIngrese el precio del producto: ");
        scanf("%d", &dproductos.precio);
        printf("\nIngrese la cantidad del producto: ");
        scanf("%d",&dproductos.cantidadproducto);
        printf("\nIngrese la descripcion del producto: ");
        scanf("%s",&dproductos.descproducto);

        dproductos.idproducto = idproductos;

        fseek(fptr, (dproductos.idproducto - 1) * sizeof(struct productos), SEEK_SET);
        fwrite(&dproductos, sizeof(struct productos), 1, fptr);
      }
   }
        fclose(fptr);
 return;
}
