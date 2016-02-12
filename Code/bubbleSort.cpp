#include <algorithm>
#include <iomanip>
#include<iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include "defns.cc"

using namespace std;

int year, numberOfYears, indexYear;
int whichYear = 0;
struct annual_stats* annualStatsList;

int getIntFieldValue(team_stats, string);
float getFloatFieldValue(team_stats, string);
string getStringFieldValue(team_stats, string);
string typeOfField(string);
bool compareFieldValues(team_stats*, string, string, int);
bool equalFieldValues(team_stats*, string, int);


void bsort(team_stats* teams, string field, string order) {
    team_stats hold;
    bool compare, isEqual;

    for(int i=0; i<NO_TEAMS-1; i++)
    {
        for(int j=0; j<NO_TEAMS-1-i; j++){
            compare = compareFieldValues(teams, field, order, j);
            isEqual = equalFieldValues(teams, field, j);
            if (compare || (isEqual && strcmp(teams[j].team_name, teams[j+1].team_name) < 0)) {
                hold=teams[j];
                teams[j]=teams[j+1];
                teams[j+1]=hold;
            }

        }

    }
}

void bfind(annual_stats* annualStatsList, int year, string field, string order) {
    int list[99];
    string dlist[NO_TEAMS];

    for(int n=0; n < numberOfYears; n++ ) {
        if(annualStatsList[n].year == whichYear) {
            indexYear = n;
        }
        else {
            cout<<"Error: no such year." <<endl;
            break;
        }
    }

    if(field == "team_name"){
        for(int i = 0; i<NO_TEAMS; i++) {
            dlist[i] = annualStatsList[indexYear].teams[i].team_name;
        }
    }

    if(field == "games"){
        for(int i = 0; i<NO_TEAMS; i++) {
            list[i] = annualStatsList[indexYear].teams[i].games;
        }
    }
    if(field == "pts_per_game"){
        for(int i = 0; i<NO_TEAMS; i++) {
            list[i] = annualStatsList[indexYear].teams[i].pts_per_game;
        }
    }
    if(field == "total_points"){
        for(int i = 0; i<NO_TEAMS; i++) {
            list[i] = annualStatsList[indexYear].teams[i].total_points;
        }
    }
    if(field == "scrimmage_plays"){
        for(int i = 0; i<NO_TEAMS; i++) {
            list[i] = annualStatsList[indexYear].teams[i].scrimmage_plays;
        }
    }
    if(field == "yds_per_game"){
        for(int i = 0; i<NO_TEAMS; i++) {
            list[i] = annualStatsList[indexYear].teams[i].yds_per_game;
        }
    }
    if(field == "yds_per_play"){
        for(int i = 0; i<NO_TEAMS; i++) {
            list[i] = annualStatsList[indexYear].teams[i].yds_per_play;
        }
    }
    if(field == "first_per_game"){
        for(int i = 0; i<NO_TEAMS; i++) {
            list[i] = annualStatsList[indexYear].teams[i].games;
        }
    }
    if(field == "third_md"){
        for(int i = 0; i<NO_TEAMS; i++) {
            list[i] = annualStatsList[indexYear].teams[i].third_md;
        }
    }
    if(field == "third_att"){
        for(int i = 0; i<NO_TEAMS; i++) {
            list[i] = annualStatsList[indexYear].teams[i].third_att;
        }
    }
    if(field == "fourth_pct"){
        for(int i = 0; i<NO_TEAMS; i++) {
            list[i] = annualStatsList[indexYear].teams[i].fourth_pct;
        }
    }
    if(field == "penalties"){
        for(int i = 0; i<NO_TEAMS; i++) {
            list[i] = annualStatsList[indexYear].teams[i].penalties;
        }
    }
    if(field == "pen_yds"){
        for(int i = 0; i<NO_TEAMS; i++) {
            list[i] = annualStatsList[indexYear].teams[i].pen_yds;
        }
    }
    if(field == "fum"){
        for(int i = 0; i<NO_TEAMS; i++) {
            list[i] = annualStatsList[indexYear].teams[i].fum;
        }
    }
    if(field == "lost"){
        for(int i = 0; i<NO_TEAMS; i++) {
            list[i] = annualStatsList[indexYear].teams[i].lost;
        }
    }
    if(field == "to"){
        for(int i = 0; i<NO_TEAMS; i++) {
            list[i] = annualStatsList[indexYear].teams[i].to;
        }
    }

    if(order == "max") {
        int hold;
        for(int i=0; i<31; i++)
        {

            for(int j=0; j<31; j++){
                if(list[j]<list[j+1]) {
                    hold=list[j];
                    list[j]=list[j+1];
                    list[j+1]=hold;
                }
            }
        }
        cout<<"Team \t\t\t";
        cout<<"Max ";
        cout<<field<<endl;
        cout<<"\n";
        cout<<annualStatsList[indexYear].teams[1].team_name;
        cout<<"\t";
        cout<<list[1]<<endl;
        cout<<"\n\n";

    }
    if(order =="average") {
        float total = 0;

        for(int i =0; i < NO_TEAMS; i++) {
            total = total+list[i];
        }
        float average = total/NO_TEAMS;
        cout<<"Average ";
        cout<<field;
        cout<<"\n\n";
        cout<< setprecision(4)<<average<<endl;
        cout <<"\n";

    }

    if(order =="min") {
        cout<<"should be min"<<endl;
        cout<<order<<endl;
    }
    cin.clear();
    cin.ignore();
}

int getIntFieldValue(team_stats team, string field) {

    if(field == "games") return team.games;
    if(field == "total_points") return team.total_points;
    if(field == "scrimmage_plays") return team.scrimmage_plays;
    if(field == "third_md") return team.third_md;
    if(field == "third_att") return team.third_att;
    if(field == "third_pct") return team.third_pct;
    if(field == "fourth_md") return team.fourth_md;
    if(field == "fourth_att") return team.fourth_att;
    if(field == "fourth_pct") return team.fourth_pct;
    if(field == "penalties") return team.penalties;
    if(field == "pen_yds") return team.pen_yds;
    if(field == "fum") return team.fum;
    if(field == "lost") return team.lost;
    if(field == "to") return team.to;

    return -1;
}

string getStringFieldValue(team_stats team, string field) {

    if(field == "team_name") return team.team_name;
    if(field == "top_per_game") return team.top_per_game;

    return NULL;
}

string typeOfField(string field) {
    if(field == "pts_per_game" ||
            field == "yds_per_game" ||
            field == "yds_per_play" ||
            field == "first_per_game") {
        return "float";
    } else if (field == "team_name" ||
            field == "top_per_game") {
        return "string";
    }
    return "int";
}

float getFloatFieldValue(team_stats team, string field) {

    if(field == "pts_per_game") return team.pts_per_game;
    if(field == "yds_per_game") return team.yds_per_game;
    if(field == "yds_per_play") return team.yds_per_play;
    if(field == "first_per_game") return team.first_per_game;

    return 0;
}

bool equalFieldValues(team_stats* teams, string field, int j) {
    bool equal;

    if(typeOfField(field) == "string") {
        equal = !getStringFieldValue(teams[j], field).compare(getStringFieldValue(teams[j+1], field));
    } else if(typeOfField(field) == "float") {
        equal = getFloatFieldValue(teams[j], field) == getFloatFieldValue(teams[j+1], field);
    } else {
        equal = getIntFieldValue(teams[j], field) == getIntFieldValue(teams[j+1], field);
    }
    return equal;
}


bool compareFieldValues(team_stats* teams, string field, string order, int j) {
    bool compare;

    if(typeOfField(field) == "string") {
        if (order == "decr") {
            compare = strcmp(teams[j].team_name, teams[j+1].team_name) < 0;
        } else {
            compare = strcmp(teams[j].team_name, teams[j+1].team_name) > 0;
        }
    } else if(typeOfField(field) == "float") {
        if (order == "decr") {
            compare = getFloatFieldValue(teams[j], field) < getFloatFieldValue(teams[j+1], field);
        } else {
            compare = getFloatFieldValue(teams[j], field) > getFloatFieldValue(teams[j+1], field);
        }
    } else {
        if (order == "decr") {
            compare = getIntFieldValue(teams[j], field)<getIntFieldValue(teams[j+1], field);
        } else {
            compare = getIntFieldValue(teams[j], field)>getIntFieldValue(teams[j+1], field);
        }
    }
    return compare;
}

void bsort_command(annual_stats* annualStatsList, int year, string field,string order) {

    // check year, grab correct index, re-write year as index var, error if no year match
    for(int n=0; n < numberOfYears; n++ ) {
        if(annualStatsList[n].year == whichYear) {
            indexYear = n;
        } else {
            cout<<"Error: no such year." <<endl;
            break;
        }
    }

    team_stats* teams = annualStatsList[indexYear].teams;
    bsort(teams, field, order);

    cout<<"\n"<<"Team"<<"\t\t\t\t"<<field<<"\n"<<endl;
    for (int i = 0; i < NO_TEAMS; i++) {
        if (typeOfField(field) == "float") {
            cout<<teams[i].team_name<< "\t\t" << getFloatFieldValue(teams[i], field) <<endl;
        } else if (typeOfField(field) == "string") {
            cout<<teams[i].team_name;
            if(teams[i].team_name != getStringFieldValue(teams[i],field)) {
                cout<<"\t\t" << getStringFieldValue(teams[i], field);
            }
            cout<<endl;
        } else {
            cout<<teams[i].team_name<< "\t\t" << getIntFieldValue(teams[i], field) <<endl;
        }
    }
}

main() {
    int commands;
    string command, range, year1, year2, field, order;


    cin >> numberOfYears;
    annualStatsList = new annual_stats[numberOfYears];

    //takes in file as if it were a user inputting data
    for(int i = 0; i < numberOfYears; i++) {
        cin >> annualStatsList[i].year;
        for(int j = 0; j < NO_TEAMS; j++ ) {

            string tm;
            string team_name = "";
            string top_per_game = "";
            string tempString = "";

            do{
                cin >> tempString;
                team_name += tempString;
                team_name += " ";
            }
            while(tempString.at(tempString.length()-1) != '\"');

            strcpy(annualStatsList->teams[j].team_name, team_name.c_str());
            //team_name.erase(remove( team_name.begin(), team_name.end(), '\"' ),team_name.end());
            cin >> annualStatsList->teams[j].games;
            cin >> annualStatsList->teams[j].pts_per_game;
            cin >> annualStatsList->teams[j].total_points;
            cin >> annualStatsList->teams[j].scrimmage_plays;
            cin >> annualStatsList->teams[j].yds_per_game;
            cin >> annualStatsList->teams[j].yds_per_play;
            cin >> annualStatsList->teams[j].first_per_game;
            cin >> annualStatsList->teams[j].third_md;
            cin >> annualStatsList->teams[j].third_att;
            cin >> annualStatsList->teams[j].third_pct;
            cin >> annualStatsList->teams[j].fourth_md;
            cin >> annualStatsList->teams[j].fourth_att;
            cin >> annualStatsList->teams[j].fourth_pct;
            cin >> annualStatsList->teams[j].penalties;
            cin >> annualStatsList->teams[j].pen_yds;

            do{
                cin >> tempString;
                top_per_game += tempString;
                top_per_game += " ";
            }
            while(tempString.at(tempString.length()-1) != '\"');
            top_per_game.erase(remove( top_per_game.begin(), top_per_game.end(), ' ' ));
            strcpy(annualStatsList->teams[j].top_per_game, top_per_game.c_str());

            cin >>annualStatsList->teams[j].fum;
            cin >>annualStatsList->teams[j].lost;
            cin >>annualStatsList->teams[j].to;
        }
    }
       cin >> commands;

       for(int m = 0;m < commands; m++) {
       cin >> command;
       cin >> range;
       if(range != "range") {
       year = atoi(range.c_str());
       } else {
       cin >> year1;
       cin >> year2;
       }
       cin >> field;
       cin >> order;
       if(command == "bsort") {
       bsort_command(annualStatsList,year,field,order);
       }else if(command == "bfind") {
       bfind(annualStatsList,year,field, order);
       }
       }
}

