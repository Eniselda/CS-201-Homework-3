#include "Team.h"
#include <string>
#include <algorithm>
using namespace std;

Team::Team()
{
    head = NULL;
    noPlayers= 0;
}
Team::Team(string name, string color)
{
    teamName= name;
    teamColor = color;
    noPlayers= 0;
    head = NULL;
}


Team::PlayerNode* Team::findPlayer(string playerName)
{
    transform(playerName.begin(), playerName.end(), playerName.begin(),::tolower);
    PlayerNode* curr = head;
    while(curr!=NULL)
    {

        string name= curr->playerName;
        transform(name.begin(), name.end(), name.begin(),::tolower);
        if(playerName == name) return curr;
        curr=curr->next;
    }
    curr=NULL;
    return curr;
}



void Team::addPlayer(string playerName, string position)
{
    if(findPlayer(playerName) != NULL && head!=NULL)
        cout << "This Player already exists" <<endl;
    else
    {

        PlayerNode* temp =new PlayerNode();
        temp->playerName = playerName;
        temp->position = position;
        temp->next=NULL;
        if(head == NULL)
        {
            head=temp;
            noPlayers++;
            return;
        }

        PlayerNode* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }

        curr->next = temp;
        noPlayers++;

    }
}


//REMOVE PLAYER
void Team:: removePlayer(string playerName)
{
    if(head == NULL)
    {
        cout<< "There are no players to remove from"<<endl;
        return;
    }
    if(findPlayer(playerName) == NULL)  cout<< "This player is not found"<<endl;
    else
    {

        PlayerNode* tobedeleted = findPlayer(playerName);
        if(tobedeleted!=NULL)
        {
            PlayerNode* curr = head;

            if(tobedeleted==head)
            {
                head= tobedeleted->next;
                delete tobedeleted;
                noPlayers--;
                return;
            }

            while(curr->next !=tobedeleted )
            {

                curr=curr->next;
            }

            curr->next = tobedeleted->next;
            delete tobedeleted;
            noPlayers--;
        }
    }
}


//Prints one player
void Team::returnPlayer(string playerName)
{

    if(head==NULL) cout<< "--EMPTY PLAYERS LIST--"<< endl;
    else
    {
        PlayerNode* player= findPlayer(playerName);

        cout << "  Position: " <<player->position <<"  " << "Team: "<< teamName<< "  " << "Team Color: "<< teamColor <<endl;
    }
}

//Prints all players
void Team::displayPlayers()
{
    if(head==NULL) cout<< "--EMPTY LIST OF PLAYERS--"<< endl;
    else
    {

        PlayerNode* curr = head;
        while (curr!= NULL)
        {

            cout<< curr->playerName << "   "<< curr->position <<endl;
            curr=curr->next;
        }

    }
}


string Team::getName()
{
    return teamName;
}

string Team::getColor()
{
    return teamColor;
}

void Team::setColor(string color)
{
    teamColor = color;
}

void Team::setName(string name)
{
    teamName = name;
}


Team:: ~Team()
{
    if(head== NULL) return;
    PlayerNode* curr=head;
    while(curr!=NULL)
    {
        PlayerNode*temp = curr;
        curr=curr->next;
        delete temp;
}
}
