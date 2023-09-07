// Materia: Programaci�n I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creaci�n: 04/07/2023

// Fecha modificaci�n: 07/09/2023

// N�mero de ejericio: 4

// Problema planteado: En la segunda temporada de The Walking Dead, los personajes llegaron a una
// c�rcel para refugiarse. La c�rcel estaba rodeada de vallas por lo que los muertos
// vivientes no pod�an entrar en ella. Sin embargo, dentro de las instalaciones aun
// exist�an muertos vivientes que amenazaban a los personajes. Por tanto, Rick y
// otros miembros del grupo decidieron ir a investigar las instalaciones con el fin
// de determinar cu�les eran los lugares seguros. Para lograr su objetivo
// construyeron un mapa basado en una matriz que indicaba las zonas seguras.
// Despu�s de un tiempo, tu grupo llega al mismo complejo y encuentra el mapa
// hecho por Rick. Para mantener a salvo a tus amigos decides dise�ar e
// implementar un programa que te ayude a determinar las zonas seguras.
// Tu trabajo es determinar los siguientes datos:
// a) Mostrar la matriz que describe el �rea.
// b) Mostrar el n�mero de filas y columnas que no tienen un muerto viviente.
// c) Determinar las coordenadas de los muertos vivientes en la matriz. Utilice vectores
// paralelos para almacenar la posici�n de los muertos vivientes. Un vector almacenara el
// �ndice de la fila y otro vector almacenara el �ndice de la columna.
// d) La cantidad de muertos vivientes que existen en toda la matriz.
// e) Determinar si dos o m�s muertos vivientes se encuentran en la primera columna. Si
// es as� imprimir �no es posible entrar al complejo� de otro modo imprimir �es posible
// entrar al complejo�.
// NOTA 1.- INICIALIZE LA SIGUIENTE MATRIZ COMO CONSTANTE PARA
// PROBAR SU PROGRAMA
// x o x o
// o o o o
// o o x o
// Las "o" describen lugares seguros mientras que las "x" describen los lugares con un
// muerto viviente.
// NOTA 2.- AYUDA --> PUEDE DECLARAR DOS VARIABLES GLOBALES
// CONSTANTES PARA DETERMINAR EL TAMANO DE LA MATRIZ
// NOTA 3.- CADA INCISO DEBE SER RESUELTO CON UNA FUNCION
// ESTRICTAMENTE, EXCEPTO EL ULTIMO INCISO QUE NO REQUIERE DE
// UNA FUNCION.
// EJEMPLOS:
// 1. a) Mostrar matriz
// x o o o
// o o o o
// x o o o
// b) filas libres:1
//    columnas libres:3
// c) Posiciones en la matriz:
// 0 -- 0
// 2 -- 0
// d) total muertos viviente: 2
// e) no es posi le entrar al complejo!
// f) espacio libre: 13
// 2. a) Mostrar matriz
// o o o o
// o x x o
// x o o o
// b) filas libres:1
// columnas libres:1
// c) posiciones en la matriz:
// 1 -- 1
// 1 -- 2
// 2 -- 0
// d) total muertos vivientes: 3
// e) es posible entrar al complejo!
// f) espacio libre : ?
#include <iostream>
#include <vector>

using namespace std;

// Tama�o de la matriz
const int FILAS = 3;
const int COLUMNAS = 4;

// Funci�n para mostrar la matriz
void mostrarMatriz(const vector<vector<char>>& matriz) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Funci�n para contar filas y columnas seguras
void contarFilasColumnas(const vector<vector<char>>& matriz, int& filasLibres, int& columnasLibres) {
    filasLibres = 0;
    columnasLibres = 0;

    for (int i = 0; i < FILAS; i++) {
        bool filaSegura = true;
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] == 'x') {
                filaSegura = false;
                break;
            }
        }
        if (filaSegura) {
            filasLibres++;
        }
    }

    for (int j = 0; j < COLUMNAS; j++) {
        bool columnaSegura = true;
        for (int i = 0; i < FILAS; i++) {
            if (matriz[i][j] == 'x') {
                columnaSegura = false;
                break;
            }
        }
        if (columnaSegura) {
            columnasLibres++;
        }
    }
}

// Funci�n para determinar las coordenadas de los muertos vivientes
void encontrarMuertosVivientes(const vector<vector<char>>& matriz, vector<int>& filasMuertos, vector<int>& columnasMuertos, int& totalMuertos) {
    totalMuertos = 0;
    filasMuertos.clear();
    columnasMuertos.clear();

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] == 'x') {
                totalMuertos++;
                filasMuertos.push_back(i);
                columnasMuertos.push_back(j);
            }
        }
    }
}

int main() {
    // Matriz de ejemplo
    vector<vector<char>> matriz = {
        {'x', 'o', 'x', 'o'},
        {'o', 'o', 'o', 'o'},
        {'o', 'o', 'x', 'o'}
    };

    // a) Mostrar matriz
    cout << "a) Mostrar matriz" << endl;
    mostrarMatriz(matriz);

    int filasLibres, columnasLibres;
    // b) Contar filas y columnas libres
    contarFilasColumnas(matriz, filasLibres, columnasLibres);
    cout << "b) Filas libres: " << filasLibres << endl;
    cout << "   Columnas libres: " << columnasLibres << endl;

    vector<int> filasMuertos, columnasMuertos;
    int totalMuertos;
    // c) Encontrar coordenadas de los muertos vivientes
    encontrarMuertosVivientes(matriz, filasMuertos, columnasMuertos, totalMuertos);
    cout << "c) Posiciones en la matriz:" << endl;
    for (int i = 0; i < totalMuertos; i++) {
        cout << filasMuertos[i] << " -- " << columnasMuertos[i] << endl;
    }
    cout << "d) Total muertos vivientes: " << totalMuertos << endl;

    // e) Determinar si dos o m�s muertos vivientes se encuentran en la primera columna
    bool primeraColumnaSegura = true;
    for (int i = 0; i < totalMuertos; i++) {
        if (columnasMuertos[i] == 0) {
            primeraColumnaSegura = false;
            break;
        }
    }

    if (primeraColumnaSegura) {
        cout << "e) Es posible entrar al complejo!" << endl;
    } else {
        cout << "e) No es posible entrar al complejo!" << endl;
    }

    // f) Espacio libre
    int espacioLibre = FILAS * COLUMNAS - totalMuertos;
    cout << "f) Espacio libre: " << espacioLibre << endl;

    return 0;
}

