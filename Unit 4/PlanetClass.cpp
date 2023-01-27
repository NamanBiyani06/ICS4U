#include <iostream>
#include <cmath>
using namespace std;

// universal gravitational constant
const double GRAV_CONST = 6.67e-11;

// planet class
class Planet
{
  public:
    // planet name
    string name;
    // radius in meters
    int radius;
    // mass in kilograms
    double mass;
    // orbital period in days
    int orbitalPeriod;

    // planet constructor
    Planet(string a, int b, double c, int d)
    {
      cout << "Processing " << a << " Dataset..." << endl;
      name = a; radius = b; mass = c; orbitalPeriod = d;
    }

    // toString
    string toString()
    {
      return
      "Planet: " + (name) + '\n' + 
      "Radius: " + to_string(radius) + " meters" + '\n' +
      "Mass: " + to_string(mass) + " kilograms" + '\n' +
      "Orbital Period: " + to_string(orbitalPeriod) + " days";
    }

    float surfaceGravity()
    {
      /* 
      Newton's Law of Gravitation 
      g = (GM)/(r^2)
      */
      float surfaceGravity = float((GRAV_CONST * double(mass)) / (pow(radius, 2)));
      return surfaceGravity;
    }

    float surfaceArea()
    {
      /*
      Area of a Sphere
      A = 4 * pi * r^2
      */
      float area = 4.0 * M_PI * float(pow(radius, 2));
      return area;
    }
};

int main()
{
  Planet Earth("Earth", 6378100, 5.97219e+24, 365);

  cout << Earth.toString() << endl;
  cout << "Surface Gravity: " << Earth.surfaceGravity() << " meters/second" << endl;
  cout << "Surface Area: " << fixed << Earth.surfaceArea() << " meters^2" << endl;

  cout << endl;

  Planet Jupiter("Jupiter", 7.149e+7, 1.898e+27, 4380);

  cout << Jupiter.toString() << endl;
  cout << "Surface Gravity: " << Jupiter.surfaceGravity() << " meters/second" << endl;
  cout << "Surface Area: " << fixed << Jupiter.surfaceArea() << " meters^2" << endl;
}
