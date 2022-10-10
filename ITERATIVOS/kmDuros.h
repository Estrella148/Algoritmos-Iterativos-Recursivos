// Esther Peñas Martinez



#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tSol {
    int longMax = 0;
    int primer = 0;
    int ultimo = 0;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numKilometros, longitud;
    cin >> numKilometros >> longitud;

    if (numKilometros == 0 && longitud == 0)
        return false;

    vector<int>km; int elem;
    for (int i = 0; i < numKilometros; i++) {
        cin >> elem;
        km.push_back(elem);
    }
    tSol sol;
    //primer tramo
    int suma = 0;
    for (int i = 0; i < longitud; i++) {
        suma += km[i];
    }
    int sumaMax = suma;
    sol.primer = longitud - 1;
    //resto de tramos
    for (int i = longitud; i < numKilometros; i++) {
        suma -= km[i - longitud];
        suma += km[i];
        if (suma > sumaMax) {
            sol.primer = i;
            sumaMax = suma;
        }
        else if (suma == sumaMax) {
            sol.ultimo = i;
        }
    }

    sol.longMax = sumaMax;
    sol.primer = sol.primer - longitud + 1;
    if (sol.ultimo == 0) {
        sol.ultimo = sol.primer;
    }
    else {
        sol.ultimo = sol.ultimo - longitud + 1;
    }
    // escribir sol
    cout << sol.longMax << " " << sol.primer << " " << sol.ultimo << endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
