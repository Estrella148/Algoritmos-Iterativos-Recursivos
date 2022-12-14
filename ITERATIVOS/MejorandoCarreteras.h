// Esther Peñas Martinez



#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
#include <algorithm>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    cin >> tam;
    if (tam == -1)
        return false;

    int elem;
    vector<int>puntos;
    for (int i = 0; i < tam; i++) {
        cin >> elem;
        puntos.push_back(elem);
    }
    sort(puntos.begin(), puntos.end());
    int num = puntos[0]; int sol = num;
    int cont = 1; int max = 1;
    for (int i = 1; i < tam; i++) {
        if (num == puntos[i]) {
            cont++;
            if (cont > max) {
                max = cont;
                sol = num;
            }
        }
        else {
            num = puntos[i];
            cont = 1;
        }
    }
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
