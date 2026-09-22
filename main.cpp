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

    std::cout << "Ingresa tu nombre para iniciar: ";
    std::cin >> nombreUsuario;

    std::cout << "\nHola " << nombreUsuario << ", elige la regla para la partida:\n";
    std::cout << "1. Carta mas alta gana la ronda\n";
    std::cout << "2. Regla personalizada\n";
    std::cout << "Selecciona una opcion (1 o 2): ";
    std::cin >> opcionRegla;

    // Limpieza de buffer
    std::cin.ignore(10000, '\n');

    std::cout << "\n¡Perfecto! Repartiendo 4 cartas a cada jugador e iniciando la partida...\n";

    Juego miJuego(nombreUsuario);
    miJuego.iniciarPartida();

    return 0;
}