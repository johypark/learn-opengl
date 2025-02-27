// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>

void MyDisplay() {
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POLYGON);
  glColor3f(0.5, 0.5, 0.5);
  glVertex3f(-0.5, -0.5, 0.0);
  glVertex3f(0.5, -0.5, 0.0);
  glVertex3f(0.5, 0.5, 0.0);
  glVertex3f(-0.5, 0.5, 0.0);
  glEnd();

  glFlush();
}

void MyReshape(int NewWidth, int NewHeight) {
  glViewport(0, 0, NewWidth, NewHeight);

  GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)300;
  GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)300;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor,
          1.0 * HeightFactor, -1.0, 1.0);
}

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(300, 300);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("OpenGL Example Drawing");

  glClearColor(1.0, 1.0, 1.0, 1.0);

  glutDisplayFunc(MyDisplay);
  glutReshapeFunc(MyReshape);

  glutMainLoop();
}
