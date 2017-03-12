#include<iostream>
#include<string.h>
using namespace std;
class Person{
private:
    char *name;
    int age;
    char *work;
public:
    Person(){cout<<"Person()"<<endl;
    this->work=NULL;
    this->name=NULL;
    }
    Person(char *name){
        cout<<"Person(char *name)"<<endl;
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        this->work=NULL;
    }
    Person(char *name,int age,char *work="none"){
        cout<<"Person(char*,int),name="<<name<<",age="<<age<<endl;

        this->age=age;
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        this->work=new char[strlen(work)+1];
        strcpy(this->work,work);
    }
    Person(const Person &per){
        cout<<"(Person &per)"<<endl;

        this->age=per.age;
        this->name=new char[strlen(per.name)+1];
        strcpy(this->name,per.name);
        this->work=new char[strlen(per.work)+1];
        strcpy(this->work,per.work);
    }
    ~Person()
    {
        cout<<"~Person()"<<endl;
        if(this->name)
        {
            cout<<"name ="<<name<<endl;
            delete this->name;
        }

        if(this->work)
        {
             cout<<"work ="<<work<<endl;
             delete this->work;
        }
    }
    void printfInfo(void) const
    {
        cout<<"name="<<name<<" age="<<age<<" work="<<work<<endl;
    }
    Person& operator=(const Person &p)
    {
        cout<<"operator=(const)"<<endl;
        if(this==&p)
            return *this;
        this->age=p.age;
        if(this->name)
        {
            delete this->name;
        }
        if(this->work)
        {
            delete this->work;
        }
        this->name=new char[strlen(p.name)+1];
        strcpy(this->name,p.name);
        this->work=new char[strlen(p.work)+1];
        strcpy(this->work,p.work);
        return *this;
    }
};

int main()
{
    const Person p1("zhangsan",10);
    cout<<"Person p2=p1"<<endl;
    Person p2=p1;
    Person p3;
    cout<<"p3=p1"<<endl;
    p3=p1;
    cout<<"endl"<<endl;
    p1.printfInfo();
    p2.printfInfo();
    p3.printfInfo();
    return 0;
}
