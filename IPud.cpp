
// Autor/a: Nombre y apellidos
// email:
// Compilador y S.O. utilizado
// Nombre del problema
// Comentario general sobre la solución
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <list>
#include<algorithm>
// Introduce más librerías si son necesarias
using namespace std;

class IPud {
private:
    typedef struct infoCancion
    {
        int duracion;
        string artista;
    };

    list<pair<string, int>> cola;
    list<pair<string, int>> reproducidas;
    unordered_map<string, infoCancion> playlist;
    
public:
    void addSong(string s, string a, int d)
    {
        if (playlist.count(s) > 0)
        {
            throw domain_error("La canción ya esta en el ipud");
        }

        playlist[s] = { d,a };
    }

    void addToPlaylist(string s)
    {
        int duracion;
        if (playlist.count(s) == 0)
        {
            throw domain_error("La canción no existe");
        }
        else
        {
            duracion = playlist.at(s).duracion;
        }

       
    }


    string current()
    {
        if (cola.size() == 0)
        {
            throw domain_error("cola vacia");
        }

        return cola.front().first;
    }

    string play()
    {
        if (cola.size() == 0)
        {
            throw domain_error("cola vacia");
        }

        reproducidas.push_back(cola.front());
        string song = cola.front().first;
        cola.pop_front();
        return song;
    }

    int totalTime()
    {
        int suma = 0;

        auto it = cola.begin();
        while (it != cola.end())
        {
            suma += it->second;
            ++it;
        }
        
        return suma;
    }
    
    list<string> recent(int n) 
    {
        int pos = 0;
        unordered_set<string> aux;
        list<string> result;

        auto it = reproducidas.begin();
        while (pos < n && pos < reproducidas.size())
        {
            if (aux.count(it->first) == 0)
            {
                aux.insert(it->first);
                result.push_back(it->first);

            }
            pos++;
        }

        return result;
    }

    void deleteSong(string s)
    {
        if (playlist.count(s) == 0)
        {
            throw domain_error("La canción no existe");
        }
        
        playlist.erase(s);
       

    }


};


bool resuelveCaso() {

    IPud ipud;
    string linea;

    if (!std::cin)
        return false;

    while (linea != "FIN") {

       
        string operacion;
        cin >> operacion;

        if (operacion == "addSong") {
            string s, a; int d;
            cin >> s >> a >> d;
            try {
                ipud.addSong(s, a, d);
            }
            catch (domain_error& de) {
                cout << de.what() << endl;
            }
        }
        else if (operacion == "addToPlaylist") {
            string s;
            cin >> s;
            try {
                ipud.addToPlaylist(s);
            }
            catch (domain_error& de) {
                cout << de.what() << endl;
            }
        }
        else if (operacion == "current") {
            try {
                string s = ipud.current();
                cout << s << endl;
            }
            catch (domain_error& de) {
                cout << de.what() << endl;
            }
        }
        else if (operacion == "play") {
            try {
                string s = ipud.play();
                cout << "Sonando " + s << endl;
            }
            catch (domain_error& de) {
                cout << de.what() << endl;
            }
        }
        else if (operacion == "totalTime") {
            try {
                int d = ipud.totalTime();
                cout << "Tiempo total " << d << endl;
            }
            catch (domain_error& de) {
                cout << de.what() << endl;
            }
        }
        else if (operacion == "recent") {
            int n;
            cin >> n;
            try {
                list<string> l = ipud.recent(n);
                cout << "Las "; cout << l.size(); cout << " mas recientes" << endl;
                for (auto it = l.begin(); it != l.end(); ++it) {
                    cout << "    " << *it << endl;
                }
            }
            catch (domain_error& de) {
                cout << de.what() << endl;
            }
        }
        else if (operacion == "deleteSong") {
            string s;
            cin >> s;
            try {
                ipud.deleteSong(s);
            }
            catch (domain_error& de) {
                cout << de.what() << endl;
            }
        }
    }

    cout << "---" << endl;

    return true;
    
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
    while (resuelveCaso());

    return 0;
}