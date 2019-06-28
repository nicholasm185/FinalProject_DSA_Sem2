//
// Created by HP on 06/06/2019.
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include<set>

//header file defining all Functions in Functions.cpp
#ifndef FINALPROJECTCPP_FUNCTION_H
#define FINALPROJECTCPP_FUNCTION_H

void search(Hashtable<200> T);

void insert(Hashtable<200> &T, set<int> &usedHashes, int &numData);

bool checknum(string x);

vector<string> splitstring(string x);

bool read(string filename, Hashtable<200> &hashtable, set<int> &usedHashes, int &numdata);

void write(string filename, Hashtable<200> &hashtable, set<int> usedHashes);

void employeeDelete(Hashtable<200> &T, int &numData);

string loadFile(string filename, Hashtable<200> &T, set<int> usedHashes, int &numdata);

string saveFile(string filename, Hashtable<200> &hashtable, set<int> usedHashes);


#endif //FINALPROJECTCPP_FUNCTION_H
