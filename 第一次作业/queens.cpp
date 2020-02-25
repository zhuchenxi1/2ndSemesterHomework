#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;

    int column[9]={0};
    int x,y;
    int vis[2][100]={0};
    for(int i=1,t=0;i<=8;i++,t++){
        
        
        if(s[t]!='*'){
            
            column[s[t]-48]=1;
            vis[0][i+s[t]-48]=1;
            vis[1][i-s[t]+48]=1;
        }
        else x=i;//行
    }
    for(int i=1;i<=8;i++){
        if(column[i]==0){
            y=i;
            break;
        }
    }
    if(vis[0][x+y]!=1&&vis[1][x-y]!=1){
        cout << y;
    }
    else cout << "No Answer";
    
    return 0;
}
