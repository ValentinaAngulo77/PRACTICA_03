// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 04/07/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 11

// Problema planteado: Realizar el típico juego del 3 en raya, donde habrá dos jugadores que tengan que
// hacer el 3 en raya, los signos serán el X y el O, cuando haya una posición vacía
// habrá un – El tablero de juego, será una matriz de 3×3 de char.
// El juego termina cuando uno de los jugadores hace 3 en raya o si no hay más
// posiciones que poner.
// El juego debe pedir las posiciones donde el jugador actual quiera poner su
// marca, esta debe ser validada y por supuesto que no haya una marca ya puesta.
// Por último mostrar la matriz del juego y muestra al ganador.
#include <iostream>

using namespace std;

// Función para inicializar el tablero
void inicializarTablero(char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = '-';
        }
    }
}

// Función para imprimir el tablero
void imprimirTablero(char tablero[3][3]) {
    cout << "Tablero actual:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para verificar si alguien ha ganado
bool verificarGanador(char tablero[3][3], char jugador) {
    // Verificar filas y columnas
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador)
            return true;
        if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)
            return true;
    }

    // Verificar diagonales
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador)
        return true;
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)
        return true;

    return false;
}

// Función para verificar si el tablero está lleno
bool tableroLleno(char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == '-')
                return false;
        }
    }
    return true;
}

int main() {
    char tablero[3][3];
    char jugadorActual = 'X';
    bool juegoTerminado = false;

    inicializarTablero(tablero);

    while (!juegoTerminado) {
        imprimirTablero(tablero);
        cout << "Turno del jugador " << jugadorActual << endl;
        int fila, columna;

        // Pedir al jugador las coordenadas para colocar su marca
        do {
            cout << "Ingrese fila (0, 1, o 2) y columna (0, 1, o 2) separadas por espacio: ";
            cin >> fila >> columna;
        } while (fila < 0 || fila > 2 || columna < 0 || columna > 2 || tablero[fila][columna] != '-');

        // Colocar la marca del jugador en el tablero
        tablero[fila][columna] = jugadorActual;

        // Verificar si el jugador ha ganado
        if (verificarGanador(tablero, jugadorActual)) {
            imprimirTablero(tablero);
            cout << "¡El jugador " << jugadorActual << " ha ganado!" << endl;
            juegoTerminado = true;
        } else if (tableroLleno(tablero)) {
            imprimirTablero(tablero);
            cout << "Empate. No hay más movimientos posibles." << endl;
            juegoTerminado = true;
        }

        // Cambiar al siguiente jugador
        jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
    }

    return 0;
}
