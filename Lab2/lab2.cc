// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>

GLfloat angle = 0.0;
bool ascending = true;

const GLfloat delta_angle = 1.0;
const GLfloat vertical = 5.0;
const GLfloat horizontal = 10.0;
const GLfloat thickness = 0.2;
const GLfloat scale = 0.05;

void MyDisplay() {
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();
  gluLookAt(0.5, 0.5, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glScalef(scale, scale, scale);
  glTranslatef(0.0, vertical / 2, 0.0);
  {
    // Vertical
    glPushMatrix();
    glScalef(1.0, vertical, 1.0);
    glColor3f(0.3, 0.3, 0.3);
    glutWireCube(1.0);
    glPopMatrix();
  }
  {
    // Right
    glPushMatrix();
    glTranslatef(0.0, (vertical - 1.0) / 2, 0.5 + (thickness / 2));
    {
      glPushMatrix();
      glRotatef(angle, 0.0, 0.0, 1.0);
      {
        // Horizontal 1
        glPushMatrix();
        glTranslatef((horizontal - 1.0) / 2, 0.0, 0.0);
        glScalef(horizontal, 0.5, thickness);
        glColor3f(1.0, 0.3, 0.3);
        glutWireCube(1.0);
        glPopMatrix();
      }

      // Horizontal 2
      glTranslatef(horizontal - 1.0, 0.0, -thickness);
      glRotatef(-angle, 0.0, 0.0, 1.0);
      glTranslatef((horizontal - 1.0) / 2, 0.0, 0.0);
      glScalef(horizontal, 0.5, thickness);
      glColor3f(1.0, 0.3, 0.3);
      glutWireCube(1.0);
      glPopMatrix();
    }
    glPopMatrix();
  }
  {
    // Left
    glPushMatrix();
    glTranslatef(0.0, (vertical - 1.0) / 2, -(0.5 + (thickness / 2)));
    {
      glPushMatrix();
      glRotatef(270 + angle, 0.0, 0.0, 1.0);
      {
        // Horizontal 1
        glPushMatrix();
        glTranslatef(-(horizontal - 1.0) / 2, 0.0, 0.0);
        glScalef(horizontal, 0.5, thickness);
        glColor3f(1.0, 0.3, 0.3);
        glutWireCube(1.0);
        glPopMatrix();
      }

      // Horizontal 2
      glTranslatef(-(horizontal - 1.0), 0.0, thickness);
      glRotatef(90 - angle, 0.0, 0.0, 1.0);
      glTranslatef(-(horizontal - 1.0) / 2, 0.0, 0.0);
      glScalef(horizontal, 0.5, thickness);
      glColor3f(1.0, 0.3, 0.3);
      glutWireCube(1.0);
      glPopMatrix();
    }
    glPopMatrix();
  }

  glutSwapBuffers();
}

void MyIdle() {
  if (ascending)
    angle += delta_angle;
  else
    angle -= delta_angle;

  if (angle >= 90.0)
    ascending = false;
  else if (angle <= 0.0)
    ascending = true;

  glutPostRedisplay();
}

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("OpenGL Sample Drawing");

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -100.0, 100.0);

  glutDisplayFunc(MyDisplay);
  glutIdleFunc(MyIdle);

  glutMainLoop();
}
