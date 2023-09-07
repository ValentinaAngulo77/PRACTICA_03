// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 04/07/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 10

// Problema planteado: Queremos realizar una encuesta a 10 personas, en esta encuesta indicaremos el
// sexo (1=masculino, 2=femenino), si trabaja (1=si trabaja, 2= no trabaja) y su
// sueldo (si tiene un trabajo, sino sera un cero) estará entre 600 y 2000 (valor
// entero). Los valores pueden ser generados aleatoriamente. Calcula y muestra lo
// siguiente:
// • Porcentaje de hombres (tengan o no trabajo).
// • Porcentaje de mujeres (tengan o no trabajo).
// • Porcentaje de hombres que trabajan.
// • Porcentaje de mujeres que trabajan.
// • El sueldo promedio de las hombres que trabajan.
// • EL sueldo promedio de las mujeres que trabajan.
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Inicializar contador de hombres, mujeres, hombres trabajando y mujeres trabajando
    int contadorHombres = 0;
    int contadorMujeres = 0;
    int contadorHombresTrabajando = 0;
    int contadorMujeresTrabajando = 0;

    // Inicializar sumas de sueldos para hombres y mujeres trabajando
    int sumaSueldosHombresTrabajando = 0;
    int sumaSueldosMujeresTrabajando = 0;

    // Semilla aleatoria
    srand(time(0));

    for (int i = 0; i < 10; i++) {
        // Generar sexo aleatorio (1=masculino, 2=femenino)
        int sexo = rand() % 2 + 1;

        // Generar trabajo aleatorio (1=si trabaja, 2=no trabaja)
        int trabaja = rand() % 2 + 1;

        // Generar sueldo aleatorio si trabaja (entre 600 y 2000)
        int sueldo = 0;
        if (trabaja == 1) {
            sueldo = rand() % 1401 + 600; // Sueldos entre 600 y 2000
        }

        // Contar hombres y mujeres
        if (sexo == 1) {
            contadorHombres++;
        } else {
            contadorMujeres++;
        }

        // Contar hombres y mujeres que trabajan
        if (sexo == 1 && trabaja == 1) {
            contadorHombresTrabajando++;
            sumaSueldosHombresTrabajando += sueldo;
        } else if (sexo == 2 && trabaja == 1) {
            contadorMujeresTrabajando++;
            sumaSueldosMujeresTrabajando += sueldo;
        }
    }

    // Calcular porcentajes
    float porcentajeHombres = (static_cast<float>(contadorHombres) / 10) * 100;
    float porcentajeMujeres = (static_cast<float>(contadorMujeres) / 10) * 100;
    float porcentajeHombresTrabajando = (static_cast<float>(contadorHombresTrabajando) / contadorHombres) * 100;
    float porcentajeMujeresTrabajando = (static_cast<float>(contadorMujeresTrabajando) / contadorMujeres) * 100;

    // Calcular sueldo promedio de hombres y mujeres que trabajan
    float sueldoPromedioHombresTrabajando = static_cast<float>(sumaSueldosHombresTrabajando) / contadorHombresTrabajando;
    float sueldoPromedioMujeresTrabajando = static_cast<float>(sumaSueldosMujeresTrabajando) / contadorMujeresTrabajando;

    // Mostrar resultados
    cout << "Porcentaje de hombres: " << porcentajeHombres << "%" << endl;
    cout << "Porcentaje de mujeres: " << porcentajeMujeres << "%" << endl;
    cout << "Porcentaje de hombres que trabajan: " << porcentajeHombresTrabajando << "%" << endl;
    cout << "Porcentaje de mujeres que trabajan: " << porcentajeMujeresTrabajando << "%" << endl;
    cout << "Sueldo promedio de hombres que trabajan: $" << sueldoPromedioHombresTrabajando << endl;
    cout << "Sueldo promedio de mujeres que trabajan: $" << sueldoPromedioMujeresTrabajando << endl;

    return 0;
}
