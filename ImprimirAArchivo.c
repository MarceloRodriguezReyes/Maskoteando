#include <stdio.h>
#include <stdlib.h>
#include "Datosproducto.h"

void ImprimirAArchivo()
{
 struct productos dproductos, bproductos = {0, "", 0.0, 0, ""};

 /*Crear un archivo de acceso directo en forma secuncial*/

 FILE *rfptr, *wfptr;

 if((rfptr = fopen("C:\\Users\\sayer\\OneDrive\\Escritorio\\Maskoteando\\inventario.dat", "w")) == NULL)
  {
     printf("\nEl archivo no pudo ser leido");
     printf("\n");
     system("pause");
  }
 else
  {
    if((wfptr = fopen("f:\\Maskoteando\\productos.txt", "w")) == NULL)
     {
       printf("\nEl archivo no pudo ser creado");
       printf("\n");
       system("pause");
     }//fin if
   else
    {
      rewind(rfptr);
      fprintf(wfptr, "%d\t %s\t %f\t %d\t %s\n",
              "ID", "Nombre", "Precio", "Cantidad", "Descripcion\n");

      while(!feof(rfptr))
       {
        fread(&dproductos, sizeof(struct productos), 1, rfptr);

        if(dproductos.idproducto != 0)
         {
           fprintf(wfptr, "%d\t %s\t %f\t\t %d\t\t %s\n",
                   dproductos.idproducto, dproductos.nombre,
                   dproductos.precio, dproductos.cantidadproducto,
                   dproductos.descproducto);
         }//fin if
       }//fin while

        printf("\n");
        printf("\nOperacion Finalizada...\n");
        system("pause");
    }//fin else m�s interno

  }//fin del else m�s externo
   fclose(rfptr);
   fclose(wfptr);
 return;
}
