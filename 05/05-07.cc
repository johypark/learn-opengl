// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>

GLint top_left_x, top_left_y, bottom_right_x, bottom_right_y;

void MyDisplay() {
  glViewport(0, 0, 300, 300);
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0.5, 0.5, 0.5);
  glBegin(GL_POLYGON);
  glVertex3f(top_left_x / 300.0, (300 - top_left_y) / 300.0, 0.0);
  glVertex3f(top_left_x / 300.0, (300 - bottom_right_y) / 300.0, 0.0);
  glVertex3f(bottom_right_x / 300.0, (300 - bottom_right_y) / 300.0, 0.0);
  glVertex3f(bottom_right_x / 300.0, (300 - top_left_y) / 300.0, 0.0);
  glEnd();

  glFlush();
}

void MyMouseClick(GLint button, GLint state, GLint x, GLint y) {
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    top_left_x = x;
    top_left_y = y;
  }
}

void MyMouseMove(GLint x, GLint y) {
  bottom_right_x = x;
  bottom_right_y = y;

  glutPostRedisplay();
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
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

  glutDisplayFunc(MyDisplay);
  glutMouseFunc(MyMouseClick);
  glutMotionFunc(MyMouseMove);

  glutMainLoop();
}
