/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

 /*
   Indica el nombre y apellidos de los componentes del grupo
   ---------------------------------------------------------
   Componente 1:
   Componente 2:
 */

#include <iostream>
#include <fstream>
#include <cassert>
#include <list>

using namespace std;

void suavizar(list<int>& l) {
	// Implementa aquí la función pedida
	auto it = l.begin();
	int dif = 0;
	bool itMenor = false, insert = false;

	while(it != l.end())
	{
		if (l.size() > 1)
		{
			auto it_next = it;
			++it_next;

			
			if (*it == *it_next) //Numeros repetidos
			{
				l.erase(it_next);
				insert = false;
			}
			else if (*it < *it_next)
			{
				dif = *it_next - *it;
				itMenor = true;
			}
			else if (*it > *it_next)
			{
				dif = *it - *it_next;
				itMenor = false;
			}

			int val = *it;
			for (int i = 0; i < dif - 1; i++)
			{
				insert = true;
				auto aux = it;
	
				++aux;

				//Si it es menor que it_next
				if (itMenor) { l.insert(aux, val + 1 + i);  }
				else { l.insert(aux, val - 1 - i);	}
				++it;
			}
		}
		if (insert) ++it;

	}
	auto iter = l.begin();
	for (int i = 0; i < l.size(); i++)
	{
		cout << *iter << " ";
		++iter;
	}
}

bool tratar_caso() {
	list<int> l;
	int size;

	cin >> size;
	for (int i = 0; i < size; i++)
	{
		int n;
		cin >> n;
		l.push_back(n);
	}
	suavizar(l);
	return true;
}

int main() {
//#ifndef DOMJUDGE
//	std::ifstream in("sample.in");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf());
//#endif

	while (tratar_caso()) {}

//#ifndef DOMJUDGE
//	std::cin.rdbuf(cinbuf);
//#endif
	return 0;
}
