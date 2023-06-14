
// Autor/a: Sergio Domínguez Alcalá y Silvia Egido Díaz
// email:
// Compilador y S.O. utilizado
// Nombre del problema
// Comentario general sobre la solución
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include "bintree.h"
#include <queue>

// Introduce más librerías si son necesarias
using namespace std;

typedef struct tLista
{
    BinTree<int> tree;
    int level;
};

//Lo resolvemos por anchura
//El coste de esta función es O(n) siendo n el tamaño del árbol, ya que lo recorre entero
void resolver(BinTree<int> const& a)
{
    tLista l;
    int currentLevel = 0;

    if (!a.empty())
    {
        queue<tLista> pending;

        //Introducimos el nodo raiz
        l.level = 1;
        l.tree = a;
        pending.push(l);

        while (!pending.empty())
        {
            BinTree<int> current = pending.front().tree;
           
            //Vemos si seguimos en el mismo nivel o hemos cambiado. 
            //Hacemos cout del primer nodo que cambia de nivel (el que está más a la izquierda)
            if (currentLevel < pending.front().level)
            {
                currentLevel = pending.front().level;
                cout << current.root() << " ";
            }
       
           
            pending.pop();

            //Introducimos los nodos hijos
            if (!current.left().empty()) {
                l.tree = current.left();
                l.level = currentLevel + 1;
                pending.push(l);
            }
            if (!current.right().empty()) {
                l.tree = current.right();
                l.level = currentLevel + 1;
                pending.push(l);
            }
        }
    }
  
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    BinTree<int> tree = read_tree<int>(cin);

    resolver(tree);

    cout << endl;
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
