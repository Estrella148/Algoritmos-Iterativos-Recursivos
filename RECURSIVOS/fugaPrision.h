// Esther Peñas Martinez

#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

// función que resuelve el problema
char resolver(vector<char>const& datos, int ini, int fin, char primer) {
    if (ini + 1 == fin) {//si el vector solo tiene un elemento
        if (datos[ini] - primer == (fin - 1)) {//si el elemento es es primero
            return datos[ini] + 1;//retornamos el ultimo que falta
        }
        else {//si no es el primero, retornaremos el primero
            return datos[ini] - 1;
        }
    }
    else if (ini == fin) {
        return datos[ini - 1] + 1;
    }
    else {
        int mitad = (ini + fin) / 2;
        if (datos[mitad] - primer == mitad) {
            resolver(datos, mitad + 1, fin, primer);
        }
        else {
            resolver(datos, ini, mitad, primer);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char l1, l2;
    cin >> l1 >> l2;
    vector<char>letras(l2 - l1);
    char elem;
    for (int i = 0; i < (l2 - l1); i++) {
        cin >> elem;
        letras[i] = elem;
    }

    char sol = resolver(letras, 0, (l2 - l1), l1);
    // escribir sol
    cout << sol << endl;

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