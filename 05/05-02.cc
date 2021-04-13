// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>

void MyDisplay() {
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POLYGON);
  glVertex3f(-0.5, -0.5, 0.0);
  glVertex3f(0.5, -0.5, 0.0);
  glVertex3f(0.5, 0.5, 0.0);
  glVertex3f(-0.5, 0.5, 0.0);
  glEnd();

  glFlush();
}

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutCreateWindow("OpenGL Drawing Example");

  glutDisplayFunc(MyDisplay);

  glutMainLoop();
}
