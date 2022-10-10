// Esther Peñas Martinez
// E57

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Explicación del algoritmo utilizado: hacemos tres particiones.
/* Se recorre el vector con tres iteradores p, k y q.
*  Los dos primeros marcan el inicio y q marca final del vector.
*  Se comprueba si el elemento es verde, si es así se incrementa la k.
*  Se comprueba si el elemento es azul, si es así se hace un cambio de posición para la parte inicial y se incrementa p y k.
*  Se comprueba el resto de los casos (si el elemento es rojo), si es así se hace un cambio de posición para la parte final y decrementamos q.
*/
// Coste del algoritmo utilizado
// Lineal O(n), siendo n el número de elementos del vector de pares.

using psi = std::pair<char, int>;

// Recibe un vector con los datos de entrada del problema
// Modifica este vetor dejando en las primeras posiciones 
// las cintas azules, luego las verdes y luego las rojas
// NO se puede utilizar sort
// p es la primera posicion de una cinta verde, q es la ultima posicion de una cinta verde
void particion(std::vector<psi>& v, int& p, int& q) {
    p = 0; int k = 0;
    q = (int)v.size() - 1;
    while (k <= q) {
        if (v[k].first == 'v') {
            k++;
        }
        else if (v[k].first == 'a') {
            swap(v[k], v[p]);
            k++; p++;

        }
        else {
            swap(v[k], v[q]);
            q--;
        }
    }
}

// Entrada y salida de datos
bool resuelveCaso() {
    // Lectura de los datos de entrada
    int numCintas;
    std::cin >> numCintas;
    if (!std::cin) return false;
    std::vector<psi> v(numCintas); // nombre y altura
    for (psi& n : v) {
        std::cin >> n.first >> n.second;
    }
    // LLamada a la función paticion
    int p, q;
    particion(v, p, q);
    // Ordena cada parte para la salida de datos
    std::sort(v.begin(), v.begin() + p);
    std::sort(v.begin() + p, v.begin() + 1 + q);
    std::sort(v.begin() + 1 + q, v.end());
    // Escribe las cintas azules
    std::cout << "Azules:";
    for (int i = 0; i < p; ++i) {
        std::cout << ' ' << v[i].second;
    }
    std::cout << '\n';
    // Escribe la segunda parte
    std::cout << "Verdes:";
    for (int i = p; i <= q; ++i) {
        std::cout << ' ' << v[i].second;
    }
    std::cout << '\n';
    // Escribe la tercera parte
    std::cout << "Rojas:";
    for (int i = q + 1; i < v.size(); ++i) {
        std::cout << ' ' << v[i].second;
    }
    std::cout << '\n';
    return true;
}



int main() {

#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {} //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
