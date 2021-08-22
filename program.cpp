#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("file.txt", ios::in);

    ofstream outFile;
    outFile.open("file1.txt", ios::app);

    string name;
    string id;
    string dept;
    string sem;

    string id1;

    cout << "Enter a student id : ";
    getline(cin, id1);

    while(inFile.eof()==false){
        getline(inFile, name);
        getline(inFile, id);
        getline(inFile, dept);
        getline(inFile, sem);

        if(id1 == id){
            cout << "Name : " << name << endl;
            cout << "ID : " << id << endl;
            cout << "Dept : " << dept << endl;
            cout << "Semester : " << sem << endl;

            outFile << name << endl;
            outFile << id << endl;
            outFile << dept << endl;
            outFile << sem << endl;
        }
    }
    inFile.close();
    outFile.close();




    return 0;
}
