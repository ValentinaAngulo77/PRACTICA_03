// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 04/07/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 6

// Problema planteado: Generar una matriz NxN, que se llene con la serie de Fibonacci.

#include <iostream>

using namespace std;

// Función para calcular el término de Fibonacci dado un número
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int N;

    // Solicitar al usuario el tamaño de la matriz (N)
    cout << "Ingrese el tamaño de la matriz (N): ";
    cin >> N;

    int matriz[N][N];

    // Llenar la matriz con la serie de Fibonacci
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = fibonacci(i * N + j);
        }
    }

    // Imprimir la matriz
    cout << "Matriz NxN con la serie de Fibonacci:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
