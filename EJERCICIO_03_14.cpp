// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 04/07/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 14

// Problema planteado:. Simule una elección de nuestro país Bolivia. En ello se mostrará las elecciones
// por departamento y existirá N candidatos.
// El programa debe pedir la cantidad de votos por departamento y candidato y
// almacenarlos en una matriz.
// El programa debe calcular lo siguiente:
// • Si un candidato gana con el 50% + 1 voto es ganador absoluto.
// • Si no ningún candidato que logre el 50% + 1 voto el programa debe sacar
// los dos mas votados para una segunda vuelta
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N; // Cantidad de candidatos
    int D; // Cantidad de departamentos
    int totalVotos = 0; // Total de votos en la elección

    // Solicitar al usuario la cantidad de candidatos y departamentos
    cout << "Ingrese la cantidad de candidatos: ";
    cin >> N;
    cout << "Ingrese la cantidad de departamentos: ";
    cin >> D;

    // Crear una matriz para almacenar los votos por departamento y candidato
    vector<vector<int>> votos(D, vector<int>(N, 0));

    // Leer los votos por departamento y candidato
    for (int i = 0; i < D; i++) {
        cout << "Departamento " << i + 1 << ":" << endl;
        for (int j = 0; j < N; j++) {
            cout << "Votos para el candidato " << j + 1 << ": ";
            cin >> votos[i][j];
            totalVotos += votos[i][j];
        }
    }

    // Calcular el 50% + 1 voto
    int mitadMasUno = (totalVotos / 2) + 1;
    bool hayGanadorAbsoluto = false;
    int candidatoGanadorAbsoluto = -1;

    // Encontrar al candidato ganador absoluto (si existe)
    for (int j = 0; j < N; j++) {
        int totalVotosCandidato = 0;
        for (int i = 0; i < D; i++) {
            totalVotosCandidato += votos[i][j];
        }
        if (totalVotosCandidato >= mitadMasUno) {
            hayGanadorAbsoluto = true;
            candidatoGanadorAbsoluto = j + 1;
            break;
        }
    }

    // Si no hay ganador absoluto, encontrar a los dos candidatos más votados para la segunda vuelta
    if (!hayGanadorAbsoluto) {
        int primerCandidatoMasVotado = -1;
        int segundoCandidatoMasVotado = -1;
        int votosPrimerCandidatoMasVotado = 0;
        int votosSegundoCandidatoMasVotado = 0;

        for (int j = 0; j < N; j++) {
            int totalVotosCandidato = 0;
            for (int i = 0; i < D; i++) {
                totalVotosCandidato += votos[i][j];
            }

            if (totalVotosCandidato > votosPrimerCandidatoMasVotado) {
                segundoCandidatoMasVotado = primerCandidatoMasVotado;
                votosSegundoCandidatoMasVotado = votosPrimerCandidatoMasVotado;

                primerCandidatoMasVotado = j + 1;
                votosPrimerCandidatoMasVotado = totalVotosCandidato;
            } else if (totalVotosCandidato > votosSegundoCandidatoMasVotado) {
                segundoCandidatoMasVotado = j + 1;
                votosSegundoCandidatoMasVotado = totalVotosCandidato;
            }
        }

        cout << "Segunda vuelta entre los candidatos " << primerCandidatoMasVotado << " y " << segundoCandidatoMasVotado << endl;
    } else {
        cout << "El candidato " << candidatoGanadorAbsoluto << " es el ganador absoluto." << endl;
    }

    return 0;
}
