#ifndef REGLA_CPP
#define REGLA_CPP

#include <string>
#include <vector>
#include "Jugador.cpp"

class Regla {
private:
    std::string _descripcion;

public:
    // Constructor: Recibe el texto de la regla (ej: "El número más alto gana")
    Regla(std::string descripcion) : _descripcion(descripcion) {}

    // Devuelve el texto de la regla
    std::string descripcion() const { 
        return _descripcion; 
    }

    // Compara las cartas que están en la mesa y devuelve al jugador ganador
    Jugador* evaluarGanador(const std::vector<std::pair<Jugador*, Carta>>& mesa) {
        Jugador* ganador = mesa[0].first;
        int mejorValor = mesa[0].second.valor();

        // Recorre las cartas lanzadas en la mesa para ver cuál tiene el valor más alto
        for (size_t i = 1; i < mesa.size(); i++) {
            if (mesa[i].second.valor() > mejorValor) {
                mejorValor = mesa[i].second.valor();
                ganador = mesa[i].first;
            }
        }

        return ganador;
    }
};

#endif