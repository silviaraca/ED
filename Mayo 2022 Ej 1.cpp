
// Autor/a: Nombre y apellidos
// email:
// Compilador y S.O. utilizado
// Nombre del problema
// Comentario general sobre la solución
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include <list>
#include <stack>
// Introduce más librerías si son necesarias
using namespace std;


// función que resuelve el problema
void reconstruir(list<int>& lista) {
    stack<int> pila;

    int tam = lista.size();
    for (int i = 0; i < tam; i++)
    {
        if (lista.front() > 0) 
        {
            pila.push(lista.front());
            int num = lista.front();
            lista.pop_front();
            lista.push_back(num);

        }
        else
        {
            if (pila.size() > 0)
            {
                lista.pop_front();
                int val = pila.top() * (-1);
                lista.push_back(val);
                pila.pop();
            }
            else
            {
                lista.pop_front();
            }
        }
    }

    while (pila.size() > 0)
    {
        int val = pila.top() * (-1);
        lista.push_back(val);
        pila.pop();
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    list<int> lista;
    int num, total;

    cin >> total;
    for (int i = 0; i < total; i++)
    {
        cin >> num;
        lista.push_back(num);
    }
     reconstruir(lista);
     
     int tam = lista.size();

     for (int i = 0; i < tam; i++)
     {
         cout << lista.front() << " ";
         lista.pop_front();
     }
     cout << endl;
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

