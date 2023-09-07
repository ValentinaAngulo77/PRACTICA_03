// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 04/07/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 2

// Problema planteado: Generar la matriz espiral para un orden n :
// Sea n=3:
// 1 2 3
// 8 9 4
// 7 6 5
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    // Solicitar al usuario el orden de la matriz (n)
    cout << "Ingrese el orden de la matriz (n): ";
    cin >> n;

    // Crear una matriz n x n
    vector<vector<int>> matriz(n, vector<int>(n));

    int valor = 1; // Valor inicial
    int filaInicio = 0, filaFin = n - 1;
    int columnaInicio = 0, columnaFin = n - 1;

    while (valor <= n * n) {
        // Llenar fila superior
        for (int i = columnaInicio; i <= columnaFin; i++) {
            matriz[filaInicio][i] = valor++;
        }
        filaInicio++;

        // Llenar columna derecha
        for (int i = filaInicio; i <= filaFin; i++) {
            matriz[i][columnaFin] = valor++;
        }
        columnaFin--;

        // Llenar fila inferior
        if (filaInicio <= filaFin) {
            for (int i = columnaFin; i >= columnaInicio; i--) {
                matriz[filaFin][i] = valor++;
            }
            filaFin--;
        }

        // Llenar columna izquierda
        if (columnaInicio <= columnaFin) {
            for (int i = filaFin; i >= filaInicio; i--) {
                matriz[i][columnaInicio] = valor++;
            }
            columnaInicio++;
        }
    }

    // Imprimir la matriz espiral
    cout << "Matriz espiral para n=" << n << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
