// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

GLint x[3];
GLint y[3];

GLint x_1, y_1, x_2, y_2, x_3, y_3, count = 0;
GLboolean is_triangle = false;

GLfloat red = 0.0;
GLfloat green = 0.0;
GLfloat blue = 0.0;

// 여기에 vec3, mat3 클래스를 작성합니다.
class vec3 {
 public:
  float m[3];
  vec3() {
    for (size_t i = 0; i < 3; i++) m[i] = 0;
  }

  vec3(float a0, float a1, float a2) {
    m[0] = a0;
    m[1] = a1;
    m[2] = a2;
  }

  vec3 operator-(vec3 a) {
    vec3 result;

    for (size_t i = 0; i < 3; i++) result.m[i] = m[i] - a.m[i];

    return result;
  }

  void Print() {
    printf("\n");
    for (size_t i = 0; i < 3; i++) printf("%.4f ", m[i]);
    printf("\n");
  }

  float Length() { return sqrtf(pow(m[0], 2) + pow(m[1], 2) + pow(m[2], 2)); }

  void Normalize() {
    float length = Length();

    for (size_t i = 0; i < 3; i++) m[i] /= length;
  }

  vec3 CrossProduct(vec3 a) {
    vec3 result;

    result.m[0] = m[1] * a.m[2] - m[2] * a.m[1];
    result.m[1] = m[2] * a.m[0] - m[0] * a.m[2];
    result.m[2] = m[0] * a.m[1] - m[1] * a.m[0];

    return result;
  }
};

class mat3 {
 public:
  float m[3][3];
  mat3() {
    for (size_t i = 0; i < 3; i++)
      for (size_t j = 0; j < 3; j++) m[i][j] = 0;
  }

  mat3(float a0, float a1, float a2, float a3, float a4, float a5, float a6,
       float a7, float a8) {
    m[0][0] = a0;
    m[0][1] = a1;
    m[0][2] = a2;
    m[1][0] = a3;
    m[1][1] = a4;
    m[1][2] = a5;
    m[2][0] = a6;
    m[2][1] = a7;
    m[2][2] = a8;
  }

  mat3 operator+(mat3 a) {
    mat3 result;

    for (size_t i = 0; i < 3; i++)
      for (size_t j = 0; j < 3; j++) result.m[i][j] = m[i][j] + a.m[i][j];

    return result;
  }

  mat3 operator*(mat3 a) {
    mat3 result;

    for (size_t i = 0; i < 3; i++)
      for (size_t j = 0; j < 3; j++)
        for (size_t k = 0; k < 3; k++) result.m[i][j] += m[i][k] * a.m[k][j];

    return result;
  }

  vec3 operator*(vec3 a) {
    vec3 result;

    for (size_t i = 0; i < 3; i++)
      for (size_t j = 0; j < 3; j++) result.m[i] += m[i][j] * a.m[i];

    return result;
  }

  void Print() {
    printf("\n");
    for (size_t i = 0; i < 3; i++) {
      for (size_t j = 0; j < 3; j++) printf("%.4f ", m[i][j]);
      printf("\n");
    }
  }

  mat3 Transpose() {
    mat3 result;

    for (size_t i = 0; i < 3; i++)
      for (size_t j = 0; j < 3; j++) result.m[i][j] = m[j][i];

    return result;
  }
};

void MyDisplay() {
  glViewport(0, 0, 600, 600);

  if (is_triangle) {
    if (count == 3) {
      glBegin(GL_TRIANGLES);
      glColor3f(red, green, blue);
      glVertex3f(x[0] / 600.0, (600 - y[0]) / 600.0, 0.0);
      glVertex3f(x[1] / 600.0, (600 - y[1]) / 600.0, 0.0);
      glVertex3f(x[2] / 600.0, (600 - y[2]) / 600.0, 0.0);
      glEnd();

      count = 0;
      is_triangle = false;
    }
  } else {
    glBegin(GL_LINES);
    glColor3f(red, green, blue);
    glVertex3f(x[0] / 600.0, (600 - y[0]) / 600.0, 0.0);
    glVertex3f(x[1] / 600.0, (600 - y[1]) / 600.0, 0.0);
    glEnd();

    x[0] = x[1];
    y[0] = y[1];
  }

  glFlush();
}

void MyMouseClick(GLint button, GLint state, GLint new_x, GLint new_y) {
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    if (is_triangle) {
      x[count] = new_x;
      y[count] = new_y;
      if (++count == 3) glutPostRedisplay();
    } else {
      x[0] = new_x;
      y[0] = new_y;
    }
  }
}

void MyMouseMove(GLint new_x, GLint new_y) {
  x[1] = new_x;
  y[1] = new_y;

  glutPostRedisplay();
}

void MyKeyboard(unsigned char key_pressed, int x, int y) {
  switch (key_pressed) {
    case 'r':
    case 'R':
      red = 1;
      green = 0;
      blue = 0;
      break;
    case 'g':
    case 'G':
      red = 0;
      green = 1;
      blue = 0;
      break;
    case 'b':
    case 'B':
      red = 0;
      green = 0;
      blue = 1;
      break;
    case 'c':
    case 'C':
      red = 0;
      green = 0;
      blue = 0;
      glClear(GL_COLOR_BUFFER_BIT);
      glutPostRedisplay();
      break;
    case 't':
    case 'T':
      is_triangle = true;
      break;
  }
}

// 여기에 opengl코드 함수들을 작성합니다.
int main(int argc, char** argv) {
  vec3 v1(3.0, 4.0, 5.0), v2(1.0, 1.0, 1.0);  // float 값을 받는 생성자 작성
  vec3 v3 = v1 - v2;  // - 연산자 오버로딩 v3 에는 (2,3,4) 대입됨
  v3.Print();         // 대략 (2.0000, 3.0000, 4.0000) 형식으로 printf
  printf("\n%f", v1.Length());  // v1벡터의 크기인 root(50), 대략 7.07... 이
                                // 출력. sqrtf함수를 사용할 것
  v2.Normalize();  // v2벡터가 단위벡터(크기가 1이고 방향은 동일)로 변경됨
  vec3 v4 = v1.CrossProduct(v2);  // v1과 v2벡터의 외적 결과가 v4에 저장됨
  v4.Normalize();
  v4.Print();  // v4를 normalize한 결과를 출력

  mat3 m1(3, 0, 1, 2, 5, 3, 1, 2, 4),
      m2(2, 4, 1, 1, 3, 4, 5, 1, 0);  // float 값을 9개 받는 생성자 작성
  m1.Print();                         // 3.0000 0.0000 1.0000
                                      // 2.0000 5.0000 3.0000
                                      // 1.0000 2.0000 4.0000

  mat3 m3 = m1 + m2;  // 행렬 덧셈 수행
  m3.Print();
  mat3 m4 = m1 * m2;  // 행렬 곱 수행
  m4.Print();
  mat3 m5 = m1.Transpose();  // 전치행렬 생성, 여기서 m1은 변화되지 않는다.
  m5.Print();
  vec3 v5 = m1 * v1;  // mat3와 vec3를 곱한 곱을 vec3로 저장
  v5.Print();

  // 여기에서부터 opengl 코드를 작성하면 됩니다.
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Paint");

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glutDisplayFunc(MyDisplay);
  glutMouseFunc(MyMouseClick);
  glutMotionFunc(MyMouseMove);
  glutKeyboardFunc(MyKeyboard);

  glutMainLoop();

  // 이하 생략
  return 0;
}
