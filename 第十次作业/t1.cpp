#include <iostream>
#include <fstream>
#include <cstdlib> 
using namespace std;
void myswap(double &a,double &b){
    double c;
    c=a;
    a=b;
    b=c;
}
double a[1000]; 

int main()
{
    int total = 0;//读入的整数个数
    ifstream inFile("a.txt",ios::in); //以文本模式打开in.txt备读
    
    ofstream outFile("b.txt",ios::out); //以文本模式打开out.txt备写
    
    double x;   
    while(inFile >> x) //可以像用cin那样用ifstream对象
        a[total++] = x;
    for(int i=0;i<total-1;i++){
        int j=0;
        for(j=0;j+1<=total-1-i;j++){
            if(a[j]>a[j+1]) myswap(a[j],a[j+1]);
        }
    }
    for(int i = 0;i < total; ++i)
        outFile << a[i] << " "; //可以像用cout那样用ofstream对象
    outFile.close();
    inFile.close();
    return 0;
}
