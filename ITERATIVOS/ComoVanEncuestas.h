// Esther Peñas Martinez

#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam, num;
    cin >> tam;
    int sumaTotal = 0;
    int min = 10000;
    int contMin = 0;
    for (int i = 0; i < tam; i++) {
        cin >> num;
        sumaTotal += num;
        if (num < min) {
            min = num;
            contMin = 1;
        }
        else if (num == min) {
            contMin++;
        }
    }
    // escribir sol
    int suma = sumaTotal - (min * contMin);
    int valores = tam - contMin;
    cout << suma << " " << valores << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}