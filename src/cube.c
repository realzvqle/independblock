#include "cube.h"


void draw_cube(float size, vector3 pos, vector3 rotation) {
    glPushMatrix();  // Save the current matrix state

    // Apply transformations
    glTranslatef(pos.x, pos.y, pos.z);
    glRotatef(rotation.x, 1.0f, 0.0f, 0.0f); // Rotate around x-axis
    glRotatef(rotation.y, 0.0f, 1.0f, 0.0f); // Rotate around y-axis
    glRotatef(rotation.z, 0.0f, 0.0f, 1.0f); // Rotate around z-axis

    float half = size / 2.0f;
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f(-half, -half,  half);
    glVertex3f( half, -half,  half);
    glVertex3f( half,  half,  half);
    glVertex3f(-half,  half,  half);

    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f(-half, -half, -half);
    glVertex3f( half, -half, -half);
    glVertex3f( half,  half, -half);
    glVertex3f(-half,  half, -half);

    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f(-half,  half, -half);
    glVertex3f( half,  half, -half);
    glVertex3f( half,  half,  half);
    glVertex3f(-half,  half,  half);

    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex3f(-half, -half, -half);
    glVertex3f( half, -half, -half);
    glVertex3f( half, -half,  half);
    glVertex3f(-half, -half,  half);

    glColor3f(1.0f, 0.0f, 1.0f); // Magenta
    glVertex3f( half, -half, -half);
    glVertex3f( half,  half, -half);
    glVertex3f( half,  half,  half);
    glVertex3f( half, -half,  half);

    glColor3f(0.0f, 1.0f, 1.0f); 
    glVertex3f(-half, -half, -half);
    glVertex3f(-half,  half, -half);
    glVertex3f(-half,  half,  half);
    glVertex3f(-half, -half,  half);

    glEnd();
}