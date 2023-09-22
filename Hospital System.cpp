#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

string names[2][5];
string status[20][5];
int len[20];

void add_patient(){
    int spec, stat;
    string name;
    cout << "Enter your Specialization, Name, Status: ";
    cin >> spec >> name >> stat;
    spec--;
    if(len[spec]==5){
        cout << "Sorry, we can't accept any patients now." << endl;
        return;
    }
    if(stat==0){
        names[spec][len[spec]] = name;
        status[spec][len[spec]] = "regular";
    }
    else{
        for(int i = len[spec] ; i >= 1 ; i--){
            names[spec][i] = names[spec][i-1];
            status[spec][i] = status[spec][i-1];
        }
        names[spec][0] = name;
        status[spec][0] = "urgent";
    }
    len[spec]++;
    cout << endl;
    return;
}
void print_patients(){
    bool flag = false;
    for(int i = 0 ; i < 20 ; i++){
        if(len[i]==0) continue;
        flag = true;
        cout << "There are " << len[i] << " in specialization " << i+1 << endl;
        for(int j = 0 ; j < len[i] ; j++)
            cout << names[i][j] << " " << status[i][j] << endl;
    }
    if(!flag) cout << "No patients now!" << endl;
    cout << endl;
    return;
}
void get_next_patient(){
    cout << "Enter Specialization: ";
    int spec; cin >> spec;
    spec--;
    if(len[spec]==0){
        cout << "No patients at the moment. Have rest, Dr." << endl << endl;
        return;
    }
    cout << names[spec][0] << " please go to the Dr" << endl << endl;
    for(int i = 1 ; i < len[spec] ; i++){
        names[spec][i-1] = names[spec][i];
        status[spec][i-1] = status[spec][i];
    }
    len[spec]--;
    return;
}
int menu(){
    cout << "1-Add new patient" << endl
         << "2-Print patients" << endl
         << "3-Get next patient" << endl
         << "4-Exit" << endl;
    int choice; cin >> choice;
    return choice;
}
void system(){
    while(true){
    int choice = menu();
    if(choice==1) add_patient();
    else if(choice==2) print_patients();
    else if(choice==3) get_next_patient();
    else return;
    }
}
int main() {
    system();
    return 0;
}

