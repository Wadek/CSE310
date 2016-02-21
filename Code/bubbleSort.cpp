#include <algorithm>
#include <utility>
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

int year = 0;
int endYear = 0;
int indexYear,structYear;
int numberOfYears = 0;
int rangeYear;
struct annual_stats* annualStatsList;
string command;

int getIntFieldValue(team_stats, string);
float getFloatFieldValue(team_stats, string);
string getStringFieldValue(team_stats, string);
string typeOfField(string);
bool compareFieldValues(team_stats*, string, string, int);
bool equalFieldValues(team_stats*, string, int);

void bsort(team_stats* teams, string field, string order) {
    team_stats hold;
    bool compare, isEqual;

    for(int i=0; i<rangeYear-1; i++)
    {
        for(int j=0; j<rangeYear-1-i; j++){
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

void quicksort(team_stats* teams, int l, int r,string field, string order) {
    int i = l, j =r;
    int pivot = getIntFieldValue(teams[(l+r)/ 2], field);
    team_stats hold;
    bool compare;

    while(i <= j) {
        while(getIntFieldValue(teams[i], field) < pivot) {
            i++;
        }
        while(getIntFieldValue(teams[j], field) > pivot) {
            j--;
        }
        if(i <= j){
            hold = teams[i];
            teams[i] = teams[j];
            teams[j] = hold;
            i++;
            j--;
        }
    }
    if(l < i) {
        quicksort(teams,l,j,field,order);
    }
    if(i < r) {
        quicksort(teams,i,r,field,order);
    }
}

void qsort(team_stats* teams, string field, string order) {
    int i = 0;
    int j = rangeYear;
    quicksort(teams,i,j,field,order);
}

void sort_command(annual_stats* annualStatsList, int year, int endYear, string field,string order) {

    int years = (1+(endYear - year));
    rangeYear = years*NO_TEAMS;
    team_stats* teams = new team_stats[rangeYear];

    if(year != endYear) {
        for(int i = 0; i < rangeYear; i++) {
            teams[i] = annualStatsList[i/NO_TEAMS].teams[i%NO_TEAMS];
        }
    } else {
        teams = annualStatsList[year-2010].teams;
    }

    if(command =="qsort") {
        qsort(teams,field,order);
    }
    else {
        bsort(teams, field, order);
    }

    if(order == "max" || order=="min" ||order == "average" || order =="median") {
        string tempOrder = "";
        float average = 0;
        int median = 0;

        if(order =="average") {
            tempOrder = "average";
            float total = 0;
            if (typeOfField(field) == "float") {
                teams[0].team_name;
                for(int i =0; i < rangeYear; i++) {
                    total = total + getFloatFieldValue(teams[i], field);
                }
            } else {
                teams[0].team_name;
                for(int i =0; i < rangeYear; i++) {
                    total = total + getIntFieldValue(teams[i], field);
                }
            }
            for(int i =0; i < rangeYear; i++) {
                total = total + getIntFieldValue(teams[i], field);
            }
            average = total/rangeYear;
            cout<<"\n"<<tempOrder<<" "<<field<<"\n"<<setprecision(4)<<average<<endl;
        }
        else if(order =="median") {
            tempOrder = "median";
            median = rangeYear - rangeYear/2;
            cout<<"\n"<<tempOrder<<" "<<field<<"\n";
            if (typeOfField(field) == "float") {
                cout<< getFloatFieldValue(teams[median], field) <<endl;
            } else if (typeOfField(field) == "string") {
                cout<<teams[median].team_name;
                if(teams[median].team_name != getStringFieldValue(teams[median],field)) {
                    cout<<"\t\t" << getStringFieldValue(teams[median], field);
                }
                cout<<endl;
            } else {
                if(year != endYear) {
                    cout << getIntFieldValue(teams[16], field) <<endl;
                }
                else {
                    cout<< getIntFieldValue(teams[16], field) <<endl;
                }
            }
            cout<<endl;

        }
        else if(order =="max" || order =="min") {
            tempOrder = "min";
            if(order =="max") {
                tempOrder = "max";
                order = "decr";
                bsort(teams, field, order);
            }
            cout<<"\n"<<tempOrder<<" "<<field<<endl;
            if (typeOfField(field) == "float") {
                cout<< getFloatFieldValue(teams[0], field) <<endl;
            } else if (typeOfField(field) == "string") {
                cout<<teams[0].team_name;
                if(teams[0].team_name != getStringFieldValue(teams[0],field)) {
                    cout<<"\t\t" << getStringFieldValue(teams[0], field);
                }
                cout<<endl;
            } else {
                if(year != endYear) {
                    cout<<teams[0].team_name<< "\t\t" << getIntFieldValue(teams[0], field) <<endl;
                }
                else {
                    cout<<teams[0].team_name<< "\t\t" << getIntFieldValue(teams[0], field) <<endl;
                }
            }

        }
    }
    else {
        cout<<"\n"<<"Team"<<"\t\t\t"<<field<<"\t\t";
        if(year != endYear) {cout<<"Year";}
        cout<<"\n"<<endl;
        for (int i = 0; i < rangeYear; i++) {
            if (typeOfField(field) == "float") {
                cout<<teams[i].team_name<< "\t\t";
                float tempFloat = getFloatFieldValue(teams[i], field);
                cout<<setprecision(4)<<tempFloat<<endl;

            } else if (typeOfField(field) == "string") {
                cout<<teams[i].team_name;
                if(teams[i].team_name != getStringFieldValue(teams[i],field)) {
                    cout<<"\t\t" << getStringFieldValue(teams[i], field);
                }
                cout<<endl;
            } else {
                cout<<teams[i].team_name<< "\t\t";
                if(year != endYear) {
                    cout<<getIntFieldValue(teams[i], field)<<"\t\t"<<annualStatsList[0].year<<endl;
                }
                else {
                    cout<< getIntFieldValue(teams[i], field)<<endl;
                }
            }
        }
    }
    cin.clear();
}

//runs a comparison by calling getIntFieldValue, which returns 1,0 depending on which value is greater. returns boolean
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

main() {
    int numberOfCommands;
    string range,field, order;
    cin >> numberOfYears;
    annualStatsList = new annual_stats[numberOfYears];

    for(int i = 0; i < numberOfYears; i++) {
        cin >> structYear;
        annualStatsList[i].year = structYear;
        for(int j = 0; j < NO_TEAMS; j++ ) {

            string team_name = "";
            string top_per_game = "";
            string tempString = "";

            do{
                cin >> tempString;
                team_name += tempString;
                team_name += " ";
            }
            while(tempString.at(tempString.length()-1) != '\"');

            strcpy(annualStatsList[i].teams[j].team_name, team_name.c_str());
            //team_name.erase(remove( team_name.begin(), team_name.end(), '\"' ),team_name.end());
            cin >> annualStatsList[i].teams[j].games;
            cin >> annualStatsList[i].teams[j].pts_per_game;
            cin >> annualStatsList[i].teams[j].total_points;
            cin >> annualStatsList[i].teams[j].scrimmage_plays;
            cin >> annualStatsList[i].teams[j].yds_per_game;
            cin >> annualStatsList[i].teams[j].yds_per_play;
            cin >> annualStatsList[i].teams[j].first_per_game;
            cin >> annualStatsList[i].teams[j].third_md;
            cin >> annualStatsList[i].teams[j].third_att;
            cin >> annualStatsList[i].teams[j].third_pct;
            cin >> annualStatsList[i].teams[j].fourth_md;
            cin >> annualStatsList[i].teams[j].fourth_att;
            cin >> annualStatsList[i].teams[j].fourth_pct;
            cin >> annualStatsList[i].teams[j].penalties;
            cin >> annualStatsList[i].teams[j].pen_yds;

            do{
                cin >> tempString;
                top_per_game += tempString;
                top_per_game += " ";
            }
            while(tempString.at(tempString.length()-1) != '\"');
            top_per_game.erase(remove( top_per_game.begin(), top_per_game.end(), ' ' ));
            strcpy(annualStatsList[i].teams[j].top_per_game, top_per_game.c_str());

            cin >>annualStatsList[i].teams[j].fum;
            cin >>annualStatsList[i].teams[j].lost;
            cin >>annualStatsList[i].teams[j].to;
        }
    }
    cin >> numberOfCommands;

    for(int m = 0;m < numberOfCommands; m++) {
        cin >> command;
        cin >> range;
        if(range != "range") {
            year = endYear = atoi(range.c_str());
        } else {
            cin >> year;
            cin >> endYear;
        }
        cin >> field;
        cin >> order;
        sort_command(annualStatsList,year,endYear,field,order);
        cin.clear();
        cin.ignore();
    }
}
