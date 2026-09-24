#include <iostream>
#include <string>

#include "src/Carta.cpp"
#include "src/Jugador.cpp"
#include "src/Mazo.cpp"
#include "src/Regla.cpp"
#include "src/Juego.cpp"

int main() {
    std::string nombreUsuario;
    int opcionRegla = 1;

    std::cout << "====================================\n";
    std::cout << "   JUEGO DE CARTAS INTERACTIVO      \n";
    std::cout << "====================================\n\n";

    std::cout << "Ingresa tu nombre para unirte como jugador: ";
    std::cin >> nombreUsuario;

    std::cout << "\nHola " << nombreUsuario << ", elige la regla o condicion para la partida:\n";
    std::cout << "1. El Rojo mas alto gana\n";
    std::cout << "2. El Rojo mas bajo gana\n";
    std::cout << "3. El Azul mas alto gana\n";
    std::cout << "4. El Azul mas bajo gana\n";
    std::cout << "5. El Verde mas alto gana\n";
    std::cout << "6. El Verde mas bajo gana\n";
    std::cout << "7. El Amarillo mas alto gana\n";
    std::cout << "8. El Amarillo mas bajo gana\n";
    std::cout << "Selecciona una opcion (1-8): ";
    
    while (!(std::cin >> opcionRegla) || opcionRegla < 1 || opcionRegla > 8) {
        std::cout << "Opcion invalida. Elige un numero del 1 al 8: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    Regla reglaJuego(opcionRegla);

    std::cout << "\n>> Regla seleccionada: " << reglaJuego.getDescripcion() << "\n";
    std::cout << "Repartiendo 4 cartas a cada uno de los 4 jugadores e iniciando...\n";

    Juego miJuego(nombreUsuario, reglaJuego);
    miJuego.iniciarPartida();

    return 0;
}