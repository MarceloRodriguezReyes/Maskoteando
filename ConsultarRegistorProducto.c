#include <stdio.h>
#include <stdlib.h>
#include "Datosproducto.h"

void ConsultarRegistroProducto(void)
{
  FILE *fptr;
  int idproducto;
  struct productos dproducto;

  //Recordar cambiar la direccion del archivo
  if((fptr = fopen("C:\\_I Semestre 2023\\MP\\Clase 34 - (15May)\\TransaccionesBanco\\credito.dat", "r+")) == NULL)
     printf("\nEl archivo no se pudo abrir");
  else
   {
     printf("Ingrese la id del producto que desea consultar (1-100): ");
     scanf("%d", &idproducto);

     fseek(fptr, (idproducto - 1) * sizeof(struct productos), SEEK_SET);
     fread(&dproducto, sizeof(struct productos), 1, fptr);

     if(dproducto.idproducto == 0)
      {
       printf("\nEl registro del producto %d no existe", idproducto);
       printf("\n");
       system("pause");
      }
     else
      {
       fseek(fptr, (idproducto - 1) * sizeof(struct productos), SEEK_SET);
       fwrite(&dproducto, sizeof(struct productos), 1, fptr);
       printf("\n");
       printf("%s\t %s\t %s\t %s\t %s\n",
             "ID", "Nombre", "Precio", "Cantidad", "Descripcion");
       printf("%d\t %s\t %.2f\t %d\t\t %s\n\n",
              dproducto.idproducto, dproducto.nombre,
              dproducto.precio, dproducto.cantidadproducto,
              dproducto.descproducto);
       printf("\n");
       system("pause");
      }
   }
       fclose(fptr);
  return;
}
