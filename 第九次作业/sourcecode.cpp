#include <iostream>
using namespace std;


class Complex
{
private:
    double real,im;
public:
    void print(){
        cout << real<< '+'<<im<<'i';
    }
    Complex(double a=0,double b=0){
        real=a;
        im=b;
    }
    double getreal(){
        return real;
    }
    double getim(){
        return im;
    }
    Complex operator +(Complex c){
        Complex x;
        x.real=real+c.getreal();
        x.im=im+c.getim();
        return x;
    }
    Complex operator +(double c){
        Complex x;
        x.real=real+c;
        x.im=im;
        return x;
    }
    Complex operator -(Complex c){
        Complex x;
        x.real=real-c.getreal();
        x.im=im-c.getim();
        return x;
    }
    Complex operator -(double c){
        Complex x;
        x.real=real-c;
        x.im=im;
        return x;
    }
};



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

    return 0;
}


