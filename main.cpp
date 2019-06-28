#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <set>

#include "hashtable.cpp"
#include "Function.h"


int main() {
    //data intitialization
    int choice;
    set<int> usedHashes;
    Hashtable<200> T;
    string filename = "saved.txt";
    vector<Data> data;
    int numData = 0;

    //main UI loop
    cout << "|<<<<<<<<<<< |      WELCOME TO       | >>>>>>>>>>>|" << endl;
    cout << "|<<<<<<<<<<< | MANAGEMENT APPLICATION| >>>>>>>>>>>|" << endl;
    cout << "\nLoading from file..." << endl;
    loadFile(filename, T, usedHashes, numData);
    while (true) {
        //option show and detection
        cout << "Number of data: " << numData << endl;
        cout
                << "What Do You Want To Do?\n1. Add employee\n2. Search for specific employee\n"
                   "3. Delete Specific Employee By Name\n4. Save\n"
                   "5. Load Preexisting Save\n6. Exit\nInput:";
        cin >> choice;
        if (choice == 1) {
            insert(T, usedHashes, numData);
        } else if (choice == 2) {
            search(T);
        } else if (choice == 3) {
            employeeDelete(T, numData);
        } else if (choice == 4) {
            filename = saveFile(filename, T, usedHashes);
        } else if (choice == 5) {
            filename = loadFile(filename, T, usedHashes, numData);
        }
        else if (choice == 6) {
            //exit display and function
            cout << "|<<<<<<<<<<< |      SEE YOU       | >>>>>>>>>>>|" << endl;
            cout << "|<<<<<<<<<<< |     NEXT TIME      | >>>>>>>>>>>|" << endl;
            break;
        } else{
            cout << "Invalid input!";
            cin.ignore();
        }

//    T.search("boi", "dead");

    }
        return 0;

}