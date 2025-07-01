#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *string_clone(const char *str, size_t length) {
    char *clone = calloc(length, sizeof(char));

    char *output=clone;
    for (size_t i=0; i<length; i++) {
        clone[i] = str[i];
    }
    clone[length] = '\0';
    return output;
}


int main(void) {
    char *original=""
         "______ time ago in a galaxy far, far away...\n\n\n"
         "         _______..___________.     ___      .______             \n"
         "        /       ||           |    /   \\     |   _  \\          \n"
         "       |   (----``---|  |----`   /  ^  \\    |  |_)  |          \n"
         "        \\   \\        |  |       /  /_\\  \\   |      /        \n"
         "    .----)   |       |  |      /  _____  \\  |  |\\  \\----.    \n"
         "    |_______/        |__|     /__/     \\__\\ | _| `._____|     \n"
         "                                                                \n"
         "____    __    ____      ___      .______           _______.     \n"
         "\\   \\  /  \\  /   /     /   \\     |   _  \\         /       |\n"
         " \\   \\/    \\/   /     /  ^  \\    |  |_)  |       |   (----` \n"
         "  \\            /     /  /_\\  \\   |      /         \\   \\    \n"
         "   \\    /\\    /     /  _____  \\  |  |\\  \\----..----)   |   \n"
         "    \\__/  \\__/     /__/     \\__\\ | _| `._____||_______/     \n"
         "\n\n\n"
         "                     Episode IV \n\n"
         "                     A NEW HOPE \n\n"
         "                     It is a period of civil war. Rebel\n"
         "spaceships, striking from a hidden base, have won their\n"
         "first victory against the evil Galactic Empire. During the\n"
         "battle, Rebel spies managed to steal secret plans to the\n"
         "Empire’s ultimate weapon, the DEATH STAR, an armored space\n"
         "station with enough power to destroy an entire planet.\n"
         "Pursued by the Empire’s sinister agents, Princess Leia\n"
         "races home aboard her starship, custodian of the stolen\n"
         "plans that can save her people and restore freedom to the\n"
         "galaxy...\n";
    char *copy=NULL;

    copy = string_clone(original, strlen(original));
    printf("Original: %s\n", original);
    copy[0] = 'A';
    copy[1] = ' ';
    copy[2] = 'l';
    copy[3] = 'o';
    copy[4] = 'n';
    copy[5] = 'g';
    printf("Copia   : %s\n", copy);

    free(copy); //Liberamos la memoria reservada en string_clone
    return EXIT_SUCCESS;
}

/*
Problema 1:
En la implementacion de string_clone(), el puntero al output apunta al arreglo 
de caracteres clone. Perp dicho arreglo esta almacenado en la memoria dianmica, 
por lo tanto al salir de la funcion con return output, clone se elimina automaticamente 
y output queda sin apuntar a ninguna cadena.


Problema 2:
EL parametro length toma el valor 7,porque: 
    sizeof(original) == 8, yaque se trata de una dirreccion de memoria.
    sizeof(char) == 1
    Luego 8 - 1 = 7
Esto provoca que la copia no tenga el tamaño correcto po lo que no copia toda la cadena. 
Cambiandolo por strlen(original) pasamos como argumento el largo de la cadena orignal sin 
incluir el caracter '\0'
*/

