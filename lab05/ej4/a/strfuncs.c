#include <stdio.h>
#include <stdlib.h>
#include "strfuncs.h"

size_t string_length(const char *str){
    unsigned int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

char *string_filter(const char *str, char c) {
    char *str_filter = NULL;
    str_filter = malloc(sizeof(str));
    unsigned int i = 0;
    while (*str != '\0'){          //Itera hasta llegar al final de la cadena str
        if (*str != c) {
            str_filter[i]  = *str ;   
            i++;
        }
        str++;  //Avanzo en el arreglo str. Ahora (*str) == str[i+1]
    }
    return str_filter;
}


/*
---Otra forma usando un puntero auxiliar en vez de un indice i para recorrer la cadena:---

char *string_filter(const char *str, char c) {
    char *str_filter = NULL;
    str_filter = calloc(string_length(str), sizeof(char));
    char *aux = str_filter;

    while (*str != '\0'){
        if (*str != c) {
            *aux = *str;
            aux++;
        }
        str++;
    }
    return str_filter;
}
*/

