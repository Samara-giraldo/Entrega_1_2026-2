#include "src/Juego.cpp"

int main() {
    // 1. Crear la instancia del juego con los nombres de 4 jugadores
    Juego partida("Samara", "Maria", "Esteban", "Felipe");

    // 2. Iniciar y ejecutar la partida completa
    partida.iniciar();

    return 0;
}