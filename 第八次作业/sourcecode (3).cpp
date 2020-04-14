#include <iostream>
using namespace std;
const int pi=3.14159;
class Shape{
private:
    int m_ID;
public:
    static int count;
    void setid(int a){
        m_ID=a;
    }
    int getid(void){
        return m_ID;
    }
    int getArea(){
        return 0;
    }
    Shape(int a){
        count++;
        m_ID=a;
        cout << "Shape constructor called:" << count <<endl;
    }
    ~Shape(){
        count--;
        cout << "Shape destructor called:" << count << endl;
    }
};
int Shape::count=0;
class Circle:public Shape
{
private:
    int r;
public:
    int getr(){
        return r;
    }
    void setr(int a){
        r=a;
    }
    int getArea(){
        return r*r*pi;
    }
    Circle(int a,int b):Shape(b){
        r=a;
        //count++;
        cout <<"Circle constructor called:" << count << endl;
    }
    ~Circle(){
        count--;
        cout << "Circle destructor called:" << count << endl;
        count++;
    }
};
class Rectangle:public Shape
{
private:
    int h,w;
public:
    int geth(){
        return h;
    }
    int getw(){
        return w;
    }
    void set(int a,int b){
        h=a;
        w=b;
    }
    int getArea(){
        return h*w;
    }
    Rectangle(int a,int b,int c):Shape(c){
        //count++;
        h=a;
        w=b;
        cout << "Rectangle constructor called:" << count <<endl;
    }
    ~Rectangle(){
        //count--;
        
        cout << "Rectangle destructor called:" << count << endl;
        count++;
    }
};

int main()
{
    Shape s(1);//1表示ID
    Circle c(4,2);//4表示半径，2表示ID
    Rectangle r(4, 5,3);//4和5表示长和宽，3表示ID
    cout<<"Shape的面积"<<s.getArea()<<endl;
    cout<<"Circle的面积"<<c.getArea()<<endl;
    cout<<"Rectangle的面积"<<r.getArea()<<endl;
}

