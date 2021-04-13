// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>

GLboolean is_sphere = true;
GLboolean is_small = true;

void MyDisplay() {
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0.5, 0.0, 0.5);
  if (is_sphere) {
    if (is_small)
      glutWireSphere(0.2, 15, 15);
    else
      glutWireSphere(0.4, 15, 15);
  } else {
    if (is_small)
      glutWireTorus(0.1, 0.3, 40, 20);
    else
      glutWireTorus(0.2, 0.5, 40, 20);
  }

  glFlush();
}

void MyMainMenu(int entry_id) {
  switch (entry_id) {
    case 1:
      is_sphere = true;
      break;
    case 2:
      is_sphere = false;
      break;
    case 3:
      exit(0);
  }

  glutPostRedisplay();
}

void MySubMenu(int entry_id) {
  switch (entry_id) {
    case 1:
      is_small = true;
      break;
    case 2:
      is_small = false;
      break;
  }

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
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

  GLint my_sub_menu_id = glutCreateMenu(MySubMenu);
  glutAddMenuEntry("Small One", 1);
  glutAddMenuEntry("Big One", 2);

  GLint my_main_menu_id = glutCreateMenu(MyMainMenu);
  glutAddMenuEntry("Draw Sphere", 1);
  glutAddMenuEntry("Draw Torus", 2);
  glutAddSubMenu("Change Size", my_sub_menu_id);
  glutAddMenuEntry("Exit", 3);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  glutDisplayFunc(MyDisplay);

  glutMainLoop();
}
