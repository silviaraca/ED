//@ <answer>
// ===========================================================
// Escribe tu soluci�n por debajo de esta l�nea
// ===========================================================

#include <stack>
#include <string>
#include <iostream>

using namespace std;

// �No te olvides del coste!
void tratar_caso() {
	// Escribe aqu� el c�digo para tratar un (y solo un) caso de prueba. 
	string palabra = "";
	stack<string> frase, eliminadas;
	
	//Esta pila se va a utilizar para saber qu� acciones se han ido haciendo 
	//(1 es que se ha a�adido una palabra y 2 es que se ha eliminado)
	stack<int> acciones;

	cin >> palabra;

	//QUITAR EL WHILE X
	while (palabra != "x")
	{
		if (palabra == "*")
		{
			if (!frase.empty())
			{
				//Eliminamos la �ltima palabra que hemos metido y la a�adimos a la pila de eliminadas
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
					//Quitamos la ultima palabra a�adida
					frase.pop();
					acciones.pop();
				}
					
			}

		}
		else
		{
			//A�adimos la palabra
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
// No modifiques nada por debajo de esta l�nea
// ===========================================================


int main() {

//#ifndef DOMJUDGE
//	std::ifstream in("sample.in");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf());
//#endif

	// El primer dato le�do indica el n�mero de casos de prueba
	int num_casos;
	cin >> num_casos;
	// El puntero de lectura ahora mismo se sit�a detr�s del n�mero de casos de prueba
	// Si se queda ah�, la pr�xima llamada a getline() leer�a el resto de esa l�nea, que
	// no es lo que queremos. Por tanto, avanzamos la lectura de la entrada hasta el
	// fin de l�nea.
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


