#pragma once
#include "iostream"
#include "string"

using namespace std;

class Player{

public:

    Player(int id,string name,float score);
    void Show_Info();

    int m_Id;
    string m_Name;
    float m_Score;


};
