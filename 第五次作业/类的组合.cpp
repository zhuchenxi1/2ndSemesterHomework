#include <iostream>
using namespace std;
//请在这里补充CPoint，CRectangle类的定义
class CPoint{
private:
    int X,Y;
public:
    void alter(int a,int b){
        X=a;
        Y=b;
    }
    CPoint(int a=0,int b=0){
        X=a;
        Y=b;
        cout << "CPoint contstructor with default value(0,0) is called." <<endl;
        
    }
    CPoint(CPoint &p){
        X=p.X;
        Y=p.Y;
        cout << "CPoint copy contstructor is called."<<endl;
    }
    int getx(){
        return X;
    }
    int gety(){
        return Y;
    }
    
};
class CRectangle{
private:
    CPoint p1,p2;
public:
    CRectangle(){
        
        cout << "CRectangle default contstructor is called."<< endl;
    }
    CRectangle(CPoint a,CPoint b):p1(a),p2(b){
       
        
        cout << "CRectangle contstructor with (CPoint,CPoint) is called."<<endl;
    }
    CRectangle(int a,int b,int c,int d){
        p1.alter(a,b);
        p2.alter(c,d);
        
        cout << "CRectangle contstructor with (int,int,int,int) is called."<<endl;
    }
    CRectangle(CRectangle &r):p1(r.p1),p2(r.p2){
        
        cout << "CRectangle copy contstructor is called."<<endl;
    }
    int GetArea(){
        
        int m=p1.getx()-p2.getx();
        int n=p1.gety()-p2.gety();
        int ret=m*n;
        
        if(ret<0) ret=-ret;
        return ret;
    }
};


int main()
{
    int a=1, b=1, c=6, d=11;
    cout<<"# Define p1 ######"<<endl;
    CPoint p1;
    cout<<"# Define p2 ######"<<endl;
    CPoint p2(10,20);
    cout<<"# Define rect1 ######"<<endl;
    CRectangle rect1;
    cout<<"# Define rect2 ######"<<endl;
    CRectangle rect2(p1, p2);
    cout<<"# Define rect3 ######"<<endl;
    CRectangle rect3(a, b, c, d);
    cout<<"# Define rect4 ######"<<endl;
    CRectangle rect4(rect2);
    cout<<"# Calculate area ######"<<endl;
    cout << "rect1面积为" << rect1.GetArea() << endl;
    cout << "rect2面积为" << rect2.GetArea() << endl;
    cout << "rect3面积为" << rect3.GetArea() << endl;
    cout << "rect4面积为" << rect4.GetArea() << endl;
    system("pause");
    return 0;
}



