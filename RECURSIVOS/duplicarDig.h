// Esther Peñas Martinez

#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

//NO FINAL
long long int resolver(long long  num) {

    if (num < 10) {
        return num * 10 + num;
    }
    else {
        return resolver(num / 10) * 100 + (num % 10 * 10 + num % 10);
    }
}

//FINAL
struct tSol {
    int num;
    int pot;
};

tSol resolver2(long long  num) {
    if (num < 10) {
        tSol s;
        s.pot = 10;
        s.num = num * s.pot + num;
        return s;
    }
    else {
        tSol s = resolver2(num / 10);
        s.pot = 100;
        s.num = s.num * s.pot + (num % 10 * 10 + num % 10);
        return s;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    long long int num; cin >> num;

    long long int sol = resolver(num);
    tSol sol2 = resolver2(num);
    // escribir sol
    cout << sol << " " << sol2.num << endl;
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