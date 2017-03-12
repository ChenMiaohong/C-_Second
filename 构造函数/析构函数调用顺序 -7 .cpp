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
int main()
{
    Student s(10,"cath","lily");
    return 0;
}
