#include<iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "defns.cc"

using namespace std;
//std::ifstream input("../2015-game-stats.txt");

int numberOfYears, games, total_points, scrimmage_plays, third_md, third_att, third_pct, fourth_md, fourth_att, fourth_pct, penalties, pen_yds, fum, lost, to;
int whichYear = 0;
float pts_per_game, yds_per_game, first_per_game;
string top_per_game;
string command;
string range;
string year1;
string year2;
string stat;
string order;
int algAmount,year, year3, year4;
int list[99];
char clist[25];
string dlist[32];
int indexYear;
string team_name;
string* field;

struct annual_stats* annualStatsList;


void sortAsc(int list[]) {
    int hold;

    for(int i=0; i<19; i++)
    {
        for(int j=0; j<19; j++){
            if(list[j]>list[j+1]) {
                hold=list[j];
                list[j]=list[j+1];
                list[j+1]=hold;
            }
        }
    }

    cout<<""<<endl;
    cout<<"Teams \t\t\t";
    cout<<"c is limited";
    cout<<"\n"<<endl;

    for(int i=0; i<20; i++)
    {
        cout<<list[i]<<endl;
    }
}

void sortDesc(int list[]) {
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
    cout<<""<<endl;
    cout<<"Teams \t\t\t";
    cout<<"c is limited";
    cout<<"\n"<<endl;

    for(int i=0; i<32; i++)
    {
        cout<<annualStatsList[indexYear].teams[i].team_name;
        cout<<" \t";
        cout<<list[i]<<endl;
    }
    cout<<"\n\n\n"<<endl;
}

void sortAscChar(string dlist[]){
    string hold;
    for(int i=0; i<31; i++)
    {

        for(int j=0; j<31; j++){
            if(dlist[j]>dlist[j+1]) {
                hold=dlist[j];
                dlist[j]=dlist[j+1];
                dlist[j+1]=hold;
            }
        }
    }

    for(int i=0; i<32; i++)
    {
        cout<<dlist[i]<<endl;
    }
}

void sortDescChar(string dlist[]){
    string hold;
    for(int i=0; i<19; i++)
    {

        for(int j=0; j<19; j++){
            if(dlist[j]<dlist[j+1]) {
                hold=dlist[j];
                dlist[j]=dlist[j+1];
                dlist[j+1]=hold;
            }

        }
    }

    for(int i=0; i<20; i++)
    {
        cout<<dlist[i]<<endl;
    }
}

void bfind(annual_stats* annualStatsList ,int year,string order) {

    for(int n=0; n < numberOfYears; n++ ) {
        if(annualStatsList[n].year == whichYear) {
            indexYear = n;
        }
    }

    if(stat == "team_name"){
        for(int i = 0; i<32; i++) {
            dlist[i] = annualStatsList[indexYear].teams[i].team_name;
        }


    }

    if(order == "incr") {
        //          sortAscChar(clist);
    }else {
        //  sortDescChar(clist);
    }

    if(stat == "games"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].games;
        }
    }
    if(stat == "pts_per_game"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].pts_per_game;
        }
    }
    if(stat == "total_points"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].total_points;
        }
    }
    if(stat == "scrimmage_plays"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].scrimmage_plays;
        }
    }
    if(stat == "yds_per_game"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].yds_per_game;
        }
    }
    if(stat == "yds_per_play"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].yds_per_play;
        }
    }
    if(stat == "first_per_game"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].games;
        }
    }
    if(stat == "third_md"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].third_md;
        }
    }
    if(stat == "third_att"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].third_att;
        }
    }
    if(stat == "fourth_pct"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].fourth_pct;
        }
    }
    if(stat == "penalties"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].penalties;
        }
    }
    if(stat == "pen_yds"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].pen_yds;
        }
    }
    /*
       if(stat == "top_per_game"){

       for(int i = 0; i<32; i++) {
       for(int j = 0; j < 6;j++) {
       clist[i][j] = annualStatsList[indexYear].teams[i].top_per_game;
       }
       }
//bsortChar(clist);
}*/
if(stat == "fum"){
    for(int i = 0; i<32; i++) {
        list[i] = annualStatsList[indexYear].teams[i].fum;
    }
}
if(stat == "lost"){
    for(int i = 0; i<32; i++) {
        list[i] = annualStatsList[indexYear].teams[i].lost;
    }
}
if(stat == "to"){
    for(int i = 0; i<32; i++) {
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
    cout<<annualStatsList[indexYear].teams[1].team_name;
    cout<<"\t";
    cout<<list[1]<<endl;
    cout<<"\n\n";

}

if(order =="average") {
    int total;
    for(int i =0; i < 31; i++) {
        list[i]+total;
    }
    int average = total/32;
    cout<<"average: \t";
    cout<<average<<endl;
    cout<<"\n\n";

}

if(order =="min") {
    cout<<"should be min"<<endl;
    cout<<order<<endl;
}
cin.clear();
cin.ignore();
}


void bsort(annual_stats* annualStatsList ,int year,string order) {
    // check year, grab correct index, re-write year as index var

    for(int n=0; n < numberOfYears; n++ ) {
        if(annualStatsList[n].year == whichYear) {
            indexYear = n;
        }
    }

    if(stat == "team_name"){
        for(int i = 0; i<32; i++) {
            dlist[i] = annualStatsList[indexYear].teams[i].team_name;
        }

        if(order == "incr") {
            sortAscChar(dlist);
        }else {
            sortDescChar(dlist);
        }

    }

    if(order == "incr") {
        //          sortAscChar(clist);
    }else {
        //  sortDescChar(clist);
    }

    if(stat == "games"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].games;
        }
        if(order == "incr") {
            sortAsc(list);
        }else {
            sortDesc(list);
        }
    }
    if(stat == "pts_per_game"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].pts_per_game;
        }
        if(order == "incr") {
            sortAsc(list);
        }else {
            sortDesc(list);
        }
    }
    if(stat == "total_points"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].total_points;
        }
        if(order == "incr") {
            sortAsc(list);
        }else {
            sortDesc(list);
        }
    }
    if(stat == "scrimmage_plays"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].scrimmage_plays;
        }
        if(order == "incr") {
            sortAsc(list);
        }else {
            sortDesc(list);
        }
    }
    if(stat == "yds_per_game"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].yds_per_game;
        }
        if(order == "incr") {
            sortAsc(list);
        }else {
            sortDesc(list);
        }
    }
    if(stat == "yds_per_play"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].yds_per_play;
        }
        if(order == "incr") {
            sortAsc(list);
        }else {
            sortDesc(list);
        }
    }
    if(stat == "first_per_game"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].games;
        }
        if(order == "incr") {
            sortAsc(list);
        }else {
            sortDesc(list);
        }
    }
    if(stat == "third_md"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].third_md;
        }
        if(order == "incr") {
            sortAsc(list);
        }else {
            sortDesc(list);
        }
    }
    if(stat == "third_att"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].third_att;
        }
        if(order == "incr") {
            sortAsc(list);
        }else {
            sortDesc(list);
        }
    }
    if(stat == "fourth_pct"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].fourth_pct;
        }
        if(order == "incr") {
            sortAsc(list);
        }else {
            sortDesc(list);
        }
    }
    if(stat == "penalties"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].penalties;
        }
        if(order == "incr") {
            sortAsc(list);
        }else {
            sortDesc(list);
        }
    }
    if(stat == "pen_yds"){
        for(int i = 0; i<32; i++) {
            list[i] = annualStatsList[indexYear].teams[i].pen_yds;
        }
        if(order == "incr") {
            sortAsc(list);
        }else {
            sortDesc(list);
        }
    }
    /*
       if(stat == "top_per_game"){

       for(int i = 0; i<32; i++) {
       for(int j = 0; j < 6;j++) {
       clist[i][j] = annualStatsList[indexYear].teams[i].top_per_game;
       }
       }
//bsortChar(clist);
}*/
if(stat == "fum"){
    for(int i = 0; i<32; i++) {
        list[i] = annualStatsList[indexYear].teams[i].fum;
    }
    if(order == "incr") {
        sortAsc(list);
    }else {
        sortDesc(list);
    }
}
if(stat == "lost"){
    for(int i = 0; i<32; i++) {
        list[i] = annualStatsList[indexYear].teams[i].lost;
    }
    if(order == "incr") {
        sortAsc(list);
    }else {
        sortDesc(list);
    }
}
if(stat == "to"){
    for(int i = 0; i<32; i++) {
        list[i] = annualStatsList[indexYear].teams[i].to;
    }
    if(order == "incr") {
        sortAsc(list);
    }else {
        sortDesc(list);
    }
}
cin.clear();
cin.ignore();
}


// main execution
main() {
    cin >> numberOfYears;
    annualStatsList = new annual_stats[numberOfYears];
    int temp;
    string tempString;
    float tempFloat;

    for(int i = 0; i < numberOfYears; i++) {
        cin >> whichYear;
        annualStatsList[i].year = whichYear;

        for(int j = 0; j < 32; j++ ) {
            cin.ignore();
            getline(cin, team_name, '\t');
            strcpy(annualStatsList[i].teams[j].team_name, team_name.c_str());

            cin.ignore();
            int games;
            cin >> games;
            annualStatsList->teams[j].games = temp;

            cin.ignore();
            cin >> pts_per_game;
            annualStatsList->teams[j].pts_per_game = temp;

            cin >> total_points;
            annualStatsList->teams[j].total_points = temp;

            cin >> scrimmage_plays;
            annualStatsList->teams[j].scrimmage_plays = temp;

            //cin >> yds_per_game;
            cin >> tempFloat;
            annualStatsList->teams[j].yds_per_game = tempFloat;

            //cin >> yds_per_play;
            cin >> tempFloat;
            annualStatsList->teams[j].yds_per_play= tempFloat;

            cin >> first_per_game;
            annualStatsList->teams[j].first_per_game = temp;

            cin >> third_md;
            annualStatsList->teams[j].third_md = temp;

            cin >> third_att;
            annualStatsList->teams[j].third_att = temp;

            cin >> third_pct;
            annualStatsList->teams[j].third_pct = temp;

            cin >> fourth_md;
            annualStatsList->teams[j].fourth_md = temp;

            //cin >> fourth_att;
            cin >> temp;
            annualStatsList->teams[j].fourth_att = temp;


            //cin >> fourth_pct;
            cin >> temp;
            annualStatsList->teams[j].fourth_pct = temp;

            //cin >> penalties;
            cin >> temp;
            annualStatsList->teams[j].penalties = temp;

            cin >> pen_yds;
            annualStatsList->teams[j].pen_yds;

            cin.ignore();
            getline(cin, top_per_game, '\t');
            strcpy(annualStatsList[i].teams[j].top_per_game, top_per_game.c_str());

            //cin >> fum;
            cin >> temp;
            annualStatsList->teams[j].fum = temp;

            cin >> lost;
            annualStatsList->teams[j].lost = temp;

            cin >> to;
            annualStatsList->teams[j].to = temp;
            cin.ignore();
        }

        cin >> algAmount;
        //deicdes how to treat commands at end of file
        for(int m = 0;m < algAmount; m++) {
            cin >> command;
            //&field = command;
            cin >> range;
            if(range != "range") {
                year = std::atoi(range.c_str());
            } else {
                cin >> year1;
                cin >> year2;
                year3 = std::atoi(year1.c_str());
                year4 = std::atoi(year2.c_str());

            }
            cin >> stat;
            cin >> order;
            if(command[1] == 's') {
                bsort(annualStatsList,year,order);
            }else if(command[1] == 'f') {
                bfind(annualStatsList,year, order);
            }
        }
    }
}
