#include <stdio.h>

int Menu(void)
{
  int mopcion;
  //textbackground(CYAN);
  do
  {
     printf("\n\t\t\tMaskoteando\n");
     printf("\n\t\t1. Agregar registro de producto \"producto.dat\"");
     printf("\n\t\t2. Consultar registro de producto");
     printf("\n\t\t3. Actuliazar registro de producto");
     printf("\n\t\t4. Eliminar registro de producto");
     printf("\n\t\t5. Comprar producto(s)");//Nueva opcion
     printf("\n\t\t6. Imprimir registro de productos");//Nueva opcion
     printf("\n\t\t7. Calcular total de productos comprados");//Nueva opcion 
     printf("\n\t\t8. Imprimir factura de productos comprados \"productos.txt\"");
     printf("\n\t\t9. Finalizar programa");
     printf("\n\n");
     printf("\n\t\t   Elija su opción: ");
     scanf("%d", &mopcion);
  }
  while(!(mopcion >= 1 && mopcion <= 9));
  return(mopcion);
 }

