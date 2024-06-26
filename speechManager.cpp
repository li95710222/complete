#include "iostream"
#include "fstream"
#include "speechManager.h"
#include "vector"
#include "player.h"
#include "random"
#include "deque"
#include "algorithm"
#include "numeric"
#include "fstream"
#include "sstream"
#define PLAYER_NUM 12
#define JUDGE_NUM 10
#define WIN_NUM 3
using namespace std;

void SpeechManager::Show_Menu(){
    ifstream file("title.txt",ios::in);
    string str;
    if(file.is_open()){
        while(getline(file,str)){
            cout<<str<<endl;
        }
    }
}

void SpeechManager::System_Exit()
{
    cout<<"欢迎下次使用"<<endl;
    system("pause");
    exit(0);
}

void SpeechManager::Judge(Player &player)
{
    deque<int> scores;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0,100);

    for (int i = 0; i < JUDGE_NUM; ++i)
    {
        scores.push_back(dis(gen));
    }
    sort(scores.begin(),scores.end());
    scores.pop_front();
    scores.pop_back();
    float total=accumulate(scores.begin(),scores.end(),0);
    player.m_Score=total/(JUDGE_NUM-2);
    player.m_Score=round(player.m_Score*100)/100.0;
}

bool Player_Compare(Player player1,Player player2){
    return player1.m_Score>player2.m_Score;
};

void SpeechManager::Speech(int turn,int group_num,vector<Player> & players){
    cout<<"第<<"<<turn<<">>轮比赛选手正在抽签"<<endl;
    cout<<"----------------------------"<<endl;
    random_device rd;
    mt19937 gen(rd());
    shuffle(players.begin(),players.end(),gen);
    cout<<"抽签后演讲顺序如下"<<endl;
    for(Player player:players)
    {
        cout<<player.m_Id<<" ";
    }
    cout<<endl;
    cout<<"----------------------------"<<endl;
    system("pause");

    cout<<"-----------第"<<turn<<"轮比赛正式开始-----------"<<endl;
    for(Player &player:players)
    {
        Judge(player);
    }

    int group_player_num=players.size()/group_num;
    vector<Player> winner;
    for (int i = 0; i < group_num; ++i)
    {
        cout<<"第"<<i+1<<"小组比赛名次："<<endl;
        auto begin=players.begin()+group_player_num*i;
        auto end=players.begin()+group_player_num*(i+1);
        auto winner_end=begin+WIN_NUM;

        sort(begin,end,Player_Compare);
        for_each(begin,end,[](Player &player){player.Show_Info();});

        copy(begin,winner_end, back_inserter(winner));
        cout<<endl;
    }

    cout<<"-----------第"<<turn<<"轮比赛结束-----------"<<endl;

    players.swap(winner);
    winner.clear();

    cout<<"-----------第"<<turn<<"轮晋级选手信息如下-----------"<<endl;
    for(Player &player:players)
    {
        player.Show_Info();
    }
    system("pause");
    system("cls");

}

void Result_Save(vector<Player> &players){
    ofstream ofs("score.csv",ios::app);
    if(ofs.is_open()){
        for(Player &player:players){
            ofs<<player.m_Id<<","<<player.m_Score<<",";
        }
        ofs<<endl;
        ofs.close();
    }
    else{
        cout<<"文件打开失败，无法写入"<<endl;

    }


}

void SpeechManager::Speech_Start()
{
    vector<Player> players;
    for (int i = 0; i < PLAYER_NUM; ++i)
    {
        string name={"选手"};
        name.append(1,'A'+i);
        Player player(10001+i,name,0);
        players.push_back(player);
    }

    Speech(1,2,players);
    Speech(2,1,players);

    Result_Save(players);

}


void SpeechManager::Show_History()
{
    ifstream ifs("score.csv",ios::in);
    string line;
    int i=1;
    const vector<string> flag={"冠军","亚军","季军"};
    while(getline(ifs,line)){
        cout<<"第"<<i<<"届 ";
        i++;
        int j=0;
        stringstream ss(line);
        string item;
        while (getline(ss,item,',')){
            cout<<flag[j]<<"编号: "<<item<<" ";
            getline(ss,item,',');
            cout<<"得分: "<<item<<" ";
            j++;
        }
        cout<<endl;
    }
    ifs.close();
    system("pause");
    system("cls");
}

void SpeechManager::Clear_History()
{
    cout<<"请确认是否清除全部记录，确认请输入1:"<<endl;
    int choice;
    cin>>choice;
    if(choice==1){
        ofstream ofs("score.csv",ios::out);
        if(ofs.is_open()){
            ofs.close();
            cout<<"清除成功"<<endl;
        }
        else{
            cout<<"文件打开失败，无法清除"<<endl;
        }

    }
    system("pause");
    system("cls");

}