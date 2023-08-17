class Point {
public:
  void setX(double x) { p_X = x; }
  void setY(double y) { p_Y = y; }
  double getX() { return p_X; }
  double getY() { return p_Y; }

private:
  double p_X, p_Y;
};
