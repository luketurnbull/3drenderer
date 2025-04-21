#include "vector.h"
#include <math.h>


// Implementations of Vector 2D functions
float vec2_length(vec2_t v) {
   return sqrt(v.x * v.x + v.y * v.y);
}

vec2_t vec2_add(vec2_t a, vec2_t b) {
   vec2_t v = {
      .x = a.x + b.x,
      .y = a.y + b.y
   };

   return v;
}

vec2_t vec2_subtract(vec2_t a, vec2_t b) {
   vec2_t v = {
      .x = a.x - b.y,
      .y = b.x - b.y
   };

   return v;
}

vec2_t vec2_multiply(vec2_t v, float factor) {
   vec2_t result = {
      .x = v.x * factor,
      .y = v.y * factor
   };

   return result;
}

vec2_t vec2_divide(vec2_t v, float factor) {
   vec2_t result = {
      .x = v.x / factor,
      .y = v.y / factor
   };

   return result;
}

float vec2_dot(vec2_t a, vec2_t b) {
   return (a.x * b.x) + (a.y * b.y);
}

void vec2_normalize(vec2_t* v) {
   float length = sqrt(v->x * v->x + v->y * v->y);
   v->x /= length;
   v->y /= length;
}



// Implementations of Vectors 3D functions
float vec3_length(vec3_t v) {
   return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

vec3_t vec3_add(vec3_t a, vec3_t b) {
   vec3_t v = {
      .x = a.x + b.x,
      .y = a.y + b.y,
      .z = a.z + b.z
   };
   
   return v;
}

vec3_t vec3_subtract(vec3_t a, vec3_t b) {
   vec3_t v = {
      .x = a.x - b.x,
      .y = a.y - b.y,
      .z = a.z - b.z
   };
   
   return v;
}

vec3_t vec3_multiply(vec3_t v, float factor) {
   vec3_t result = {
      .x = v.x * factor,
      .y = v.y * factor,
      .z = v.z * factor
   };

   return result;
}

vec3_t vec3_divide(vec3_t v, float factor) {
   vec3_t result = {
      .x = v.x / factor,
      .y = v.y / factor,
      .z = v.z / factor
   };

   return result;
}

vec3_t vec3_cross(vec3_t a, vec3_t b){
   vec3_t result = {
      .x = a.y * b.z - a.z * b.y,
      .y = a.z * b.x - a.x * b.z,
      .z = a.x * b.y - a.y * b.x
   };

   return result;
}

float vec3_dot(vec3_t a, vec3_t b) {
   return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

void vec3_normalize(vec3_t* v) {
   float length = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
   v->x /= length;
   v->y /= length;
   v->z /= length;
}



vec3_t vec3_rotate_x(vec3_t v, float angle) {
   vec3_t rotated_vector = {
      .x = v.x,
      .y = v.y * cos(angle) - v.z * sin(angle),
      .z = v.y * sin(angle) + v.z * cos(angle)
   };
   return rotated_vector;
}

vec3_t vec3_rotate_y(vec3_t v, float angle) {
   vec3_t rotated_vector = {
      .x = v.x  * cos(angle) - v.z * sin(angle),
      .y = v.y,
      .z = v.x * sin(angle) + v.z * cos(angle)
   };
   return rotated_vector;
}

vec3_t vec3_rotate_z(vec3_t v, float angle) {
   vec3_t rotated_vector = {
      .x = v.x * sin(angle) + v.y * cos(angle),
      .y = v.x * cos(angle) - v.y * sin(angle),
      .z = v.z
   };
   return rotated_vector;
}
