#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    if (x > 0) {
        *y = x;
    } else {
        *y = -x;
    }
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    a = -10;
    absolute(a, &res);
    printf("Valor abolute de la variable res: %d\n", res);

    return EXIT_SUCCESS;
}

/*Supongo que es de tipo out ya que esta no esta siendo modificada, sino el valor se modifica el al que esta apunta*/

/*COMPLETAR*/