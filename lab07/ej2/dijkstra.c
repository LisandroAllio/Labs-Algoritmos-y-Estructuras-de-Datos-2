#include <assert.h>
#include <stdlib.h>
#include <limits.h>

#include "cost.h"
#include "graph.h"
#include "mini_set.h"

unsigned int minimun(set vertexs, cost_t *costs, unsigned int max_vertecs){
    cost_t min = INT_MAX;
    unsigned int ret;
    for (unsigned int i = 0; i < max_vertecs; ++i) {
        if (costs[i] < min && set_member(i, vertexs)){
            min = costs[i];
            ret = i;
        }
    }
    return ret;
}

cost_t *dijkstra(graph_t graph, vertex_t init) {
    unsigned int c;
    set vertexs = set_empty(); 
    unsigned int n = graph_max_vertexs(graph);
    cost_t *costs = calloc(n, sizeof(cost_t));

    cost_t suma;

    for (unsigned int i = 0; i < n; ++i) {
        vertexs = set_add(vertexs, i); 
    }
    vertexs = set_elim(vertexs, init);

    for (unsigned int j = 0; j < n; ++j){
        costs[j] = graph_get_cost(graph, init, j);
    }

    while (!set_is_empty(vertexs)) {
        c = minimun(vertexs, costs, n);
        vertexs = set_elim(vertexs, c);
        
        for (unsigned int j = 0; j < n; ++j ) {
            if (set_member(j, vertexs)){
                suma = cost_sum(costs[c], graph_get_cost(graph, c, j));
                
                if (cost_le(suma, costs[j])){
                    costs[j] = suma;
                }
            }
        } 
    }
    return costs;
}



