#include "gcode.h"

Gcode* gcode_create() {
    FILE *file = fopen(gcodeFile, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    Gcode* gcode = malloc(sizeof(gcode));
    if (gcode == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    gcode->commandsCount = 0;

    while (fgets(gcode->commands[gcode->commandsCount], LMAX, file)) {
        gcode->commandsCount++;
    }

    fclose(file);

    return gcode;
}

void gcode_destroy(Gcode *gcode) {
    free(gcode);
}
