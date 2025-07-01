#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}

static bool invrep(abb tree) {
    static bool inv = true;
    if (tree != NULL){
        inv = inv && invrep(tree->left);
        if (tree->left != NULL) {
            inv = elem_less(tree->left->elem, tree->elem);
        }
        inv = inv && invrep(tree->right); 
        if (tree->right != NULL) {
            inv = !elem_less(tree->right->elem, tree->elem);
        } 
    } 
    return inv;
}

abb abb_empty(void) {
    abb tree = NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    if (tree == NULL) {
        tree = malloc(sizeof(struct _s_abb));
        tree->elem = e;
        tree->left = NULL;
        tree->right = NULL;
    } else {
        if (elem_eq(e, tree->elem)) {//Si elem_eq(e, tree->elem). Entonces no hace nada 
            return tree;
        } else if (elem_less(e, tree->elem)) {
            tree->left = abb_add(tree->left, e);
        } else { 
            tree->right = abb_add(tree->right, e);;
        }
    } 
    
    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    bool is_empty=false;
    assert(invrep(tree));
    is_empty = (tree == NULL);
    return is_empty;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists=false;
    assert(invrep(tree));
    if (tree != NULL){
        if (elem_eq(e, tree->elem)) {
            exists = true;
        } else if (elem_less(e,tree->elem)) {
            exists = exists || abb_exists(tree->left, e);
        } else { 
            exists = exists || abb_exists(tree->right, e); 
        }
    } 
    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    if (tree != NULL) {
        length += 1;
        length += abb_length(tree->left);
        length += abb_length(tree->right);
    }
    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    // base case
    if (tree == NULL) {
        return tree;
    }
    if (elem_less(e, tree->elem)) {
        tree->left = abb_remove(tree->left, e);
    } else if (elem_less(tree->elem, e)) {
        tree->right = abb_remove(tree->right, e);
    }
 
    // if elem is same as tree's elem,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (tree->left == NULL) {
            abb temp = tree->right;
            free(tree);
            return temp;
        }
        else if (tree->right == NULL) {
            abb temp = tree->left;
            free(tree);
            return temp;
        }
 
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        abb_elem min = abb_min(tree->right);
 
        // Copy the inorder
        // successor's content to this node
        tree->elem = min;
 
        // Delete the inorder successor
        tree->right = abb_remove(tree->right, min);
    }
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}

abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    root = tree->elem;
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    if (tree->right == NULL) {
        max_e = tree->elem;
    } else {
        max_e = abb_max(tree->right);
    }
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
     if (tree->left == NULL) {
        min_e = tree->elem;
    } else {
        min_e = abb_min(tree->left);
    }

    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        printf("%d ", tree->elem);
        abb_dump(tree->left);
        abb_dump(tree->right);
    }
}

/*
-abb_dump orignial mostraba los elementos del arbol en orden, ya que 
recorria siempre primero la rama izquierda antes que la derecha.  
-El arbol generado por el contenido mostrado por abb_dump (original) era un arbol 
con todos elementos en la rama derecha, ya qeue era en orden creciente. 
*/

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        abb_destroy(tree->left);
        abb_destroy(tree->right);
        free(tree);
    }
    tree = NULL;
    assert(tree == NULL);
    return tree;
}

