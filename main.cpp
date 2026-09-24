#include <iostream>
#include <string>
#include "src/Juego.cpp"

int main() {
    std::string nombreUsuario;

    std::cout << "====================================\n";
    std::cout << "   JUEGO DE CARTAS INTERACTIVO      \n";
    std::cout << "====================================\n\n";

    std::cout << "Ingresa tu nombre para unirte como jugador: ";
    std::cin >> nombreUsuario;

    Juego miJuego(nombreUsuario);
    miJuego.iniciarPartida();

    return 0;
}