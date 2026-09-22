#ifndef REGLA_CPP
#define REGLA_CPP

#include <iostream>
#include <vector>
#include <string>
#include "Carta.cpp"

class Regla {
private:
    int _tipoRegla; // 1: Mayor Valor con Jerarquía de Color | 2: Regla Personalizada
    std::string _descripcionPersonalizada;
    std::string _colorTriunfo; // Color dominante en caso de regla personalizada

public:
    Regla(int tipo = 1) : _tipoRegla(tipo), _colorTriunfo("Rojo") {}

    void setTipoRegla(int tipo) { _tipoRegla = tipo; }
    void setDescripcionPersonalizada(const std::string& desc) { _descripcionPersonalizada = desc; }
    void setColorTriunfo(const std::string& color) { _colorTriunfo = color; }

    int getTipoRegla() const { return _tipoRegla; }
    std::string getDescripcion() const { return _descripcionPersonalizada; }

    // Convierte el color a una jerarquía numérica para desemparar o evaluar prioridad
    static int obtenerPesoColor(const std::string& color) {
        if (color == "Rojo" || color == "rojo") return 4;
        if (color == "Azul" || color == "azul") return 3;
        if (color == "Verde" || color == "verde") return 2;
        if (color == "Amarillo" || color == "amarillo") return 1;
        return 0;
    }

    // Evalúa quién gana la ronda considerando el Valor Y el Color
    int evaluarGanadorRonda(const std::vector<Carta>& mesa) const {
        if (mesa.empty()) return 0;

        int indiceGanador = 0;

        if (_tipoRegla == 1) {
            // REGLA 1: Gana el valor más alto. Si hay empate en valor, desempata la jerarquía de color (Rojo > Azul > Verde > Amarillo)
            for (size_t i = 1; i < mesa.size(); ++i) {
                if (mesa[i].getValor() > mesa[indiceGanador].getValor()) {
                    indiceGanador = i;
                } else if (mesa[i].getValor() == mesa[indiceGanador].getValor()) {
                    // Desempate por color
                    if (obtenerPesoColor(mesa[i].getColor()) > obtenerPesoColor(mesa[indiceGanador].getColor())) {
                        indiceGanador = i;
                    }
                }
            }
        } else if (_tipoRegla == 2) {
            // REGLA 2 (Personalizada): Las cartas del Color de Triunfo/Predilecto ganan automáticamente sobre otros colores.
            // Si hay varias del color triunfo, gana la de mayor valor.
            for (size_t i = 1; i < mesa.size(); ++i) {
                bool cartaActualEsTriunfo = (mesa[i].getColor() == _colorTriunfo);
                bool cartaGanadoraEsTriunfo = (mesa[indiceGanador].getColor() == _colorTriunfo);

                if (cartaActualEsTriunfo && !cartaGanadoraEsTriunfo) {
                    indiceGanador = i;
                } else if (cartaActualEsTriunfo && cartaGanadoraEsTriunfo) {
                    if (mesa[i].getValor() > mesa[indiceGanador].getValor()) {
                        indiceGanador = i;
                    }
                } else if (!cartaActualEsTriunfo && !cartaGanadoraEsTriunfo) {
                    if (mesa[i].getValor() > mesa[indiceGanador].getValor()) {
                        indiceGanador = i;
                    }
                }
            }
        }

        return indiceGanador;
    }
};

#endif