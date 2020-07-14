#include <stdlib.h>

#include "binary_heap.h"

#define inflate_h(i, w) (i/w)
#define inflate_w(i, w) (i%w)

#define flatten(i, k, w) (i*w + k)
#define left(i) (2*i + 1)
#define right(i) (2*i + 2)
#define parent(i) ((i-1)/2)

binary_heap * create_bh(labirynth *lab) {
    binary_heap *bh = malloc(sizeof(binary_heap));
    bh->max_size = lab->non_wall_tiles;
    bh->array = malloc(sizeof(int)*(bh->max_size));
    bh->used_size = 0;

    bh->dist = malloc(sizeof(int)*(lab->height * lab->width));
    bh->heap_place = malloc(sizeof(int)*(lab->height * lab->width));

    bh->array[0] = lab->start_pos;
    bh->heap_place[lab->start_pos] = 0;
    bh->used_size++;

    bh->prev = malloc(sizeof(int)*(lab->height * (lab)->width));

    for (int i=0; i<lab->height; i++) {
        for (int k=0; k<lab->width; k++) {
            if (lab->shape[i][k] != '1' && flatten(i, k, lab->width) != lab->start_pos) {
                bh->array[bh->used_size] = flatten(i, k, lab->width);
                bh->heap_place[flatten(i, k, lab->width)] = bh->used_size;

                bh->dist[flatten(i, k, lab->width)] = __INT32_MAX__;
                bh->used_size++;
            } else {
                bh->dist[flatten(i, k, lab->width)] = -1;
            }
        }
    }
    *(bh->dist + (lab)->start_pos) = 0;

    return bh;
}

int pop_bh(binary_heap *bh) {
    int ret_val = bh->array[0];

    int i = 0;
    bh->used_size--;
    bh->array[0] = bh->array[bh->used_size];
    // heap_place swap
    bh->heap_place[bh->array[0]] = 0;
    while (left(i) < bh->used_size) {
        int k;
        if (right(i) < bh->used_size) {
            if (bh->dist[bh->array[left(i)]] >= bh->dist[bh->array[right(i)]]) {
                k = right(i);
            } else {
                k = left(i);
            }
        } else {
            k = left(i);
        }

        if (bh->dist[bh->array[i]] > bh->dist[bh->array[k]]) {
            int temp = bh->array[i];
            bh->array[i] = bh->array[k];
            bh->array[k] = temp;

            // heap_place swap
            bh->heap_place[temp] = k;
            bh->heap_place[bh->array[i]] = i;

            i = k;
        } else {
            return ret_val;
        }
    }

    return ret_val;
}

void free_bh(binary_heap *bh) {
    free(bh->array);
    free(bh->dist);
    free(bh->prev);
    free(bh->heap_place);

    free(bh);
}

void change_dist_bh(binary_heap *bh, int heap_place) {
    while (heap_place > 0) {
        if (bh->dist[bh->array[parent(heap_place)]] > bh->dist[bh->array[heap_place]]) {
            int temp = bh->array[parent(heap_place)];
            bh->array[parent(heap_place)] = bh->array[heap_place];
            bh->array[heap_place] = temp;

            // heap_place swap
            bh->heap_place[temp] = heap_place;
            bh->heap_place[parent(heap_place)] = parent(heap_place);

            heap_place = parent(heap_place);
        } else {
            break;
        }
    }
}
