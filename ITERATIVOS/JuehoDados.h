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
    int tam;
    cin >> tam;
    if (tam == -1)
        return false;

    int valMax; cin >> valMax;
    vector<int>tiradas;
    int elem;
    for (int i = 0; i < tam; i++) {
        cin >> elem;
        tiradas.push_back(elem);
    }

    vector<int>repetidos(valMax);
    for (int i = 0; i < tam; i++) {
        repetidos[tiradas[i]]++;
    }

    int max = 0;
    for (int i = 0; i < valMax; i++) {
        if (max < repetidos[i]) {
            max = repetidos[i];
        }
    }

    // escribir sol
    for (int i = valMax - 1; i >= 0; i--) {
        if (max == repetidos[i]) {
            cout << i << " ";
        }
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
