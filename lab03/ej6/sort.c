/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    bool b = ((*x).rank <= (*y).rank);
    return b;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

/**
 * @brief Changes the position of an element in a array with its previuos ones
 * @details It use a funciont goes_bebore to compare the element with its previus.
 *          if the return is true exchange the position of the elements.
 * 
 * @param[in]      a     Players array
 * @param[in]      i     Index of an element 
 */
void insert(player_t a[], unsigned int i) {
    unsigned int j = i;
    while (j>0 && goes_before(a[j],a[j-1])){ 
        swap(a, j-1, j);
        j--;
    }
}

void sort(player_t a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
}

