// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>
#include <math.h>

float gTime = 0;

void DrawObject(float angle) {
  glPushMatrix();

  glPushMatrix();
  glRotatef(angle, 0, 1, 0);
  glutWireTeapot(1.0);
  // Stick
  glPushMatrix();
  glScalef(4, 0.2, 0.2);
  glTranslatef(0.5, 0, 0);
  glutWireCube(1.0);
  glPopMatrix();
  // Ball
  glPushMatrix();
  glTranslatef(4, 0, 0);
  glRotatef(gTime * 5, 1, 0, 0);
  glutWireSphere(0.4, 20, 20);
  // Stick
  glPushMatrix();
  glScalef(0.1, 2, 0.1);
  glTranslatef(0.0, 0.5, 0.0);
  glutWireCube(1.0);
  glPopMatrix();
  // Ball
  glTranslatef(0, 2, 0);
  glutWireSphere(0.1, 20, 20);
  glPopMatrix();
  glPopMatrix();

  glTranslatef(0, -1, 0);
  glScalef(3, 0.2, 3);
  glutWireCube(1.0);

  glPopMatrix();
}

void MyDisplay() {
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0.3, 0.3, 0.7);
  DrawObject(0);

  glPushMatrix();
  glColor3f(0.7, 0.3, 0.2);
  // float x = 2.0 * cos(gTime * 0.05);
  // float z = 2.0 * sin(gTime * 0.05);
  // glTranslatef(x, 0, z);
  glRotatef(gTime, 0, 0, 1);
  glTranslatef(2, 0, 0);
  glScalef(0.3, 0.3, 0.3);
  DrawObject(gTime);
  glPopMatrix();

  glFlush();
}

void MyReshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(30, (GLdouble)w / (GLdouble)h, 1.0, 50.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glutPostRedisplay();
}

void MyTimer(int x) {
  gTime += 1.0;

  glutTimerFunc(20, MyTimer, 0);

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
  glutTimerFunc(20, MyTimer, 0);
  glutMainLoop();
}
