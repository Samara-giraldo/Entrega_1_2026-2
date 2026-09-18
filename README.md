# JUEGO DE CARTAS
# Juego de Cartas Dinámico 🃏

## Introducción
Este proyecto es una implementación en C++ de un juego de cartas dinámico para 4 jugadores. Combina mecánicas de estrategia, descarte y evaluación lógica en tiempo real, donde las reglas de victoria cambian en cada ronda según la condición impuesta por el jugador activo.

## Descripción del Proyecto
El sistema está diseñado bajo el paradigma de **Programación Orientada a Objetos (POO)**. Cuenta con un mazo estructurado de 16 cartas divididas en 4 colores. En cada turno, un jugador asume el rol activo y dicta la regla de la ronda (por ejemplo: *"el valor más alto"*, *"el valor más bajo"* o *"el azul más alto"*). Los demás jugadores deben responder lanzando cartas de sus manos para intentar llevarse las cartas de la mesa y acumular puntos.

---

## Reglas del Juego

1. **Estructura de Cartas:**
   * El mazo contiene 16 cartas en total (4 colores distintos con valores del 1 al 4 cada uno).
2. **Distribución Inicial:**
   * Cada uno de los 4 jugadores recibe 4 cartas al comenzar la partida.
3. **Mecánica de Ronda:**
   * El **Jugador Activo** impone una regla verbal o lógica para la ronda.
   * Todos los jugadores juegan una carta de su mano intentando cumplir la regla impuesta.
4. **Sistema de Puntuación:**
   * El jugador que mejor cumpla la condición impuesta se lleva las 4 cartas de la mesa.
   * Cada carta recolectada equivale a **1 punto** (4 puntos por ronda ganada).
5. **Fin del Juego:**
   * La partida concluye cuando los jugadores se quedan sin cartas en la mano.
   * El jugador con más puntos acumulados es declarado ganador.

---

## Manual de Usuario (Cómo Jugar)

1. Al ejecutar el juego, el sistema repartirá las cartas automáticamente a los 4 jugadores.
2. En cada ronda, se mostrará en pantalla cuál es el **Jugador Activo** y la **Regla de la Ronda**.
3. Los jugadores lanzarán sus cartas a la mesa.
4. El sistema evaluará automáticamente qué carta cumple mejor la regla, anunciará al ganador de la ronda y le sumará los puntos correspondientes.
5. Al finalizar las 4 rondas, se mostrará la tabla final de puntuaciones y el ganador de la partida.

---

## Cómo Ponerlo a Funcionar

### Requisitos Previos
* Tener instalado un compilador de C++ compatible con C++11 o superior (`g++`, `clang++`, o Visual Studio).

### Compilación y Ejecución desde Terminal

1. **Clonar el repositorio:**
   ```bash
   git clone [https://github.com/tu-usuario/tu-repositorio.git](https://github.com/tu-usuario/tu-repositorio.git)
   cd tu-repositorio
<img width="1600" height="900" alt="WhatsApp Image 2026-09-17 at 11 09 41 PM" src="https://github.com/user-attachments/assets/e7c31627-3218-47b9-84e0-d0be148a928c" />

