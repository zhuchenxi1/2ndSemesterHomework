#include<iostream>
#include<fstream>
using namespace std;

int main(){
    struct student{
        short int stu_id;
        short int score;

    };
    int n;
    cin >> n;
    student *a=new student[1000];
    for(int i=0;i<n;i++){
        cin >> a[i].stu_id;
        cin >> a[i].score;
    }
    ofstream outFile("out.txt",ios::out| ios::binary);
    for(int i=0;i<n;i++){
        outFile.write((char *)&a[i],sizeof(a[i]));
    }
    outFile.close();
    student *b=new student[1000];
    ifstream inFile("out.txt",ios::in|ios::binary);
    int i=0;
    while(i<n&&inFile.read((char *)&a[i], sizeof(a[i]))) { //一直读到文件结束
        b[i].stu_id << a[i].stu_id;
        b[i].score << a[i].score;
        i++;
    }
    ofstream destFile("out.txt",ios::app); 
    for(int j=0;j<n;j++){
    destFile.write((char *)&b[j],4);
    }
    delete []a;
    delete []b;
    
    inFile.close();
    destFile.close();
    return 0;
}
