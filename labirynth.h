#ifndef LABIRYNTH
#define LABIRYNTH

/*
// Structure of labirynth
*/
typedef struct {
    /*
    // shape is [H][W]
    */
    char **shape;

    int width, height;
    // flatten
    int start_pos;
    int non_wall_tiles;
} labirynth;

/*
// Take stdin for labirynth
*/
labirynth * take_stdin();

/*
// Print labirynth
*/
void print_labirynth(labirynth *lab);

/*
// Free labirynth
*/
void free_labirynth(labirynth *lab);

#endif
