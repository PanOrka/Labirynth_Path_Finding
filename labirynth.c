#include <stdlib.h>
#include <stdio.h>

#include "labirynth.h"

labirynth * take_stdin() {
    labirynth *lab = malloc(sizeof(labirynth));

    scanf("%d %d", (int *)lab + 2, (int *)lab + 3);

    lab->shape = malloc(sizeof(char *)*lab->height);
    lab->non_wall_tiles = 0;

    for (int i=0; i<lab->height; i++) {
        lab->shape[i] = malloc(sizeof(char)*lab->width);
        for (int k=0; k<lab->width; k++) {
            scanf(" %c", lab->shape[i] + k);
            if (lab->shape[i][k] == 'S') {
                lab->start_pos = i*(lab->width) + k;
                lab->non_wall_tiles++;
            } else if (lab->shape[i][k] != '1') {
                lab->non_wall_tiles++;
            }
        }
    }

    return lab;
}

void print_labirynth(labirynth *lab) {
    for (int i=0; i<lab->height; i++) {
        for (int k=0; k<lab->height; k++) {
            if (lab->shape[i][k] == 'T') {
                printf("\u2588");
            } else {
                printf("%c", lab->shape[i][k]);
            }
        }
        printf("\n");
    }
}

void free_labirynth(labirynth *lab) {
    for (int i=0; i<lab->height; i++) {
        free(lab->shape[i]);
    }
    free(lab->shape);
    free(lab);
}
