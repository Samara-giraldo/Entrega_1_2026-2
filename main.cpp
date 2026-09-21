#include <iostream>
#include <string>

#include "src/Carta.cpp"
#include "src/Jugador.cpp"
#include "src/Mazo.cpp"
#include "src/Regla.cpp"
#include "src/Juego.cpp"

int main() {
    std::string nombreUsuario;
    int opcionRegla;

    std::cout << "====================================\n";
    std::cout << "   JUEGO DE CARTAS INTERACTIVO      \n";
    std::cout << "====================================\n\n";

    // 1. Pedir el nombre del jugador humano por teclado
    std::cout << "Ingresa tu nombre para iniciar: ";
    std::cin >> nombreUsuario;

    // 2. Pedir interacción sobre las reglas
    std::cout << "\nHola " << nombreUsuario << ", elige la regla para la partida:\n";
    std::cout << "1. Carta mas alta gana la ronda\n";
    std::cout << "2. Regla personalizada\n";
    std::cout << "Selecciona una opcion (1 o 2): ";
    std::cin >> opcionRegla;

    std::cout << "\n¡Perfecto! Iniciando la partida e interactuando con la mesa...\n";

    // Iniciar el juego con la entrada del usuario
    Juego miJuego(nombreUsuario);
    miJuego.iniciarPartida();

    return 0;
}