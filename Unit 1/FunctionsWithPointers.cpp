#include <iostream>
#include <math.h>
using namespace std;

void cubeByPointer(int * pcube);
void sumTwoInt(int * sum, int * addOn);
void circle(int * pradius, int * parea, int * pcircumference);
bool quadEquation(int a, int b, int c, double * solution1, double * solution2);
void swap(float *p1, float *p2);
void SquareComplex(double &a, double &b);



int main()
{
  int cube = 5;
  int * pcube = &cube;
  cubeByPointer(pcube);

  int sum = 1, addOn = 2;
  int * psum = &sum, * paddOn = &addOn;
  sumTwoInt(psum, paddOn);

  int radius = 5;
  int area, circumference;
  int * pradius = &radius;
  int * parea = &area, * pcircumference = &circumference;
  circle(pradius, parea, pcircumference);

  int a = 1, b = 4, c = 4;
  double solution1, solution2;
  double * psolution1 = &solution1, * psolution2 = &solution2;
  bool solutionCheck = quadEquation(a, b, c, psolution1, psolution2);

  float x = 1.0, y = 2.0;
  float * px = &x, * py = &y;
  swap(px, py);
  swap(px, py);

}

void cubeByPointer(int * pcube)
{
  *pcube = pow(*pcube, 3);
}

void sumTwoInt(int * psum, int * paddOn)
{
  *psum = *psum + *paddOn;
}

void circle(int * pradius, int * parea, int * pcircumference)
{
  double pi = 2 * acos(0.0);
  *pcircumference = (2) * (pi) * (*pradius);
  *parea = (pi) * (pow(*pradius, 2));
}

bool quadEquation(int a, int b, int c, double * solution1, double * solution2)
{
  int discrim = pow(b, 2) - (4*a*c);
  
  if (discrim > 0)
  {
    * solution1 = ((-b) + pow(pow(b,2) - 4*a*c,0.5))/2*a;
    * solution2 = ((-b) - pow(pow(b,2) - 4*a*c,0.5))/2*a;
    return true;
  }
  else if (discrim == 0)
  {
    * solution1 = ((-b) + pow(pow(b,2) - 4*a*c,0.5))/2*a;
    * solution2 = * solution1;
    return true;
  }
  else
  {
    return false;
  }
}

void swap(float *p1, float *p2)
{
  //the prior issue was that the pointer "temp" did not point to a memory address of a real float
  float temp;
  float * ptemp = &temp;
  * ptemp = * p1;
  * p1 = * p2;
  * p2 = * ptemp;
}

void SquareComplex(double * a, double * b) 
{
  // Squares a complex number a + bi
  * a = (*a)*(*a) - (*b)*(*b);
  * b = 2*(*a)*(*b);
}
