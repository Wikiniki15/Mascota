#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresoDatosMascota(int* idm, char nombre[50], char tipo[50], int* edad, char dueño[50]) {
   printf("Ingrese la ID de su mascota: ");
   scanf("%d", idm);

   printf("Ingrese el nombre de su mascota: ");
   scanf("%s", nombre);

   printf("Ingrese el tipo de su mascota: ");
   scanf("%s", tipo);

   printf("Ingrese la edad de su mascota: ");
   scanf("%d", edad);

   printf("Ingrese el nombre del propietario: ");
   scanf("%s", dueño);
}

void mostrarServicios() {
   char servicios[10][4][200] = {
       {"18715", "Hotel", "Es un lugar con las instalaciones y el personal adecuado para que tu mascota se sienta como en casa mientras tu no estas.", "$40"},
       {"49057", "Guardería", "Es un lugar donde tu mascota convivirá con otros animales a la vez que es atendido y vigilado, mientras estás en tu jornada laboral.", "$100"},
       {"91432", "Gimnasio", "Es una opción para que tu mascota haga la actividad física que necesita para estar tranquila y feliz.", "$5"},
       {"76201", "Restaurante", "Es un lugar en el que tanto las personas como las mascotas pueden disfrutar de comida y café gourmet y en el que tu mascota será consentida incluso más que tú.", "$4.50"},
       {"34878", "Estética y Spa", "Es un lugar en el que tu mascota recibirá un masaje o un baño reconfortante, al igual que le cortarán las uñas, le lavarán los dientes y las glándulas, además de que le harán un corte de pelo.", "$20"},
       {"62190", "Transporte", "Es un servicio que te ayudará a desplazarte con tu mascota de un lugar a otro dentro de la ciudad.", "$7.50"},
       {"25649", "Fiestas", "Puedes organizar una fiesta para tu mascota, también una sesión de fotos en la que tu mascota sea la protagonista.", "$15"},
       {"53924", "Seguros", "Entre la cobertura se encuentra la muerte, atropellamiento, lesiones del mismo o que pueda causarles a otros animales, caídas y enfermedades.", "$40"},
       {"80563", "Funeraria", "Los servicios son la cremación, eutanasia para aquellos con enfermedades terminales o que sufren mucho dolor por algún sufrimiento e incluso terapias para superar el duelo", "$40"},
       {"07386", "Veterinaria", "Consiste en la desparasitación, una revisión general, vacunas y pruebas de sangre, heces y orina.", "$40"}
   };

   printf("Servicios disponibles:\n");
   for (int i = 0; i < 10; i++) {
       printf("Código: %s\n", servicios[i][0]);
       printf("Nombre: %s\n", servicios[i][1]);
       printf("Descripción: %s\n", servicios[i][2]);
       printf("Precio: %s\n", servicios[i][3]);
       printf("\n");
   }
}

void seleccionarServicios(char detalles[10][4][200], int* numDetalles, float* total) {
   char servicios[10][4][200] = {
       {"18715", "Hotel", "Es un lugar con las instalaciones y el personal adecuado para que tu mascota se sienta como en casa mientras tu no estas.", "$40"},
       {"49057", "Guardería", "Es un lugar donde tu mascota convivirá con otros animales a la vez que es atendido y vigilado, mientras estás en tu jornada laboral.", "$100"},
       {"91432", "Gimnasio", "Es una opción para que tu mascota haga la actividad física que necesita para estar tranquila y feliz.", "$5"},
       {"76201", "Restaurante", "Es un lugar en el que tanto las personas como las mascotas pueden disfrutar de comida y café gourmet y en el que tu mascota será consentida incluso más que tú.", "$4.50"},
       {"34878", "Estética y Spa", "Es un lugar en el que tu mascota recibirá un masaje o un baño reconfortante, al igual que le cortarán las uñas, le lavarán los dientes y las glándulas, además de que le harán un corte de pelo.", "$20"},
       {"62190", "Transporte", "Es un servicio que te ayudará a desplazarte con tu mascota de un lugar a otro dentro de la ciudad.", "$7.50"},
       {"25649", "Fiestas", "Puedes organizar una fiesta para tu mascota, también una sesión de fotos en la que tu mascota sea la protagonista.", "$15"},
       {"53924", "Seguros", "Entre la cobertura se encuentra la muerte, atropellamiento, lesiones del mismo o que pueda causarles a otros animales, caídas y enfermedades.", "$40"},
       {"80563", "Funeraria", "Los servicios son la cremación, eutanasia para aquellos con enfermedades terminales o que sufren mucho dolor por algún sufrimiento e incluso terapias para superar el duelo", "$40"},
       {"07386", "Veterinaria", "Consiste en la desparasitación, una revisión general, vacunas y pruebas de sangre, heces y orina.", "$40"}
   };

   char numero[10];
   int cantidad, encontrado;

   do {
       mostrarServicios();

       printf("Ingrese el código del servicio que desea: ");
       scanf("%s", numero);

       encontrado = 0;
       for (int i = 0; i < 10; i++) {
           if (strcmp(servicios[i][0], numero) == 0) {
               encontrado = 1;

               printf("Ingrese la cantidad deseada: ");
               scanf("%d", &cantidad);

               if (cantidad > 0) {
                   float precio;
                   sscanf(servicios[i][3], "$%f", &precio);
                   *total += precio * cantidad;

                   strcpy(detalles[*numDetalles][0], servicios[i][0]);
                   strcpy(detalles[*numDetalles][1], servicios[i][1]);
                   strcpy(detalles[*numDetalles][2], servicios[i][3]);
                   sprintf(detalles[*numDetalles][3], "%d", cantidad);

                   (*numDetalles)++;
               }
           }
       }

       if (!encontrado) {
           printf("Servicio no encontrado.\n");
       }

       printf("Desea facturar otro servicio?\n");
       printf("Si = 1 | No = 0\n");
       scanf("%d", &encontrado);
   } while (encontrado == 1);
}

void generarFactura(int idm, char nombre[50], char tipo[50], char dueño[50], char detalles[10][4][200], int numDetalles, float total) {
   printf("################################################################\n");
   printf("##########################FACTURA###############################\n");
   printf("Nombre: %s\n", nombre);
   printf("ID: %d\n", idm);
   printf("Tipo: %s\n", tipo);
   printf("Propietario: %s\n", dueño);
   printf("\n");

   printf("Detalles de los servicios escogidos:\n");
   for (int i = 0; i < numDetalles; i++) {
       printf("Código: %s\n", detalles[i][0]);
       printf("Nombre: %s\n", detalles[i][1]);
       printf("Cantidad: %s\n", detalles[i][3]);

       float precio;
       sscanf(detalles[i][2], "$%f", &precio);
       printf("Precio unitario: $%.2f\n", precio);

       int cantidad;
       sscanf(detalles[i][3], "%d", &cantidad);
       printf("Total: $%.2f\n", precio * cantidad);

       printf("\n");
   }

   printf("Total a pagar: $%.2f\n", total);
}