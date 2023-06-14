#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
#include <list>

using namespace std;

class Restaurante
{
private:
	typedef struct infoPedido
	{
		int mesa;
		string plato;
	};

	unordered_set<int> mesas;
	list<infoPedido> pedidos;

public:
	void nueva_mesa(int num) {
		if (mesas.count(num) > 0)
		{
			throw domain_error("Mesa ocupada");
		}

		mesas.insert(num);
	}

	void nuevo_pedido(int mesa, const string& plato) {
		if (mesas.count(mesa) == 0)
		{
			throw domain_error("Mesa vacía");
		}

		infoPedido pedido = { mesa, plato };
		pedidos.push_back(pedido);
	}

	void cancelar_pedido(int mesa, const string& plato) {
		if (mesas.count(mesa) == 0)
		{
			throw domain_error("Mesa vacía");
		}

		bool found = false;
		auto it = pedidos.begin();
		while (it != pedidos.end() && !found)
		{
			if (it->mesa == mesa && it->plato == plato)
			{
				found = true;
				it = pedidos.erase(it);
			}
			else
			{
				++it;
			}
		}

		if (!found)
		{
			throw domain_error("Producto no pedido por la mesa");
		}
	}

	pair<int, string> servir()
	{
		if (pedidos.size() == 0)
		{
			throw domain_error("No hay pedidos pendientes");
		}

		pair<int, string> pedido;
		pedido.first = pedidos.front().mesa;
		pedido.second = pedidos.front().plato;
		pedidos.pop_front();

		return pedido;
	}

	vector<string> que_falta(int mesa) const
	{
		if (mesas.count(mesa) == 0)
		{
			domain_error("Mesa vacía");
		}

		set<string> platos;
		auto it = pedidos.begin();
		while (it != pedidos.end())
		{
			if (it->mesa == mesa) {
				platos.insert(it->plato);
			}
			++it;
		}
		vector<string> resul;
		
		for (string p : platos)
		{
			resul.push_back(p);
		}

		return resul;

	}

};


bool tratar_caso() {
	Restaurante r;

	string operacion;
	cin >> operacion;

	if (cin.eof()) return false;

	while (operacion != "FIN") {
		try {
			if (operacion == "nueva_mesa") {
				int n; cin >> n;
				r.nueva_mesa(n);
			}
			else if (operacion == "nuevo_pedido") {
				int n; cin >> n;
				string p; cin >> p;
				r.nuevo_pedido(n, p);
			}
			else if (operacion == "cancelar_pedido") {
				int n; cin >> n;
				string p; cin >> p;
				r.cancelar_pedido(n, p);
			}
			else if (operacion == "servir") {
				pair<int, string> par = r.servir();
				cout << par.second << " " << par.first << "\n";
			}
			else if (operacion == "que_falta") {
				int n; cin >> n;
				vector<string> platos = r.que_falta(n);
				cout << "En la mesa " << n << " falta:\n";
				for (const string& p : platos) {
					cout << "  " << p << "\n";
				}
			}
		}
		catch (exception& e) {
			cout << "ERROR: " << e.what() << "\n";
		}

		cin >> operacion;
	}

	cout << "---\n";

	return true;
} // tratar_caso

int main() {


	while (tratar_caso()) {}



	return 0;
}