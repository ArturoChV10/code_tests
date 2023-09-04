#include "lista.h"
#include <iostream>

int main() {
    // Aquí puedes utilizar los métodos definidos en "lista.h"
    listadoble miLista;  // Crear una instancia de la estructura listadoble
    string myString1 = "Esta es una cadena de texto larga número 1. Puede contener múltiples líneas y caracteres especiales.";
    miLista.agregarFinal(&myString1);  // Ejemplo de llamada a un método
    // ...
    return 0;
}