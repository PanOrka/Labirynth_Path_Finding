#include <stdio.h>

#include "labirynth.h"
#include "djikstra/djikstra.h"

int main() {
    labirynth *lab = take_stdin();
    char type[20];
    scanf("%s", type);

    printf("INPUT:\n");
    print_labirynth(lab);

    djikstra_path_finder(lab);
    free_labirynth(lab);
}
