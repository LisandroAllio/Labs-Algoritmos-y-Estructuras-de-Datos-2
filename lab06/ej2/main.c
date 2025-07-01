#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

#define MAX_LENGTH 20

int main(void) {
    char input[MAX_LENGTH];
    string str1 = NULL;
    string str2 = NULL;

    printf("Ingrese el contenido de string 1: ");
    fgets(input, MAX_LENGTH, stdin);
    //---Eliminemos lel caracter '\n'---
    unsigned int i = 0;
    while (i < strlen(input)-1){            
        i++;  
    } //Avanzo en el arreglo str hasta *str == '\n'. 
    input[i] = '\0'; 

    str1 = string_create(input);

    printf("Ingrese el  contenido de string 2: ");
    fgets(input, MAX_LENGTH, stdin); 
    //---Eliminemos lel caracter '\n'---
    i = 0;
    while (i < strlen(input)-1){            
        i++;  
    } //Avanzo en el arreglo str hasta *str == '\n'. 
    input[i] = '\0'; 

    str2 = string_create(input);
    
    //usamod string_eq()
    string_eq(str1, str2) ? printf("Los string son iguales\n") : printf("Los string NO son iguales\n");

    //usamod string_less()
    string_less(str1, str2) ? printf("String 1 es mayor\n") : printf("String 2 es mayor\n");
    return EXIT_SUCCESS;
}
