// Esther Peñas Martinez

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tSol {
    int maxPruebas = 0;
    int ini = 0;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    cin >> tam;
    if (tam == 0)
        return false;

    vector<int>v; int elem;
    for (int i = 0; i < tam; i++) {
        cin >> elem;
        v.push_back(elem);
    }
    tSol sol;
    int mejorMarca = v[0]; int cont = 0;
    for (int i = 1; i < tam; i++) {
        if (v[i] <= mejorMarca) {//mala racha
            cont++;
            if (cont >= sol.maxPruebas) {
                sol.maxPruebas = cont;
                sol.ini = i - cont + 1;
            }
        }
        else {//supera
            mejorMarca = v[i];
            cont = 0;
        }
    }
    if (sol.ini == 0) {
        sol.ini = tam;
    }
    // escribir sol
    cout << sol.maxPruebas << " " << sol.ini;
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
