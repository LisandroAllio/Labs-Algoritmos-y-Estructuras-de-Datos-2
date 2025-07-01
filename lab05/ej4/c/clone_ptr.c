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
    char *original="";
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
No he podido encontrar el problema el programa ahce exactamente lo mismo que antes solo que imprime " " en original.
*/