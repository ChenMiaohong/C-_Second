#include<iostream>
#include<string.h>
using namespace std;
class Point{
private:
    int x;
    int y;
public:

    Point(){
        cout<<"Point()"<<endl;
    }
    Point(int x,int y):x(x),y(y){}
    int getX(){return x;}
    int getY(){return y;}
    void setX(int x){this->x=x;}
    void setY(int y){this->y=y;}
    void printInfo()
    {
            cout<<"("<<x<<","<<y<<")"<<endl;
    }
    friend Point operator+(Point &p1,Point &p2);
    friend Point add(Point &p1,Point &p2);
    friend Point operator++(Point &p);
    friend Point operator++(Point &p,int a);
};
Point add(Point &p1,Point &p2)
{
    Point n;
    n.setX(p1.getX()+p2.getX());
    n.setY(p1.getY()+p2.getY());
    return n;
}
Point operator+(Point &p1,Point &p2)
{
    cout<<"operator+"<<endl;
    Point n;
    n.setX(p1.getX()+p2.getX());
    n.setY(p1.getY()+p2.getY());
    return n;
}
/*Point p(1,2);++p*/
Point operator++(Point &p)
{
    cout<<"++P"<<endl;
    p.x+=1;
    p.y+=1;
    return p;
}
/*point p(1,2); p++*/
Point operator++(Point &p,int a)
{
    cout<<"p++"<<endl;
    Point n;
    n=p;
    p.x+=1;
    p.y+=1;
    return n;
}
int main()
{
    Point p1(1,2);
    Point p2(2,3);
    Point n=++p1;
    n.printInfo();
    p1.printInfo();
    cout<<"---------------------"<<endl;
    Point m=p2++;
    m.printInfo();
    p2.printInfo();

    return 0;
}
