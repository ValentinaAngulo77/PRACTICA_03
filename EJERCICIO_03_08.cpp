// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 04/07/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 8

// Problema planteado: Multiplique dos matrices una de N x M y la otra de M x N
#include <iostream>

using namespace std;

int main() {
    int N, M;

    // Solicitar al usuario las dimensiones de las matrices
    cout << "Ingrese el número de filas (N) de la primera matriz: ";
    cin >> N;
    cout << "Ingrese el número de columnas (M) de la primera matriz: ";
    cin >> M;

    // Verificar si las dimensiones permiten la multiplicación
    int M2;
    cout << "Ingrese el número de columnas (M2) de la segunda matriz: ";
    cin >> M2;
    if (M != M2) {
        cout << "No se pueden multiplicar las matrices. Las dimensiones no son compatibles." << endl;
        return 1;
    }

    // Declarar las dos matrices
    int matriz1[N][M];
    int matriz2[M][N];
    int resultado[N][N];

    // Leer la primera matriz
    cout << "Ingrese los elementos de la primera matriz:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matriz1[i][j];
        }
    }

    // Leer la segunda matriz
    cout << "Ingrese los elementos de la segunda matriz:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matriz2[i][j];
        }
    }

    // Inicializar la matriz resultado con ceros
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i][j] = 0;
        }
    }

    // Realizar la multiplicación de matrices
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    // Imprimir la matriz resultado
    cout << "Matriz resultado de la multiplicación:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << resultado[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
