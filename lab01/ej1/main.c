/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {

    unsigned int lenght = 0;
    int scanfiles = 0; //guarda el resultado de retunr fscanf
    FILE *fp;

    fp = fopen(filepath, "r");

    //assert(fp != NULL); --> Chequea que el archivo pueda abrirse
    if (fp == NULL) { 
            print("Error: No se pudo abrir el archivo \n");
            exit(EXIT_FAILURE);         
        } 
    
    scanfiles = fscanf(fp, "%u", &lenght); //escaneamos el primer valor del filepath, que es el largo

    if (scanfiles != 1) { //si la var almacenada es distinta de 1; ocurrio un error en  la lectura.
            print("Error en lectura del largo del arreglo \n");
            exit(EXIT_FAILURE);         
        } 
    
    //assert(lenght > max_size); -->chequea que el tamaño no sea mayor al permitido
    if (lenght > max_size) { 
            print("Error: Tamaño del arreglo mayor al permitido \n");
            exit(EXIT_FAILURE);         
        } 

    //recorro el arreglo segun el largo dado en el archivo
    for(unsigned int i = 0; i < max_size; i++) {
        
        scanfiles = fscanf(fp, "%d", &array[i] ); //guardo en array[i] el valor que aputa el puntero del archivo
        
        if (scanfiles != 1) { //si la var almacenada es distinta de 1; ocurrio un error en  la lectura.
            print("Error en lectura de elemento a[%d] del arreglo \n");
            exit(EXIT_FAILURE);         
        } 
    }
    fclose(fp);
    return lenght;
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


int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);
    
    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
