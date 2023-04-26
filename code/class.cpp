#include <iostream>
#include<string>
using namespace  std;

class  Human{

    private:


    public:
        int id;
        char _name[20];
        string  _des;
        void setId(int id_){
           id=id_;
        }
        void setName(char *name_);
        void setDes(string des_);


};

void Human::setName(char *name_){
    strcpy(_name,name_);
}

void Human::setDes(string des_) {
    _des=des_;
}


void ReferCall(int x, int& y){
    x=1;
    y=1;
    cout<<"ReferCall x:"<<x<<"  y:"<<y<<endl;
}

int main() {

    int x=0;
    int y=0;
    ReferCall(x,y);
    cout<<"main x:"<<x<<"  y:"<<y<<endl;

    Human tom;
    tom.setId(10);
    cout<<"tom id: "<<tom.id<<endl;
    char str_name[]="Tom";
    tom.setName(str_name);
    cout<<"Tom name:"<<tom._name<<endl;
    string str_description="tom is a boy";
    tom.setDes(str_description);
    cout<<"Tom des:"<<tom._des<<endl;



    return 0;
}
