#include "lista.h"
#include "nodo.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

void agregarTitular(string pTitular, int pRelevancia) {
    agregarPosicion(pTitular, pRelevancia);
}

void mostrarTitulares() {
    mostrarElementos();
}

void eliminarTitulares(string pPalabra){
    eliminarElementoPalabra(pPalabra);
}

void buscarTitulares(string pPalabra) {
    mostrarElementoPosicion(buscarElementoPalabra(pPalabra));
}

void manipularRelevancia2(int pPosicionTitular, int pModificacion) {
    manipularRelevancia(pPosicionTitular, pModificacion);
}

// Main de pruebas
int main(void)
{

    string myString1 = "Esta es una cadena de texto larga número 1. Puede contener múltiples líneas y caracteres especiales.";
    string myString2 = "Esta es una cadena de texto larga número 2. Puede contener múltiples líneas y caracteres especiales.";
    string myString3 = "Esta es una cadena de texto larga número 3. Puede contener múltiples líneas y caracteres especiales.";
    string myString4 = "Esta es una cadena de texto larga número 4. Puede contener múltiples líneas y caracteres especiales.";
    string myString5 = "Esta es una cadena de texto larga número 5. Puede contener múltiples líneas y caracteres especiales.";
    string myString6 = "Esta es una cadena de texto larga número 6. Puede contener múltiples líneas y caracteres especiales.";
    string myString7 = "Esta es una cadena de texto larga número 7. Puede contener múltiples líneas y caracteres especiales.";
    string myString8 = "Esta es una cadena de texto larga número 8. Puede contener múltiples líneas y caracteres especiales.";
    string myString9 = "Esta es una cadena de texto larga número 9. Puede contener múltiples líneas y caracteres especiales.";


    listadoble testlista;

    testlista.listaVacia();

    testlista.eliminarPosicion(2);

    testlista.agregarInicio(&myString8);
    testlista.agregarFinal(&myString9);
    testlista.agregarInicio(&myString7);
    testlista.agregarInicio(&myString6);
    testlista.agregarInicio(&myString5);
    testlista.agregarInicio(&myString4);
    testlista.agregarInicio(&myString3);
    testlista.agregarInicio(&myString2);
    testlista.agregarInicio(&myString1);

    testlista.mostrarElementos();

    cout << "--" << endl;

    testlista.eliminarFinal();

    testlista.mostrarElementos();

    cout << "--" << endl;

    testlista.obtenerInicio();

    testlista.getSize();

    cout << "--" << endl;

    testlista.eliminarPosicion(1);

    testlista.getSize();

    cout << "--" << endl;

    testlista.mostrarElementos();

    testlista.listaVacia();

    testlista.mostrarPosicion(5);

    testlista.buscarElementoPalabra("4.");

    return 0;
}