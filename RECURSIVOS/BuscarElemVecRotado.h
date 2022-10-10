// Esther Peñas Martinez

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

//O(logn)
// función que resuelve el problema
bool resolver(vector<int>const& v, int ini, int fin, int buscado) {
    if (ini + 1 == fin) {
        if (v[ini] == buscado || v[fin] == buscado) {
            return true;
        }
        else {
            return false;
        }

    }
    else if (ini == fin) {
        if (v[ini] == buscado) {
            return true;
        }
        else {
            return false;
        }

    }
    else {
        int mitad = (ini + fin) / 2;
        bool sol;
        if (v[mitad] == buscado) {
            sol = true;
        }
        else {
            if (v[mitad] > buscado) {//izq
                if (v[mitad] > v[fin]) {//rotado
                    if (buscado > v[fin]) {//izq
                        sol = resolver(v, ini, mitad, buscado);
                    }
                    else {//der
                        sol = resolver(v, mitad, fin, buscado);
                    }
                }
                else {//no rotado
                    sol = resolver(v, ini, mitad, buscado);
                }
            }
            else {
                if (v[mitad] < v[ini]) {
                    if (buscado >= v[ini]) {
                        sol = resolver(v, ini, mitad, buscado);
                    }
                    else {
                        sol = resolver(v, mitad, fin, buscado);
                    }
                }
                else {
                    sol = resolver(v, mitad, fin, buscado);
                }

            }
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
    if (elem == -1)
        return false;

    vector<int>v(elem);
    int buscado; cin >> buscado;
    int d;
    for (int i = 0; i < elem; i++) {
        cin >> d;
        v[i] = d;
    }
    bool sol = false;
    sol = resolver(v, 0, v.size() - 1, buscado);

    // escribir sol

    sol ? cout << "SI\n" : cout << "NO\n";
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
