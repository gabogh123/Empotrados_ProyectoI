// biblioteca.h
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdbool.h>

void setupGPIO();
void toggleLuzCuarto();
void toggleLuzSala();
void toggleLuzCuarto2();
void toggleLuzBano();
void toggleLuzCocina();
bool leerPuertaPrincipal();
bool leerPuertaCuarto();
bool leerPuertaBano();
bool leerPuertaCuarto2();

#endif

