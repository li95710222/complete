#include "player.h"
#include "iostream"

using namespace std;

Player::Player(int id,string name,float score)
{
    this->m_Id=id;
    this->m_Name=name;
    this->m_Score=score;
}

void Player::Show_Info()
{
    cout<<"编号："<<this->m_Id;
    cout<<"\t姓名："<<this->m_Name;
    cout<<"\t成绩："<<this->m_Score<<endl;
}