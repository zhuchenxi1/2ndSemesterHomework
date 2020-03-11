#include <iostream>
#include <iomanip>
using namespace std;
//请在此处补充Account类的定义
class Account{
    public :
       void init(string a,string b,string c,int d,double e){
           id=a;
           name=b;//引号没有输出
           gender=c;
           age=d;
           char alter[100]={0};
           sprintf(alter,"%.3lf",e);
           int point=0;
           int flag=0;//默认可以
           int fflag=0;
           for(int i=0;i<20;i++){
               if(alter[i]=='.'){
                   fflag=1;
                   point=i;
               }
               if(fflag){
                   if(i-point==3){
                       if(alter[i]=='0'){
                           
                           break;
                       }
                       else{
                           flag=1;
                       }
                   }
               }
           }
           if(flag){
               money=0;
               cout << "您输入的金额不合法"<<endl;
           }
           else money=e;
       }
       void printmoney(void){
           cout<<fixed<<setprecision(2);
           cout << name;
           cout << "的存款为";
           cout << money<<endl;
       }
       void deposit(double e){
           char alter[100];
           sprintf(alter,"%.3lf",e);
            int point=0;
           int flag=0;//默认可以
           int fflag=0;
           for(int i=0;i<20;i++){
               if(alter[i]=='.'){
                   fflag=1;
                   point=i;
               }
               if(fflag){
                   if(i-point==3){
                       if(alter[i]=='0'){
                           
                           break;
                       }
                       else{
                           flag=1;
                       }
                   }
               }
           }
           if(flag) cout << "您输入的金额不合法"<<endl;
           else money=e+money;
       }
       void withdraw(double e){
           char alter[100]={0};
           sprintf(alter,"%.3lf",e);
           int point=0;
           int flag=0;//默认可以
           int fflag=0;
           for(int i=0;i<20;i++){
               if(alter[i]=='.'){
                   fflag=1;
                   point=i;
               }
               if(fflag){
                   if(i-point==3){
                       if(alter[i]=='0'){
                           
                           break;
                       }
                       else{
                           flag=1;
                       }
                   }
               }
           }
           if(flag) cout << "您输入的金额不合法"<<endl;
           else{
               if(money-e>=0) money=money-e;
               else cout << "您的存款金额不足"<<endl;
           }
       }

    private :
      string id;
      string name;
      string gender;
      int age;
      double money;
      

};


int main()
{
    Account tom;
    tom.init("32020320011001876X", "Tom Black", "男", 19, 2000.89);
    tom.printmoney();//输出：Tom Black的存款为2000.89
    tom.deposit(89.471);//输出：您输入的金额不合法
    tom.printmoney();//输出：Tom Black的存款为2000.89
    tom.deposit(10000);
    tom.printmoney();//输出：Tom Black的存款为12000.89
    tom.withdraw(10001);
    tom.printmoney();//输出：Tom Black的存款为1999.89
    tom.withdraw(10000.123);//输出：您输入的金额不合法
    tom.printmoney();//输出：Tom Black的存款为1999.89
    tom.withdraw(10000.9);//输出：您的存款金额不足
    tom.printmoney();//输出：Tom Black的存款为1999.89
    Account jerry;
    jerry.init("320203200910116569", "Jerry Black", "女", 11, 100.956);//输出：您输入的金额不合法
    jerry.printmoney();//输出：Jerry Black的存款为0.00
}

