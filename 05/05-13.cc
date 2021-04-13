// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>

GLfloat MyVertices[8][3] = {
    {-0.25, -0.25, 0.25},   // 0
    {-0.25, 0.25, 0.25},    // 1
    {0.25, 0.25, 0.25},     // 2
    {0.25, -0.25, 0.25},    // 3
    {-0.25, -0.25, -0.25},  // 4
    {-0.25, 0.25, -0.25},   // 5
    {0.25, 0.25, -0.25},    // 6
    {0.25, -0.25, -0.25}    // 7
};

GLfloat MyColors[8][3] = {
    {0.2, 0.2, 0.2},  // 0
    {1.0, 0.0, 0.0},  // 1
    {1.0, 1.0, 0.0},  // 2
    {0.0, 1.0, 0.0},  // 3
    {0.0, 0.0, 1.0},  // 4
    {1.0, 0.0, 1.0},  // 5
    {1.0, 1.0, 1.0},  // 6
    {0.0, 1.0, 1.0}   // 7
};

GLubyte MyVertexList[24] = {
    0, 3, 2, 1,  // 0
    2, 3, 7, 6,  // 1
    0, 4, 7, 3,  // 2
    1, 2, 6, 5,  // 3
    4, 5, 6, 7,  // 4
    0, 1, 5, 4   // 5
};

void MyDisplay() {
  glClear(GL_COLOR_BUFFER_BIT);
  glFrontFace(GL_CCW);
  glEnable(GL_CULL_FACE);
  glEnableClientState(GL_COLOR_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  glColorPointer(3, GL_FLOAT, 0, MyColors);
  glVertexPointer(3, GL_FLOAT, 0, MyVertices);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glRotatef(30.0, 1.0, 1.0, 1.0);
  for (GLint i = 0; i < 6; i++)
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4 * i]);

  glFlush();
}

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(300, 300);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("OpenGL Drawing Example");

  glClearColor(0.5, 0.5, 0.5, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

  glutDisplayFunc(MyDisplay);

  glutMainLoop();
}
