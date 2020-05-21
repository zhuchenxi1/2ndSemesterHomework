#include <iostream>
#include <vector>

using namespace std;
template <typename T>
class Array
{
  public:
 vector <T> a;  //
    Array(int n){}
 void input(int n){
   int i=0;
   while(i<n){
     T k;
     cin >> k;
     a.push_back(k);
       i++;
   }
 }
T & operator[](int n)
{
  return a[n];
}

};

int gcd(int a,int b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

    

int max(int a,int b){
    if(a>b) return a;
    return b;
}
int min(int a,int b){
    if(a<b) return a;
    return b;
}

class Fract
{
  public:
  int n,m;
  Fract(int a=0,int b=1):n(a),m(b){
    
      if(a<0) a=-a;
      if(b<0) b=-b;
      int c;
      c=gcd(max(a,b),min(a,b));
      if(m<0){
          n=-n;
          m=-m;
      }
      if(c!=1){
          n=n/c;
          m=m/c;
      }
  }
    void show(){
        if(n==0||m==1) cout << n << endl;
        else{
            cout << n << '/' << m << endl;
        }
    }
    Fract &operator +=(Fract &x){
    Fract y(x.n*m+x.m*n,x.m*m);
    return *this=y;

}
    
   friend istream &operator>>(istream &is,Fract &f)
   {
       is>>f.n>>f.m;
       return is;
   }

    
   
};

int main()
{
    unsigned int n;
    cin >> n;
    Array<double> db(n);
    db.input(n);
    double dbsum(0.0);
    for (unsigned int i = 0; i < n; i++)
        dbsum += db[i];
    cout << dbsum << endl;

    cin >> n;
    Array<Fract> fr(n);
    fr.input(n);
    Fract frsum(0, 1);
    for (unsigned int i = 0; i < n; i++)
        frsum += fr[i];
    frsum.show();
}


