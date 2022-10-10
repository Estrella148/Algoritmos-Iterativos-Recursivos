// Esther Peñas Martinez



#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tSol {
    int edVistas = 0;
    vector<string>edSol;
};
struct tDatos {
    string id;
    int altura;
    int pisoVenta;
};

// función que resuelve el problema
tSol resolver(vector<tDatos>const& v) {
    int tam = v.size() - 1;
    tSol sol; int alturaMax = v[tam].altura;
    if (v[tam].pisoVenta != -1) {
        sol.edSol.push_back(v[tam].id);
    }
    for (int i = tam - 1; i >= 0; i--) {
        if (v[i].pisoVenta != -1) {
            if (v[i].pisoVenta > alturaMax) {
                sol.edSol.push_back(v[i].id);
            }
        }
        if (v[i].altura > alturaMax) {
            alturaMax = v[i].altura;
        }
    }
    sol.edVistas = sol.edSol.size();
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numEdificios;
    cin >> numEdificios;
    if (numEdificios == 0)
        return false;

    tDatos d;
    vector<tDatos>edificios;
    for (int i = 0; i < numEdificios; i++) {
        cin >> d.id >> d.altura >> d.pisoVenta;
        edificios.push_back(d);
    }

    tSol sol = resolver(edificios);

    // escribir sol
    if (sol.edVistas == 0) {
        cout << "Ninguno";
    }
    else {
        cout << sol.edVistas << endl;
        for (int i = 0; i < sol.edSol.size(); i++) {
            cout << sol.edSol[i] << " ";
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
