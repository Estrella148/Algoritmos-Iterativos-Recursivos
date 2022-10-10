// Esther Peñas Martinez

#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

// función que resuelve el problema
int resolver(vector<char>const& v, int ini, int fin, int cantado) {
    if (ini + 1 == fin) {
        if (v[ini] == ini + cantado) {
            return v[ini];
        }
        else  if (v[fin] == fin + cantado) {
            return v[fin];
        }
        else {
            return -1;
        }
    }
    else if (ini == fin) {
        if (v[ini] == ini + cantado) {
            return v[ini];
        }
        else {
            return -1;
        }
    }
    else {
        int mitad = (ini + fin) / 2;
        if (v[mitad] - cantado == mitad) {
            return v[mitad];
        }
        else if (v[mitad] - cantado > mitad) {
            resolver(v, ini, mitad, cantado);
        }
        else {
            resolver(v, mitad + 1, fin, cantado);
        }

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam; int cantado;
    cin >> tam >> cantado;
    vector<char>v1(tam);
    int elem;
    for (int i = 0; i < tam; i++) {
        cin >> elem;
        v1[i] = elem;
    }

    int sol = resolver(v1, 0, tam - 1, cantado);
    // escribir sol
    if (sol == -1) {
        cout << "NO" << endl;
    }
    else {
        cout << sol << endl;
    }


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