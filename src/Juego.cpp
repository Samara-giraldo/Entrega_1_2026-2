#ifndef JUEGO_CPP
#define JUEGO_CPP

#include <iostream>
#include <vector>
#include "Jugador.cpp"
#include "Mazo.cpp"
#include "Regla.cpp"

class Juego {
private:
    std::vector<Jugador> _jugadores; // Lista de los 4 jugadores
    Mazo _mazo;                     // El mazo de cartas
    Regla _regla;                   // La regla del juego

public:
    // Constructor: Recibe los nombres de los 4 jugadores
    Juego(std::string j1, std::string j2, std::string j3, std::string j4) 
        : _regla("El valor más alto gana la ronda") {
        
        _jugadores.push_back(Jugador(j1));
        _jugadores.push_back(Jugador(j2));
        _jugadores.push_back(Jugador(j3));
        _jugadores.push_back(Jugador(j4));
    }

    // Inicia y controla toda la partida
    void iniciar() {
        std::cout << "========================================\n";
        std::cout << "   ¡INICIANDO EL JUEGO DE CARTAS!\n";
        std::cout << "   Regla: " << _regla.descripcion() << "\n";
        std::cout << "========================================\n\n";

        // 1. Mezclar el mazo
        _mazo.mezclar();

        // 2. Bucle principal: jugar rondas mientras el mazo no esté vacío
        int numeroRonda = 1;
        while (!_mazo.vacio()) {
            std::cout << "--- Ronda " << numeroRonda << " ---\n";

            // Repartir 1 carta a cada jugador
            for (size_t i = 0; i < _jugadores.size(); i++) {
                _jugadores[i].recibirCarta(_mazo.tomarCarta());
            }

            // Cada jugador lanza su carta a la mesa
            std::vector<std::pair<Jugador*, Carta>> mesa;
            for (size_t i = 0; i < _jugadores.size(); i++) {
                Carta cartaLanzada = _jugadores[i].lanzarCarta();
                
                std::cout << _jugadores[i].nombre() << " jugo: " 
                          << cartaLanzada.color() << " " << cartaLanzada.valor() << "\n";

                // Guardamos en la mesa quién jugó qué carta
                mesa.push_back({&_jugadores[i], cartaLanzada});
            }

            // Evaluar quién gana la ronda usando la Regla
            Jugador* ganadorRonda = _regla.evaluarGanador(mesa);
            ganadorRonda->agregarPuntos(1); // El ganador recibe 1 punto

            std::cout << ">> Gana la ronda: " << ganadorRonda->nombre() << "!\n\n";
            numeroRonda++;
        }

        // 3. Mostrar el resultado final
        mostrarGanadorFinal();
    }

private:
    // Determina quién acumuló más puntos al final
    void mostrarGanadorFinal() {
        std::cout << "========================================\n";
        std::cout << "             PUNTUACION FINAL\n";
        std::cout << "========================================\n";

        Jugador* ganadorFinal = &_jugadores[0];

        for (size_t i = 0; i < _jugadores.size(); i++) {
            std::cout << _jugadores[i].nombre() << ": " 
                      << _jugadores[i].puntos() << " puntos\n";

            if (_jugadores[i].puntos() > ganadorFinal->puntos()) {
                ganadorFinal = &_jugadores[i];
            }
        }

        std::cout << "\n========================================\n";
        std::cout << " ¡EL GANADOR DE LA PARTIDA ES: " << ganadorFinal->nombre() << "! \n";
        std::cout << "========================================\n";
    }
};

#endif