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
    //debugging and test code

//    read(filename, T, usedHashes);

//    insert(T,usedHashes);
//
//    search(T);


//    T.insert_item("new","shit","in","32423532","OB");
//    usedHashes.insert(T.hashfunc("new")%200);

//    set<int>::iterator itr;
//    for(itr = usedHashes.begin(); itr != usedHashes.end(); itr++){
//        cout << *itr << endl;
//    }

//    write(filename, T, usedHashes);


//    usedHashes.insert(T.insert_item("boi", "rekt", "dead", "243523552", "director"));
//    T.insert_item("boi", "rekt", "dead", "243523552", "director");
//    usedHashes.insert(T.insert_item("iob", "bitch", "dead", "243523552", "director"));
//    usedHashes.insert(T.insert_item("jing","dog","dog","2222222","ampas"));
    //main UI loop
    cout << "|<<<<<<<<<<< |      WELCOME TO       | >>>>>>>>>>>|" << endl;
    cout << "|<<<<<<<<<<< | MANAGEMENT APPLICATION| >>>>>>>>>>>|" << endl;
    while (true) {
        //option show and detection
        cout
                << "What Do You Want To Do?\n1. Add employee\n2. Search for specific employee\n"
                   "3. Delete Specific Employee By Name\n4. Save\n"
                   "5. Load Preexisting Save\n6. exit\nInput:";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            insert(T, usedHashes);
        } else if (choice == 2) {
            search(T);
        } else if (choice == 3) {
            employeeDelete(T);
        } else if (choice == 4) {
            filename = saveFile(filename, T, usedHashes);
        } else if (choice == 5) {
            filename = loadFile(filename, T, usedHashes);
        }
        else if (choice == 6) {
            //exit display and function
            cout << "|<<<<<<<<<<< |      SEE YOU       | >>>>>>>>>>>|" << endl;
            cout << "|<<<<<<<<<<< |     NEXT TIME      | >>>>>>>>>>>|" << endl;
            break;
        }

//    T.search("boi", "dead");

    }
        return 0;

}