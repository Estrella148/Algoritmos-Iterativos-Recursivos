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

    int numElem, p;
    cin >> numElem >> p;
    int maxIzq = 0;
    int minDer = 10000000000;
    int num;
    for (int i = 0; i <= p; i++) {
        cin >> num;
        if (num > maxIzq) {
            maxIzq = num;
        }
    }
    for (int i = p + 1; i < numElem; i++) {
        cin >> num;
        if (num < minDer) {
            minDer = num;
        }
    }

    // escribir sol
    if (maxIzq < minDer) {
        cout << "SI" << endl;
    }
    else {
        cout << "NO" << endl;
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