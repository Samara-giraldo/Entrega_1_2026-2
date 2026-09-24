## Juego de Cartas en C++

Desarrollamos un juego de cartas para 4 jugadores en C++, aplicando programación orientada a objetos para que el código sea ordenado y fácil de entender.

## Descripción del Proyecto
El objetivo de este proyecto es simular una partida de cartas donde 4 jugadores (Samara, Maria, Esteban y Felipe) compiten a lo largo de varias rondas.

A diferencia de los juegos tradicionales donde las reglas son siempre fijas, aquí la regla para ganar cambia en cada ronda según la condición que imponga el jugador activo. Esto hace que cada partida sea dinámica y estratégica.

## Reglas del Juego
La Baraja: El juego cuenta con un mazo de 32 cartas divididas en 4 colores (Rojo, Azul, Verde y Amarillo). Cada color tiene números del 1 al 8.

Los Jugadores: Participan 4 jugadores en total. A cada uno se le reparte la misma cantidad de cartas al inicio.

Las Rondas: En cada turno, los jugadores lanzan una carta a la mesa.

Cómo se Gana una Ronda: Quien lanza la carta que cumple con la regla de esa ronda, se lleva el punto.

El Ganador Final: Al quedarse sin cartas, se cuentan los puntos acumulados por cada jugador y quien tenga más puntos gana la partida.

## Manual del Juego
El juego funciona de forma automática siguiedno estos pasos:

Inicio: El programa crea a los 4 jugadores y baraja el mazo completo.

Reparto: Se entregan las cartas equitativamente a cada participante.

Desarrollo de la Ronda:

Se anuncia quién es el jugador activo de la ronda.

Cada jugador selecciona y lanza una carta de su mano.

El programa evalúa todas las cartas sobre la mesa, aplica la regla vigente y anuncia al ganador de la ronda.

Final del Juego: El sistema muestra una tabla de puntuación final con los puntos de cada uno y anuncia al ganador definitivo.

## Cómo ponerlo a funcionar
Para probar el juego desde la terminal (en tu computador o en GitHub Codespaces), solo debes ejecutar estos dos comandos:

Para compilar y ejecutar el proyecto desde la terminal:

```bash
g++ -std=c++11 main.cpp src/*.cpp -o juego_cartas
./juego_cartas
```

## **EJEMPLO**











## DIAGRAMA UML
<img width="1600" height="900" alt="WhatsApp Image 2026-09-17 at 11 09 41 PM" src="https://github.com/user-attachments/assets/b884642d-a1d8-492a-987a-7505f3460c7a" />



