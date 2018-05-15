class Circle {
private:
  double radius;
  const double pi = 3.14159;

public:
  Circle();
  Circle(double r);
  void setRadius(double r);
  double getRadius() const;
  double getArea() const;
  double getDiameter() const;
  double getCircumference() const;
};
