// Esther Peñas Martinez

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam, cantidad;
    cin >> tam >> cantidad;
    if (tam == 0 && cantidad == 0)
        return false;

    vector<int>v(tam); int elem; int max = 0;
    for (int i = 0; i < tam; i++) {
        cin >> elem;
        v[i] = elem;
        if (elem > max) {
            max = elem;
        }
    }
    //primer intervalo
    int puntos = 0;
    int puntosMax = 0;
    int ini = 0;
    bool esta = false;
    for (int i = 0; i < cantidad; i++) {
        puntos += v[i];
        if (v[i] == max) {
            esta = true;
        }
    }
    if (esta) {
        puntosMax = puntos;
    }

    //resto de intervalos
    for (int i = cantidad; i < tam; i++) {
        puntos -= v[i - cantidad];
        puntos += v[i];
        if (v[i - cantidad] != max && esta) {
            ini = i - cantidad + 1;
        }
        if (v[i - cantidad] == max) {
            esta = false;
        }
        if (puntos >= puntosMax && v[i] == max) {
            puntosMax = puntos;
            ini = i - cantidad + 1;
        }
    }
    // escribir sol
    cout << ini << endl;

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
