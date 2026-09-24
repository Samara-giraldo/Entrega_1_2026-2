#ifndef REGLA_CPP
#define REGLA_CPP

#include <string>
#include <vector>
#include "Carta.cpp"

class Regla {
private:
    int _opcion;

public:
    Regla(int opcion) : _opcion(opcion) {}

    std::string getDescripcion() const {
        switch (_opcion) {
            case 1: return "El Rojo mas alto gana";
            case 2: return "El Rojo mas bajo gana";
            case 3: return "El Azul mas alto gana";
            case 4: return "El Azul mas bajo gana";
            case 5: return "El Verde mas alto gana";
            case 6: return "El Verde mas bajo gana";
            case 7: return "El Amarillo mas alto gana";
            case 8: return "El Amarillo mas bajo gana";
            default: return "Regla invalida";
        }
    }

    int evaluarGanadorRonda(const std::vector<Carta>& mesa) const {
        std::string colorBuscado;
        bool buscaMayor = true;

        switch (_opcion) {
            case 1: colorBuscado = "Rojo"; buscaMayor = true; break;
            case 2: colorBuscado = "Rojo"; buscaMayor = false; break;
            case 3: colorBuscado = "Azul"; buscaMayor = true; break;
            case 4: colorBuscado = "Azul"; buscaMayor = false; break;
            case 5: colorBuscado = "Verde"; buscaMayor = true; break;
            case 6: colorBuscado = "Verde"; buscaMayor = false; break;
            case 7: colorBuscado = "Amarillo"; buscaMayor = true; break;
            case 8: colorBuscado = "Amarillo"; buscaMayor = false; break;
        }

        int idxGanador = -1;
        int mejorValor = buscaMayor ? -1 : 999;

        for (size_t i = 0; i < mesa.size(); ++i) {
            if (mesa[i].getColor() == colorBuscado) {
                if (buscaMayor) {
                    if (mesa[i].getValor() > mejorValor) {
                        mejorValor = mesa[i].getValor();
                        idxGanador = i;
                    }
                } else {
                    if (mesa[i].getValor() < mejorValor) {
                        mejorValor = mesa[i].getValor();
                        idxGanador = i;
                    }
                }
            }
        }

        // Si nadie jugo el color indicado en la regla, gana el primero que jugo
        if (idxGanador == -1) {
            idxGanador = 0;
        }

        return idxGanador;
    }
};

#endif