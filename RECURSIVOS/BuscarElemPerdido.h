// Esther Peñas Martinez

#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

// función que resuelve el problema
char resolver(vector<char>const& v1, vector<char>const& v2, int ini, int fin) {
    if (ini + 1 == fin) {
        if (v1[ini] != v2[ini]) {
            return v1[ini];
        }
        else {
            return v1[fin];
        }
    }
    else if (ini == fin) {
        return v1[fin];
    }
    else {
        int mitad = (ini + fin) / 2;
        if (v1[mitad] == v2[mitad]) {
            resolver(v1, v2, mitad + 1, fin);
        }
        else if (v1[mitad] > v2[mitad]) {
            resolver(v1, v2, mitad + 1, fin);
        }
        else {
            resolver(v1, v2, ini, mitad);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    cin >> tam;
    vector<char>v1(tam);
    vector<char>v2(tam - 1);
    int elem;
    for (int i = 0; i < tam; i++) {
        cin >> elem;
        v1[i] = elem;
    }
    for (int i = 0; i < tam - 1; i++) {
        cin >> elem;
        v2[i] = elem;
    }

    int sol = resolver(v1, v2, 0, tam - 1);
    // escribir sol
    cout << sol << endl;

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