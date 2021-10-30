
#include <bits/stdc++.h>
using namespace std;
/*


drawLine(p1, p2)

X-------X
p1      p2


Write a function drawHTree that constructs an H-tree, given its center (x and y coordinates), a starting length, and depth. Assume that the starting line is parallel to the X-axis.


drawHTree(Point p, length  (int),  depth (int)  )


 -._
  | |       |
Y'|____X____|X'
  |         |
  |         |


p1   p2

------> X


>                        |
                X------->X
                (X)
                 |
                 |
                 |
           X------

length of child = L/sqrt(2)


1. Make a recursive function to simulate printing a H tree

2. at the end point (upper-left... ur, ll, lr) -> currDepth - depth


*/

class Point
{
public:
  int x;
  int y;
};

void drawLine(Point p1, Point p2)
{
}

void getEndpoints(Point p, int length, vector<Point> &points)
{
  for (int i = -1; i <= 1; i += 2)
    points.push_back({p.x, (i * length) + p.y});
  return;
}

void drawHTree(Point p, int depth, int length)
{
  if (depth == 0)
    return;

  Point p1 = p, p2 = p;

  p1.x = p.x - (length / 2);
  p2.x = p.x + (length / 2);

  vector<Point> endPoints;

  getEndpoints(p1, (length / 2), endPoints);
  getEndpoints(p2, (length / 2), endPoints);

  drawLine(p1, p2);
  drawLine(endPoints[0], endPoints[1]);
  drawLine(endPoints[2], endPoints[3]);

  for (Point endPoint : endPoints)
    drawHTree(endPoint, depth - 1, (length / sqrt(2)));

  return;
}

/*
 -1,1           1,1  (0)

 -1,0    0,0    1,0

 -1,-1          1,-1

*/

int main()
{
  std::cout << "Practice makes Perfect!" << std::endl;
  return 0;
}
