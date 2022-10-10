// Esther Peñas Martinez

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    cin >> tam;
    if (tam == -1)
        return false;


    vector<int>v(tam); int elem;
    for (int i = 0; i < tam; i++) {
        cin >> elem;
        v[i] = elem;
    }
    int i = 0; int j = tam; int k = 1;
    while (i < j && k < j) {
        if (v[i] % 2 == 0) {
            i += 2;
        }
        else if (v[k] % 2 == 1) {
            k += 2;
        }
        else {
            swap(v[i], v[k]);
            i += 2;
            k += 2;
        }
    }

    int aux = i;
    while (aux < tam) {
        if (v[aux] % 2 == 0) {
            v[i] = v[aux];
            i += 2;
        }
        aux += 2;
    }

    aux = k;
    while (aux < tam) {
        if (v[aux] % 2 == 1) {
            v[k] = v[aux];
            k += 2;
        }
        aux += 2;
    }

    if (i <= k) {
        v.resize(i);
    }
    else {
        v.resize(k - 1);
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

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
