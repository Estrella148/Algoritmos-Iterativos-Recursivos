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
    int tam, cant;
    cin >> tam >> cant;

    if (tam == 0 && cant == 0)
        return false;

    vector<int>val; int elem;
    for (int i = 0; i < tam; i++) {
        cin >> elem;
        val.push_back(elem);
    }
    tSol sol;
    int longAct = 1;
    for (int i = 1; i < tam; i++) {
        if (val[i] + 1 == val[i - 1] || val[i] - 1 == val[i - 1] || val[i] == val[i - 1]) {
            longAct++;
        }
        else {
            if (longAct >= cant) {
                sol.numLlanas++;
                sol.iniIzq.push_back(i - longAct);
            }
            longAct = 1;
        }
    }
    if (longAct >= cant) {
        sol.numLlanas++;
        sol.iniIzq.push_back(tam - longAct);
    }

    // escribir sol
    cout << sol.numLlanas << " ";
    for (int i = 0; i < sol.iniIzq.size(); i++) {
        cout << sol.iniIzq[i] << " ";
    }
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
