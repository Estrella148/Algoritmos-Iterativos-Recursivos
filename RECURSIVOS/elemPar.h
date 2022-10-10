// Esther Peñas Martinez

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
long long int resolver(long long int num) {
    if (num / 10 == 0) {
        if (num % 2 == 0) {
            return 0;
        }
        else {
            return num;
        }

    }
    else {
        if (num % 2 == 0) {
            return resolver(num / 10);
        }
        else {
            return resolver(num / 10) * 10 + num % 10;
        }

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long long int num; cin >> num;
    if (!std::cin)
        return false;

    long long int sol = resolver(num);

    // escribir sol
    cout << sol << endl;

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