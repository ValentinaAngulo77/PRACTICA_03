// Materia: Programaci�n I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creaci�n: 04/07/2023

// Fecha modificaci�n: 07/09/2023

// N�mero de ejericio: 7

// Problema planteado:Efectuar la suma de una matriz tridimensional de orden n x n x n
#include <iostream>
#include <cstdlib> // Para generar n�meros aleatorios

using namespace std;

int main() {
    int N;

    // Solicitar al usuario el tama�o de la matriz tridimensional (N)
    cout << "Ingrese el tama�o de la matriz tridimensional (N): ";
    cin >> N;

    // Crear la matriz tridimensional de orden N x N x N
    int matriz[N][N][N];

    // Inicializar la matriz con valores aleatorios
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                matriz[i][j][k] = rand() % 100; // Valores aleatorios entre 0 y 99
            }
        }
    }

    // Calcular la suma de todos los elementos de la matriz
    long long suma = 0; // Usamos long long para evitar desbordamientos en la suma
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                suma += matriz[i][j][k];
            }
        }
    }

    // Imprimir la suma
    cout << "La suma de todos los elementos de la matriz tridimensional es: " << suma << endl;

    return 0;
}
