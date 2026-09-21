#ifndef REGLA_CPP
#define REGLA_CPP

#include <vector>
#include <string>

class Regla {
public:
    static int evaluarGanadorRonda(const std::vector<Carta>& mesa) {
        int indiceGanador = 0;
        int valorMaximo = -1;

        for (size_t i = 0; i < mesa.size(); ++i) {
            if (mesa[i].getValor() > valorMaximo) {
                valorMaximo = mesa[i].getValor();
                indiceGanador = i;
            }
        }
        return indiceGanador;
    }
};

#endif