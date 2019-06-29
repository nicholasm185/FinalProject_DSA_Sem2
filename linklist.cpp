#include<iostream>
#include<string>
#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;

//Node struct template for all data storage and pointers
struct Node{
    string name;
    string middleName;
    string lastName;
    string phoneNumber;
    string position;
    Node *next = nullptr;
    Node(){};
    Node(string name, string middleName , string lastName, string phoneNumber, string position,Node *ptr){
        this->name = name;
        this->middleName = middleName;
        this->lastName = lastName;
        this->phoneNumber = phoneNumber;
        this->position = position;
        this->next = ptr;
    }
};
//struct with all data except the pointers
struct Data{
    string name;
    string middleName;
    string lastName;
    string phoneNumber;
    string position;
    Data(string name, string middleName , string lastName,
         string phoneNumber, string position){
        this->name = name;
        this->middleName = middleName;
        this->lastName = lastName;
        this->phoneNumber = phoneNumber;
        this->position = position;
    }
};
//LinkedList class with head pointer attribute
class LinkedList{
private:
    Node *head;
public:
    LinkedList(){
        head = nullptr;
    }
    //function to insert to front of list
    void insertFront(string name, string middleName , string lastName, string phoneNumber, string position) {
        Node *nood = new Node();
        nood->name = name;
        nood->middleName = middleName;
        nood->phoneNumber = phoneNumber;
        nood->lastName = lastName;
        nood->position = position;
        if (head == nullptr) {
            nood->next = nullptr;
            head = nood;
        } else {
            nood->next = head;
            head = nood;

        }
    }
    //check is list is empty or not
    bool empty(){
        if(head ==nullptr){
            return true;
        }
        else{
            return false;
        }
    }
    //Unused popHead but is available if needed
    string popHead() {
        string x;
        string name;
        Node *detector = head;
        if (!this->empty()) {
            if (head->next == nullptr) {
                name = head->name;
                delete head;
                cout << name << "has been deleted";
            } else {
                x = head->name;
                detector = head->next;
                delete head;
                head = detector;
                cout << name << "has been deleted";
            }
        }
        return x;
    }
    //delete function based on name and lastName
    bool deleteKey(string name,string lastName){
        Node *curr = head;
        Node *temp;
        if (head ==nullptr){
            cout<< "Nothing here";
            return false;
        }
        else if(curr->next == nullptr){
            if (curr->name == name && curr->lastName == lastName){
                cout<< lastName << " entry has been deleted.\n";
                temp = curr;
                head = curr->next;
                delete temp;
                return true;

            }
        }
        else if(head->name == name  && head->lastName == lastName){
            cout<< lastName << " entry has been deleted.\n";
            curr=curr->next;
            temp = head;
            head = curr;
            delete temp;
            return true;
        }
        else{
            while(curr->next != nullptr){
                if(curr->next->name == name && curr->next->lastName == lastName){
                    cout<< lastName << " entry has been deleted.\n";
                    temp = curr->next;
                    curr->next= curr->next->next;
                    delete temp;
                    return true;
                }
                curr= curr->next;
            }
        }
        return false;
    }
    //view specific data
    bool viewOnName(string Name, string lastName){
        Node *curr = head;
        bool status = false;
        if(!this -> empty()){
            while(curr != nullptr){
                if(Name == curr->name && lastName == curr->lastName){
                    cout
                    << "\n*****************************************"
                    << "\nName:        " << curr->name
                    << "\nMiddle Name: " << curr->middleName
                    << "\nLast Name:   " << curr-> lastName
                    << "\nPhone number:" << curr->phoneNumber
                    << "\nposition:    " << curr->position
                    << "\n*****************************************\n";
                    status = true;

                }
                curr= curr->next;
            }
        }
        return status;
    }
    //debugging function to check if LinkedList works properly
    void view(){
        Node *curr = head;
        cout << curr->name<< " "<< curr->lastName<<" \n";
        while (curr->next != nullptr){
            curr = curr->next;
            cout<< curr->name<< " "<< curr->lastName<<" \n";
        }
//        cout<< "DONE\n";
    }
    //get every single data value into a data struct without a pointer
    vector<Data> getAllValues(){
        vector<Data> data;
        Node *curr = head;
        if(empty()){
            cout<<"nothing here";
            return data;
        }
        else{
            while(curr != nullptr){
                data.emplace_back(Data(curr->name,curr->middleName,curr->lastName,curr->phoneNumber,curr->position));
                curr= curr->next;

            }
        }
        return data;
    }

    void viewonfirst(string firstname) {
        cout << "|" << setfill('-') << setw(20) << "first Name" << "|" << setfill('-') << setw(19) << "Last Name" << "|"
             << endl;
        Node *curr = head;
        bool status = false;
        if (!this->empty()) {
            while (curr != nullptr) {
                if (firstname == curr->name) {
                    cout << "|" << setfill(' ') << setw(20) << curr->name << "|" << setfill(' ') << setw(20)
                         << curr->lastName << "|" << endl;

                }
                curr = curr->next;
            }
        }
    }



};
