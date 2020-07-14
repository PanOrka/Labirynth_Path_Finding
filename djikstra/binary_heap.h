#ifndef BINARY_HEAP
#define BINARY_HEAP

#include "../labirynth.h"

/*
// Binary heap structure
*/
typedef struct {
    //flatten
    int *array;
    //flatten
    int *prev;
    //flatten
    int *dist;
    //flatten
    int *heap_place;

    int used_size;
    int max_size;
} binary_heap;

/*
// Creating binary heap from labirynth
*/
binary_heap * create_bh(labirynth *lab);

/*
// Pop lowest
*/
int pop_bh(binary_heap *bh);

/*
// Free heap
*/
void free_bh(binary_heap *bh);

/*
// Change priority of node in heap_place
*/
void change_dist_bh(binary_heap *bh, int heap_place);

#endif
