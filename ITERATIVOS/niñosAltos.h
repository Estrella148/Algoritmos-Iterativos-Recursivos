// Esther Peñas Martinez

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tSol {
    int numLlanas = 0;
    vector<int> iniIzq;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    cin >> tam;
    if (tam == -1)
        return false;

    int altMax, longitud;
    cin >> altMax >> longitud;

    vector<int>v; int elem;
    for (int i = 0; i < tam; i++) {
        cin >> elem;
        v.push_back(elem);
    }
    vector<int>alturas(altMax + 1);
    for (int i = 0; i < tam; i++) {
        alturas[v[i]]++;
    }
    //primer intervalo
    int sumaAct = 0;
    for (int i = 1; i <= longitud; i++) {
        sumaAct += alturas[i];
    }
    int sumaMax = sumaAct;
    for (int i = longitud + 1; i < alturas.size(); i++) {
        sumaAct -= alturas[i - longitud];
        sumaAct += alturas[i];
        if (sumaAct > sumaMax) {
            sumaMax = sumaAct;
        }
    }
    // escribir sol
    cout << sumaMax;
    cout << endl;

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
