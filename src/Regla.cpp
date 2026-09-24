#ifndef REGLA_CPP
#define REGLA_CPP

#include <iostream>
#include <vector>
#include <string>
#include "Carta.cpp"

class Regla {
private:
    int _opcionSeleccionada;
    std::string _descripcion;

public:
    Regla(int opcion = 1) : _opcionSeleccionada(opcion) {
        setOpcion(opcion);
    }

    void setOpcion(int opcion) {
        _opcionSeleccionada = opcion;
        switch (_opcionSeleccionada) {
            case 1: _descripcion = "El Rojo mas alto gana"; break;
            case 2: _descripcion = "El Rojo mas bajo gana"; break;
            case 3: _descripcion = "El Azul mas alto gana"; break;
            case 4: _descripcion = "El Azul mas bajo gana"; break;
            case 5: _descripcion = "El Verde mas alto gana"; break;
            case 6: _descripcion = "El Verde mas bajo gana"; break;
            case 7: _descripcion = "El Amarillo mas alto gana"; break;
            case 8: _descripcion = "El Amarillo mas bajo gana"; break;
            default: _descripcion = "El Rojo mas alto gana"; break;
        }
    }

    std::string getDescripcion() const { return _descripcion; }

    int evaluarGanadorRonda(const std::vector<Carta>& mesa) const {
        if (mesa.empty()) return 0;

        std::string colorBuscado = "";
        bool buscarMasAlto = true;

        switch (_opcionSeleccionada) {
            case 1: colorBuscado = "Rojo"; buscarMasAlto = true; break;
            case 2: colorBuscado = "Rojo"; buscarMasAlto = false; break;
            case 3: colorBuscado = "Azul"; buscarMasAlto = true; break;
            case 4: colorBuscado = "Azul"; buscarMasAlto = false; break;
            case 5: colorBuscado = "Verde"; buscarMasAlto = true; break;
            case 6: colorBuscado = "Verde"; buscarMasAlto = false; break;
            case 7: colorBuscado = "Amarillo"; buscarMasAlto = true; break;
            case 8: colorBuscado = "Amarillo"; buscarMasAlto = false; break;
            default: colorBuscado = "Rojo"; buscarMasAlto = true; break;
        }

        std::vector<int> candidatosColor;

        // 1. Filtrar las cartas que cumplen con el color objetivo de la regla
        for (size_t i = 0; i < mesa.size(); ++i) {
            if (mesa[i].getColor() == colorBuscado) {
                candidatosColor.push_back(i);
            }
        }

        // CASO A: Hay cartas del color buscado en la mesa
        if (!candidatosColor.empty()) {
            int idxMejor = candidatosColor[0];

            for (size_t i = 1; i < candidatosColor.size(); ++i) {
                int idxActual = candidatosColor[i];
                if (buscarMasAlto) {
                    if (mesa[idxActual].getValor() > mesa[idxMejor].getValor()) {
                        idxMejor = idxActual;
                    }
                } else { // Buscar el más bajo
                    if (mesa[idxActual].getValor() < mesa[idxMejor].getValor()) {
                        idxMejor = idxActual;
                    }
                }
            }
            return idxMejor;
        }

        // CASO B: Nadie jugo el color objetivo. Desempate por la carta jugada primero (el jugador humano) o valor mas alto
        int idxMejor = 0;
        for (size_t i = 1; i < mesa.size(); ++i) {
            if (buscarMasAlto) {
                if (mesa[i].getValor() > mesa[idxMejor].getValor()) {
                    idxMejor = i;
                }
            } else {
                if (mesa[i].getValor() < mesa[idxMejor].getValor()) {
                    idxMejor = i;
                }
            }
        }

        return idxMejor;
    }
};

#endif