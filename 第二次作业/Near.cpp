#include<iostream>
#include<string>
using namespace std;
int max(int a[],int t){
	int max=a[0];
	for(int i=0;i<t;i++){
		if(a[i]>max) max=a[i];
	};
	return max;
}
int min(int a[],int t){
	int min=a[0];
	for(int i=0;i<t;i++){
		if(a[i]<min) min=a[i];
	};
	return min;
}
int main(){
	string a;
	string b;
	int c[10000]={0};
	int d[10000]={0};
	int t=0;
	int k=0;
	cin >> a >> b;
	
	for(int i=0;i<a.length();i++){
		if(a[i]<=90){
			c[t++]=a[i]-64;
			
		}
		else{
			c[t++]=a[i]-96;
			
		}
	}
	for(int i=0;i<b.length();i++){
		if(b[i]<=90){
			d[k++]=b[i]-64;
			
		}
		else{
			d[k++]=b[i]-96;
			
		}
	}
	
	if(max(c,t)<min(d,k)) cout << min(d,k)-max(c,t);
	else{
		if(min(c,t)<=max(d,k)) cout << 0;
		else{
			cout << min(c,t)-max(d,k);
		}
		
	}
	return 0;
} 

