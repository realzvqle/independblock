#include "cube.h"


void draw_cube(float size, vector3 pos, vector3 rotation, bool isLines) {
    glPushMatrix();  

    glTranslatef(pos.x, pos.y, pos.z);
    glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(rotation.y, 0.0f, 1.0f, 0.0f); 
    glRotatef(rotation.z, 0.0f, 0.0f, 1.0f); 

    float half = size / 2.0f;
    isLines ? glBegin(GL_LINES) : glBegin(GL_QUADS);

    
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex3f(-half, -half,  half);
    glVertex3f( half, -half,  half);
    glVertex3f( half,  half,  half);
    glVertex3f(-half,  half,  half);

    glColor3f(0.0f, 1.0f, 0.0f); 
    glVertex3f(-half, -half, -half);
    glVertex3f( half, -half, -half);
    glVertex3f( half,  half, -half);
    glVertex3f(-half,  half, -half);

    glColor3f(0.0f, 0.0f, 1.0f); 
    glVertex3f(-half,  half, -half);
    glVertex3f( half,  half, -half);
    glVertex3f( half,  half,  half);
    glVertex3f(-half,  half,  half);

    glColor3f(1.0f, 1.0f, 0.0f); 
    glVertex3f(-half, -half, -half);
    glVertex3f( half, -half, -half);
    glVertex3f( half, -half,  half);
    glVertex3f(-half, -half,  half);

    glColor3f(1.0f, 0.0f, 1.0f); 
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