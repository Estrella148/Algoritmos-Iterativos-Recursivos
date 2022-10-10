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
    int tam, alt;
    cin >> tam >> alt;
    vector<int>edificios;
    int elem;
    for (int i = 0; i < tam; i++) {
        cin >> elem;
        edificios.push_back(elem);
    }

    int ini = 0; int fin = 0; int longAct = 0; int longMax = 0;
    for (int i = 0; i < tam; i++) {
        if (edificios[i] > alt) {
            longAct++;
            if (longAct > longMax) {
                longMax = longAct;
                fin = i;
            }
        }
        else {
            longAct = 0;
        }
    }
    ini = fin - longMax + 1;


    // escribir sol
    cout << ini << " " << fin << endl;

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