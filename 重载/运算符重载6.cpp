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
    Point(int x,int y):x(x),y(y){
        cout<<"Point(int x,int y):x(x),y(y)"<<endl;
    }
    Point(const Point &p)
    {
        cout<<" Point(const Point &p)"<<endl;
        x=p.x;
        y=p.y;
    }
    ~Point()
    {
        cout<<" ~Point()"<<endl;
    }
    int getX(){return x;}
    int getY(){return y;}
    void setX(int x){this->x=x;}
    void setY(int y){this->y=y;}
    void printInfo()
    {
            cout<<"("<<x<<","<<y<<")"<<endl;
    }
Point operator+(Point &p)
{
    cout<<"operator+"<<endl;
    Point n;
    n.x=this->x+p.x;
    n.y=this->y+p.y;
    return n;
}
/*Point p(1,2);++p*/
Point& operator++()
{
    cout<<"++P"<<endl;
    this->x+=1;
    this->y+=1;
    return *this;
}
/*point p(1,2); p++*/
Point operator++(int a)
{
    cout<<"p++"<<endl;
    Point n;
    n=*this;
    this->x+=1;
    this->y+=1;
    return n;
}

    friend Point add(Point &p1,Point &p2);
    friend ostream& operator<<(ostream &o,Point p);
};
Point add(Point &p1,Point &p2)
{
    Point n;
    n.setX(p1.getX()+p2.getX());
    n.setY(p1.getY()+p2.getY());
    return n;
}

ostream& operator<<(ostream &o,Point p)
{
    cout<<"("<<p.x<<","<<p.y<<")";
    return o;
}
int main()
{
    Point p1(1,2);
    Point p2(2,3);
    Point m,n;
    cout<<"begin"<<endl;
    m=p1+p2;/*m=p1.operator+p(2);*/
    cout<<"add p1,p2 = "<<m<<endl;
    cout<<"begin"<<endl;
    n=++p1;/*m=p1.operator++();*/
    cout<<"m = "<<n<<" "<<"p1 = "<<p1<<endl;
    cout<<"------------------------"<<endl;
    n=p1++;
    cout<<"n= "<<n<<" "<<"p1 = "<<p1<<endl;
    cout<<"end"<<endl;

    return 0;
}
