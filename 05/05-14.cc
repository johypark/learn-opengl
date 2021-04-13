// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>

int my_list_id;

void MyCreateList() {
  my_list_id = glGenLists(1);

  glNewList(my_list_id, GL_COMPILE);
  glBegin(GL_POLYGON);
  glColor3f(0.5, 0.5, 0.5);
  glVertex3f(-0.5, -0.5, 0.0);
  glVertex3f(0.5, -0.5, 0.0);
  glVertex3f(0.5, 0.5, 0.0);
  glVertex3f(-0.5, 0.5, 0.0);
  glEnd();
  glEndList();
}

void MyDisplay() {
  glClear(GL_COLOR_BUFFER_BIT);
  glViewport(0, 0, 300, 300);

  glCallList(my_list_id);

  glFlush();
}

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(300, 300);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("OpenGL Drawing Example");

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

  glutDisplayFunc(MyDisplay);
  MyCreateList();

  glutMainLoop();
}
