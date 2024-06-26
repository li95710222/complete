#include <iostream>
#include "fstream"
#include "speechManager.h"
using namespace std;

int main()
{
    SpeechManager SM;
    int choice;
    while (true){
        SM.Show_Menu();
        cout<<"请输入你的选择:"<<endl;
        cin>>choice;
        switch (choice){
            case 0:
                SM.System_Exit();
                break;
            case 1:
                SM.Speech_Start();
                break;
            case 2:
                SM.Show_History();
                break;
            case 3:
                SM.Clear_History();
                break;
            default:
                system("cls");
                break;
        }


    }


    return 0;
}
