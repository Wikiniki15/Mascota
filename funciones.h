void ingresoDatosMascota(int* idm, char nombre[50], char tipo[50], int* edad, char dueño[50]);
void mostrarServicios();
void seleccionarServicios(char detalles[10][4][200], int* numDetalles, float* total);
void generarFactura(int idm, char nombre[50], char tipo[50], char dueño[50], char detalles[10][4][200], int numDetalles, float total);