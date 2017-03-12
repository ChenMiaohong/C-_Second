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
        cout<<"Person(char *name,int age)"<<endl;

        this->age=age;
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        this->work=new char[strlen(work)+1];
        strcpy(this->work,work);
    }
    ~Person()
    {
        if(this->name)
            delete this->name;
        if(this->work)
        delete this->work;

    }
    void printfInfo(void)
    {
        cout<<"name="<<name<<" age="<<age<<" work="<<work<<endl;
    }

};
void test_func()
{
    Person Per("chenmiaohong",16);
    Person Per2;
    Person Per3();
    Person *per4=new Person;//�����޲������캯��
    Person *per5=new Person();//�����޲������캯��
    Person *per6=new Person[2];
    Person *per7=new Person("ls",18,"stu");
    Person *per8=new Person("ww",16);

    Per.printfInfo();
    per7->printfInfo();
    per8->printfInfo();
    delete per4;
    delete per5;
    delete []per6;
    delete per7;
    delete per8;

}
int main()
{
    test_func();
}
