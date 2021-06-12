// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>

float r = 0;

void MyDisplay() {
  glClear(GL_COLOR_BUFFER_BIT);
  glViewport(0, 0, 600, 600);
  glColor3f(1.0, 0.0, 0.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(-0.15, -0.15, 0.0);
  glRotatef(r, 0.0, 0.0, 1.0);
  glTranslatef(0.15, 0.15, 0.0);
  glutSolidCube(0.3);

  glFlush();
}

void MyIdle() {
  r += 3;
  glutPostRedisplay();
}

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("OpenGL Sample Drawing");

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

  glutDisplayFunc(MyDisplay);
  glutIdleFunc(MyIdle);

  glutMainLoop();
}
