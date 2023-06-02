#include <stdio.h>

int MostrarMenu()
{
  int mopcion;
  //textbackground(CYAN);
  do
  {
     printf("\n\t\t\tMaskoteando\n");
     
     printf("\n\t\t1. Crear archivo de productos \"inventario.dat\"");
     printf("\n\t\t2. Agregar registro de producto");
     printf("\n\t\t3. Consultar registro de producto");
     printf("\n\t\t4. Actualizar registro de producto");
     printf("\n\t\t5. Eliminar registro de producto");
     printf("\n\t\t6. Generar factura de venta de productos");
   //   printf("\n\t\t6. Comprar producto(s)");//Nueva opcion
   //   printf("\n\t\t7. Imprimir registro de productos");//Nueva opcion
   //   printf("\n\t\t8. Calcular total de productos comprados");//Nueva opcion 
   //   printf("\n\t\t9. Imprimir factura de productos comprados \"productos.txt\"");
     printf("\n\t\t7. Finalizar programa");
     printf("\n\n");
     printf("\n\t\t   Elija su opcion: ");
     scanf("%d", &mopcion);
  }
  while(!(mopcion >= 1 && mopcion <= 7));
  return(mopcion);
 }

