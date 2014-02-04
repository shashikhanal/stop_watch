/************************************************************************
 * @author    Shashi Khanal <evergreenshashi@gmail.com>
 * @file      stop_watch.cpp
 * @includes  conioLinux.h (Modified the code from @nootanghimire 's Git repo)
 *
 * @license   Creative Commons: Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)
 * @license   http://creativecommons.org/licenses/by-sa/4.0/deed.en_US
 *
 * @desc      A Simple Stopwatch.
 *
 * MAY NOT RUN IN TURBO C/C++ .
 * TURBO C/C++ NOT RECOMMENDED.
 */

#include <iostream>
#define conioOnLinux
#include "conioLinux.h" //include this to run in Linux (gcc/g++ compiler)
using namespace std;

time_t si;
int pi;

class watch {
private:
    int h=0, m=0, s=1; //variable for hour, minute and second
public:
    watch(){}
        int start(){
        s=1;m=0;h=0;
        system("clear");
        int diff,temp;
        si = time (NULL);//initial time in second
        cout<<"Press ctrl+c to cancel"<<endl;
        cout<<endl;
        cout<<"                                  ";
        cout<<"00"<<":"<<"00"<<":"<<"00"<<endl;

        while(1){
            int i=1;
            while(1){
                    time_t s[i];
                    s[i]=time(NULL);    //receive system time
                if((s[i]-si)!=0)        //continues in this infinite loop until the time difference is zero
                    {temp=s[i];break;}  //when difference is >0 current time is strored in var 'temp'
            }//while
            system("clear");
            cout<<"Press ctrl+c to cancel"<<endl;
            cout<<endl;
            cout<<"                                  ";
            si=temp;
            //displays the time in HH:MM:SS format
            if(s<10 & m<10 & h<10)
                cout<<"0"<<h<<":"<<"0"<<m<<":"<<"0"<<s<<endl;
            else if (s>=10 & m<10 & h<10)
                cout<<"0"<<h<<":"<<"0"<<m<<":"<<s<<endl;
            else if (s<10 & m>=10 & h<10)
                cout<<"0"<<h<<":"<<m<<":"<<"0"<<s<<endl;
            else if (s<10 & m<10 & h>=10)
                cout<<h<<":"<<"0"<<m<<":"<<"0"<<s<<endl;
            else if (s>=10 & m>=10 & h<10)
                cout<<"0"<<h<<":"<<m<<":"<<s<<endl;
            else if (s<10 & m>=10 & h>=10)
                cout<<h<<":"<<m<<":"<<"0"<<s<<endl;
            else if (s>=10 & m<10 & h>=10)
                cout<<h<<":"<<"0"<<m<<":"<<s<<endl;
            else if (s>=10 & m>=10 & h>=10)
                cout<<h<<":"<<m<<":"<<s<<endl;
            s++;//increments second
            i++;//increments value of 'i' for while loop
            if(s>=60)
                {m+=1;s-=60;}       //changing second into minute (after 60 seconds)
            if(m>=60)
                {h+=1;m-=60;}       //changing minute into hour (after 60 minutes)
        //delay(100);
    }//while
}//start
    int pause(){
        time_t s2;
        s2 = time (NULL);
        cout<<"Diff is: "<<s2-si<<endl;
    }

};

int main() {
    watch on;
    char ch;
    while(1){
            //Selection menu
    cout<<"Press S to start"<<endl;
    cout<<"Press P to pause"<<endl;
    cout<<"Press R to reset"<<endl;
    cout<<"Press C to cancel"<<endl;
    cout<<" "<<endl;
    ch=getch();//character is received from user
  switch(ch){
        case 's':
            on.start();
            break;
        /*case 'p':
            on.pause();
            break;
        case 'r':
            //on.reset();
            break;
         */
         case 'c':
             //displays this message when user wishes to cancel
            cout<<"Have a good day!!!"<<endl;
            exit(0);
        default:
            cout<<"First Press 's' to start !"<<endl;
            si = time (NULL);
            //This displays the error message and holds it for 3 second.
            while(1){
                    int i;
                    time_t s[i];
                    s[i]=time(NULL);
                if((s[i]-si)>2)
                    break;
            }
            system("clear");//clears the screen, substitute for clrscr() in Windows
}//switch
}//while
    return 0;
    }//main body
