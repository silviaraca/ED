
// Autor/a: Nombre y apellidos
// email:
// Compilador y S.O. utilizado
// Nombre del problema
// Comentario general sobre la soluci�n
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include "Header.h"
// Introduce m�s librer�as si son necesarias
using namespace std;


// funci�n que resuelve el problema
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
// configuraci�n, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    BinTree<int> a, aux;

    a = read_tree<int>(cin);

    BinTree<int> sol = resolver(a);

    // escribir soluci�n
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

}