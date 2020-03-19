#include <iostream>
#include<iostream>
using namespace std;
int flag1=0;//日期合法
int flag2=0;//时间合法
int valid=1;
class CTime{
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
public:
    //构造函数
    CTime(int a,int b,int c,int d=0,int e=0,int f=0){
        flag1=flag2=0;
        
        int run=0;//闰年
        if(a<0) flag1=1;
        switch (b){
            case 1:
            if(c<1||c>31) flag1=1;
            break;
            case 2:
            if(a%4==0&&a%100!=0) run=1;
            if(a%400==0) run=1;
            if(run){ //判断下闰年
                if(c<1||c>29) flag1=1;
            }
            else{
                if(c<1||c>28) flag1=1;
            }
            break;
            case 3:
            if(c<1||c>31) flag1=1;
            break;
            case 4:
            if(c<1||c>30) flag1=1;
            break;
            case 5:
            if(c<1||c>31) flag1=1;
            break;
            case 6:
            if(c<1||c>30) flag1=1;
            break;
            case 7:
            if(c<1||c>31) flag1=1;
            break;
            case 8:
            if(c<1||c>31) flag1=1;
            break;

            case 9:
            if(c<1||c>30) flag1=1;
            break;
            case 10:
            if(c<1||c>31) flag1=1;
            break;
            case 11:
            if(c<1||c>30) flag1=1;
            break;
            case 12:
            if(c<1||c>31) flag1=1;
            break;

        }
        if(d<0||d>23) flag2=1;
        if(e<0||e>59) flag2=1;
        if(f<0||f>59) flag2=1;
        if(flag1==1&&flag2!=1){
            valid=0;
            cout << "date error!"<<endl;
            year=month=day=hour=minute=second=0;
        }
        if(flag1!=1&&flag2==1){
            valid=0;
            cout << "time error!"<<endl;
            year=month=day=hour=minute=second=0;
        }
        if(flag1==1&&flag2==1){
            valid=0;
            cout << "date and time error!"<<endl;
            year=month=day=hour=minute=second=0;
        }
        if(flag1!=1&&flag2!=1){
            year=a;
            month=b;
            day=c;
            hour=d;
            minute=e;
            second=f;
        }
        cout << "构造函数被调用" << endl;
    }
    //拷贝构造函数
    
    //析构函数
    ~CTime(){
        cout << "析构函数被调用"<< endl;
    }
    //showtime函数
    void showTime(){
        cout << year << '/' << month << '/' << day << ' ';
        cout << hour << ':'<< minute << ':' << second<<endl;
    }
    //计算天数函数
    int dayDiff(CTime &p){
        
        int m,n,k;
        
        m=p.year;
        n=p.month;
        k=p.day;
        if(year<m){
            int num1=0;//间隔天数
            int num2=0;
            int num3=0;
            for(int i=year+1;i<m;i++){
                if((i%4==0&&i%100!=0)||i%400==0) num1+=366;
                else num1+=365;
            }
            if((year%4==0&&year%100!=0)||year%400==0){
                for(int i=1;i<month;i++){
                    if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
                        num2+=31;
                    }else if(i==2) num2+=29;
                          else num2+=30;
                    
                    
                }
            }
            else{
                for(int i=1;i<month;i++){
                    if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
                        num2+=31;
                    }else if(i==2) num2+=28;
                          else num2+=30;
                    
                    
                }
            }
            num2+=day;
            if((year%4==0&&year%100!=0)||year%400==0) num2=366-num2;
            else num2=365-num2;
            if((m%4==0&&m%100!=0)||m%400==0){
                for(int i=1;i<n;i++){
                    if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
                        num3+=31;
                    }else if(i==2) num3+=29;
                          else num3+=30;
                    
                    
                }
            }
            else{
                for(int i=1;i<n;i++){
                    if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
                        num3+=31;
                    }else if(i==2) num3+=28;
                          else num3+=30;
                    
                    
                }
            }
            num3+=k;
            cout << "拷贝构造函数被调用"<< endl;
            cout << "析构函数被调用" << endl;
            return num1+num2+num3;

        }
        if(m<year){
            int num1=0;//间隔天数
            int num2=0;
            int num3=0;
            for(int i=m+1;i<year;i++){
                if((i%4==0&&i%100!=0)||i%400==0) num1+=366;
                else num1+=365;
            }
            if((m%4==0&&m%100!=0)||m%400==0){
                for(int i=1;i<n;i++){
                    if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
                        num2+=31;
                    }else if(i==2) num2+=29;
                          else num2+=30;
                    
                    
                }
            }
            else{
                for(int i=1;i<n;i++){
                    if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
                        num2+=31;
                    }else if(i==2) num2+=28;
                          else num2+=30;
                    
                    
                }
            }
            num2+=k;
            if((m%4==0&&m%100!=0)||m%400==0) num2=366-num2;
            else num2=365-num2;
            if((year%4==0&&year%100!=0)||year%400==0){
                for(int i=1;i<month;i++){
                    if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
                        num3+=31;
                    }else if(i==2) num3+=29;
                          else num3+=30;
                    
                    
                }
            }
            else{
                for(int i=1;i<n;i++){
                    if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
                        num3+=31;
                    }else if(i==2) num3+=28;
                          else num3+=30;
                    
                    
                }
            }
            num3+=day;
            cout << "拷贝构造函数被调用"<< endl;
            cout << "析构函数被调用" << endl;
            return num1+num2+num3;

        }
        if(m==year){
            if(n==month){
                int num;
                num=day-k;
                if(num<0) num=-num;
                cout << "拷贝构造函数被调用"<<endl;
                cout << "析构函数被调用" << endl;
                return num;
            }
            else{

                int num1=0;
                int num2=0;

                for(int i=1;i<n;i++){
                    if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
                        num1+=31;
                    }
                    if(i==2){
                        if((m%4==0&&m%100!=0)||m%400==0){
                            num1+=29;
                        }
                        else num1+=28;
                    }
                    if(i==4||i==6||i==9||i==11) num1+=30;
                }
                num1+=k;
                for(int i=1;i<month;i++){
                    if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
                        num2+=31;
                    }
                    if(i==2){
                        if((year%4==0&&year%100!=0)||year%400==0){
                            num2+=29;
                        }
                        else num2+=28;
                    }
                    if(i==4||i==6||i==9||i==11) num2+=30;
                }
                num2+=day;
                int ret;
                if((num2-num1)<0) ret=num1-num2;
                else ret=num2-num1;
                cout << "拷贝构造函数被调用"<< endl;
                cout << "析构函数被调用" << endl;
                return ret;
            }
        }
        return 0;//
    }
    //isvalid
    int isvalid(){
        
        return valid;
    }

};


int main()
{
    int year, month, day, hour, minute, second;
    cin >> year >> month >> day >> hour >> minute >> second;
    CTime t1(year, month, day, hour, minute, second);
    t1.showTime();
    CTime t2(2000, 1, 1); //利用默认形参将时间初始化为00:00:00
    if (t1.isvalid())     //如果日期和时间合法，则计算天数
    {
        int days=0;
        days=t1.dayDiff(t2);
        cout << "这两天之间相隔了" << days << "天" << endl;
        days=t2.dayDiff(t1);
        cout << "这两天之间相隔了" << days << "天" << endl;
    }
}

