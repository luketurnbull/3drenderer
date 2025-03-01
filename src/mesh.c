#ifndef MESH_C
#define MESH_C

#include "mesh.h"
#include <_stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    FILE *meshFile = fopen(filename, "r");
    if (meshFile == NULL) {
        printf("❌ Error opening file: %s\n", filename);
        return;
    }

    char *line = NULL; 
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, meshFile)) != -1) {
        if (strncmp(line, "v ", 2) == 0) {
            // Parse vertex (v x y z)
            float x, y, z;
            if (sscanf(line, "v %f %f %f", &x, &y, &z) == 3) {
                vec3_t vertex = {x, y, z};
                array_push(mesh.vertices, vertex);
            }
        }
        else if (strncmp(line, "f ", 2) == 0) {
            // Parse face (f v1/vt1/vn1 v2/vt2/vn2 v3/vt3/vn3)
            int vertex_indices[3];
            int matches = sscanf(line, "f %d/%*d/%*d %d/%*d/%*d %d/%*d/%*d", 
                               &vertex_indices[0], 
                               &vertex_indices[1], 
                               &vertex_indices[2]);
            
            if (matches == 3) {
                // OBJ files use 1-based indexing, convert to 0-based;;;
                face_t face = {
                    .a = vertex_indices[0],
                    .b = vertex_indices[1],
                    .c = vertex_indices[2]
                };
                array_push(mesh.faces, face);
            }
        }
    }

    free(line);
    fclose(meshFile);
}

#endif