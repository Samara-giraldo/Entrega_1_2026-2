#ifndef JUEGO_CPP
#define JUEGO_CPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

class Juego {
private:
    Mazo _mazo;
    std::vector<Jugador> _jugadores;

    // Guarda los eventos de la partida en el disco duro
    void guardarProgresoEnDisco(const std::string& texto) {
        std::ofstream archivo("partida_guardada.txt", std::ios::app);
        if (archivo.is_open()) {
            archivo << texto << "\n";
            archivo.close();
            std::cout << ">> [DISCO OK] Registro guardado en 'partida_guardada.txt'\n";
        } else {
            std::cout << ">> [ERROR] No se pudo escribir en el disco.\n";
        }
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

        // REPARTO INICIAL: Exactamente 4 cartas a cada uno de los 4 jugadores
        for (int i = 0; i < 4; ++i) {
            for (auto& jug : _jugadores) {
                jug.recibirCarta(_mazo.repartir());
            }
        }

        guardarProgresoEnDisco("=== NUEVA PARTIDA INTERACTIVA (4 CARTAS) ===");

        // Bucle de las 4 rondas (1 carta jugada por ronda)
        for (int ronda = 1; ronda <= 4; ++ronda) {
            std::cout << "\n========================================\n";
            std::cout << "               RONDA " << ronda << "\n";
            std::cout << "========================================\n";

            std::vector<Carta> mesa;

            // --- TURNO DEL JUGADOR HUMANO (SELECCIÓN REAL) ---
            std::cout << "\nTus cartas disponibles:\n";
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

            // Lanzar la carta elegida por el jugador
            Carta cartaHumano = _jugadores[0].jugarCartaPorIndice(seleccion - 1);
            mesa.push_back(cartaHumano);
            std::cout << "\nLanzaste a la mesa: " << cartaHumano.getColor() << " " << cartaHumano.getValor() << "\n";

            // --- TURNO DE LOS OTROS JUGADORES (BOTS) ---
            for (size_t i = 1; i < _jugadores.size(); ++i) {
                Carta c = _jugadores[i].jugarCartaAuto();
                mesa.push_back(c);
                std::cout << _jugadores[i].getNombre() << " jugo: " << c.getColor() << " " << c.getValor() << "\n";
            }

            // Evaluar el ganador según la regla
            int idxGanador = Regla::evaluarGanadorRonda(mesa);
            _jugadores[idxGanador].sumarPunto();

            std::cout << "\n>> ¡Gana la ronda " << ronda << ": " << _jugadores[idxGanador].getNombre() << "!\n";

            // Guardado en el disco duro
            std::string datosRonda = "Ronda " + std::to_string(ronda) + " | Ganador: " + 
                                     _jugadores[idxGanador].getNombre() + 
                                     " | Carta: " + mesa[idxGanador].getColor() + " " + std::to_string(mesa[idxGanador].getValor());
            
            guardarProgresoEnDisco(datosRonda);
        }

        // --- RESULTADOS FINALES ---
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