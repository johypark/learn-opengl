// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>
#include <math.h>

float angle = 0;

void MyIdle() {
  angle += 1.0f;
  glutPostRedisplay();
}

void MyLightInit() {
  GLfloat global_ambient[] = {0.3, 0.3, 0.3, 1.0};

  GLfloat light0_ambient[] = {0.5, 0.4, 0.3, 1.0};
  GLfloat light0_diffuse[] = {0.5, 0.4, 0.3, 1.0};
  GLfloat light0_specular[] = {1.0, 1.0, 1.0, 1.0};

  GLfloat light1_ambient[] = {0.0, 0.0, 0.0, 1.0};
  GLfloat light1_diffuse[] = {0.5, 0.2, 0.3, 1.0};
  GLfloat light1_specular[] = {0.0, 0.0, 0.0, 1.0};

  GLfloat material_ambient[] = {0.3, 0.3, 0.3, 1.0};
  GLfloat material_diffuse[] = {0.8, 0.8, 0.8, 1.0};
  GLfloat material_specular[] = {0.0, 0.0, 1.0, 1.0};
  GLfloat material_shininess[] = {25.0};

  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);

  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);

  glEnable(GL_LIGHT1);
  glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
  glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);

  glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
  glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
  glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);

  // glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
  // glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
}

void MyDisplay() {
  GLfloat LightPosition0[] = {0.0, 0.0, 2.0, 1.0};
  GLfloat LightPosition1[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat LightDirection1[] = {-0.5, -1.0, -1.0};
  GLfloat SpotAngle1[] = {20.0};
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(sin(angle * 0.01), 1.5, 1.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  glLightfv(GL_LIGHT0, GL_POSITION, LightPosition0);
  glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);
  glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection1);
  glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, SpotAngle1);

  glPushMatrix();
  glRotatef(angle, 0, 1, 0);

  glutSolidTorus(0.3, 0.6, 100, 100);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0.6, -0.5, 0.6);
  glutSolidTeapot(0.2);
  glTranslatef(-0.6, -0.4, -0.6);
  glScalef(2, 0.1, 2);
  glutSolidCube(0.8);
  glPopMatrix();
  glutSwapBuffers();
}

void MyReshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -10.0, 10.0);
}

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(0, 0);
  // glClearColor(0.0, 0.0, 0.0, 0.0);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutCreateWindow("openGL Sample Drawing");
  MyLightInit();
  glutIdleFunc(MyIdle);
  glutDisplayFunc(MyDisplay);
  glutReshapeFunc(MyReshape);

  glutMainLoop();
}
