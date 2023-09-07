// Materia: Programaci�n I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creaci�n: 04/07/2023

// Fecha modificaci�n: 07/09/2023

// N�mero de ejericio: 12

// Problema planteado:Ingresa una matriz de NxN y a continuaci�n:
// a. Elimine una fila ingresada por el usuario.
// b. Elimine una columna ingresada por el usuario.
// c. Inserte una fila por un valor determinado por el usuario.
// d. Inserte una columna por un valor determinado por el usuario
#include <iostream>
#include <vector>

using namespace std;

// Funci�n para imprimir la matriz
void imprimirMatriz(vector<vector<int>>& matriz) {
    for (size_t i = 0; i < matriz.size(); i++) {
        for (size_t j = 0; j < matriz[i].size(); j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;

    // Solicitar al usuario el tama�o de la matriz (N)
    cout << "Ingrese el tama�o de la matriz (N): ";
    cin >> N;

    // Crear una matriz NxN
    vector<vector<int>> matriz(N, vector<int>(N));

    // Leer la matriz desde el usuario
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matriz[i][j];
        }
    }

    // Operaciones con la matriz
    char opcion;
    cout << "Seleccione una operaci�n:" << endl;
    cout << "a. Eliminar una fila" << endl;
    cout << "b. Eliminar una columna" << endl;
    cout << "c. Insertar una fila" << endl;
    cout << "d. Insertar una columna" << endl;
    cin >> opcion;

    switch (opcion) {
        case 'a': {
            int filaEliminar;
            cout << "Ingrese la fila que desea eliminar (0 a " << N - 1 << "): ";
            cin >> filaEliminar;
            if (filaEliminar >= 0 && filaEliminar < N) {
                matriz.erase(matriz.begin() + filaEliminar);
                N--;
            } else {
                cout << "Fila no v�lida." << endl;
            }
            break;
        }
        case 'b': {
            int columnaEliminar;
            cout << "Ingrese la columna que desea eliminar (0 a " << N - 1 << "): ";
            cin >> columnaEliminar;
            if (columnaEliminar >= 0 && columnaEliminar < N) {
                for (int i = 0; i < N; i++) {
                    matriz[i].erase(matriz[i].begin() + columnaEliminar);
                }
                N--;
            } else {
                cout << "Columna no v�lida." << endl;
            }
            break;
        }
        case 'c': {
            int valor;
            cout << "Ingrese el valor para la nueva fila: ";
            cin >> valor;
            vector<int> nuevaFila(N, valor);
            matriz.push_back(nuevaFila);
            N++;
            break;
        }
        case 'd': {
            int valor;
            cout << "Ingrese el valor para la nueva columna: ";
            cin >> valor;
            for (int i = 0; i < N; i++) {
                matriz[i].push_back(valor);
            }
            N++;
            break;
        }
        default:
            cout << "Opci�n no v�lida." << endl;
            break;
    }

    // Imprimir la matriz resultante
    cout << "Matriz resultante:" << endl;
    imprimirMatriz(matriz);

    return 0;
}
