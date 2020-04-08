#include <iostream>
#include <vector>
using namespace std;
class Book
{
//请在此处补充Book类的定义
private:
    unsigned int m_ID;
    string m_Name;
    string m_Introduction;
    string m_Author;
    string m_Date;
    unsigned int m_Page;
public:
    Book(){
        m_ID=0;
    }
    virtual ~Book(){
        
    }
    Book(const Book& other){
        m_ID=other.m_ID;
        m_Name=other.m_Name;
        m_Introduction=other.m_Introduction;
        m_Author=other.m_Author;
        m_Date=other.m_Date;
        m_Page=other.m_Page;
    }
    
    int GetID();
    string GetName();
    string GetIntro();
    string GetAuthor();
    string GetDate();
    unsigned int GetPage();
    void SetID(int a);
    void SetName(string a);
    void SetIntroduction(string a);
    void SetAuthor(string a);
    void SetDate(string a);
    void SetPage(unsigned int a);

};
//请在此处补充Book类的成员函数实现
int Book::GetID(){
    return m_ID;
}
string Book::GetName(){
    return m_Name;
}
string Book::GetIntro(){
    return m_Introduction;
}
string Book::GetAuthor(){
    return m_Author;
}
string Book::GetDate(){
    return m_Date;
}
unsigned int Book::GetPage(){
    return m_Page;
}
void Book::SetID(int a){
    m_ID=a;
}
void Book::SetName(string a){
    m_Name=a;
}
void Book::SetIntroduction(string a){
    m_Introduction=a;
}
void Book::SetAuthor(string a){
    m_Author=a;
}
void Book::SetDate(string a){
    m_Date=a;
}
void Book::SetPage(unsigned int a){
    m_Page=a;
}

class Store
{
//请在此处补充Store类的定义
private:
    vector <Book> m_Books;
public:
    unsigned int GetCount();
    Store(){
        cout << "Store default constructor called!" << endl;
    }
    Store(int n){
        m_Books.resize(n);
        cout << "Store constructor with (int n) called!"<<endl;
    }
    virtual ~Store(){
        cout <<"Store destructor called!"<<endl;
    }
    Store(const Store& other){
        m_Books=other.m_Books;
        cout << "Store copy constructor called!"<<endl;
    }
    void in(Book &b);
    void out(string name);
    Book findbyID(int ID);
    Book findbyName(string name);
    void printList();

};
//请在此处补充Store类的成员函数实现
unsigned int Store::GetCount(){
    return m_Books.size();
}
void Store::in(Book &b){
    m_Books.push_back(b);
}
void Store::out(string name){
    vector<Book>::iterator p;
    p=m_Books.begin();

    for( ; p!= m_Books.end(); p++ ){
        if(p->GetName()==name){
            m_Books.erase(p);
            break;
        }
    }
}
Book Store::findbyID(int ID){
    int temp=-1;
    Book none;
    Book is;
    for(int i=0;i<m_Books.size();i++){
        if(m_Books[i].GetID()==ID){
            temp=i;
            break;
        }
    }
    if(temp==-1) return none;
    else{
        is=m_Books[temp];
        return is;
    }
}
Book Store::findbyName(string name){
    int temp=-1;
    Book none;
    Book is;
    for(int i=0;i<m_Books.size();i++){
        if(m_Books[i].GetName()==name){
            temp=i;
            break;
        }
    }
    if(temp==-1) return none;
    else{
        is=m_Books[temp];
        return is;
    }
}
void Store::printList(){
    cout << "There are totally " << m_Books.size()<< " Books:" << endl;
    for(int i=0;i<m_Books.size();i++){
        cout << "ID=";
        cout << m_Books[i].GetID() << ";  ";
        cout << "Name:";
        cout <<m_Books[i].GetName() <<";  ";
        cout << "Author:";
        cout << m_Books[i].GetAuthor() <<";  ";
        cout << "Date:";
        cout << m_Books[i].GetDate()<< ";" <<endl;
        
        
    }
}

int main()
{
    Store s;
    Book b1,b2,b3;
    b1.SetID(1);
    b1.SetName("C++ 语言程序设计(第4版)");
    b1.SetAuthor("郑莉");
    b1.SetIntroduction("介绍C++及面向对象的知识");
    b1.SetDate("201007");
    b1.SetPage(529);
    b2.SetID(2);
    b2.SetName("离散数学");
    b2.SetAuthor("左孝凌");
    b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论");
    b2.SetDate("198209");
    b2.SetPage(305);
    b3.SetID(3);
    b3.SetName("c程序设计");
    b3.SetAuthor("谭浩强");
    b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等");
    b3.SetDate("201006");
    b3.SetPage(355);

    cout<<"第一本书入库"<<endl;
    s.in(b1);
    cout<<"第二本书入库"<<endl;
    s.in(b2);
    cout<<"第三本书入库"<<endl;
    s.in(b3);
    cout <<"现有库存书籍数量："<<s.GetCount() << endl;
    cout <<"查找并出库图书：离散数学" << endl;
    Book tmpbook=s.findbyName("离散数学");
    if(tmpbook.GetID()!=0)
    {
        s.out("离散数学");
        cout <<"离散数学 已成功出库" << endl;
    }
    else
        cout<<"没有找到name为离散数学的书"<<endl;
    cout <<"现有库存书籍数量："<<s.GetCount() << endl;

    cout <<"查找图书 ID：3" << endl;
    tmpbook=s.findbyID(3);
    if(tmpbook.GetID()!=0)
        cout<<"找到ID为"<<3<<"的书，书名："<<tmpbook.GetName()<<endl;
    else
        cout<<"没有找到ID为"<<3<<"的书"<<endl;

    cout <<"查找图书 name：离散数学" << endl;
    tmpbook=s.findbyName("离散数学");
    if(tmpbook.GetID()!=0)
        cout<<"找到name为离散数学的书，ID："<<tmpbook.GetID()<<endl;
    else
        cout<<"没有找到name为离散数学的书"<<endl;

    cout<<"输出所有库存图书的信息"<<endl;
    s.printList();
    cout<<"程序运行结束"<<endl;
    return 0;
}


