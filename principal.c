#include <stdlib.h>
#include <stdio.h>
#include "Datosproducto.h"

 int Menu(void);
void AgregarRegistroProducto(void);
void ActualizarRegistroProducto(void);
void EliminarRegistroProducto(void);
void ConsultarRegistroProducto(void);
/*Faltan los void de 
comprarproductos
imprimir registro de productos
calcular total de productos comprados
imprimir factura de productos comprados*/
 
int main()
 {
  int opcion;

  opcion = Menu();
  switch(opcion)
   {
     case 1: AgregarRegistroProducto();
             system("cls");
             Menu();
             //break;
     case 2: ConsultarRegistroProducto();
             system("cls");
             Menu();
             //break;
     case 3: ActualizarRegistroProducto();
             system("cls");
             Menu();
             //break;
     case 4: EliminarRegistroProducto();
             system("cls");
             Menu();
             //break;

     /*case 5: ConsultarRegistroCuenta();
             system("cls");
             Menu();
             //break;
     case 6: OrdenarRegistrosCuenta();
             system("cls");
             Menu();
             //break;
     case 7: Imprimir_a_Pantalla();
             system("cls");
             Menu();
             //break;
     case 8: Imprimir_a_Archivo();
             system("cls");
             Menu();
             //break;
     case 9: Ayuda();
             system("cls");
             Menu();
             //break;*/
     case 9: break;
   }
  return 0;
 }
