// Esther Peñas Martinez



#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tSol {
    bool ordenado;
    int max;
    int min;

};
// función que resuelve el problema
tSol resolver(vector<int>const& v, int ini, int fin) {
    if (ini + 1 == fin) {
        if (v[ini] <= v[fin]) {
            return { true,v[fin],v[ini] };
        }
        else {
            return { false,v[ini],v[fin] };
        }
    }
    else if (ini == fin) {
        return { true,v[ini],v[ini] };
    }
    else {
        int mitad = (ini + fin) / 2;
        tSol izq = resolver(v, ini, mitad);
        tSol der = resolver(v, mitad + 1, fin);
        tSol sol;
        if (izq.ordenado && der.ordenado && izq.min <= der.min && der.max >= izq.max) {
            sol.ordenado = true;
            sol.max = der.max;
            sol.min = izq.min;
        }
        else {
            sol.ordenado = false;
            sol.max = 0;
            sol.min = 0;
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

    vector<int>v;
    while (elem != 0) {
        v.push_back(elem);
        cin >> elem;
    }

    tSol sol = resolver(v, 0, v.size() - 1);

    // escribir sol

    sol.ordenado ? cout << "SI\n" : cout << "NO\n";
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
