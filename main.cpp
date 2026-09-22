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

    std::cout << "Ingresa tu nombre para iniciar: ";
    std::cin >> nombreUsuario;

    std::cout << "\nHola " << nombreUsuario << ", elige la regla para la partida:\n";
    std::cout << "1. Valor mas alto gana (Desempate por Color: Rojo > Azul > Verde > Amarillo)\n";
    std::cout << "2. Regla Personalizada (Elegir Color de Triunfo Dominante)\n";
    std::cout << "Selecciona una opcion (1 o 2): ";
    std::cin >> opcionRegla;

    Regla reglaJuego(opcionRegla);

    if (opcionRegla == 2) {
        std::string colorTriunfo;
        std::string desc;

        std::cout << "\n--- CONFIGURACION DE REGLA PERSONALIZADA ---\n";
        std::cout << "Escribe una breve descripcion para tu regla: ";
        std::cin.ignore(10000, '\n');
        std::getline(std::cin, desc);
        reglaJuego.setDescripcionPersonalizada(desc);

        std::cout << "Elige el Color de Triunfo que le gana a los demas (Rojo, Azul, Verde, Amarillo): ";
        std::cin >> colorTriunfo;
        reglaJuego.setColorTriunfo(colorTriunfo);

        std::cout << "\n>> Regla activada: Cartas de color " << colorTriunfo << " dominan la mesa.\n";
    } else {
        std::cout << "\n>> Regla activada: Valor mas alto gana (Jerarquia de colores para desempate activa).\n";
    }

    std::cout << "\n¡Perfecto! Repartiendo 4 cartas a cada jugador e iniciando la partida...\n";

    Juego miJuego(nombreUsuario, reglaJuego);
    miJuego.iniciarPartida();

    return 0;
}