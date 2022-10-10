// Esther Peñas Martinez

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
long long int complementario(long long int num) {
    if (num / 10 == 0) {
        return (9 - num);

    }
    else {
        return complementario(num / 10) * 10 + (9 - num % 10);
    }
}

struct tSol {
    int num;
    int pot;
};

//función que calcula el inverso:
tSol inverso(int num) {
    if (num < 10) {
        return{ 9 - num, 10 };
    }
    else {
        tSol s = inverso(num / 10);
        return { s.num + (9 - num % 10) * s.pot, s.pot * 10 };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long long int num; cin >> num;
    if (!std::cin)
        return false;

    long long int sol = complementario(num);
    tSol sol2 = inverso(num);
    // escribir sol
    cout << sol << " " << sol2.num << endl;

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