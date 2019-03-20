		/*
    CH08-320143
    a4_p5.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de
		*/

#include <fstream>
#include <iostream>
#include <map>
#include <string>//getline

using namespace std;

int main()
{
    map<string,string> database;
    map<string,string>::iterator it;
    string Name,Surname;	//Stores first name and last name
    string BirthDate;		//Stores bith date
    string Query;		//Name to be searched


    ifstream Data("data.txt",ios::in);

    if(!Data) {
        return(-1);
    }

    //Transfere to db
    while(!Data.eof()) {
        Data>>Name>>Surname>>BirthDate;
        database.insert(pair<string,string>(Name + " " + Surname,BirthDate));

    }

    cout<<"Enter Name :";
    getline(cin,Query);

    //Find person
    it = database.find(Query);

    if (it == database.end()) {
        cout<<"Name not found!"<<endl;
    } else {
        cout<<it->second<<endl;
    }

    Data.close();
    return 0;

}
