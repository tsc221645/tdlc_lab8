#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void function1(int n) {
    int i, j, k, counter = 0;
    for (i = n/2; i <= n; i++) {
        for (j = 1; j + n/2 <= n; j++) {
            for (k = 1; k <= n; k = k*2) {
                counter++;
            }
        }
    }
    printf("Counter final (n=%d): %d\n", n, counter);
}


void function2(int n) {
    if (n <= 1) return;
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {

            break;
        }
    }
}


void function3(int n) {
    int i, j;
    for (i = 1; i <= n/3; i++) {
        for (j = 1; j <= n; j += 4) {

        }
    }
}

void medir_tiempos(int opcion) {
    int inputs[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
    int num_inputs = sizeof(inputs) / sizeof(inputs[0]);

    printf("\nEjercicio %d - Medición de tiempos\n", opcion);
    printf("n, tiempo(segundos)\n");

    for (int i = 0; i < num_inputs; i++) {
        int n = inputs[i];
        clock_t start = clock();

        if (opcion == 1) function1(n);
        else if (opcion == 2) function2(n);
        else if (opcion == 3) function3(n);

        clock_t end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d, %f\n", n, time_spent);
    }
}

int main() {
    int opcion;
    while (1) {
        printf("\n===== MENU =====\n");
        printf("1. Ejecutar Ejercicio 1\n");
        printf("2. Ejecutar Ejercicio 2\n");
        printf("3. Ejecutar Ejercicio 3\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        if (opcion == 0) {
            printf("Saliendo...\n");
            break;
        } else if (opcion >= 1 && opcion <= 3) {
            medir_tiempos(opcion);
        } else {
            printf("Opción inválida. Intente de nuevo.\n");
        }
    }
    return 0;
}
