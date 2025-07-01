#include <assert.h>
#include <stdlib.h>
#include "pair.h"

pair_t pair_new(int x, int y){
    pair_t new_p = malloc(sizeof(struct s_pair_t)); // tambien sirve usar malloc(sizeof(struct s_pair_t));
    new_p->fst = x;
    new_p->snd = y;
    return new_p;
}

/*PRE: {p --> (x, y)}*/
int pair_first(pair_t p) {
    int first = p->fst;
    assert(p->fst == first);
    return first;
}

/*PRE: {p --> (x, y)}*/
int pair_second(pair_t p){
    int second = p->snd;
    assert(p->snd == second);
    return second;
}
/*PRE: {p --> (x, y)}*/
pair_t pair_swapped(pair_t p){
    pair_t swapped_p = malloc(sizeof(struct s_pair_t));;
    swapped_p->fst = p->snd;
    swapped_p->snd = p->fst;
    assert(swapped_p->fst == p->snd && swapped_p->snd == p->fst);
    return swapped_p;
}

pair_t pair_destroy(pair_t p){
    if (p != NULL) {
        free(p);
    }
    return p;
}
