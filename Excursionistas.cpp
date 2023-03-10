
// Autor/a: Silvia Egido Diaz y Sergio Dominguez Alcala
// email:
// Compilador y S.O. utilizado
// Nombre del problema
// Comentario general sobre la solución
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include <algorithm>
#include "bintree.h"

using namespace std;

struct total {

	int maxEx; 
	bool encontradoFinal; 
};

//El coste de la funcion es lineal con respecto al tamaño del arbol O(tamaño)
total rescate(BinTree<int> const& a, int& grupos) {
    if (a.empty()) {
        return { 0, 0};
    }
    else
    {
        total iz = rescate(a.left(), grupos);
        total der = rescate(a.right(), grupos);
        total root;

        root.encontradoFinal = iz.encontradoFinal || der.encontradoFinal;
        root.maxEx = max(iz.maxEx, der.maxEx);

        if (a.root() != 0)
        {
            if (iz.encontradoFinal || der.encontradoFinal)
            {
                root.maxEx += a.root();
            }
            else
            {
                root.maxEx += a.root();
                root.encontradoFinal = true;
                grupos++;
            }
                
        }
        
        
        return { root };
    }
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
// 
//El coste de la funcion es lineal con respecto al tamaño del arbol introducido O(tamaño)
void resuelveCaso() {

    // leer los datos de la entrada
   
    int grupo = 0;
    BinTree<int> a = read_tree<int>(cin);
	total result = rescate(a, grupo);

	cout << grupo << ' ' << result.maxEx << endl;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    std::ofstream out("datos.out");
    auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    system("PAUSE");
#endif
    return 0;
}
