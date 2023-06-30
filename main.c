#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
   int idm, edad, numDetalles = 0;
   float total = 0;
   char menu;
   char nombre[50], tipo[50], dueño[50];
   char detalles[10][4][200];

   printf("###############BIENVENIDO AL SISTEMA DE FACTURACION DE CANIN###############\n");

   do {
       printf("Elija una opción del siguiente menú:\n");
       printf("a) Ingreso de datos de mascota.\n");
       printf("b) Servicios para mascota.\n");
       printf("c) Facturar servicio.\n");
       scanf(" %c", &menu);

       switch (menu) {
           case 'a':
               ingresoDatosMascota(&idm, nombre, tipo, &edad, dueño);
               break;

           case 'b':
               seleccionarServicios(detalles, &numDetalles, &total);
               break;

           case 'c':
               generarFactura(idm, nombre, tipo, dueño, detalles, numDetalles, total);
               break;
       }
   } while (menu == 'a' || menu == 'b');

   return 0;
}