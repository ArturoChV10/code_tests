/*
author: Jorge Arturo Chavarría Villarevia
date: 28/08/2023
description: tarea #1, peliminar 2.
*/

#ifndef LISTA_H
#define LISTA_H 1

#include "nodo.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "lista.h"

using namespace std;

struct listadoble
{

    struct nodo *start = nullptr;
    struct nodo *end = nullptr;
    int size = 0;

    // Método que devuelve un valor booleano de True si el tamaño de la lista es 0 y False en caso contrario
    bool listaVacia()
    {
        if (size == 0)
        {
            cout << "True" << endl;
            return true;
        }
        else
        {
            cout << "False" << endl;
            return false;
        }
    }

    // Método que retornará el tamaño de la lista
    int getSize()
    {
        cout << size << endl;
        return size;
    }

    // Método que agrega un elemento al final de la lista
    void agregarFinal(string *pData)
    {
        struct nodo *newNode = (struct nodo *)malloc(sizeof(struct nodo));
        newNode->data = pData;

        if (size == 0)
        {
            start = newNode;
            end = newNode;
        }
        else
        {
            newNode->previous = end;
            end->next = newNode;
            end = newNode;
        }

        size++;
    }

    // Método que agrega un elemento al inicio de la lista
    void agregarInicio(string *pData)
    {
        struct nodo *newNode = (struct nodo *)malloc(sizeof(struct nodo));
        newNode->data = pData;

        if (size == 0)
        {
            start = newNode;
            end = newNode;
        }
        else
        {
            newNode->next = start;
            start->previous = newNode;
            start = newNode;
        }

        size++;
    }

    // Método que elimina un elemento al inicio de la lista
    void *eliminarInicio()
    {
        void *result = nullptr;
        struct nodo *cursor = start;

        if (size > 1)
        {
            start->next->previous = nullptr;
            start = start->next;
            cursor->next = nullptr;
            result = cursor->data;
            size--;
        }
        else if (size == 1)
        {
            start = nullptr;
            end = nullptr;
            result = cursor->data;
            size--;
        }

        return result;
    }

    // Método que elimina un elemento al final de la lista
    void *eliminarFinal()
    {
        void *result = nullptr;
        struct nodo *cursor = end;

        if (size > 1)
        {
            end->previous->next = nullptr;
            end = end->previous;
            cursor->previous = nullptr;
            result = cursor->data;
            size--;
        }
        else if (size == 1)
        {
            start = nullptr;
            end = nullptr;
            result = cursor->data;
            size--;
        }

        return result;
    }

    // Método que recibe un string y la posición de popularidad para poder agregarlo a la lista
    int agregarPosicion(struct noticia *pValue, int pPosicion)
    {

        struct nodo *newNode = (struct nodo *)malloc(sizeof(struct nodo));
        newNode->data = pValue;

        if (size == 0)
        {
            start = newNode;
            end = newNode;
            return 0;
        }
        else
        {
            if (pPosicion > size)
            {
                newNode->previous = end;
                end->next = newNode;
                end = newNode;
                return 0;
            }
            else
            {
                if (pPosicion < 0)
                {
                    cout << "Error: El indice indicado es menor a 0" << endl;
                    return 0;
                }
                else
                {
                    int posicionActual = 0;
                    struct nodo *cursor = start;

                    while (cursor != end && posicionActual < pPosicion)
                    {
                        cursor = cursor->next;
                        posicionActual++;
                    }

                    newNode->next = cursor->next;
                    newNode->previous = cursor;
                    cursor->next = newNode;
                    if (cursor == end)
                    {
                        end = newNode;
                        start->previous = newNode;
                        return 0;
                    }
                }
            }
        }
    }

    noticia *eliminarPosicion(int pPosicion)
    {
        void *result = nullptr; // Esta línea crea una variable tipo void llamada result, esta servirá para guardar el nodo eliminado

        if (size == 0)
        {
            cout << "No existen elementos en el array" << endl;
        }
        else
        {
            if (size == 1)
            {
                struct nodo *cursor = start;

                start = nullptr;
                end = nullptr;
                result = cursor->data;
                size--;
            }
            else
            {
                if (pPosicion >= size)
                {
                    struct nodo *cursor = end;

                    end->previous->next = nullptr;
                    /*La línea de arriba hace que el elemento previous al end, tenga un enlace next con nullptr, básicamente el
                    primer puntero (end) dice donde se empieza, luego el segundo puntero señala la acción que se le va a realizar,
                    en este caso retroceder un espacio, y por último el tercer puntero (next) señala que el elemento señalado anteriormente
                    va a tener una conexión next con el elemento que se encuentra después del símbolo de igual, en este caso nullptr*/
                    end = end->previous; // Asigna el puntero end al elemento anterior al último
                    cursor->previous = nullptr;
                    result = cursor->data;
                    size--;
                }
                else
                {
                    if (pPosicion < 0)
                    {
                        cout << "Error: El indice indicado es menor a 0" << endl;
                    }
                    else
                    {
                        if (pPosicion == 1)
                        {
                            struct nodo *cursor = start;

                            start->next->previous = nullptr;
                            start = start->next;
                            cursor->next = nullptr;
                            result = cursor->data;
                            size--;
                        }
                        else
                        {
                            int posicionActual = 0;
                            struct nodo *cursor = start;
                            cursor = cursor->next;

                            while (cursor != end && posicionActual < pPosicion)
                            {
                                cursor = cursor->next;
                                posicionActual++;
                            }
                            cursor = cursor->previous;
                            cursor = cursor->previous;

                            cursor->next->previous = cursor->previous;
                            cursor->previous->next = cursor->next;
                            result = cursor->data;
                            //                    cursor=cursor->next;
                            size--;
/*
                            //                    newNode->next = cursor->next;
                            //                  newNode->previous = cursor;
                            //                cursor->next = newNode;
                            //              if (cursor == end)
                            //            {
                            //              end = newNode;
                            //            start->previous = newNode;
                            //          return 0;
                            //    }
*/
                        }
                    }
                }
            }
        }
        noticia *ptrNoticia = static_cast<noticia *>(result);
        return ptrNoticia;
    }
/*
    // Método para obtener un elemento específico
    //    void mostrarElementos()
    //  {
    //    struct nodo *cursor = start;
    //  for (int indice = 0; indice >= size; indice++)
    //  {
    //        cout << cursor->data << end;
    //      }
    //    }
*/
    void manipularRelevancia(int pPosicionTitular, int pModificacion) {
        pModificacion = pModificacion * -1;
        int futuraPosicion = pPosicionTitular + pModificacion;
        noticia *variableDato = eliminarPosicion(pPosicionTitular);
        agregarPosicion(variableDato, futuraPosicion);
    }

    void mostrarElementos()
    {
        struct nodo *cursor = start;
        while (cursor != nullptr)
        {
            if (cursor->data != nullptr)
            {
                string *strPtr = static_cast<string *>(cursor->data);
                cout << *strPtr << endl; // Imprime el contenido de cada nodo
            }
            cursor = cursor->next;
        }
    }

    void obtenerInicio()
    {
        struct nodo *cursor = start;
        if (cursor->data != nullptr)
        {
            string *strPtr = static_cast<string *>(cursor->data);
            cout << *strPtr << endl; // Imprime el contenido del primer nodo
        }
    }

    void obtenerFinal()
    {
        struct nodo *cursor = end;
        if (cursor->data != nullptr)
        {
            string *strPtr = static_cast<string *>(cursor->data);
            cout << *strPtr << endl; // Imprime el contenido del último nodo
        }
    }

    void mostrarPosicion(int pPosicion)
    {
        struct nodo *cursor = start;
        if (pPosicion == size)
        {
            obtenerFinal();
        }
        else
        {
            if (pPosicion == 1) 
            {
                obtenerInicio();
            }
            else
            {
                int posicionActual = 1;

                while (posicionActual<pPosicion)
                {
                    cursor = cursor->next;
                    posicionActual++;
                }
                string *strPtr = static_cast<string *>(cursor->data);
                cout << *strPtr << endl; // Imprime el contenido del último nodo
            }
        }
    }
/*
    string obtenerFinal2()
    {
        struct nodo *cursor = end;
        if (cursor->data != nullptr)
        {
            string *strPtr = static_cast<string *>(cursor->data);
            string result = *strPtr;
            return result;
        }
    }

    void obtenerInicio2()
    {
        struct nodo *cursor = start;
        if (cursor->data != nullptr)
        {
            string *strPtr = static_cast<string *>(cursor->data);
            string result = *strPtr;
            return result;
        }
    }

    string copiarElemento(int pPosicion) {
        struct nodo *cursor = start;
        if (pPosicion == size)
        {
            obtenerFinal2();
        }
        else
        {
            if (pPosicion == 1) 
            {
                obtenerInicio2();
            }
            else
            {
                int posicionActual = 1;

                while (posicionActual<pPosicion)
                {
                    cursor = cursor->next;
                    posicionActual++;
                }
                string *strPtr = static_cast<string *>(cursor->data);
                cout << *strPtr << endl; // Imprime el contenido del último nodo
            }
        }

        return result;
    }
*/
    int buscarElementoPalabra(string pPalabra) {
        struct nodo* cursor = start;

        for (int indiceB = 1; indiceB<size; indiceB++) {

            string *strPtr = static_cast<string *>(cursor->data);

            //Comprueba que strPtr no sea null
            if (strPtr) {
                string copiaString = *strPtr;

                istringstream ss(copiaString);

                string palabra;
                vector<string> palabras;

                while (ss >> palabra) {
                    palabras.push_back(palabra);
                }

                for (const string& p : palabras) {
                    if (pPalabra == p) {
                        string posicionPalabra = to_string(indiceB);
                        cout << posicionPalabra << endl;
                        return indiceB;
                    }
                }

            }

/*
            if (pPalabra == *strPtr) {
                string posicionPalabra = to_string(indiceB);
                cout << posicionPalabra << endl;
            }
*/
            cursor = cursor->next;
        }
        
        return 0;
    }

    int eliminarElementoPalabra(string pPalabra) {
        struct nodo* cursor = start;

        for (int indiceB = 1; indiceB<size; indiceB++) {

            string *strPtr = static_cast<string *>(cursor->data);

            //Comprueba que strPtr no sea null
            if (strPtr) {
                string copiaString = *strPtr;

                istringstream ss(copiaString);

                string palabra;
                vector<string> palabras;

                while (ss >> palabra) {
                    palabras.push_back(palabra);
                }

                for (const string& p : palabras) {
                    if (pPalabra == p) {
                        eliminarPosicion(indiceB);
                    }
                }

            }

            cursor = cursor->next;
        }
        
        return 0;
    }
};

#endif