#include "BasketReg.h"
#include <algorithm>
#include <iostream>
using namespace std;

BasketReg::BasketReg()
{
    teamNo = 0;
    head = NULL;
}

//COPY CONSTRUCTOR
BasketReg::BasketReg( const BasketReg &systemToCopy )
{
    teamNo = systemToCopy.teamNo;
    head = systemToCopy.head;

}


void BasketReg::operator=( const BasketReg &right )
{
    teamNo =  right.teamNo;
    head = right.head;
}


//FINDTEAM
BasketReg::Node* BasketReg::findTeam(string teamName)
{
    transform(teamName.begin(), teamName.end(), teamName.begin(),::tolower);
    //for(int i = 0; i<teamNo; i++)
    Node* curr = head;
    while(curr!=NULL)
    {
        string name= (curr->t).getName();
        transform(name.begin(), name.end(), name.begin(),::tolower);
        if(teamName == name)
        {
            return curr;
        }
        curr=curr->next;
    }
    curr = NULL;
    return curr;
}


//ADDING A TEAM
void BasketReg::addTeam(string teamName, string teamColor)
{

    if(findTeam(teamName) != NULL && head!=NULL)
        cout << "This Team already exists" <<endl;

    else
    {

        Node* temp =new Node();
        (temp->t).setName(teamName);
        (temp->t).setColor(teamColor);
        temp->next=NULL;
        if(head == NULL)
        {
            head=temp;
            teamNo++;
            return;
        }

        Node* curr = head;
        while(curr->next != NULL)
            curr = curr->next;

        curr->next = temp;
        teamNo++;

    }
}


//REMOVING A TEAM
void BasketReg::removeTeam(string teamName)
{
    if(head==NULL)
    {
        cout<< "There are no registered teams"<<endl;
        return;
    }
    if(findTeam(teamName) == NULL)  cout<< "This team is not found"<<endl;

    else
    {
        Node* tobedeleted = findTeam(teamName);

        if(tobedeleted==head)
        {
            head= tobedeleted->next;
            teamNo--;
            delete tobedeleted;
            return;
        }

        Node* curr = head;
        while(curr->next !=tobedeleted )
        {

            curr=curr->next;
        }

        curr->next = tobedeleted->next;
        delete tobedeleted;
        teamNo--;
    }
}


//displaying the teams
void BasketReg::displayAllTeams()
{

    if(head==NULL) cout<< "--EMPTY--"<< endl;
    else
    {

        Node* curr = head;
        while (curr!= NULL)
        {

            cout<< "Team: " <<(curr->t).getName()<< "   Color: "<<(curr->t).getColor() <<endl;
            curr=curr->next;
        }

    }
}

// until here

void BasketReg::addPlayer( string teamName, string playerName, string playerPosition )
{
    if(findTeam(teamName)!=NULL)
    {
        Node* team = findTeam(teamName);
        (team->t).addPlayer(playerName,playerPosition);
    }
    else cout<< "This Team is not found"<<endl;
}

void BasketReg::removePlayer( string teamName, string playerName)
{
    if(findTeam(teamName)!=NULL)
    {
        Node* team = findTeam(teamName);
        (team->t).removePlayer(playerName);
    }

    else cout<< "This Team is not found"<<endl;
}


void BasketReg::displayTeam( string teamName )
{

    if(findTeam(teamName) == NULL) cout<<" -- EMPTY--"<<endl;
    else
    {
        Node* team = findTeam(teamName);
        cout<< "Team: " <<(team->t).getName()<< "    Color: "<<(team->t).getColor() <<endl;
        (team->t).displayPlayers();
    }
}


void BasketReg::displayPlayer( string playerName )
{
    bool found = false;
    cout<< "Player: "<< playerName<< endl;

    Node* teams = head;
//changes.. next

    while(teams!=NULL)
    {
        if(((teams->t).findPlayer(playerName))!= NULL)
        {
            (teams->t).returnPlayer(playerName);
            found=true;
        }
        teams=teams->next;
    }
    if(!found)
    {
        cout<<"--EMPTY--"<<endl;
    }
}


BasketReg::~BasketReg()
{
    if(head== NULL) return;
    Node* curr=head;
    while(curr!=NULL)
    {
        Node* temp = curr;
        curr=curr->next;
        delete temp;
    }
}

