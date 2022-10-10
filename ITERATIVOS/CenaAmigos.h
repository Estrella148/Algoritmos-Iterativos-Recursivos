// Esther Peñas Martinez

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// Datos finales:
struct tDatos {
    int sumaMax; //suma de la secuencia final
    int ini; //inicio de la secuencia final
    int maxLong; //longitud de la secuencia final
};

// Función que resuelve el problema:
tDatos resolver(vector<int>const& datos) {
    //Inicialización de datos
    tDatos d; d.sumaMax = 0; d.maxLong = 0; d.ini = 0;
    int suma = 0; int actLong = 0; int ultIni = 0;

    //Recorremos el vector
    for (int i = 0; i < (int)datos.size(); i++) {
        suma += datos[i];//vamos sumando los elementos
        if (suma > 0) {//si la suma es positiva
            actLong = i - ultIni + 1;
            if (suma > d.sumaMax) { //si la suma es mayor que la suma máxima
                d.sumaMax = suma;
                d.maxLong = actLong;
                d.ini = ultIni;
            }
            else if (suma == d.sumaMax) {//si existen dos secuencias iguales
                if (d.maxLong > actLong) {//la de menor longitud es con la que nos quedamos
                    d.maxLong = actLong;
                    d.ini = ultIni;
                }
            }

        }
        else {//si la suma es negativa
            ultIni = i + 1;
            suma = 0;
        }
    }

    return d;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    cin >> tam;
    if (!std::cin)
        return false;

    vector<int>datos(tam);
    for (int i = 0; i < tam; i++) {
        cin >> datos[i];
    }
    tDatos sol = resolver(datos);

    // escribir sol
    cout << sol.sumaMax << " " << sol.ini << " " << sol.maxLong << '\n';

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