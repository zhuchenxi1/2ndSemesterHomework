#include "iostream"
using namespace std;

class vehicle{
private:
    int maxspeed;
    int weight;
public:
    void run(){
        cout << "vehicle run" <<endl;

    }
    void stop(){
        cout << "vehicle stop" << endl;
    }
    vehicle(int a,int b){
        maxspeed=a;
        weight=b;
        cout << "vehicle constructor called. "<<"maxspeed:"<<maxspeed<<"; "<<"weight"<<weight << endl;
    }
    ~vehicle(){
        cout <<"vehicle destructor called. "  <<"maxspeed:"<<maxspeed<<"; "<<"weight"<<weight<<endl;
    }
};
class bicycle:virtual public vehicle
{
private:
    int height;
public:
    bicycle(int a,int b,int c):vehicle(b,c){
        height=a;
        cout << "bicycle constructor called. ";
        cout << "height:"<<height<<endl;
    }
    ~bicycle(){
        cout << "bicycle destructor called. ";
        cout << "height:"<< height<<endl;
    }
};
class motorcar:virtual public vehicle
{
    private:
    int setnum;
    public:
    motorcar(int a,int b,int c):vehicle(b,c){
        setnum=a;
        cout << "motorcar constructor called. ";
        cout <<"setnum:"<< setnum<<endl;
    }
    ~motorcar(){
        cout << "motorcar destructor called. ";
        cout << "setnum:"<<setnum<<endl;
    }
};
class motorcycle:public bicycle,public motorcar{
    public:
    motorcycle(int a,int b,int c,int d):bicycle(a,c,d),motorcar(b,c,d),vehicle(c,d){
        cout << "motorcycle constructor called"<<endl;
    }
    ~motorcycle(){
        cout << "motorcycle destructor called"<<endl;
    }
};


int main(int argc, char *argv[])
{
    motorcycle m(1, 2, 3, 4);//1表示height，2表示setnum，3表示maxspeed，4表示weight
    m.run();
    m.stop();
    return 0;
}

