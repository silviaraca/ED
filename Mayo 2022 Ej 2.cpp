
// Autor/a: Nombre y apellidos
// email:
// Compilador y S.O. utilizado
// Nombre del problema
// Comentario general sobre la solución
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include "bintree.h"

using namespace std;

typedef struct datos
{
    int der, iz, total;
};

// función que resuelve el problema
void resolver(BinTree<int> a, datos &data) {
   
    if (a.empty())
    {
        data.iz = 0;
        data.der = 0;
    }
    else
    {
       resolver(a.left(), data);

        if (!a.left().empty())
        {
            if (data.iz > data.der)
            {
                int val = data.iz - data.der;
                if (a.left().root() == val % a.root())
                {
                    data.total++;
                }
            }
            else
            {
                int val = data.der - data.iz;
                if (a.left().root() == val % a.root())
                {
                    data.total++;
                }
            }
        }
        
        datos dataiz = data;
       resolver(a.right(), data);

        if (!a.right().empty())
        {
            if (data.iz > data.der)
            {
                int val = data.iz - data.der;
                if (a.right().root() == val % a.root())
                {
                    data.total++;
                }
            }
            else
            {
                int val = data.der - data.iz;
                if (a.right().root() == val % a.root())
                {
                    data.total++;
                }
            }

        }
        
        datos datader = data;
      if(!a.left().empty()) data.iz = dataiz.iz + dataiz.der + a.left().root();
      if (!a.right().empty()) data.der = datader.iz + datader.der + data.der + a.right().root();

       
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    BinTree<int> arbol = read_tree<int>(cin);
    datos d = { 0,0, 0 };

   resolver(arbol, d);
   cout << d.total;
    // escribir solución
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    std::ifstream in("datos.in");
//    auto cinbuf = std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("datos.out");
//    auto coutbuf = std::cout.rdbuf(out.rdbuf());
//#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
//#ifndef DOMJUDGE
//    std::cin.rdbuf(cinbuf);
//    std::cout.rdbuf(coutbuf);
//    system("PAUSE");
//#endif
    return 0;
}