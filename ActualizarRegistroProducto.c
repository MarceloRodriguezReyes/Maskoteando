#include <stdio.h>
#include <stdlib.h>
#include "Datosproducto.h"

void ActualizarRegistroProducto()
{
 int idproducto;
 struct productos dproducto;
 FILE *fptr;

//Recordar cambiar la direccion del archivo
 if((fptr = fopen("C:\\C:\\Users\\marcelor\\Desktop\\Maskoteando", "r+")) == NULL)
    printf("\nEl archivo no se pudo abrir");
 else
  {
    printf("Ingrese la id del producto que desea actualizar (1-100): ");
    scanf("%d", &idproducto);

    fseek(fptr, (idproducto - 1) * sizeof(struct productos), SEEK_SET);
    fread(&dproducto, sizeof(struct productos), 1, fptr);

    if(dproducto.idproducto == 0)
     {
      printf("\nEl registro del producto %d no tiene información", idproducto);
      printf("\n");
      system("pause");
     }
    else
     {
    printf("\n");
    printf("%s\t %s\t %s\t %s\t %s\n",
             "ID", "Nombre", "Precio", "Cantidad", "Descripcion");
    printf("%d\t %s\t %.2f\t %d\t\t %s\n\n",
              dproducto.idproducto, dproducto.nombre,
              dproducto.precio, dproducto.cantidadproducto,
              dproducto.descproducto);
    printf("\nIngrese el nombre del producto: ");
     scanf(" %s", dproducto.nombre); 
     printf("\nIngrese el precio del producto: ");
     scanf("%f", &dproducto.precio);  
     printf("\nIngrese la cantidad disponible del producto: ");
     scanf("%d", &dproducto.cantidadproducto);
     printf("\nIngrese una descripcion sobre el producto: ");
     scanf(" %s", dproducto.descproducto); 


    printf("\n");
    printf("%s\t %s\t %s\t %s\t %s\n",
             "ID", "Nombre", "Precio", "Cantidad", "Descripcion");
    printf("%d\t %s\t %.2f\t %d\t\t %s\n\n",
              dproducto.idproducto, dproducto.nombre,
              dproducto.precio, dproducto.cantidadproducto,
              dproducto.descproducto);

       printf("\n");
       system("pause");

       fseek(fptr, (idproducto - 1) * sizeof(struct productos), SEEK_SET);
       fwrite(&dproducto, sizeof(struct productos), 1, fptr);
     }
  }
       fclose(fptr);
 return;
}
