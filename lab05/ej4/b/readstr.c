#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

int main(void) {
    char user_input[MAX_LENGTH];

    printf("Ingrese su nombre y apellido: ");
    //scanf("%s", user_input); 
    /*Esta intrunccion tiene dos problemas potenciales:
    1. Con el especificador de formato "%s" para leer una cadena, la función lee caracteres hasta encontrar un espacio, un intro, un tabulador, etc.
    Por lo tanto solo va a tomar la primera palabra de una cadena.
    2.scanf() y gets() no tienen un buffer overflow protection. Es decir, no tiene en cuenta la longitud de lo leído. Como resultado, si scanf recibe una cadena 
    cuya cantidad de caracteres es mayor a la permitida en el array definido previamente, escribirá los caracteres que ya no quepan en otras porciones de memoria 
    que pueden contener otros datos que está usando nuestro programa.
    */

    fgets(user_input, MAX_LENGTH, stdin); //Lee la line especificada por el file stream stdin (Es decir lo que le pasemos por teclado), y lo guarda en user_input
    
    //---Eliminemos lel caracter '\n'---
    unsigned int i = 0;
    while (i < strlen(user_input)-1){            
        i++;  
    } //Avanzo en el arreglo str hasta *str == '\n'. 
    user_input[i] = '\0'; 
    
    printf("Te damos la bienvenida %s a este maravilloso programa!\n", user_input);

    return EXIT_SUCCESS;
}

