#include <algorithm>
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
	/*
	for(int i=0; i<32; i++)
	{
		cout<<dlist[i]<<endl;
	}*/
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
/*
	for(int i=0; i<20; i++)
	{
		cout<<dlist[i]<<endl;
	}
	*/
}

void sortAsc(int list[]) {
	int hold;

	for(int i=0; i<31; i++)
	{
		for(int j=0; j<31; j++){
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

	for(int i=0; i<32; i++)
	{
		cout<<annualStatsList[indexYear].teams[i].team_name;
		cout<<"\t\t\t";
		cout<<list[i]<<endl;
		cout<<""<<endl;
	}
}

//bubble sort in descending order
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
	for(int i = 0; i < 31; i++) {
			if(list[i] == list[i+1]){
				strcmp(annualStatsList[indexYear].teams[i].team_name, annualStatsList[indexYear].teams[i+1].team_name) ;
			}
	}
	cout<<""<<endl;
	cout<<"Teams \t\t\t\t";
	cout<<"c is limited";
	cout<<"\n"<<endl;

	for(int i=0; i<32; i++)
	{
		cout<<annualStatsList[indexYear].teams[i].team_name;
		cout<<" \t\t";
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
	cout<<"Team \t\t\t";
	cout<<"Max ";
	cout<<"c is limited"<<endl;
	cout<<"\n";
	cout<<annualStatsList[indexYear].teams[1].team_name;
	cout<<"\t";
	cout<<list[1]<<endl;
	cout<<"\n\n";

}
if(order =="average") {
	int total = 0;

	for(int i =0; i < 32; i++) {
		total = total+list[i];
	}
	int average = total/32;
	cout<<"Average ";
	cout<<"c is limited";
	cout<<"\n\n";
	cout<<average<<endl;
	cout <<"\n";

}

if(order =="min") {
	cout<<"should be min"<<endl;
	cout<<order<<endl;
}
cin.clear();
cin.ignore();
}


void bsort(annual_stats* annualStatsList ,int year,string order) {

	// check year, grab correct index, re-write year as index var, error if no year match
	for(int n=0; n < numberOfYears; n++ ) {
		if(annualStatsList[n].year == whichYear) {
			indexYear = n;
		}
		else {
			cout<<"Error: no such year." <<endl;
			break;
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
			if(command == "bsort") {
				bsort(annualStatsList,year,order);
			}else if(command == "bfind") {
				bfind(annualStatsList,year, order);
			}
		}
	}
}
