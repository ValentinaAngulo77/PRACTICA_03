// Materia: Programaci�n I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creaci�n: 04/07/2023

// Fecha modificaci�n: 07/09/2023

// N�mero de ejericio: 13

// Problema planteado:La farmacia FARMACARP tiene N sucursales, leer sus ventas por mes de un
// a�o entero de cada sucursal y calcule:
// a. Total, de ventas
// b. Total, de ventas por sucursal.
// c. Sucursal que m�s ha vendido.
// d. Sucursal que menos ha vendido.
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;

    // Solicitar al usuario el n�mero de sucursales (N)
    cout << "Ingrese el n�mero de sucursales (N): ";
    cin >> N;

    vector<vector<double>> ventasAnuales(N, vector<double>(12)); // Matriz para almacenar las ventas mensuales de cada sucursal

    // Leer las ventas mensuales de cada sucursal
    for (int i = 0; i < N; i++) {
        cout << "Sucursal " << i + 1 << ":" << endl;
        for (int j = 0; j < 12; j++) {
            cout << "Ventas en el mes " << j + 1 << ": ";
            cin >> ventasAnuales[i][j];
        }
    }

    // Calcular el total de ventas
    double totalVentas = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 12; j++) {
            totalVentas += ventasAnuales[i][j];
        }
    }

    // Calcular el total de ventas por sucursal
    vector<double> totalVentasPorSucursal(N, 0.0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 12; j++) {
            totalVentasPorSucursal[i] += ventasAnuales[i][j];
        }
    }

    // Encontrar la sucursal que m�s ha vendido
    int sucursalMasVendio = 0;
    double maxVentas = totalVentasPorSucursal[0];
    for (int i = 1; i < N; i++) {
        if (totalVentasPorSucursal[i] > maxVentas) {
            maxVentas = totalVentasPorSucursal[i];
            sucursalMasVendio = i;
        }
    }

    // Encontrar la sucursal que menos ha vendido
    int sucursalMenosVendio = 0;
    double minVentas = totalVentasPorSucursal[0];
    for (int i = 1; i < N; i++) {
        if (totalVentasPorSucursal[i] < minVentas) {
            minVentas = totalVentasPorSucursal[i];
            sucursalMenosVendio = i;
        }
    }

    // Mostrar resultados
    cout << "a. Total de ventas: " << totalVentas << endl;
    cout << "b. Total de ventas por sucursal:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "   Sucursal " << i + 1 << ": " << totalVentasPorSucursal[i] << endl;
    }
    cout << "c. Sucursal que m�s ha vendido: Sucursal " << sucursalMasVendio + 1 << " (" << maxVentas << " ventas)" << endl;
    cout << "d. Sucursal que menos ha vendido: Sucursal " << sucursalMenosVendio + 1 << " (" << minVentas << " ventas)" << endl;

    return 0;
}
