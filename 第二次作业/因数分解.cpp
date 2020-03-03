#include <iostream>
#include <cmath>
using namespace std;

//判断是否为素数
int isPrime(long num)
{
    int flag=1;
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
            flag=0;
            break;
        }
}
return flag;

}

//计算质因素分解，
void factorization(long n,long a[],int &b)
{
    if(isPrime(n)){
        cout << n;
        return;
    }
    else{
        int k=0;
        while(!isPrime(n)){
          for(int i=2;i<n;i++){
                if(n%i==0){
                  a[k++]=i;
                  n=n/i;
                  b++;
                  break;
                }
            }
    }
            a[k++]=n;
            b++;
  }

    return;
}

int main()
{
    long n;
    long factor[100];
    int numofFactor = 0;
    cin >> n;
    factorization(n, factor, numofFactor);
    for (int i = 0; i < numofFactor; i++)
    {
        cout << factor[i] << " ";
    }
    cout << endl;
    return 0;
}

