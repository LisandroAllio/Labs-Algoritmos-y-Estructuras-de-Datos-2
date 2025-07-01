#include <assert.h>
#include <stdlib.h>
#include "dict.h"
#include "key_value.h"


struct _node_t {
    dict_t left;
    dict_t right;
    key_t key;
    value_t value;
};

static bool invrep(dict_t d) {
    bool inv = true;
    if (d != NULL){
        inv = inv && invrep(d->left);
        if (d->left != NULL) {
            inv = key_less(d->left->key, d->key);
        }
        inv = inv && invrep(d->right); 
        if (d->right != NULL) {
            inv = !key_less(d->right->key, d->key);
        } 
    } 
    return inv;
}

dict_t dict_empty(void) {
    dict_t dict = NULL;
    assert(invrep(dict) && dict_length(dict) == 0);
    return dict;
} 

dict_t dict_add(dict_t dict, key_t word, value_t def) {
    assert(invrep(dict) && word != NULL && def != NULL);
    if (dict == NULL ) { 
        dict = malloc(sizeof(struct _node_t));
        dict->key = word;
        dict->value = def;
        dict->left = NULL;
        dict->right = NULL;
    } else {
        if (key_eq(word, dict->key)) {//En caso que word ya existe, se actualiza su definición con def. 
            dict->value = def;
        } else if (key_less(word, dict->key)) {
            dict->left = dict_add(dict->left, word, def);
        } else { 
            dict->right = dict_add(dict->right, word, def);
        }
    } 
    assert(invrep(dict) && key_eq(def, dict_search(dict, word)));
    return dict;
}

value_t dict_search(dict_t dict, key_t word) {
    assert(invrep(dict) && word != NULL);
    value_t def=NULL;
    if (dict !=NULL) {
        if(key_eq(dict->key,word)){
            def = dict->value;
        } else if (key_less(word, dict->key)) {
            def = dict_search(dict->left, word);
        } else {
            def = dict_search(dict->right, word);
        } 
    }
    assert((def != NULL) == dict_exists(dict, word));
    return def;
}

bool dict_exists(dict_t dict, key_t word) {
    assert(invrep(dict) && word != NULL);
    bool exist = false;
    if (dict != NULL) {
        if(key_eq(dict->key,word)){
            exist = true;
        } else if (key_less(word, dict->key)) {
            exist = dict_exists(dict->left, word);
        } else {
            exist = dict_exists(dict->right, word);
        } 
    }
    assert(invrep(dict));
    return exist;
}

unsigned int dict_length(dict_t dict) {
    assert(invrep(dict));
    unsigned int length=0;
    if (dict!=NULL){
        length++;
        length += dict_length(dict->left);
        length += dict_length(dict->right);
    }
    return length;
}

key_t dict_max(dict_t d) {
    key_t max_d;
    assert(invrep(d));
    while(d->right!=NULL){
        d = d->right;
    }
    max_d = d->key;
    return max_d;
}

dict_t dict_remove(dict_t dict, key_t word) {
     assert(invrep(dict));
    if(dict != NULL){
        if(key_eq(dict->key,word)){
            if ((dict->left == NULL) && (dict->right == NULL)){
                free(dict);
                dict=NULL;
            }else if(dict->left == NULL && dict->right != NULL){
                dict=dict->right;

            }else if(dict->left != NULL && dict->right == NULL){
                dict = dict->left;
     
            }else{
                dict->key=dict_max(dict->left);
                dict->left=dict_remove(dict->left,dict_max(dict->left));
            }
            
        }else if(key_less(word,dict->key)){
            dict->left=dict_remove(dict->left,word);
        } else {
            dict->right=dict_remove(dict->right,word);
        }
    }
    assert(invrep(dict) && !dict_exists(dict, word));
    return dict;
}

dict_t dict_remove_all(dict_t dict) {
    assert(invrep(dict));
    if (dict != NULL){
        dict->key = key_destroy(dict->key);
        dict->value = value_destroy(dict->value);
        dict->left = dict_remove_all(dict->left);
        dict->right = dict_remove_all(dict->right);
        free (dict);
        dict = NULL;
    }
    assert(invrep(dict) && dict_length(dict) == 0);
    return dict;
}

void dict_dump(dict_t dict, FILE *file) {
    assert(invrep(dict) && file != NULL);
    if (dict != NULL) {
        dict_dump(dict->left,file);
        key_dump(dict->key,file);
        fprintf(file,":");
        value_dump(dict->value,file);
        fprintf(file,"\n");
        dict_dump(dict->right,file);
    }
}

dict_t dict_destroy(dict_t dict) {
    assert(invrep(dict));
    if (dict != NULL){
        dict_destroy(dict->left);
        dict_destroy (dict->right);
        dict_remove_all(dict);
        dict = NULL;
    }
    assert(dict == NULL);
    return dict;
}

