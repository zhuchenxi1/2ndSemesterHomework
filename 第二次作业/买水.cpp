#include<iostream>
using namespace std;

int max(int emp,int lid,int maxdrinks);
int main(){
    int money;
    cin >> money;
    
    
    cout << max(money,money,money);
    return 0;
}
int max(int emp,int lid,int maxdrinks){
    if(emp<2&&lid<3) return maxdrinks;
    else{
        int k=emp;
        maxdrinks+=emp/2+lid/3;
        emp=emp%2+emp/2+lid/3;
        lid=lid%3+lid/3+k/2;
        return max(emp,lid,maxdrinks);
    }
}
