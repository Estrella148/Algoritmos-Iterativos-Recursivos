// Esther Peñas Martinez

#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int p1, p2;
    cin >> p1 >> p2;
    vector<int>a;
    vector<int>b;
    int p;
    for (int i = 0; i < p1; i++) {
        cin >> p;
        a.push_back(p);
    }
    for (int i = 0; i < p2; i++) {
        cin >> p;
        b.push_back(p);
    }

    vector<int>sol; int j = 0; int i = 0;
    while (i < p1 && j < p2) {
        if (a[i] == b[j]) {
            sol.push_back(a[i]);
            i++; j++;
        }
        else if (a[i] > b[j]) {
            sol.push_back(b[j]);
            j++;
        }
        else if (a[i] < b[j]) {
            sol.push_back(a[i]);
            i++;
        }
    }

    while (i < p1) {
        sol.push_back(a[i]);
        i++;
    }
    while (j < p2) {
        sol.push_back(b[j]);
        j++;
    }

    // escribir sol
    for (int k = 0; k < sol.size(); k++) {
        cout << sol[k] << " ";
    }
    cout << endl;
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