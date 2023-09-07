// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 04/07/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 5

// Problema planteado:Generar la matriz para un orden NxN
// Sea n=5
// 1 2 3 4 5
// 3 4 5 6 7
// 5 6 7 8 9
// 7 8 9 10 11
// 9 10 11 12 13
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    // Solicitar al usuario el valor de n (tamaño de la matriz)
    cout << "Ingrese el valor de n: ";
    cin >> n;

    // Crear una matriz n x n
    vector<vector<int>> matriz(n, vector<int>(n));

    // Inicializar la matriz con el patrón dado
    int valor = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = valor;
            valor += 2;
        }
    }

    // Imprimir la matriz resultante
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
