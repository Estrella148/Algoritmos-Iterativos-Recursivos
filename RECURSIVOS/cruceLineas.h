// Esther Peñas Martinez

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tSol {
    bool existe;
    int i;
    int j;
};
//O(logn)
// función que resuelve el problema
tSol resolver(vector<int>const& v, vector<int>const& v2, int ini, int fin) {
    if (ini + 1 == fin) {
        if (v[ini] == v2[ini]) {
            return { true,ini,0 };
        }
        else if (v[fin] == v2[fin]) {
            return{ true,fin,0 };
        }
        else {
            /*if (fin + 1 == v.size()) {
                if (v[fin] < v2[fin]) {
                    return { false, fin,fin + 1 };
                }
                else {
                    return { false, fin - 1,fin };
                }
            }
            else {*/
            if (v[ini] < v2[ini]) {
                return { false, ini,ini + 1 };
            }
            else {
                return { false, ini - 1,ini };
            }
            //} 
        }
    }
    else if (ini == fin) {
        if (v[ini] == v2[ini]) {
            return { true,ini,0 };
        }
        else {
            if (v[ini] < v2[ini]) {
                return { false, ini,fin + 1 };
            }
            else {
                return { false, ini - 1,fin };
            }
        }
    }
    else {
        int mitad = (ini + fin) / 2;
        if (v[mitad] == v2[mitad]) {
            return { true,mitad,0 };
        }
        else if (v[mitad] > v2[mitad]) {
            resolver(v, v2, ini, mitad);
        }
        else {
            resolver(v, v2, mitad + 1, fin);
        }

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
    vector<int>v2(elem);
    for (int i = 0; i < elem; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < elem; i++) {
        cin >> v2[i];
    }
    tSol sol = resolver(v, v2, 0, elem - 1);

    // escribir sol

    sol.existe ? cout << "SI " << sol.i << endl : cout << "NO " << sol.i << " " << sol.j << endl;
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
