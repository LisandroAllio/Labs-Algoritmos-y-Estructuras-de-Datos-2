#include <assert.h>
#include "pair.h"

pair_t pair_new(int x, int y){
    pair_t new_p;
    new_p.fst = x;
    new_p.snd = y;
    return new_p;
}
   
/*PRE: {p --> (x, y)}*/
int pair_first(pair_t p) {
    int first = p.fst;
    assert(p.fst == first);
    return first;
}

/*PRE: {p --> (x, y)}*/
int pair_second(pair_t p){
    int second = p.snd;
    assert(p.snd == second);
    return second;
}
/*PRE: {p --> (x, y)}*/
pair_t pair_swapped(pair_t p){
    pair_t swapped_p;
    swapped_p.fst = p.snd;
    swapped_p.snd = p.fst;
    assert(swapped_p.fst == p.snd && swapped_p.snd == p.fst);
    return swapped_p;
}

pair_t pair_destroy(pair_t p){
    p.fst = 0;
    p.snd = 0;
    return p;
}
