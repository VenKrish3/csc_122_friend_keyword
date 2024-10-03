#include <iostream>

using namespace std;

class GeometricScaler;
class GeometricSwapper;

class Rectangle
{
  int width, height;

public:
  Rectangle(int w, int h) : width(w), height(h) {}

  int area()
  {
    return (width * height);
  }
  void scale(GeometricScaler scalar);
  void swap(GeometricSwapper swapper);
};

class GeometricScaler
{
private:
  friend class Rectangle;
  int factor;

public:
  GeometricScaler(int factor)
  {
    this->factor = factor;
  }
};

class GeometricSwapper
{
private:
  friend class Rectangle;
  int height;

public:
  GeometricSwapper(int height)
  {
    this->height = height;
  }
};

void Rectangle::swap(GeometricSwapper swapper)
{
  swapper.height = this->width;
  this->width = this->height;
  this->height = swapper.height;
}

void Rectangle::scale(GeometricScaler scalar)
{
  this->width = this->width * scalar.factor;
  this->height = this->height * scalar.factor;
}

int main()
{
  Rectangle rectangle(1, 2);
  cout << "Area of the Rectangle: " << rectangle.area() << endl;

  GeometricScaler scaler(5);
  rectangle.scale(scaler);

  cout << "Area of the Rectangle: " << rectangle.area() << endl;

  return 0;
}
