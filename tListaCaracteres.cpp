#include <stdlib.h>
#include <stdio.h>
#include "tListaCaracteres.hpp"

class caracteres {
private:
    char* listArray;
    int listSize;
    int maxSize;
    int curr;
public:
    void inicializarLista (tListaCaracteres &lista, int capacidadinicial) {
        lista.listSize = 0;
        lista.curr = 0;
        lista.maxSize = capacidadinicial;
        lista.listArray = new char[capacidadinicial];
    }
    void insertarCaracter (tListaCaracteres &lista, char c, int pos) {
        if (lista.listSize < lista.maxSize) {
            lista.listArray[lista.listSize++] = c;
        }
        else {
            int nuevomaxsize = lista.maxSize * 2;
            char* nuevoArray = new char[nuevomaxsize];
            for (int i = 0; i < lista.listSize; i++) {
                nuevoArray[i] = lista.listArray[i];
            }
            delete[] lista.listArray;
            lista.listArray = nuevoArray;
            lista.maxSize = nuevomaxsize;
            lista.listArray[lista.listSize++] = c;
        }
    }
    char borrarCaracter (tListaCaracteres &lista, int pos) {
        if (pos < 0 || pos >= lista.listSize) {
            return '\0';
        }
        char Charporeliminar = lista.listArray[pos];
        for (int i = pos; i < lista.listSize - 1; i++) {
            lista.listArray[i] = lista.listArray[i + 1];
        }
        lista.listSize--;
        if(lista.curr > lista.listSize) {
            lista.curr = lista.listSize;
        }
        if(lista.curr > pos) {
            lista.curr--;
        }
        return Charporeliminar;
    }
    void concatenarTexto (tListaCaracteres &lista, const char* texto,int len) {
        int largotexto = strlen(texto);
        if (len > lista.maxSize - lista.listSize) {
            int nuevomaxsize = lista.maxSize + len;
            char* nuevoArray = new char[nuevomaxsize];
            for (int i = 0; i < lista.listSize; i++) {
                nuevoArray[i] = lista.listArray[i];
            }
            delete[] lista.listArray;
            lista.listArray = nuevoArray;
            lista.maxSize = nuevomaxsize;
        }
        if (lista.listSize + largotexto <= lista.maxSize) {
            for (int i = 0; i < largotexto; i++) {
                lista.listArray[lista.listSize++] = texto[i];
            }
        }
    }
    void LiberarLista (tListaCaracteres &lista) {
        delete[] lista.listArray;
        lista.listArray = nullptr;
        lista.listSize = 0;
        lista.curr = 0;
    }
};