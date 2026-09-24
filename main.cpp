#include <iostream>
#include <string>

#include "src/Carta.cpp"
#include "src/Jugador.cpp"
#include "src/Mazo.cpp"
#include "src/Regla.cpp"
#include "src/Juego.cpp"

int main() {
    std::string nombreUsuario;

    std::cout << "====================================\n";
    std::cout << "   JUEGO DE CARTAS INTERACTIVO      \n";
    std::cout << "====================================\n\n";

    std::cout << "Ingresa tu nombre para unirte como jugador: ";
    std::cin >> nombreUsuario;

    std::cout << "\nHola " << nombreUsuario << ", listo para comenzar el juego.\n";
    std::cout << "En cada ronda podras elegir una condicion diferente.\n";

    Juego miJuego(nombreUsuario);
    miJuego.iniciarPartida();

    return 0;
}