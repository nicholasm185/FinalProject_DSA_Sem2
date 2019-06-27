#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "hashtable.cpp"
#include "Function.h"

//split string into usable data
vector<string> splitstring(string x){
    string temp;
    stringstream f(x);
    vector<string> data;
    while(getline(f,temp,',')){
        data.push_back(temp);
    }

    return data;
}
//read filename based on filename string and inserts to the data structure
bool read(string filename, Hashtable<200> &hashtable, set<int> &usedHashes) {
    ifstream readFile;
    readFile.open(filename);
    if (readFile.good()) {
        cout << "success" << endl;
        string x;
        cout << setfill('-')<<setw(42)<< "-" <<endl;
        cout <<"|" <<setfill('-')<<setw(20)<< "first Name" << "|" <<setfill('-')<<setw(19)<<"Last Name"<<"|"<<endl;
        cout << setfill('-')<<setw(42)<< "-" <<endl;
        while (getline(readFile, x)) {

            vector<string> processed = splitstring(x);

            hashtable.insert_item(processed[0],processed[1],processed[2],processed[3],processed[4]);

            usedHashes.insert(hashtable.hashfunc(processed[0])%200);

            cout <<"|" <<setfill(' ')<<setw(20)<< processed[0] <<"|" <<setfill(' ')<<setw(20)<< processed[1]<<"|"<< endl;
        }
        readFile.close();
        return true;
    }
    else {
        cout << "file not found\n";
        return false;
    }
}

//translates data structure into writable format and writes it into file
void write(string filename, Hashtable<200> &hashtable, set<int> usedHashes) {
    ofstream writeFile;
    writeFile.open(filename);
    set <int> :: iterator itr;
    vector<Data> datavector;

    for (itr = usedHashes.begin(); itr != usedHashes.end(); ++itr)
    {
        datavector = hashtable.getRawStruct(*itr);
        for(int f = 0; f < datavector.size(); f++){
            writeFile << datavector[f].name << "," << datavector[f].middleName << ","
                      << datavector[f].lastName << "," << datavector[f].phoneNumber << "," << datavector[f].position << "\n";

        }

    }

    writeFile.close();
}
//unused function for testing writing to file ability
void writeToFile(string filename, vector<string> data) {
    ofstream writeFile;
    writeFile.open(filename, ofstream::app);
    vector<string> ::iterator it;
    for (it = data.begin(); it != data.end(); it++) {
        writeFile << *it << "\n";
    }
    writeFile.close();
}
//creating a new file
void newfile(string filename) {
    cout << "creating new file\n";
    ofstream writeFile;
    writeFile.open(filename);
    writeFile.close();
}
//check if each letter in a string is a number
bool checknum(string x){
    bool isnum = true;
    string::iterator it = x.begin();
    for(it; it!=x.end(); it++){
        if(!isdigit(*it)){
            return false;
        }
    }

    return true;
}
//inserts new data into file
void insert(Hashtable<200> &T, set<int> &usedHashes){
    string firstname;
    string middlename;
    string lastname;
    string phonenumber;
    string position;
    bool ok = true;

    while(ok){
        cout << "Insert first name[3...20]: ";
        cin >> firstname;
        cin.ignore();
        if(firstname.length() >= 3 and firstname.length() <= 20){
            ok = false;
        } else{
            cout << "\ninvalid input\n";
        }
    }
    while(!ok){
        cout << "\nInsert middle name [3...20]: ";
        cin >> middlename;
        cin.ignore();
        if(middlename.length() >= 3 and middlename.length() <= 20){
            ok = true;
        } else{
            cout << "\ninvalid input\n";
        }
    }
    while(ok){
        cout << "\nInsert last name [3...20]: ";
        cin >> lastname;
        cin.ignore();
        if(lastname.length() >= 3 and lastname.length() <= 20){
            ok = false;
        } else{
            cout << "\ninvalid input\n";
        }
    }
    while(!ok){
        cout << "\nInsert phonenumber: ";
        cin >> phonenumber;
        cin.ignore();
        if(checknum(phonenumber)){
            ok = true;
        } else{
            cout << "\ninvalid input\n";
        }
    }
    while(ok){
        cout << "\nInsert position [3...20]: ";
        cin >> position;
        cin.ignore();
        if(position.length() >= 3 and position.length() <= 20){
            ok = false;
        } else{
            cout << "\ninvalid input\n";
        }
    }
    usedHashes.insert(T.insert_item(firstname,middlename,lastname,phonenumber,position));
}
//search function based on firstname and lastname
void search(Hashtable<200> T){
    string firstname;
    string lastname;
    bool ok = true;
    while(ok){
        cout << "Insert first name [3...20]: ";
        cin >> firstname;
        cin.ignore();
        if(firstname.length() >= 3 and firstname.length() <= 20){
            ok = false;
        } else{
            cout << "\ninvalid input\n";
        }
    }
    while(!ok){
        cout << "\nInsert middle name [3...20]: ";
        cin >> lastname;
        cin.ignore();
        if(lastname.length() >= 3 and lastname.length() <= 20){
            ok = true;
        } else{
            cout << "\ninvalid input\n";
        }
    }
    T.search(firstname, lastname);

}
//delete employee function baed on name
void employeeDelete(Hashtable<200> &T){
    string firstname;
    string lastname;
    bool ok = true;
    while(ok){
        cout << "Insert first name [3...20]: ";
        cin >> firstname;
        cin.ignore();
        if(firstname.length() >= 3 and firstname.length() <= 20){
            ok = false;
        } else{
            cout << "\ninvalid input\n";
        }
    }
    while(!ok){
        cout << "\nInsert last name [3...20]: ";
        cin >> lastname;
        cin.ignore();
        if(lastname.length() >= 3 and lastname.length() <= 20){
            ok = true;
        } else{
            cout << "\ninvalid input\n";
        }
    }
    T.del_item(firstname,lastname);


}
//load existing file and chooses filename
string loadFile(string filename, Hashtable<200> &T, set<int> usedHashes){
    string choice;
    bool ok = true;
    while(ok){
        cout << "do you want to use the default/previously used save file[Y/N}?";
        cin>>choice;
        cin.ignore();
        if(choice.compare("Y")==0){
            ok = false;
        }
        else if(choice.compare("N")==0){
            ok = false;
        }else{
            cout << "\ninvalid input\n";
        }
    }
    if(choice.compare("N")==0){
        while(!ok){
            cout << "\nInsert filename [3...20]: ";
            cin >> filename;
            cin.ignore();
            if(filename.length() >= 3 and filename.length() <= 20){
                ok = true;
            } else{
                cout << "\ninvalid input\n";
            }
        }
    }
    read(filename,T,usedHashes);
    return filename;

}
//save data structure into file in its entirety
string saveFile(string filename, Hashtable<200> &hashtable, set<int> usedHashes){
    string choice;
    bool ok = true;
    while(ok){
        cout << "do you want to use the default/previously used save file[Y/N}?";
        cin>>choice;
        cin.ignore();
        if(choice.compare("Y")==0){
            ok = false;
        }
        else if(choice.compare("N")==0){
            ok = false;
        }else{
            cout << "\ninvalid input\n";
        }
    }
    if(choice.compare("N")==0){
        while(!ok){
            cout << "\nInsert filename [3...20]: ";
            cin >> filename;
            cin.ignore();
            if(filename.length() >= 3 and filename.length() <= 20){
                ok = true;
            } else{
                cout << "\ninvalid input\n";
            }
        }
    }
    write(filename,hashtable,usedHashes);
    return filename;

}