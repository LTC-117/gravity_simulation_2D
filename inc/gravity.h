#ifndef GRAVITY_H_
#define GRAVITY_H_

#include "SDL2/SDL.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    double x;
    double y;
    double v_x;
    double v_y;
    double mass;
    double radius;
    double g_force;
} cel_body;


cel_body define_planet(double radius, double vel_x, double vel_y, double x_pos, double y_pos);
void update_planet_pos(cel_body *p1, cel_body *p2, double delta_t);
void fill_planet(SDL_Surface *surface, cel_body planet, Uint32 color);



#endif
