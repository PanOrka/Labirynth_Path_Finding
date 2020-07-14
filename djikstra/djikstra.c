#include "djikstra.h"
#include "binary_heap.h"

#include <stdio.h>

#define inflate_h(i, w) (i/w)
#define inflate_w(i, w) (i%w)
#define flatten(i, k, w) (i*w + k)

#define up(i, w) (i - w)
#define left(i) (i-1)
#define right(i) (i+1)
#define down(i, w) (i + w)

void draw_path(labirynth *lab, binary_heap *bh, int exit_pos);

void djikstra_path_finder(labirynth *lab) {
    binary_heap *bh = create_bh(lab);
    int w = lab->width;
    int pos;

    /*
    // Djikstra
    // Path finding algorithm
    */
    while (bh->used_size > 0) {
        pos = pop_bh(bh);

        if (lab->shape[inflate_h(pos, w)][inflate_w(pos, w)] == 'E') {
            break;
        }

        if (bh->dist[pos] + 1 < bh->dist[right(pos)]) {
            bh->dist[right(pos)] = bh->dist[pos] + 1;
            bh->prev[right(pos)] = pos;
            change_dist_bh(bh, bh->heap_place[right(pos)]);
        }
        if (bh->dist[pos] + 1 < bh->dist[left(pos)]) {
            bh->dist[left(pos)] = bh->dist[pos] + 1;
            bh->prev[left(pos)] = pos;
            change_dist_bh(bh, bh->heap_place[left(pos)]);
        }
        if (bh->dist[pos] + 1 < bh->dist[up(pos, w)]) {
            bh->dist[up(pos, w)] = bh->dist[pos] + 1;
            bh->prev[up(pos, w)] = pos;
            change_dist_bh(bh, bh->heap_place[up(pos, w)]);
        }
        if (bh->dist[pos] + 1 < bh->dist[down(pos, w)]) {
            bh->dist[down(pos, w)] = bh->dist[pos] + 1;
            bh->prev[down(pos, w)] = pos;
            change_dist_bh(bh, bh->heap_place[down(pos, w)]);
        }
    }

    draw_path(lab, bh, pos);
    free_bh(bh);
}

void draw_path(labirynth *lab, binary_heap *bh, int exit_pos) {
    int prev = bh->prev[exit_pos];
    while (prev != lab->start_pos) {
        lab->shape[inflate_h(prev, lab->width)][inflate_w(prev, lab->width)] = 'T';
        prev = bh->prev[prev];
    }
    printf("\nOUTPUT:\n");
    print_labirynth(lab);
}
