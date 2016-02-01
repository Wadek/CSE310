#include<iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdio.h>


using namespace std;
std::ifstream input("../2015-game-stats.txt");

void readFile() {
	for( std::string line; getline( input, line ); ) {
		cout << line <<endl;
	}
}
//bubble sort in Descending order
void sortDesc() {
	int hold;
	int array[5];
	cout<<"Enter 5 numbers: "<<endl;
	for(int i=0; i<5; i++) { cin>>array[i];
	}
	cout<<endl;

	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++){ 
			if(array[j]>array[j+1]) {
				hold=array[j];
				array[j]=array[j+1];
				array[j+1]=hold;
			}
		}
	}

	cout<<"Sorted Array is: "<<endl;
	for(int i=0; i<5; i++)
	{
		cout<<array[i]<<endl;
	}
}

//bubble sort in ascending order
void sortAsc() {
	int hold;
	int array[5];
	cout<<"Enter 5 numbers: "<<endl;
	for(int i=0; i<5; i++) { cin>>array[i];
	}
	cout<<endl;

	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++){ 
			if(array[j]<array[j+1]) {
				hold=array[j];
				array[j]=array[j+1];
				array[j+1]=hold;
			}
		}
	}

	cout<<"Sorted Array is: "<<endl;
	for(int i=0; i<5; i++)
	{
		cout<<array[i]<<endl;
	}
}

//bsort algorithm
void bsort() {
	int dec = 0;
	cout<<"desc, enter 1, asc enter 0"<<endl;
	cin>>dec;
	if(dec == 1) {
		sortAsc();
	}else {
		sortDesc();
	}
}

// main execution
main() {
	readFile();
}
