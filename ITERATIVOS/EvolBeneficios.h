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
    int ini, fin;
    cin >> ini >> fin;
    int tam = fin - ini + 1;
    vector<int>ventas;
    vector<int>sol;
    int valor;
    for (int i = 0; i < tam; i++) {
        cin >> valor;
        ventas.push_back(valor);
    }
    int anio = ini + 1; int max = ventas[0];
    for (int i = 1; i < tam; i++) {
        if (max < ventas[i]) {
            sol.push_back(anio);
            max = ventas[i];
        }
        anio++;
    }


    // escribir sol
    for (int k = 0; k < sol.size(); k++) {
        cout << sol[k] << " ";
    }
    cout << endl;
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