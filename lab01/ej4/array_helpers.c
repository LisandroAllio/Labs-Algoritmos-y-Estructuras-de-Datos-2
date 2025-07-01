#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {

    int aux;
    int scanfiles = 0; //guarda el resultado de retunr fscanf

    FILE *fp;
    fp = fopen(filepath, "r");

    fscanf(fp, "%u", &max_size); //escaneamos el primer valor del filepath, que es el largo

    //recorro el arreglo segun el largo dado en el archivo
    for(unsigned int i = 0; i < max_size; i++) {
        
        scanfiles = fscanf(fp, "%d", &aux); //guardo en aux el valor que aputa el puntero del archivo

        if (scanfiles == 1) { //si la var almacenada es distinta de 1; ocurrio un error en  la lectura.
            array[i] = aux;       
        } else {
            exit(EXIT_FAILURE);         
        } 
        
    }
    fclose(fp);
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

bool array_is_sorted(int a[], unsigned int length) {
    bool is_sorted = true;
    int i = 0;
    while (i < length-1 && is_sorted){
        is_sorted = is_sorted && a[i] <= a[i+1];
    }
    return is_sorted;

    /*Es una forma mas eficiente que:
    for (unsigned int i = 0; i < length-1; i++) {
        res = res && a[i] <= a[i+1];
    }
    return res;
    */
}