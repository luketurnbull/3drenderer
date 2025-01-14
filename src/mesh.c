#ifndef MESH_C
#define MESH_C

#include "mesh.h"
#include <stdio.h>
#include "array.h"
#include "vector.h"

mesh_t mesh = {
   .vertices = NULL,
   .faces = NULL,
   .rotation = { 0, 0, 0 }
};

vec3_t cube_vertices[N_CUBE_VERTICES] = {
   { .x = -1, .y = -1, .z = -1 }, // 1
   { .x = -1, .y = 1, .z = -1 }, // 2
   { .x = 1, .y = 1, .z = -1 }, // 3
   { .x = 1, .y = -1, .z = -1 }, // 4
   { .x = 1, .y = 1, .z = 1 }, // 5
   { .x = 1, .y = -1, .z = 1 }, // 6
   { .x = -1, .y = 1, .z = 1 }, // 7
   { .x = -1, .y = -1, .z = 1 }, // 8
};

face_t cube_faces[N_CUBE_FACES] = {
   // front
   { .a = 1, .b = 2, .c = 3 },
   { .a = 1, .b = 3, .c = 4 },

   // right
   { .a = 4, .b = 3, .c = 5 },
   { .a = 4, .b = 5, .c = 6 },

   // back
   { .a = 6, .b = 5, .c = 7 },
   { .a = 6, .b = 7, .c = 8 },

   // left
   { .a = 8, .b = 7, .c = 2 },
   { .a = 8, .b = 2, .c = 1 },

   // top
   { .a = 2, .b = 7, .c = 5 },
   { .a = 2, .b = 5, .c = 3 },

   // bottom
   { .a = 6, .b = 8, .c = 1 },
   { .a = 6, .b = 1, .c = 4 }
};

void load_cube_mesh_data(void) {
   for (int i = 0; i < N_CUBE_VERTICES; i++) {
      vec3_t cube_vertex = cube_vertices[i];
      array_push(mesh.vertices, cube_vertex);
   }
   for (int i = 0; i < N_CUBE_FACES; i++) {
      face_t cube_face = cube_faces[i];
      array_push(mesh.faces, cube_face);
   }
}

void load_obj_file_data(char* filename) {
   // TODO: Read the contents of the .obj filename
   // and load the vertices and faces in 
   // our mesh.vertices and mesh.faces


   // Read file data

   // Parse OBJ, and loop through all lines

   // Find vertices and add them to mesh.vertices
   // Does it start with "v"?


   // Find faces and add them to mesh.faces
   // Does is start with "f"?
   // "f 1/1/1 2/2/2 3/3/1"
   // This face indexes will be 1, 2 and 3
}

#endif