// main.c
#include "biblioteca.h"
#include <stdio.h>
#include <unistd.h> // Para sleep()

// Prototipos de funciones adicionales
void chequearPuertas();
void controlarLuces();

int main() {
    setupGPIO(); // Configurar GPIO
    
    printf("Sistema de control de casa inteligente iniciado.\n");
    printf("Ingrese un número (1-5) para controlar la luz correspondiente.\n");
    printf("Presione Ctrl+C para salir.\n");

    while (1) {
        chequearPuertas();
        controlarLuces();
        sleep(1); // Pequeña pausa para reducir el uso de CPU
    }

    return 0;
}

void chequearPuertas() {
    // Estado previo de las puertas para detectar cambios
    static bool estadoPrevioPuertas[4] = {true, true, true, true}; // Inicializa como cerradas

    for (int i = 0; i < 4; ++i) {
        bool estadoActual = leerPuerta(i);
        if (estadoActual != estadoPrevioPuertas[i]) { // Si hay cambio
            printf("Puerta %d %s.\n", i + 1, estadoActual ? "abierta" : "cerrada");
            estadoPrevioPuertas[i] = estadoActual;
        }
    }
}

void controlarLuces() {
    if (!feof(stdin)) { // Verificar si hay entrada disponible
        int luz;
        scanf("%d", &luz); // Leer la entrada del usuario
        if (luz >= 1 && luz <= 5) {
            switch (luz) {
                case 1: toggleLuzCuarto(); break;
                case 2: toggleLuzSala(); break;
                case 3: toggleLuzCuarto2(); break;
                case 4: toggleLuzBano(); break;
                case 5: toggleLuzCocina(); break;
            }
            printf("Luz %d alternada.\n", luz);
        } else {
            printf("Entrada inválida. Por favor ingrese un número del 1 al 5.\n");
        }
    }
}

