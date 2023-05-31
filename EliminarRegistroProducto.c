#include <stdio.h>
#include <stdlib.h>
#include "Datosproducto.h"

void EliminarRegistroProducto()
{
  FILE *fptr;
  int idproducto;
  struct productos dproducto, bproducto = {0, "", 0.0 ,0 , ""};

  //Recordar cambiar la direccion del archivo
  if((fptr = fopen("C:\\C:\\Users\\marcelor\\Desktop\\Maskoteando", "r+")) == NULL)
     printf("\nEl archivo no se pudo abrir");
  else
   {
     printf("Ingrese la id del producto que desea eliminar (1-100): ");
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
       fwrite(&bproducto, sizeof(struct productos), 1, fptr);
       printf("\nRegistro %d eliminado", idproducto);
       printf("\n");
       system("pause");
      }
   }
      fclose(fptr);
 return;
}

