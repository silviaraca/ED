#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>

using namespace std;

class Red {
private:
    unordered_map<string, set<string>> lineas;
    unordered_map<string, map<int, string>> distancias;
    unordered_map<string, set<string, int>> estaciones;

public:
    void nueva_linea(const string& nombre) {
        if (lineas.count(nombre) > 0) {
            throw domain_error("Linea existente");
        }
        lineas[nombre] = {};
        distancias[nombre] = {};
        estaciones[nombre] = { "A", {"R", 2} };

    }

    void nueva_estacion(const string& linea, const string& nombre, int posicion) {
        if (lineas.count(linea) <= 0) {
            throw domain_error("Linea no existente");
        }
        if (lineas.at(linea).count(nombre) > 0) {
            throw domain_error("Estacion duplicada en linea");
        }
        if (distancias.at(linea).count(posicion) > 0)
        {
            throw domain_error("Posicion ocupada en linea");
        }

        lineas.at(linea).insert(nombre);
        distancias.at(linea)[posicion] = {};
        distancias.at(linea).at(posicion) = nombre;
        if (estaciones.count(nombre) == 0) estaciones[nombre] = {};
        estaciones.at(nombre).insert(linea);
    }

    void eliminar_estacion(const string& estacion) {

        if (estaciones.count(estacion) == 0) {
            throw domain_error("Estacion no existente");
        }

        auto it = estaciones.at(estacion).cbegin();
        bool found = false;
        while (it != estaciones.at(estacion).cend())
        {
            lineas.at(*it).erase(estacion);
            auto it2 = distancias.at(*it).begin();
            bool deleted = false;
            while (!deleted && it2 != distancias.at(*it).cend())
            {
                if (it2->second == estacion)
                {
                    distancias.at(*it).erase(it2);
                    deleted = true;
                }
                else
                {
                    ++it2;
                }
          
            }
            ++it;
     
        }

        estaciones.erase(estacion);
    }

    vector<string> lineas_de(const string& estacion) const {
        if (estaciones.count(estacion) == 0) {
            throw domain_error("Estacion no existente");
        }

        vector<string> l;
        auto it = estaciones.at(estacion).cbegin();

        while (it != estaciones.at(estacion).cend())
        {
            l.push_back(*it);
            ++it;
        }
        return l;
    }

    string proxima_estacion(const string& linea, const string& estacion) const {
        if (lineas.count(linea) == 0) {
            throw domain_error("Linea no existente");
        }
        if (lineas.at(linea).count(estacion) == 0) {
            throw domain_error("Estacion no existente");
        }

        auto it = distancias.at(linea).cbegin();
        while (it != distancias.at(linea).cend())
        {
            if (it->second == estacion) {
                auto aux = it;
                aux++;
                if (aux == distancias.at(linea).cend())
                {
                    throw domain_error("Fin de trayecto");
                }
                else
                {
                    return aux->second;
                }
            }
            ++it;
        }
    }
};


bool tratar_caso() {

    Red red;

    string command = "";

    if (cin.eof()) {
        return false;
    }

    while (command != "FIN")
    {
        cin >> command;
        try {
            if (command == "nueva_linea") {
                string nombre;
                cin >> nombre;
                red.nueva_linea(nombre);
            }
            else if (command == "nueva_estacion") {
                string linea, nombre;
                int posicion;
                cin >> linea >> nombre >> posicion;
                red.nueva_estacion(linea, nombre, posicion);
            }
            else if (command == "eliminar_estacion") {
                string estacion;
                cin >> estacion;
                red.eliminar_estacion(estacion);
            }
            else if (command == "lineas_de") {
                string estacion;
                cin >> estacion;
                vector<string> lineas = red.lineas_de(estacion);
                cout << "Lineas de " << estacion << ": ";
                for (const string& linea : lineas) {
                    cout << linea << " ";
                }
                cout << endl;
            }
            else if (command == "proxima_estacion") {
                string linea, estacion;
                cin >> linea >> estacion;
                string siguienteEstacion = red.proxima_estacion(linea, estacion);
                cout << siguienteEstacion << endl;
            }
        }
        catch (const exception& e) {
            cout << "ERROR: " << e.what() << endl;
        }
    }

    
    cout << "---" << endl;
    return true;
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (tratar_caso()) {}

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}