#include<iostream>
#include<string.h>
using namespace std;
class Person{
private:
    char *name;
    int age;
    char *work;
    static int cnt;
public:
    static int getCount(){
        return cnt;
    }
    Person(){cout<<"Person()"<<endl;
    this->work=NULL;
    this->name=NULL;
    cnt++;
    }
    Person(char *name){
        cout<<"Person(char *name)"<<endl;
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        this->work=NULL;
        cnt++;
    }
    Person(char *name,int age,char *work="none"){
        cout<<"Person(char*,int),name="<<name<<",age="<<age<<endl;

        this->age=age;
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        this->work=new char[strlen(work)+1];
        strcpy(this->work,work);
        cnt++;
    }
    Person(Person &per){
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
    void printfInfo(void)
    {
        cout<<"name="<<name<<" age="<<age<<" work="<<work<<endl;
    }

};
class Student{
private:
    Person father;
    Person mother;
    int stu_id;
public :
    Student()
    {
        cout<<"Student()"<<endl;

    }
    ~Student()
    {
        cout<<"~Student()"<<endl;
    }
    Student(int id,char *father,char *mother,int father_age=40,int mother_age=39):father(father,father_age),mother(mother,mother_age)
    {
        cout<<"Student(int id,char *father,char *mother,int father_age=40,int mother_age=39)"<<endl;

    }

};
int Person::cnt=0;
int main()
{
    Person per1;
    Person per2;
    Person per3;
    Person per4;
    Person *per5=new Person[10];
    delete per5;
    cout<<"Person num "<<Person::getCount()<<endl;
    return 0;
}
