// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 04/07/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 3

// Problema planteado:Generar una matriz de N x N con números al azar entre A y B, y determinar:
// • La suma de la última columna
// • El producto total de la última fila
// • Obtener el mayor valor y su posición
// • Obtener la desviación estándar de todos los elementos de la matriz
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    int N, A, B;

    // Solicitar al usuario el tamaño de la matriz (N), el rango (A y B)
    cout << "Ingrese el tamaño de la matriz (N): ";
    cin >> N;
    cout << "Ingrese el valor mínimo (A): ";
    cin >> A;
    cout << "Ingrese el valor máximo (B): ";
    cin >> B;

    // Inicializar una matriz de NxN con números aleatorios entre A y B
    srand(time(0));
    int matriz[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand() % (B - A + 1) + A;
        }
    }

    // Calcular la suma de la última columna
    int sumaUltimaColumna = 0;
    for (int i = 0; i < N; i++) {
        sumaUltimaColumna += matriz[i][N - 1];
    }

    // Calcular el producto total de la última fila
    int productoUltimaFila = 1;
    for (int j = 0; j < N; j++) {
        productoUltimaFila *= matriz[N - 1][j];
    }

    // Encontrar el mayor valor y su posición
    int mayorValor = matriz[0][0];
    int filaMayor = 0;
    int columnaMayor = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matriz[i][j] > mayorValor) {
                mayorValor = matriz[i][j];
                filaMayor = i;
                columnaMayor = j;
            }
        }
    }

    // Calcular la desviación estándar de todos los elementos de la matriz
    double sumaCuadrados = 0.0;
    double media = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            media += matriz[i][j];
        }
    }
    media /= (N * N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sumaCuadrados += pow(matriz[i][j] - media, 2);
        }
    }

    double desviacionEstandar = sqrt(sumaCuadrados / (N * N));

    // Imprimir los resultados
    cout << "Suma de la última columna: " << sumaUltimaColumna << endl;
    cout << "Producto total de la última fila: " << productoUltimaFila << endl;
    cout << "Mayor valor: " << mayorValor << " (Fila: " << filaMayor << ", Columna: " << columnaMayor << ")" << endl;
    cout << "Desviación estándar de la matriz: " << desviacionEstandar << endl;

    return 0;
}
