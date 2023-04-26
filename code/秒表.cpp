#include <iostream>
#include<iomanip>
#include<Windows.h>
using namespace std;

class clock{
public:
    clock(){};
    void setTime(int H=0,int M=0,int S=0);
    void increase();
    void showTime();
private:
    int hour,minute,second;
};
    void clock::setTime(int H,int M,int S)
    {
        hour=H;minute=M;second=S;
    }
    void clock::showTime()
    {
        if (hour>24||hour<0||minute>60||minute<0||second>60||second<0)
            {cout<<"ÊäÈë´íÎó"<<endl;
        exit(0);}
        else
        {
            cout<<setw(2)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')
            <<minute<<":"<<setw(2)<<setfill('0')<<second<<endl;
        }
    }
    void clock::increase()
    {
        while(1)
        {
            second+=1;
            if(second>=60)
            {
                second-=60;
                minute+=1;
            }
            if(minute>=60)
            {
                minute-=60;
                hour+=1;
            }
            if(hour>=24)
            {
                hour-=24;
            }
            system("cls");
            showTime();
            Sleep(1000);
        }
    }
int main()
{
   clock aclock;
   aclock.setTime(23,59,55);
   aclock.showTime();
   aclock.increase();
    return 0;
}
