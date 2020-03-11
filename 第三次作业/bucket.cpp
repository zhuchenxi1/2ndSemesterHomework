#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;

const double PI=3.1415926;
//请在此处完善类的设计
class cylinder{
   public:
      void init(double a,double b){
          h=a;
          r=b;
}
     double getvolumn(void){
      return PI*r*r*h;
}
    double getarea(void){
     return PI*r*r*2+2*PI*r*h;
}

   private:
     double r;
     double h;
};


int main()
{
    double d,h;
    cin>>d>>h;
    cylinder can;

    can.init(h,d/2);
    cout<<fixed<<setprecision(6);
    cout<<"油桶的容积是"<<can.getvolumn()<<" "<<endl;
    cout<<"铁皮的面积是"<<can.getarea()<<endl;
}



