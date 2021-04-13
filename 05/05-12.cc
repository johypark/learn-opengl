// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>

unsigned char PALETTE[16][3] = {
    {255, 255, 255},  // WHITE
    {0, 255, 255},    // CYAN
    {255, 0, 255},    // PURPLE
    {0, 0, 255},      // BLUE
    {192, 192, 192},  // LIGHT GRAY
    {128, 128, 128},  // DARK GRAY
    {0, 128, 128},    // DARK TEAL
    {128, 0, 128},    // DARK PURPLE
    {0, 0, 128},      // DARK BLUE
    {255, 255, 0},    // YELLOW
    {0, 255, 0},      // GREEN
    {128, 128, 0},    // DARK YELLOW
    {0, 128, 0},      // DARK GREEN
    {255, 0, 0},      // RED
    {128, 0, 0},      // DARK RED
    {0, 0, 0},        // BLACK
};

GLfloat delta = 0.0;
GLint index = 0;
GLfloat red = 0.0;
GLfloat green = 0.0;
GLfloat blue = 0.0;

void MyDisplay() {
  red = PALETTE[index][0] / 255.0f;
  green = PALETTE[index][1] / 255.0f;
  blue = PALETTE[index][2] / 255.0f;

  glBegin(GL_LINES);
  glColor3f(red, green, blue);
  glVertex3f(-1.0 + delta, 1.0, 0.0);
  glVertex3f(1.0 - delta, -1.0, 0.0);
  glVertex3f(-1.0, -1.0 + delta, 0.0);
  glVertex3f(1.0, 1.0 - delta, 0.0);
  glEnd();

  glutSwapBuffers();
}

void MyTimer(int value) {
  if (delta < 2.0f) {
    delta += 0.01;
  } else {
    delta = 0.0;
    ++index %= 16;
    glClear(GL_COLOR_BUFFER_BIT);
  }

  glutPostRedisplay();
  glutTimerFunc(10, MyTimer, 1);
}

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("OpenGL Timer Animation Sample");

  glClearColor(0.0, 0.0, 0.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

  glutDisplayFunc(MyDisplay);
  glutTimerFunc(10, MyTimer, 1);

  glutMainLoop();
}
