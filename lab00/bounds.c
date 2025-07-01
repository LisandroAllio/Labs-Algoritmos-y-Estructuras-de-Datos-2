#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    res.is_upperbound = true; //Para todo -> valo inicial true ya que es una disyuncion universal
    res.is_lowerbound = true;
    res.exists = false; //existencial -> valo incial false ya que es una disyuncion universal

    for (unsigned int i= 0u; i <(length); i++){
        res.is_upperbound = res.is_upperbound && value >= arr[i];
        res.is_lowerbound = res.is_lowerbound && value <= arr[i];
        if (value == arr[i]) {
            res.exists = true;
            res.where = i;
        }
        /* for (i=0; i !=(length); i++){
        if (value == arr[i]) {
            res.exists = true;
            res.where = i;}
        else if (value > arr[i]){
            res.is_upperbound = res.is_upperbound && true;
            res.is_lowerbound = false;}
        else { 
            res.is_lowerbound = res.is_lowerbound && true;
            res.is_upperbound = false;} */
  
    }
    return res;
}

void llenar_arreglo(int a[]);

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;

    llenar_arreglo(a);
    printf("Ingrese un valor: ");
    scanf("%d", &value);
    
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);


    if (result.exists) {
        if (result.is_upperbound) {
            printf("Su valor es Maximo\n");
        }
        if (result.is_lowerbound) {
            printf("Su valor es Minimo\n");
        }
        printf("El elemento se encunetra en el indice: %d\n", result.where);
    }
    else {
        if (result.is_upperbound) {
            printf("Su valor es Cota superior\n");
        }
        if (result.is_lowerbound) {
            printf("Su valor es Cota inferior\n");
        }
        printf("El elemento No se encuentra");


    }


    /* if (result.is_upperbound == true) {
        printf("Su valor es cota superior\n");
        if (result.exists == true){
            printf("Su valor es Maximo y su posicion es: %d\n", result.where);
        }
    } 
    else if (result.is_lowerbound == true) {
        printf("Su valor es cota inferior\n");
        if (result.exists == true){
            printf("SU valor es Minimo y su posicion es: %d\n", result.where);
        }
    } */


    return EXIT_SUCCESS;
}

void llenar_arreglo(int a[]) {
    int i;
    for (i=0; i !=(ARRAY_SIZE); i++){
        printf("Ingrese el valor %d en el arreglo: ", i);
        scanf("%d", &a[i]);}
    
}