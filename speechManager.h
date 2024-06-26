#pragma once
#include "iostream"
#include "fstream"
#include "player.h"
#include "vector"

using namespace std;

class SpeechManager{
public:
    static void Show_Menu();
    static void System_Exit();
    void Judge(Player &player);
    void Speech(int turn,int group_num,vector<Player> & players);
    void Speech_Start();
    void Show_History();
    void Clear_History();

};