
// Autor/a: Nombre y apellidos
// email:
// Compilador y S.O. utilizado
// Nombre del problema
// Comentario general sobre la solución
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include "Header.h"
// Introduce más librerías si son necesarias
using namespace std;


// función que resuelve el problema
BinTree<int> resolver(const BinTree<int> &a) {
    if (a.empty())
    {
        return 0;
    }
    else
    {
        BinTree<int> iz = resolver(a.left());
        BinTree<int> der = resolver(a.right());


    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    BinTree<int> a, aux;

    a = read_tree<int>(cin);

    BinTree<int> sol = resolver(a);

    // escribir solución
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

}