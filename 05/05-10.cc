// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>

GLfloat delta = 0.0;

void MyDisplay() {
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POLYGON);
  glColor3f(0.0, 0.5, 0.8);
  glVertex3f(-1.0 + delta, -0.5, 0.0);
  glVertex3f(0.0 + delta, -0.5, 0.0);
  glVertex3f(0.0 + delta, 0.5, 0.0);
  glVertex3f(-1.0 + delta, 0.5, 0.0);
  glEnd();

  glutSwapBuffers();
}

void MyIdle() {
  delta += 0.001;

  glutPostRedisplay();
}

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(300, 300);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("OpenGL Drawing Example");

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

  glutDisplayFunc(MyDisplay);
  glutIdleFunc(MyIdle);

  glutMainLoop();
}
