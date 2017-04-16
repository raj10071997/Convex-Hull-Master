#include <cstdio>
#include <stack>
#include <algorithm>
#include<iostream>
#include<ctime>
using namespace std;

class Point    {
public:
    int x, y;

    
    bool operator < (Point b) {
        if (y != b.y)
            return y < b.y;
        return x < b.x;
    }
};


Point pivot;


int CW(Point a, Point b, Point c) {
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}


int SQRDistance(Point a, Point b)  {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}


bool POorder(Point a, Point b)  {
    int order = CW(pivot, a, b);
    if (order == 0)
        return SQRDistance(pivot, a) < SQRDistance(pivot, b);
    return (order == -1);
}

stack<Point> GRAHAMSCAN(Point *points, int N)    {
    stack<Point> hull;

    if (N < 3)
        return hull;

    
    int leastY = 0;
    for (int i = 1; i < N; i++)
        if (points[i] < points[leastY])
            leastY = i;

 
    Point temp = points[0];
    points[0] = points[leastY];
    points[leastY] = temp;

 
    pivot = points[0];
    sort(points + 1, points + N, POorder);

    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);

    for (int i = 3; i < N; i++) {
        Point top = hull.top();
        hull.pop();
        while (CW(hull.top(), top, points[i]) != -1)   {
            top = hull.top();
            hull.pop();
        }
        hull.push(top);
        hull.push(points[i]);
    }
    return hull;
}

int main()  {
	
	int n,x,y,i;
	cout<<"Enter No of points :: ";
	cin>>n;
	Point points[n];

	cout<<"Now Enter the points locations \n";
	for(i=0;i<n;i++)
	{cin>>x>>y;	points[i].x=x;		points[i].y=y;
	}


    
	clock_t tStart = clock();	
    stack<Point> hull = GRAHAMSCAN(points, n);

cout<<"\n CONVEX HULL:"<<endl;
    while (!hull.empty())   {
        Point p = hull.top();
        hull.pop();

        printf("(%d, %d)\n", p.x, p.y);
    }
cout<<"\nTime taken: "<<(double)(((double)(clock()) - (double)(tStart))/CLOCKS_PER_SEC)<<endl;
    return 0;
}

