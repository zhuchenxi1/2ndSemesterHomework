#include<iostream>
using namespace std;
int main(){
    int m1[3][3];
    int m2[3][3];
    int ret[9];
    int t=0;
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
        cin >> m1[i][j];
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
        cin >> m2[i][j];
    for(int k=0;k<3;k++)
      for(int n=0;n<3;n++)
        ret[t++]=m1[k][0]*m2[0][n]+m1[k][1]*m2[1][n]+m1[k][2]*m2[2][n];

    for(int i=1;i<=9;i++){
        cout << ret[i-1];
        if(i!=9){
            if(i%3==0) cout << endl;
            else cout << ' ';
        }
    }
    return 0;
}



