#include <iostream>

int LEER_NUMERO() {
    int numero;
    std::cout << "Enter a number: ";
    std::cin >> numero;
    return numero;
}

void PAR_IMPAR(int n){
    if (n % 2 == 0) {
        std::cout << "El numero es par" << std::endl;
    } else {
        std::cout << "El numero es impar" << std::endl;
    }
    while (n >= 0){
        std::cout << n << std::endl;
        n -= 2;
    }
}

void ex1() {
    int NUMERO = LEER_NUMERO();
    PAR_IMPAR(NUMERO);
}
