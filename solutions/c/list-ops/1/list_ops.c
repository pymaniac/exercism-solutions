#include "list_ops.h"

#include <string.h>
#include <stdio.h>

// constructs a new list
list_t *new_list(size_t length, list_element_t elements[]) {
    list_t *ll = calloc(1, sizeof(*ll) + length * sizeof(ll->elements[0]));
    if(ll) {
        ll->length = length;
        if (length && elements)
            memcpy(ll->elements, elements, length * sizeof(ll->elements[0]));
    }
    return ll;
}

// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2) {
    list_t *al = new_list(list1->length + list2->length, list1->elements);
    if (!al) return al;
    if (al->length)
        memcpy(al->elements + list1->length, list2->elements, list2->length * sizeof(list2->elements[0]));
    return al;
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {    
    int cnt = 0;
    for(int i = 0; i < (int)list->length; i++) {
        if (filter(list->elements[i])) cnt++;
    }
    list_t *fl = new_list(cnt, NULL);

    cnt = 0;
    for(size_t i = 0; i < list->length; i++) {
        if (filter(list->elements[i])) fl->elements[cnt++] = list->elements[i];
    }

    return fl;
}

// returns the length of the list
size_t length_list(list_t *list) { return list->length; }

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
    list_t *ml = new_list(list->length, list->elements);
    if (!ml) return ml;
    for(size_t i = 0; i < list->length; i++) {
        ml->elements[i] = map(list->elements[i]);
    }
    return ml;
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
    for(size_t i = 0; i < list->length; i++) {
        initial = foldl(initial, list->elements[i]);
    }

    return initial;
}

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {
    int i = (int)list->length-1;
    if (i < 0) return initial;
    int sv = list->elements[i];
    for(--i; i >= 0; i--) {
        sv = foldr(sv, list->elements[i]);
        printf("%d %d: \n", list->elements[i], initial);
    }

    return foldr(initial, sv);
}

// reverse the elements of the list
list_t *reverse_list(list_t *list) {
    list_t *rl = new_list(list->length, list->elements);
    
    int l = 0, r = (int)rl->length-1;
    while(l < r) {
        list_element_t tmp = rl->elements[l];
        rl->elements[l] = rl->elements[r];
        rl->elements[r] = tmp;
        ++l;
        --r;
    }

    return rl;
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list) {
    free(list);
}