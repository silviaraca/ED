
// Autor/a: Nombre y apellidos
// email:
// Compilador y S.O. utilizado
// Nombre del problema
// Comentario general sobre la solución
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include "Header.h"
// Introduce más librerías si son necesarias
using namespace std;


void resuelveCaso() {

    // leer los datos de la entrada
    ListLinkedDouble<int> l, aux;
    int n;
    cin >> n;

    while (n != 0)
    {
        l.push_back(n);
        cin >> n;
    }
 
    cin >> n;
    while (n != 0)
    {
        aux.push_back(n);
        cin >> n;
    }

    l.desparizar(aux);
    // escribir solución
    int tam = l.size();
    for (int i = 0; i < tam; i++)
    {
        cout << l.front() << " ";
        l.pop_front();
    }

    cout << endl;

    tam = aux.size();
    for (int i = 0; i < tam; i++)
    {
        cout << aux.front()<< " ";
        aux.pop_front();
    }
}


int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
    return 0;
}