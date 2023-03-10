//@ <answer>
// ===========================================================
// Escribe tu solución por debajo de esta línea
// ===========================================================

#include <stack>
#include <string>
#include <iostream>

using namespace std;

// ¡No te olvides del coste!
void tratar_caso() {
	// Escribe aquí el código para tratar un (y solo un) caso de prueba. 
	string palabra = "";
	stack<string> frase, eliminadas;
	
	//Esta pila se va a utilizar para saber qué acciones se han ido haciendo 
	//(1 es que se ha añadido una palabra y 2 es que se ha eliminado)
	stack<int> acciones;

	cin >> palabra;

	//QUITAR EL WHILE X
	while (palabra != "x")
	{
		if (palabra == "*")
		{
			if (!frase.empty())
			{
				//Eliminamos la última palabra que hemos metido y la añadimos a la pila de eliminadas
				eliminadas.push(frase.top());
				frase.pop();
				acciones.push(2);
			}
		}
		else if (palabra == "+")
		{
			if (!acciones.empty())
			{
				if (acciones.top() == 2) //La ultima accion fue eliminar una palabra
				{
					//Metemos la ultima palabra eliminada de nuevo en la frase
					frase.push(eliminadas.top());
					eliminadas.pop();
					acciones.pop();
				}
				else if (acciones.top() == 1)
				{
					//Quitamos la ultima palabra añadida
					frase.pop();
					acciones.pop();
				}
					
			}

		}
		else
		{
			//Añadimos la palabra
			frase.push(palabra);
			acciones.push(1);
		}
		cin >> palabra;

	}

	stack<string> aux;
	int tam = frase.size();
	for (int i = 0; i < tam; i++)
	{
		aux.push(frase.top());
		frase.pop();
	}

	for (std::stack<string> dump = aux; !dump.empty(); dump.pop())
		std::cout << dump.top() << ' ';

	cout << endl;

}

//@ </answer>
// ===========================================================
// No modifiques nada por debajo de esta línea
// ===========================================================


int main() {

//#ifndef DOMJUDGE
//	std::ifstream in("sample.in");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf());
//#endif

	// El primer dato leído indica el número de casos de prueba
	int num_casos;
	cin >> num_casos;
	// El puntero de lectura ahora mismo se sitúa detrás del número de casos de prueba
	// Si se queda ahí, la próxima llamada a getline() leería el resto de esa línea, que
	// no es lo que queremos. Por tanto, avanzamos la lectura de la entrada hasta el
	// fin de línea.
	cin.ignore(10, '\n');

	// Llamamos a tratar_caso tantas veces como indica num_caso
	for (int i = 0; i < num_casos; i++) {
		tratar_caso();
	}

//#ifndef DOMJUDGE
//	std::cin.rdbuf(cinbuf);
//#endif
	return 0;
}


