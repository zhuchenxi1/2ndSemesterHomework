#include<iostream>
#include<iomanip>
using namespace std;
double real,im;
void mminus(double a,double b,double c,double d);
int main(){
	cout << fixed << setprecision(2);
	double a,b,c,d;
	cin >> a >> b >> c >> d;
	mminus(a,b,c,d);
	cout << real << ' ' << im;
	
	
	return 0;
}
void mminus(double a,double b,double c,double d){
	real=a-c;
	im=b-d;
	
}

