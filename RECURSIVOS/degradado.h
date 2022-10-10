// Esther Peñas Martinez

#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

struct tSol {
    bool degradado;
    int suma;
};
// función que resuelve el problema
tSol resolver(vector<int> const& v, int ini, int fin) {
    tSol sol;
    if (ini + 1 == fin) {
        sol.suma = v[ini] + v[fin];
        if (v[ini] < v[fin]) {
            sol.degradado = true;

        }
        else {
            sol.degradado = false;
        }
        return sol;
    }
    else if (ini == fin) {
        sol.degradado = true;
        sol.suma = v[ini];
        return sol;
    }
    else {
        int mitad = (ini + fin) / 2;
        tSol izq = resolver(v, ini, mitad);
        tSol der = resolver(v, mitad + 1, fin);
        sol.suma = izq.suma + der.suma;
        if (izq.degradado && der.degradado && izq.suma < der.suma) {
            sol.degradado = true;
        }
        else {
            sol.degradado = false;
        }
        return sol;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    cin >> n >> m;
    if (!std::cin)
        return false;

    vector<vector<int>>matriz(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matriz[i][j];
        }
    }
    tSol sol = { true,0 };
    for (int i = 0; sol.degradado && i < n; i++) {
        sol.suma = 0;
        sol = resolver(matriz[i], 0, m - 1);
    }

    // escribir sol
    if (sol.degradado) {
        cout << "SI" << endl;
    }
    else {
        cout << "NO" << endl;
    }

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