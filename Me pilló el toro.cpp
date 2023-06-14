
// Autor/a: Nombre y apellidos
// email:
// Compilador y S.O. utilizado
// Nombre del problema
// Comentario general sobre la solución
// explicando como se resuelve el problema


#include <iostream>
#include <fstream>
#include <map>
// Introduce más librerías si son necesarias
using namespace std;

// función que resuelve el problema
void resolver(map<string, int>& notas) {

    string nombre, calificacion;

    cin >> nombre >> calificacion;

    if (notas.count(nombre) > 0)
    {
        auto it = notas.find(nombre);

        if (calificacion == "INCORRECTO") { it->second--; }
        else it->second--;
    }
    else
    {
        if (calificacion == "INCORRECTO") { notas.insert({ nombre, -1 }); }
        else notas.insert({ nombre, 1 });

    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0)
        return false;


    map<string, int> notas;

    for (int i = 0; i < n; i++)
    {
        resolver(notas);
    }

    for (std::map<string, int>::iterator i = notas.begin(); i != notas.end(); ++i) {
        if (i->second != 0) {
            std::cout << i->first << ", " << i->second << std::endl;
        }
    }

    std::cout << "---" << std::endl;
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    std::ifstream in("casos.txt");
//    auto cinbuf = std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("datos.out");
//    auto coutbuf = std::cout.rdbuf(out.rdbuf());
//#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
//#ifndef DOMJUDGE
//    std::cin.rdbuf(cinbuf);
//    std::cout.rdbuf(coutbuf);
//    system("PAUSE");
//#endif
    return 0;
}