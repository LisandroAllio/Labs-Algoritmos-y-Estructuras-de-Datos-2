/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

unsigned int array_from_stdin(int array[], unsigned int max_size) { 

    unsigned int lenght = 0;
    int scanfiles = 0; //guarda el resultado de return scanf

    printf("Ingrese el tamaño del arreglo: ");
    scanf("%u", &lenght); //escaneamos el tamaño
    
    //assert(lenght > max_size); -->chequea que el tamaño no sea mayor al permitido
    if (lenght > max_size) { 
            print("Error: Tamaño del arreglo mayor al permitido \n");
            exit(EXIT_FAILURE);         
        } 

    //recorro el arreglo segun el tamaño dado
    for(unsigned int i = 0; i < max_size; i++) {
        printf("Ingrese el Elemento Nº %d: ", i);
        scanfiles = scanf("%d", &array[i]); //guardo en array[i] el valor que ingresa el usuario

        if (scanfiles < 1) { //Ocurrio un error al leer el input stdio
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
    }
    return max_size;
}

void array_dump(int a[], unsigned int length) {
    if (length != 0u) {
    } 
        printf("CONTENIDO DE ARCHIVO: \n[");
    for (unsigned int i = 0u; i < length; i++) {
        printf(" %d", a[i]);
    }   
    printf("]\n");
} 


int main() {
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_stdin(array, MAX_SIZE);
    
    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
