// Esther Peñas Martinez

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

//O(logn)
// función que resuelve el problema
int resolver(vector<int>const& v, int ini, int fin) {
    if (ini + 1 == fin) {
        if (v[ini] + 1 == v[fin]) {
            return v[ini] - 1;
        }
        else {
            return v[fin] - 1;
        }
    }
    else if (ini == fin) {
        return v[ini] + 1;
    }
    else {
        int mitad = (ini + fin) / 2;
        int sol;
        if (v[mitad] + 1 == v[mitad + 1]) {
            if (v[fin] - v[mitad] != (fin - mitad)) {
                sol = resolver(v, mitad, fin);
            }
            else {
                sol = resolver(v, ini, mitad);
            }

        }
        else {
            sol = resolver(v, mitad, fin);
        }

        return sol;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int elem;
    cin >> elem;
    if (elem == 0)
        return false;

    vector<int>v(elem);
    int d;
    for (int i = 0; i < elem; i++) {
        cin >> d;
        v[i] = d;
    }

    int sol = resolver(v, 0, elem - 1);

    // escribir sol

    cout << sol << "\n";
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
