// biblioteca.c
#include "biblioteca.h"
#include <wiringPi.h>

// Definir pines GPIO (Modificar según tu configuración)
const int pinLuces[5] = {0, 1, 2, 3, 4};
const int pinPuertas[4] = {5, 6, 7, 8};

// Estados de las luces
bool estadoLuces[5] = {false, false, false, false, false};

void setupGPIO() {
    wiringPiSetup();
    for (int i = 0; i < 5; ++i) {
        pinMode(pinLuces[i], OUTPUT);
    }
    for (int i = 0; i < 4; ++i) {
        pinMode(pinPuertas[i], INPUT);
        pullUpDnControl(pinPuertas[i], PUD_UP);
    }
}

void toggleLuz(int luzIndex) {
    estadoLuces[luzIndex] = !estadoLuces[luzIndex];
    digitalWrite(pinLuces[luzIndex], estadoLuces[luzIndex] ? HIGH : LOW);
}

void toggleLuzCuarto() { toggleLuz(0); }
void toggleLuzSala() { toggleLuz(1); }
void toggleLuzCuarto2() { toggleLuz(2); }
void toggleLuzBano() { toggleLuz(3); }
void toggleLuzCocina() { toggleLuz(4); }

bool leerPuerta(int puertaIndex) {
    return digitalRead(pinPuertas[puertaIndex]) == LOW;
}

bool leerPuertaPrincipal() { return leerPuerta(0); }
bool leerPuertaCuarto() { return leerPuerta(1); }
bool leerPuertaBano() { return leerPuerta(2); }
bool leerPuertaCuarto2() { return leerPuerta(3); }

