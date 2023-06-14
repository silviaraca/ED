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

    ac.anyadir_curso("Introducción a la rubismática", 20);
    ac.anyadir_curso("Fundamentos de pastificio", 2);
    ac.matricular_en_curso("Genaro Pérez", "Introducción a la rubismática");
    ac.matricular_en_curso("Santiago Carvajal", "Introducción a la rubismática");
    ac.matricular_en_curso("Mireia Casado", "Introducción a la rubismática");

    ac.matricular_en_curso("Genaro Pérez", "Fundamentos de pastificio");

    cout << ac.plazas_libres("Introducción a la rubismática") << endl;
    for (const Estudiante& e : ac.estudiantes_matriculados("Introducción a la rubismática")) {
        cout << e << endl;
    }

    return 0;
}