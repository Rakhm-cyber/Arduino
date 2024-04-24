#ifndef GCODE_H
#define GCODE_H

#include <stdio.h>
#include <string.h>

#define LMAX 100
#define gcodeFile "gcode.txt"
typedef struct {
    char commands[LMAX][LMAX];
    int commandsCount;
} Gcode;

Gcode* gcode_create();
void gcode_destroy(Gcode *gcode);

#endif
