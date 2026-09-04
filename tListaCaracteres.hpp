#ifndef TLISTACARACTERES_HPP
#define TLISTACARACTERES_HPP

#include <cstring>

struct tListaCaracteres {
    char* listArray;
    int listSize;
    int maxSize;
    int curr;
};
void inicializarLista (tListaCaracteres &lista, int capacidadinicial);
void insertarCaracter (tListaCaracteres &lista, char c, int pos);
char borrarCaracter (tListaCaracteres &lista, int pos);
void concatenarTexto (tListaCaracteres &lista, const char* texto, int len);
void LiberarLista (tListaCaracteres &lista);

#endif 