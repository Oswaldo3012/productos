#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PRODUCTOS 5
#define MAX_NOMBRE 30

extern char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
extern int cantidades[MAX_PRODUCTOS];
extern int tiemposFabricacion[MAX_PRODUCTOS];
extern int recursosNecesarios[MAX_PRODUCTOS];
extern int totalProductos;

void ingresarProducto();
void editarProducto();
void eliminarProducto();
void calcularProduccion();
void mostrarProductos();
void limpiarBuffer();
int leerEnteroSeguro();

#endif
