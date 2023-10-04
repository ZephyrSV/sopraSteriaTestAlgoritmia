#include <iostream>
#include <vector>

inline double Get_Salario(int horas, double tarifa) {
    return std::min(horas, 40) * tarifa + std::max(0,horas-40) * tarifa * 1.5;
}

inline int LEER_HORAS_TRABAJADAS(){
    int horas;
    std::cout << "Ingrese las horas trabajadas: ";
    std::cin >> horas;
    return horas;
}
inline double LEER_TARIFA(){
    double tarifa;
    std::cout << "Ingrese la tarifa: ";
    std::cin >> tarifa;
    return tarifa;
}

void ex3() {
    int HORAS = LEER_HORAS_TRABAJADAS();
    double TARIFA = LEER_TARIFA();
    std::cout << "El salario es: " << Get_Salario(HORAS, TARIFA) << std::endl;
}