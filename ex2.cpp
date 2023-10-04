#include <iostream>
#include <vector>



enum Sexo {MASCULINO, FEMENINO};

class Persona {
public:
    Sexo sexo;
    uint32_t edad;
    bool es_mayor_edad(){
        return edad >= 18;
    }
};

void LEER_PERSONAS(std::vector<Persona> &personas, int n=50){
    Persona persona;
    std::cout << "Ingrese el sexo de la persona (0: masculino, 1: femenino): ";
    int sexo;
    while (std::cin >> sexo){
        if (sexo == 0) {
            persona.sexo = MASCULINO;
            break;
        }
        else if (sexo == 1) {
            persona.sexo = FEMENINO;
            break;
        }
        std::cout << "Error en el ingreso del sexo. Ingrese nuevamente: (0: masculino, 1: femenino)";
    }
    std::cout << "Ingrese la edad de la persona: ";
    std::cin >> persona.edad;
    personas.push_back(persona);
    if (n < 0)
        return;
    LEER_PERSONAS(personas, n-1); // Tail-end recursion, no stack overflow
}

void ex2(){
    std::vector<Persona> personas;
    personas.reserve(50); // Reserve memory for 50 personas

    LEER_PERSONAS(personas);

    int mayores_edad = 0;
    int mayores_edad_masculinos = 0;
    int masculinos = 0;

    for (Persona p : personas){
        if (p.sexo == MASCULINO){
            masculinos++;
        }
        if (p.es_mayor_edad()){
            mayores_edad++;
        }
        if (p.sexo == MASCULINO && p.es_mayor_edad()){
            mayores_edad_masculinos++;
        }
    }

    std::cout << "Cantidad de personas mayores de edad " << mayores_edad << std::endl;
    std::cout << "Cantidad de personas menores de edad " << personas.size()-mayores_edad << std::endl;
    std::cout << "Cantidad de personas masculinas mayores de edad " << mayores_edad_masculinos << std::endl;
    std::cout << "Cantidad de personas femininas mayores de edad " << mayores_edad - mayores_edad_masculinos << std::endl;
    std::cout << "Porcentaje que representan las personas mayores de edad respecto al total de personas " << 100*mayores_edad/(double)personas.size() << '%' << std::endl;
    std::cout << "Porcentaje que representan las personas las mujeres respecto al total de personas " << 100*masculinos/(double)personas.size() << '%' << std::endl;

}