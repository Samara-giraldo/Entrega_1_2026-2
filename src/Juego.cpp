std::cout << "\n========================================\n";
        std::cout << "           PUNTUACION FINAL             \n";
        std::cout << "========================================\n";

        int maxPuntos = -1;
        for (const auto& jug : _jugadores) {
            std::cout << jug.getNombre() << ": " << jug.getPuntos() << " puntos\n";
            if (jug.getPuntos() > maxPuntos) {
                maxPuntos = jug.getPuntos();
            }
        }

        // Buscar todos los jugadores que alcanzaron el puntaje maximo
        std::vector<std::string> ganadores;
        for (const auto& jug : _jugadores) {
            if (jug.getPuntos() == maxPuntos) {
                ganadores.push_back(jug.getNombre());
            }
        }

        std::string mensajeGanador = "";
        if (ganadores.size() > 1) {
            mensajeGanador = "EMPATE ENTRE: ";
            for (size_t i = 0; i < ganadores.size(); ++i) {
                mensajeGanador += ganadores[i];
                if (i < ganadores.size() - 1) mensajeGanador += " Y ";
            }
        } else {
            mensajeGanador = "GANADOR DE LA PARTIDA: " + ganadores[0];
        }

        std::cout << "\n¡" << mensajeGanador << "!\n";
        guardarProgresoEnDisco(mensajeGanador + " con " + std::to_string(maxPuntos) + " puntos\n---");
    }
};