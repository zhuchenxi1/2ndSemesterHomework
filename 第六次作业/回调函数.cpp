//实现功能：既能排序整型数，也可以排序字符串

#include <iostream>
#include <cstring>
using namespace std;

int cmpGT(const int *p1, const int *p2)
{
//实现两数比较，如果大于，则返回1，等于则返回0，小于则返回-1
 if(*p1>*p2) return 1;
    if(*p1==*p2) return 0;
    if(*p1<*p2) return -1;
    return 0;

}
int cmpLT(const int *p1, const int *p2)
{
//实现两数比较，如果大于，则返回-1，等于则返回0，小于则返回1
if(*p1>*p2) return -1;
    if(*p1==*p2) return 0;
    if(*p1<*p2) return 1;
    return 0;


}

void swap(int *p1, int *p2)
{
//实现两个整形变量的值交换
int temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;

}

void bubble(int *base,  int(*cmp)(const int *, const int *))
{
//请在这里补充冒泡排序，请根据main函数中对bubble函数的调用，分析形参的作用
 int i=0;
    int j=0;
    for(i=0;i<9;i++){
        for(j=0;j+1<9-i+1;j++){
            if(cmp(&base[j],&base[j+1])==1){
                swap(&base[j],&base[j+1]);
            }
        }
    }


}

int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int i = 0;
	bubble(arr,  cmpGT);
	for (i = 0; i < 10; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	bubble(arr,  cmpLT);
	for (i = 0; i < 10; i++)
	{
		cout<<arr[i]<<" ";
	}	
	cout<<endl;
	return 0;
}

