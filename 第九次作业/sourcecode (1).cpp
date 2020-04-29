#include <iostream>
using namespace std;
class Complex{
    private:
    double real,im;
    public:
    Complex(double a=0,double b=0){
        real=a;
        im=b;
    }
    void print(){
        cout <<'(' <<real <<')'<< '+' <<'('<<im<<'i'<<')';
    }
    friend Complex operator +(Complex a,Complex b);
    friend Complex operator +(Complex a,double b);
    friend Complex operator +(double a,Complex b);
    friend Complex operator -(Complex a,Complex b);
    friend Complex operator -(Complex a,double b);
    friend Complex operator -(double a,Complex b);
};
Complex operator +(Complex a,Complex b){
    Complex x;
    x.real=a.real+b.real;
    x.im=a.im+b.im;
    return x;
}
Complex operator +(Complex a,double b){
    Complex x;
    x.real=a.real+b;
    x.im=a.im;
    return x;
}
Complex operator +(double a,Complex b){
    Complex x;
    x.real=a+b.real;
    x.im=b.im;
    return x;
}
Complex operator -(Complex a,Complex b){
    Complex x;
    x.real=a.real-b.real;
    x.im=a.im-b.im;
    return x;
}
Complex operator -(Complex a,double b){
    Complex x;
    x.real=a.real-b;
    x.im=a.im;
    return x;
}
Complex operator -(double a,Complex b){
    Complex x;
    x.real=a-b.real;
    x.im=-b.im;
    return x;
}

int main()
{
    Complex a(3,4),b(1,-1),c;
    c=a+b;
    cout<<"a+b=";
    c.print();
    cout<<endl;
    c=a-b;
    cout<<"a-b=";
    c.print();
    cout<<endl;
    c=a+100;
    cout<<"a+100=";
    c.print();
    cout<<endl;
    c=a-2.5;
    cout<<"a-2.5=";
    c.print();
    cout<<endl;
    c=100+a;
    cout<<"100+a=";
    c.print();
    cout<<endl;
    c=2.5-a;
    cout<<"2.5-a=";
    c.print();
    cout<<endl;
    return 0;
}


