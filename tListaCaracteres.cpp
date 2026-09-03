#include <stdlib.h>
#include <stdio.h>
#include "tListaCaracteres.h"

class caracteres {
public:
    char* listArray;
    int listSize;
    int maxSize;
    int curr;
private:
    void duplicar(){
        maxSize *= 2;
        char* newArray = new char[maxSize]; 
    }