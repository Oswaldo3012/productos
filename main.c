#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    int opcion;
    char buffer[10];

    do {
        printf("\n=== Menu de Produccion ===\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Calcular produccion\n");
        printf("5. Mostrar productos\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");

        if (fgets(buffer, sizeof(buffer), stdin) != NULL && sscanf(buffer, "%d", &opcion) == 1) {
            switch (opcion) {
                case 1: ingresarProducto(); break;
                case 2: editarProducto(); break;
                case 3: eliminarProducto(); break;
                case 4: calcularProduccion(); break;
                case 5: mostrarProductos(); break;
                case 0: printf("Saliendo del programa.\n"); break;
                default: printf("Opcion invalida. Intente de nuevo.\n");
            }
        } else {
            printf("Entrada invalida. Intente de nuevo.\n");
        }

    } while (opcion != 0);

    return 0;
}
