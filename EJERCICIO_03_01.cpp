// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 04/07/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 1

// Problema planteado: Elabore un programa que lea una matriz de orden n x n y la cambie la fila 1 por
// la fina n.
// Por ejemplo, si la matriz que da el usuario es:
// 4 7 1 3 5
// 2 0 6 9 7
// 3 1 2 6 4
// Entonces el programa debe escribir la matriz :
// 3 1 2 6 4
// 2 0 6 9 7
// 4 7 1 3 5
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

    // Leer la matriz desde el usuario
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    // Intercambiar la fila 1 por la fila n
    for (int j = 0; j < n; j++) {
        swap(matriz[0][j], matriz[n - 1][j]);
    }

    // Imprimir la matriz resultante
    cout << "Matriz con la fila 1 intercambiada por la fila n:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
