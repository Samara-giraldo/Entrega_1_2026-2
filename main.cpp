#include <iostream>
#include <string>
#include "src/Carta.cpp"
#include "src/Mazo.cpp"
#include "src/Jugador.cpp"
#include "src/Regla.cpp"
#include "src/Juego.cpp"

int main() {
    std::cout << "========================================\n";
    std::cout << "      JUEGO DE CARTAS INTERACTIVO       \n";
    std::cout << "========================================\n\n";

    std::string nombre;
    std::cout << "Ingresa tu nombre para iniciar: ";
    std::cin >> nombre;

    std::cout << "\nHola " << nombre << ", elige la regla para la partida:\n";
    std::cout << "1. Carta mas alta gana la ronda\n";
    std::cout << "2. Regla personalizada\n";
    std::cout << "Selecciona una opcion (1 o 2): ";
    
    int opcion;
    std::cin >> opcion;

    // --- LIMPIEZA DE BUFER DE TECLADO ---
    std::cin.ignore(10000, '\n');

    std::cout << "\n¡Perfecto! Iniciando la partida e interactuando con la mesa...\n";

    // Iniciar el juego
    Juego miJuego(nombre);
    miJuego.iniciarPartida();

    return 0;
}