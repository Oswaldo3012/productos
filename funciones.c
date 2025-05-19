#include <stdio.h>
#include <string.h>
#include "funciones.h"

char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
int cantidades[MAX_PRODUCTOS];
int tiemposFabricacion[MAX_PRODUCTOS];
int recursosNecesarios[MAX_PRODUCTOS];
int totalProductos = 0;

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int leerEnteroSeguro() {
    char buffer[50];
    int numero;
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &numero) == 1) return numero;
            printf("Entrada invalida. Ingrese un numero valido: ");
        }
    }
}

void ingresarProducto() {
    if (totalProductos >= MAX_PRODUCTOS) {
        printf("Ya se han ingresado los 5 productos.\n");
        return;
    }

    printf("Nombre del producto: ");
    fgets(nombres[totalProductos], MAX_NOMBRE, stdin);
    nombres[totalProductos][strcspn(nombres[totalProductos], "\n")] = '\0';

    printf("Cantidad demandada: ");
    cantidades[totalProductos] = leerEnteroSeguro();

    printf("Tiempo de fabricacion por unidad (minutos): ");
    tiemposFabricacion[totalProductos] = leerEnteroSeguro();

    printf("Recursos necesarios por unidad: ");
    recursosNecesarios[totalProductos] = leerEnteroSeguro();

    totalProductos++;
}

void editarProducto() {
    char nombreBusqueda[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a editar: ");
    fgets(nombreBusqueda, MAX_NOMBRE, stdin);
    nombreBusqueda[strcspn(nombreBusqueda, "\n")] = '\0';

    for (int i = 0; i < totalProductos; i++) {
        if (strcmp(nombres[i], nombreBusqueda) == 0) {
            printf("Nuevo nombre: ");
            fgets(nombres[i], MAX_NOMBRE, stdin);
            nombres[i][strcspn(nombres[i], "\n")] = '\0';

            printf("Nueva cantidad demandada: ");
            cantidades[i] = leerEnteroSeguro();

            printf("Nuevo tiempo de fabricacion: ");
            tiemposFabricacion[i] = leerEnteroSeguro();

            printf("Nuevos recursos necesarios: ");
            recursosNecesarios[i] = leerEnteroSeguro();
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminarProducto() {
    char nombreBusqueda[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a eliminar: ");
    fgets(nombreBusqueda, MAX_NOMBRE, stdin);
    nombreBusqueda[strcspn(nombreBusqueda, "\n")] = '\0';

    for (int i = 0; i < totalProductos; i++) {
        if (strcmp(nombres[i], nombreBusqueda) == 0) {
            for (int j = i; j < totalProductos - 1; j++) {
                strcpy(nombres[j], nombres[j + 1]);
                cantidades[j] = cantidades[j + 1];
                tiemposFabricacion[j] = tiemposFabricacion[j + 1];
                recursosNecesarios[j] = recursosNecesarios[j + 1];
            }
            totalProductos--;
            printf("Producto eliminado.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void calcularProduccion() {
    int totalTiempo = 0, totalRecursos = 0;

    for (int i = 0; i < totalProductos; i++) {
        totalTiempo += cantidades[i] * tiemposFabricacion[i];
        totalRecursos += cantidades[i] * recursosNecesarios[i];
    }

    printf("Tiempo total requerido: %d minutos\n", totalTiempo);
    printf("Total de recursos necesarios: %d unidades\n", totalRecursos);

    printf("Ingrese el tiempo disponible (minutos): ");
    int tiempoDisponible = leerEnteroSeguro();

    printf("Ingrese los recursos disponibles: ");
    int recursosDisponibles = leerEnteroSeguro();

    if (totalTiempo <= tiempoDisponible && totalRecursos <= recursosDisponibles)
        printf("La fabrica puede cumplir con la demanda.\n");
    else
        printf("La fabrica NO puede cumplir con la demanda.\n");
}

void mostrarProductos() {
    if (totalProductos == 0) {
        printf("No hay productos ingresados.\n");
        return;
    }

    for (int i = 0; i < totalProductos; i++) {
        printf("Producto %d:\n", i + 1);
        printf("  Nombre: %s\n", nombres[i]);
        printf("  Cantidad: %d\n", cantidades[i]);
        printf("  Tiempo: %d min\n", tiemposFabricacion[i]);
        printf("  Recursos: %d\n", recursosNecesarios[i]);
    }
}
