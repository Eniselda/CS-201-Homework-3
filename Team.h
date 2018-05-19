#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <string>
using namespace std;

class Team
{

            struct PlayerNode {
            string playerName;
            string position;
            PlayerNode* next;
 };
    public:
        Team();
        Team(string , string);
        string getName();
        string getColor();
        void setName(string);
        void setColor(string);
        void addPlayer(string, string);
        void removePlayer(string);
        void returnPlayer(string);
        void displayPlayers();
        PlayerNode* findPlayer(string);



        virtual ~Team();


    protected:

    private:
        string teamName;
        string teamColor;
        //string playerName;
        //string position;


        PlayerNode* head;
        int noPlayers;



};

#endif // TEAM_H
