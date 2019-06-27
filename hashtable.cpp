#include <iostream>
#include <vector>
#include "linklist.cpp"

using namespace std;

//use of template to enable varied sizes of the hashtable
template <int T>
class Hashtable {
private:
    int const static size = T;
    LinkedList table[T];


public:

    //    hash function for the string
    int hashfunc(string name){
        int val = 0;
        for(int i = 0 ; i < name.length() ; i++){
            val += int(name[i])*name.length()*(((int(name[0])*53)+(int(name[name.length()-1]*71))%int(name[(name.length()-1)/2])));
        }
        return val;
    }

    //insert item to the hashtable
    int insert_item(string name, string middleName , string lastName, string phoneNumber, string position) {
//    gets the hash value of the item and modulus it to fit into the hashtable
        int pos = this->hashfunc(name) % this->size;
        table[pos].insertFront(name, middleName, lastName, phoneNumber, position);
        return pos;
    }

    void search(string name, string lastName) {
//    gets the hash value and position
        int pos = this->hashfunc(name) % this->size;
        if(!table[pos].viewOnName(name, lastName)){
            cout << "\n****************\n*Item not found*\n****************\n" << endl;
        }

    }
    //delete item function
    void del_item(string name, string lastName){
//    gets the hash value and position
        int pos = this->hashfunc(name) % this->size;
        table[pos].deleteKey(name, lastName);

    }
    vector<Data> getRawStruct(int position){
        return  table[position].getAllValues();
    }



};