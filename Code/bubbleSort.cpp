#include <algorithm>
#include <iomanip>
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

int numberOfYears, games, total_points, scrimmage_plays;
int third_md, third_att, third_pct, fourth_md, fourth_att, fourth_pct, penalties, pen_yds, fum, lost, to;
int whichYear = 0;
float pts_per_game, yds_per_game, first_per_game;
string top_per_game;
string command;
string range;
string year1;
string year2;
string field;
string order;
int lines,year, year3, year4;
int list[99];
char clist[25];
string dlist[NO_TEAMS];
int indexYear;
string team_name;
struct annual_stats* annualStatsList;

int getIntFieldValue(team_stats, string);
float getFloatFieldValue(team_stats, string);
string getStringFieldValue(team_stats, string);
string typeOfField(string);
bool compareFieldValues(team_stats*, string, string, int, int);
bool equalFieldValues(team_stats*, string, int, int);

//sorts teams alphabetically, by name
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
}

//sorts teams alphabetically, by name, z first
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
}

void sortAsc(int list[]) {
	int hold;

	for(int i=0; i<NO_TEAMS-1; i++)
	{
		for(int j=0; j<NO_TEAMS-1-i; j++){
			if(list[j]>list[j+1]) {
				hold=list[j];
				list[j]=list[j+1];
				list[j+1]=hold;
			}
		}
	}

	cout<<""<<endl;
	cout<<"Teams \t\t\t";
	cout<<"\n"<<endl;

	for(int i=0; i<NO_TEAMS; i++)
	{
		cout<<"\t\t\t";
		if(strlen(annualStatsList[indexYear].teams[i].team_name) < 16) {
			cout<<"\t";
		}
		cout<<list[i]<<endl;
		cout<<""<<endl;
	}
}

void bsort(team_stats* teams, string field, string order) {
	team_stats hold;
	bool compare, isEqual;

	for(int i=0; i<NO_TEAMS-1; i++)
	{
		for(int j=0; j<NO_TEAMS-1-i; j++){
			compare = compareFieldValues(teams, field, order, j, j+1); 
			isEqual = equalFieldValues(teams, field, j, j+1);
			if (compare || (isEqual && strcmp(teams[j].team_name, teams[j+1].team_name) < 0)) {
				hold=teams[j];
				teams[j]=teams[j+1];
				teams[j+1]=hold;
			} 

		}

	}
}

//bubble sort in descending order
void sortDesc(int list[]) {
	int hold;

	for(int i=0; i<NO_TEAMS-1; i++)
	{
		for(int j=0; j<NO_TEAMS-1-i; j++){
			if(list[j]<list[j+1] || (list[j] == list[j+1] && strcmp(annualStatsList[indexYear].teams[j].team_name, annualStatsList[indexYear].teams[j+1].team_name) > 0)) {

				hold=list[j];
				list[j]=list[j+1];
				list[j+1]=hold;
			}
		}

	}

	cout<<""<<endl;
	cout<<"Teams \t\t\t\t";
	cout<<field;
	cout<<"\n"<<endl;

	for(int i=0; i<NO_TEAMS; i++)
	{
		cout<<annualStatsList[indexYear].teams[i].team_name;
		cout<<"\t\t";
		if(strlen(annualStatsList[indexYear].teams[i].team_name) < 16) {
			cout<<"\t";
		}
		cout<<list[i]<<endl;
	}
	cout<<"\n"<<endl;
}


void bfind(annual_stats* annualStatsList ,int year,string order) {

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

	if(order == "incr") {
		//          sortAscChar(clist);
	}else {
		//  sortDescChar(clist);
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
	/*
	   if(field == "top_per_game"){

	   for(int i = 0; i<NO_TEAMS; i++) {
	   for(int j = 0; j < 6;j++) {
	   clist[i][j] = annualStatsList[indexYear].teams[i].top_per_game;
	   }
	   }
//bsortChar(clist);
}*/
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

bool equalFieldValues(team_stats* teams, string field, int j, int k) {
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


bool compareFieldValues(team_stats* teams, string field, string order, int j, int k) {
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
	cin >> numberOfYears;
	annualStatsList = new annual_stats[numberOfYears];

	//takes in file as if it were a user inputting data
	for(int i = 0; i < numberOfYears; i++) {
		cin >> whichYear;
		annualStatsList[i].year = whichYear;

		for(int j = 0; j < NO_TEAMS; j++ ) {
			cin.ignore();
			getline(cin, team_name, '\t');
			team_name.erase(remove( team_name.begin(), team_name.end(), '\"' ),team_name.end());
			strcpy(annualStatsList[i].teams[j].team_name, team_name.c_str());

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

			cin.ignore();
			getline(cin, top_per_game, '\t');
			strcpy(annualStatsList[i].teams[j].top_per_game, top_per_game.c_str());

			cin >>annualStatsList->teams[j].fum;
			cin >>annualStatsList->teams[j].lost;
			cin >>annualStatsList->teams[j].to;
		}

		cin >> lines;

		for(int m = 0;m < lines; m++) {
			cin >> command;
			cin >> range;
			if(range != "range") {
				year = std::atoi(range.c_str());
			} else {
				cin >> year1;
				cin >> year2;
				year3 = std::atoi(year1.c_str());
				year4 = std::atoi(year2.c_str());

			}
			cin >> field;
			cin >> order;
			if(command == "bsort") {
				bsort_command(annualStatsList,year,field,order);
			}else if(command == "bfind") {
				bfind(annualStatsList,year, order);
			}
		}
	}
}
