#ifndef JUEGO_CPP
#define JUEGO_CPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include "Regla.cpp"

class Juego {
private:
    Mazo _mazo;
    std::vector<Jugador> _jugadores;

    void guardarProgresoEnDisco(const std::string& texto) {
        std::ofstream archivo("partida_guardada.txt", std::ios::app);
        if (archivo.is_open()) {
            archivo << texto << "\n";
            archivo.close();
            std::cout << ">> [DISCO OK] Registro guardado en 'partida_guardada.txt'\n";
        }
    }

    int pedirReglaRonda(int numeroRonda) {
        int opcionRegla = 1;
        std::cout << "\n========================================\n";
        std::cout << "           RONDA " << numeroRonda << "\n";
        std::cout << "========================================\n";
        std::cout << "Selecciona la regla para esta ronda:\n";
        std::cout << "1. El Rojo mas alto gana\n";
        std::cout << "2. El Rojo mas bajo gana\n";
        std::cout << "3. El Azul mas alto gana\n";
        std::cout << "4. El Azul mas bajo gana\n";
        std::cout << "5. El Verde mas alto gana\n";
        std::cout << "6. El Verde mas bajo gana\n";
        std::cout << "7. El Amarillo mas alto gana\n";
        std::cout << "8. El Amarillo mas bajo gana\n";
        std::cout << "Opcion (1-8): ";

        while (!(std::cin >> opcionRegla) || opcionRegla < 1 || opcionRegla > 8) {
            std::cout << "Opcion invalida. Elige un numero del 1 al 8: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        return opcionRegla;
    }

public:
    Juego(std::string nombreHumano) {
        _jugadores.push_back(Jugador(nombreHumano));
        _jugadores.push_back(Jugador("Maria"));
        _jugadores.push_back(Jugador("Esteban"));
        _jugadores.push_back(Jugador("Felipe"));
    }

    void iniciarPartida() {
        _mazo.mezclar();

        for (int i = 0; i < 4; ++i) {
            for (auto& jug : _jugadores) {
                jug.recibirCarta(_mazo.repartir());
            }
        }

        guardarProgresoEnDisco("=== NUEVA PARTIDA ===");

        for (int ronda = 1; ronda <= 4; ++ronda) {
            int opcionElegida = pedirReglaRonda(ronda);
            Regla reglaActual(opcionElegida);

            std::cout << "\nCondicion activa: " << reglaActual.getDescripcion() << "\n";

            std::vector<Carta> mesa;

            // Turno del jugador humano
            std::cout << "\nTus cartas disponibles (" << _jugadores[0].getNombre() << "):\n";
            _jugadores[0].mostrarMano();

            int seleccion = 0;
            while (true) {
                std::cout << "\nElige el numero de la carta que quieres lanzar (1 a " 
                          << _jugadores[0].getCantidadCartas() << "): ";
                
                if (std::cin >> seleccion && seleccion >= 1 && seleccion <= _jugadores[0].getCantidadCartas()) {
                    break;
                } else {
                    std::cout << "Opcion invalida. Intenta nuevamente.\n";
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
            }

            Carta cartaHumano = _jugadores[0].jugarCartaPorIndice(seleccion - 1);
            mesa.push_back(cartaHumano);
            std::cout << "\n" << _jugadores[0].getNombre() << " lanzaste a la mesa: " 
                      << cartaHumano.getColor() << " " << cartaHumano.getValor() << "\n";

            // Turno de los otros jugadores
            for (size_t i = 1; i < _jugadores.size(); ++i) {
                Carta c = _jugadores[i].jugarCartaAuto();
                mesa.push_back(c);
                std::cout << _jugadores[i].getNombre() << " jugo: " 
                          << c.getColor() << " " << c.getValor() << "\n";
            }

            int idxGanador = reglaActual.evaluarGanadorRonda(mesa);
            _jugadores[idxGanador].sumarPunto();

            std::cout << "\n>> ¡Gana la ronda " << ronda << ": " << _jugadores[idxGanador].getNombre() 
                      << " con la carta " << mesa[idxGanador].getColor() << " " << mesa[idxGanador].getValor() << "!\n";

            std::string datosRonda = "Ronda " + std::to_string(ronda) + 
                                     " | Condicion: " + reglaActual.getDescripcion() +
                                     " | Ganador: " + _jugadores[idxGanador].getNombre() + 
                                     " | Carta: " + mesa[idxGanador].getColor() + " " + std::to_string(mesa[idxGanador].getValor());
            
            guardarProgresoEnDisco(datosRonda);
        }

        std::cout << "\n========================================\n";
        std::cout << "           PUNTUACION FINAL             \n";
        std::cout << "========================================\n";

        std::string ganadorFinal = _jugadores[0].getNombre();
        int maxPuntos = _jugadores[0].getPuntos();

        for (const auto& jug : _jugadores) {
            std::cout << jug.getNombre() << ": " << jug.getPuntos() << " puntos\n";
            if (jug.getPuntos() > maxPuntos) {
                maxPuntos = jug.getPuntos();
                ganadorFinal = jug.getNombre();
            }
        }

        std::cout << "\n¡GANADOR DE LA PARTIDA: " << ganadorFinal << "!\n";
        guardarProgresoEnDisco("GANADOR FINAL: " + ganadorFinal + " con " + std::to_string(maxPuntos) + " puntos\n---");
    }
};

#endif