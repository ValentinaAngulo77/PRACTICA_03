// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 04/07/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 9

// Problema planteado: Traspones una matriz de N x M
// 1  0  T
//           1  2  3
// 2  4   =
//           0  4  5
// 3  5
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;

    // Solicitar al usuario las dimensiones de la matriz
    cout << "Ingrese el número de filas (N): ";
    cin >> N;
    cout << "Ingrese el número de columnas (M): ";
    cin >> M;

    // Crear la matriz original de dimensiones NxM
    vector<vector<int>> matriz(N, vector<int>(M));

    // Leer la matriz original desde el usuario
    cout << "Ingrese los elementos de la matriz original:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matriz[i][j];
        }
    }

    // Crear la matriz traspuesta de dimensiones MxN
    vector<vector<int>> traspuesta(M, vector<int>(N));

    // Calcular la matriz traspuesta
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            traspuesta[i][j] = matriz[j][i];
        }
    }

    // Mostrar la matriz traspuesta
    cout << "Matriz traspuesta:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << traspuesta[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
