#include "gravity.h"
#include <math.h>
#include <stdlib.h>


const double G_CONST = (6.67430e-2);
const double PI = 3.1415926;


cel_body define_planet(double radius, double vel_x, double vel_y, double x_pos, double y_pos) {
    srand(time(NULL));

    cel_body planet = {
        .x = x_pos,
        .y = y_pos,
        .v_x = vel_x,
        .v_y = vel_y,
        .radius = radius,
        .mass = (double)((4.0 / 3.0) * PI * (pow(radius, 3)))
    };

    return planet;
}


void update_planet_pos(cel_body *p1, cel_body *p2, double delta_t) {
    // distâncias x e y servem apenas para contextualização vetorial
    double dist_x = p1->x - p2->x;
    double dist_y = p1->y - p2->y;
    double dist = sqrt(pow(dist_x, 2) + pow(dist_y, 2)); 

    // meramente expositivo
    printf("X: %lf  |  Y: %lf\n", dist_x, dist_y);

    double force = (G_CONST * p1->mass * p2->mass) / (dist * dist);

    double force_x = force * (dist_x / dist);
    double force_y = force * (dist_y / dist);

    // negativa pois é de atração
    double accel_x = -force_x / p1->mass;
    double accel_y = -force_y / p1->mass;

    p1->v_x += (accel_x * delta_t);
    p1->v_y += (accel_y * delta_t);

    p1->x += p1->v_x * delta_t;
    p1->y += p1->v_y * delta_t;
}


void fill_planet(SDL_Surface *surface, cel_body planet, Uint32 color){
    double low_x = planet.x - planet.radius;
    double low_y = planet.y - planet.radius;
    double high_x = planet.x + planet.radius;
    double high_y = planet.y + planet.radius;

    double radius_squared = planet.radius * planet.radius;

    for(double x=low_x; x < high_x; x++){
        for(double y=low_y; y < high_y; y++){
            //Is coordinate within planet?
            double center_distance = (x-planet.x)*(x-planet.x) + (y-planet.y)*(y-planet.y);
            if(center_distance < radius_squared){
                SDL_Rect pixel = (SDL_Rect) {x,y,1,1};
                SDL_FillRect(surface, &pixel, color);
            }
        }
    }
}


