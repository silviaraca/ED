#include <string>
#include <vector>
#include <iostream>
#include<set>
#include<unordered_set>


using Estudiante = std::string;
using Curso = std::string;

class Academia {
public:

    void anyadir_curso(const std::string& nombre, int numero_plazas) {
        // Implementar
        if (cursos.count(nombre) > 0)
        {
            throw domain_error("Ya existe un curso con ese nombre");
        }
        else
        {
            tInfoCurso cursoNuevo;
            set<Estudiante> estudiantes;
            cursoNuevo = { numero_plazas, estudiantes };
            cursos.insert({nombre, );
        }
    }

    void eliminar_curso(const Curso& curso) {
        // Implementar
    }

    int plazas_libres(const Curso& curso) const {
        // Implementar
        return 0;
    }

    void matricular_en_curso(const Estudiante& est, const Curso& curso) {
        // Implementar
    }

    std::vector<Estudiante> estudiantes_matriculados(const Curso& curso) const {
        // Implementar
        return std::vector<Estudiante>();
    }


private:
    struct tInfoCurso
    {
        int plazas;
        set<Estudiante> estudiantes;
    };
    
    unordered_set<Curso, tInfoCurso> cursos;
};


using namespace std;

int main() {
    Academia ac;

    ac.anyadir_curso("Introducci�n a la rubism�tica", 20);
    ac.anyadir_curso("Fundamentos de pastificio", 2);
    ac.matricular_en_curso("Genaro P�rez", "Introducci�n a la rubism�tica");
    ac.matricular_en_curso("Santiago Carvajal", "Introducci�n a la rubism�tica");
    ac.matricular_en_curso("Mireia Casado", "Introducci�n a la rubism�tica");

    ac.matricular_en_curso("Genaro P�rez", "Fundamentos de pastificio");

    cout << ac.plazas_libres("Introducci�n a la rubism�tica") << endl;
    for (const Estudiante& e : ac.estudiantes_matriculados("Introducci�n a la rubism�tica")) {
        cout << e << endl;
    }

    return 0;
}