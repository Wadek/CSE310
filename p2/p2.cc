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
#include <omp.h>
#include <math.h>
#include "defns.cc"

using namespace std;

int getType(string type) {
    if(type =="INT") {
        return INT;
    }
    else if(type =="CHAR") {
        return CHAR;
    }
    else if(type =="BST") {
        return BST;
    } else {
		return -1;
	}
}

string getCommand ( string command) {
    if(command == "allocate") {
	   	return "allocate";
	}else {
		return "";
	}
}

void myMalloc() {
}

void myFree() {
}

void readInput() {
    unsigned int k, t ,c;
	int n;
	int  tempType;

    string type = "";

    cin >> k;
    n = pow(2,k);
    cin >> t;

	struct symbolTableEntry* symbolTableEntryList = new struct symbolTableEntry[t];
	char *heap = new char[n];

    cin >> c;
    for(int i = 0; i < c; i++) {
        string command = "";

        cin >> command;
        if(!getCommand(command).empty()) {
				cout << "ERROR: invalid command" << endl;
				break;
		}

		cin >> type;
		tempType = getType(type);
		if (tempType == -1) {
			cout << "ERROR: invalid symbol type" << endl;
			break;
		}
		symbolTableEntryList[i].type = tempType;
		cin >> symbolTableEntryList[i].symbol;
		int value;
		cin >> value;
	}
}

main() {
    readInput();
}
