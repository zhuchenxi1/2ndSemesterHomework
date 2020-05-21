#include <iostream>
#include <iomanip>
using namespace std;


template <class T> class node{

public:
    T data;
    node<T> * next;

};
template <class T> class linkedList
{
public:
    linkedList();
    virtual ~linkedList();
    void insert(T value);
    bool initiate();
    bool isEmpty();
    bool remove(int pos, T &value);
    void print();
    int Length();
private:
    node<T> *head;
    int len;
};
template <class T>
linkedList<T>::linkedList(){
  
}
template <class T>
linkedList<T>::~linkedList(){
    node<T> *p=head;
    node<T> *q;
    while(p!=nullptr){
        q=p->next;
        delete p;
        p=q;
    }
}
template <class T>
void linkedList<T>::insert(T value){
    node<T> *p=new node<T>();
    p->data=value;
    p->next=nullptr;
    node<T> *q= head;
    while(q->next!=nullptr){
        q=q->next;
    }
    q->next=p;
}
template <class T>
bool linkedList<T>::initiate(){
    head=new node<T>();
    head->next=nullptr;
    return true;

}
template <class T>
bool linkedList<T>::isEmpty(){
    if(head->next!=nullptr) return false;
    return true;
}
template <class T>
bool linkedList<T>::remove(int pos,T &value){
    int count=1;
    node<T> *s=head->next;
    if(head->next==nullptr) count=0;
    else{
        while(s!=nullptr){
            count++;
            s=s->next;
        }
    }
    if(pos>count-1){
        cout << "pos > len, failed";
        return false;
    }
    if(pos <=0){
        cout <<"pos <= 0, failed";
        return false;
    }
    else{
        int count=0;
        node<T> *q=head;
        node<T> *p=head->next;
        while(p!=nullptr){
            count++;
            if(count==pos){
                value=p->data;
                q->next=p->next;
                delete p;
                break;
            }
            else{
                p=p->next;
                q=q->next;
            }
        }
        return true;
    }
}
template <class T>
int linkedList<T>::Length(){
    int count=1;
    node<T> *p=head->next;
    if(head->next==nullptr) return -1;
    else{
        while(p!=nullptr){
            count++;
            p=p->next;
        }
        return count-1;

    }
} 
template <class T>
void linkedList<T>::print(){
    if(isEmpty()){
        cout << "Empty" << endl;
        return;
    }
    node<T>* tmp=head->next;
    while(tmp)
    {
        cout <<tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}




int main(int argc, char* argv[])
{
    linkedList<int> L1;
    int n;
    int val;
    //初始化链表
    if(!L1.initiate())
        return 0;

    cin>>n;//输入链表中数据个数
    for(int i=0; i<n; i++) //输入n个数，并插入链表
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length：" << L1.Length() << endl;//输出链表长度
    cout << "data：" ;
    L1.print();//打印链表

    cin>>n;//输入需要删除的数据的位置
    if (L1.remove(n,val))
    {
        //删除位置n的数据，并将删除的数据值放在val中
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length：" << L1.Length()<< endl;//输出链表长度
        cout<< "data：" ;
        L1.print();//打印链表
    }

    return 0;
}






