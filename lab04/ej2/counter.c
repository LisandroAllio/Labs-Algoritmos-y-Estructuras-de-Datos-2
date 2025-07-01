#include <stdbool.h>
#include <stdlib.h>

#include "counter.h"
#include <assert.h>

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c = malloc(sizeof(struct _counter));
    c->count = 0;
    assert(counter_is_init(c));
    return c;
}

void counter_inc(counter c) {
    c->count = c->count + 1;
}

bool counter_is_init(counter c) {
    bool b = (c->count == 0);
    return b;
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c->count = c->count - 1;
}

counter counter_copy(counter c) {
    counter c_copy = malloc(sizeof(struct _counter));
    c_copy->count = c->count;
    return c_copy;
}

void counter_destroy(counter c) {
    free(c);
}
