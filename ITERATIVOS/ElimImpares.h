﻿// Esther Peñas Martinez

#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam, elem;
    cin >> tam;
    vector<int>pares;
    for (int i = 0; i < tam; i++) {
        cin >> elem;
        pares.push_back(elem);
    }

    int posPar = 0;
    for (int i = 0; i < tam; i++) {
        if (pares[i] % 2 == 0) {//si es par
            pares[posPar] = pares[i];
            posPar++;
        }
    }
    pares.resize(posPar);
    // escribir sol
    for (int i = 0; i < pares.size(); i++) {
        cout << pares[i] << " ";
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