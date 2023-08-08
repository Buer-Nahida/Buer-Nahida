#include "func.h"

string isInCircle(Circle &circle, Point &point) {
  double D = pow(circle.getCenter().getX() - point.getX(), 2) +
             pow(circle.getCenter().getY() - point.getY(), 2);

  double rD = pow(circle.getR(), 2);

  if (D == rD)
    return "点在圆上";
  else if (D > rD)
    return "点在圆外";
  else if (D < rD)
    return "点在圆内";
  else
    return "无法判断";
}
