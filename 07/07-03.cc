// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>

void MyDisplay() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.3, 0.3, 0.7);
  glBegin(GL_TRIANGLES);
  glVertex3f(0, 1, 0);
  glVertex3f(1, 0, 0);
  glVertex3f(-1, 0, 0);
  glEnd();
  glFlush();
}

void MyReshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(30, (GLdouble)w / (GLdouble)h, 1.0, 50.0);
  // glOrtho(-1, 1, -1, 1, 1.0, 10);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glutPostRedisplay();
}

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("OpenGL Sample Drawing");
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glutDisplayFunc(MyDisplay);
  glutReshapeFunc(MyReshape);
  glutMainLoop();
}
