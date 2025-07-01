#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x > 0) {
        y = x;
    } else {
        y = -x;
    }
    /*Si coloco aqui el print si funciona como es esperado
    printf("Valor abolute de la variable res: %d\n", y); */
}

int main(void) {
    int a=0, res=0;
    a = -10;
    absolute(a, res);
    printf("Valor abolute de la variable res: %d\n", res);
    return EXIT_SUCCESS;
}

/*EL valor mostrado es 0. No concide con el teorico ya que al terminar la funcion absolute no devuelve nada. 
Y cuando sus var x, y son temporales. 
Por lo que los cmabios en ellas no afectaran al resto del programa y res no cambiara*/

