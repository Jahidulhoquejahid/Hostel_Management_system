#include<iostream>
#include <fstream>
#define SEAT 20   //to assume the total seat available in hostel.
int STUDENT=3; //we suppose to have 3 students currently in the hostel.
using namespace std;

class student
{
    string name;
    string id;
    string gender;
    string room;
    string father;
    string mother;
    string date_of_birth;
    string depertment;
    string semester;
public:
    friend void write_to_file(student newstd);
    void set_name(string n)
    {
        name=n;
    }
    void set_id(string i)
    {
        id=i;
    }
    void set_gender(string g)
    {
        gender=g;
    }
    void set_room(string r)
    {
        room=r;
    }
    void set_father(string f)
    {
        father=f;
    }
    void set_mother(string m)
    {
        mother=m;
    }
    void set_birthday(string b)
    {
        date_of_birth=b;
    }
    void set_depertment(string d)
    {
        depertment=d;
    }
    void set_semester(string s)
    {
        semester=s;
    }
    string get_name()
    {
        return name;
    }
    string get_id()
    {
        return id;
    }
    string get_gender()
    {
        return gender;
    }
    string get_room()
    {
        return room;
    }
    string get_father()
    {
        return father;
    }
    string get_mother()
    {
        return mother;
    }
    string get_birthday()
    {
        return date_of_birth;
    }
    string get_depertment()
    {
        return depertment;
    }
    string get_semester()
    {
        return semester;
    }

};

void write_to_file(student newstd)
{
    ofstream outFile;
    outFile.open("data.txt", ios::app);

    outFile << newstd.get_name() << endl;
    outFile << newstd.get_father() <<endl;

    outFile.close();
}
void show_menu()
{
    cout<<"//           -MENU-            //"<<endl;
    cout<<endl;
    cout<<"Option 1: Store all students List     :"<<endl;
    cout<<"                                 "<<endl;
    cout<<"Option 2: Show all students info      :"<<endl;
    cout<<"                                 "<<endl;
    cout<<"Option 3: Search for a students entry :"<<endl;
    cout<<"                                 "<<endl;
    cout<<"Option 4: Delete a students entry     :"<<endl;
    cout<<endl;
    cout<<"Option 5: Edit a student's entry      :"<<endl;
    cout<<endl;
    cout<<"Option 6: Admit a new student         :"<<endl;
    cout<<endl;
}
void  showdata(student sT[],int m)
{
    int i;
    for(i=0; i<m; i++)
    {
        cout<<"info of student "<<i<<"is below: "<<endl<<endl<<endl;
        cout<<"name: "<<sT[i].get_name()<<endl;
        cout<<"id: "<<sT[i].get_id()<<endl;
        cout<<"gender: "<<sT[i].get_gender()<<endl;
        cout<<"room: "<<sT[i].get_room()<<endl;
        cout<<"father: "<<sT[i].get_father()<<endl;
        cout<<"mother: "<<sT[i].get_mother()<<endl;
        cout<<"birthday: "<<sT[i].get_birthday()<<endl;
        cout<<"depertment: "<<sT[i].get_depertment()<<endl;
        cout<<"semester: "<<sT[i].get_semester()<<endl<<endl;
    }
}
int studentData(student ST[],int k)
{
    int in,result,studnum=0,seat;
    string n,i,g,r,f,m,b,d,s;
    cout<<"enter 3 students entry: "<<endl;
    for(in=0; in<k; in++)
    {
        cout<<"enter student "<<in<<"'s name: "<<endl;
        cin>>n;
        cout<<"enter id: "<<endl;
        cin>>i;
        cout<<"enter gender: "<<endl;
        cin>>g;
        cout<<"enter room: "<<endl;
        cin>>r;
        cout<<"enter father: "<<endl;
        cin>>f;
        cout<<"enter mother: "<<endl;
        cin>>m;
        cout<<"enter birthday: "<<endl;
        cin>>b;
        cout<<"enter depertment: "<<endl;
        cin>>d;
        cout<<"enter semester: "<<endl;
        cin>>s;
        ST[in].set_name(n);
        ST[in].set_id(i);
        ST[in].set_gender(g);
        ST[in].set_room(r);
        ST[in].set_father(f);
        ST[in].set_mother(m);
        ST[in].set_birthday(b);
        ST[in].set_depertment(d);
        ST[in].set_semester(s);
    }
}
void searchstd(student st[],int x)
{
    int choice;
    string name,id;
    cout<<"By which info do you want to search?"<<endl<<"1: NAME"<<endl<<"2:ID"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>choice;
    if(choice==1)
    {
        int i,flag=0;

        cout<<"enter the name you want to search: "<<endl;
        cin>>name;
        for(i=0; i<x; i++)
        {
            if(st[i].get_name()==name)
            {
                flag=1;
                cout<<"entry found in index: "<<i<<endl;
                cout<<"there might be some personal informations!do you really want to see it now?"<<endl<<"If you are,then type: YES"<<endl;
                string c;
                cin>>c;
                if(c=="YES")
                {
                    if(st[i].get_gender()=="male"&&"MALE"&&"man"&&"MAN")
                    {
                        cout<<"Thank you,here is his informations: "<<endl<<endl;
                    }
                    else if(st[i].get_gender()=="female"&&"FEMALE"&&"woman"&&"WOMAN")
                    {
                        cout<<"Thank you,here is her information: "<<endl<<endl;
                    }
                    cout<<"name: "<<st[i].get_name()<<"  ";
                    cout<<"id: "<<st[i].get_id()<<" ";
                    cout<<"gender: "<<st[i].get_gender()<<" ";
                    cout<<"room: "<<st[i].get_room()<<" ";
                    cout<<"depertment: "<<st[i].get_depertment()<<" ";
                    cout<<"year: "<<st[i].get_semester()<<" ";
                    cout<<"fathers name: "<<st[i].get_father()<<" ";
                    cout<<"mothers name: "<<st[i].get_mother()<<" ";
                    cout<<"birthday: "<<st[i].get_birthday()<<" ";
                    cout<<endl<<endl;
                }//end of if for privacy checking of student.
                else
                    cout<<"going back without showing info's"<<endl;

            }//end of if for matching input for search.
        }//end of for loop for searching a member.
        if(flag==0)
            cout<<"sorry!"<<endl<<"the student you are looking for does not stay here!"<<endl;
    }//end of if for search option of id or name.
    else if (choice==2)
    {
        cout<<"enter the id you want to search: "<<endl;
        cin>>id;
        int i,flag=0;
        for(i=0; i<x; i++)
        {
            if(st[i].get_id()==id)
            {
                flag=1;
                cout<<"entry found in index: "<<i<<endl;
                cout<<"there might be some personal informations!do you really want to see it now?"<<endl<<"If you are,then type: YES"<<endl;
                string c;
                cin>>c;
                if(c=="YES")
                {
                    cout<<"and here is his informations: "<<endl<<endl;
                    cout<<"name: "<<st[i].get_name()<<"  ";
                    cout<<"id: "<<st[i].get_id()<<" ";
                    cout<<"gender: "<<st[i].get_gender()<<" ";
                    cout<<"room: "<<st[i].get_room()<<" ";
                    cout<<"depertment: "<<st[i].get_depertment()<<" ";
                    cout<<"semester: "<<st[i].get_semester()<<" ";
                    cout<<"fathers name: "<<st[i].get_father()<<" ";
                    cout<<"mothers name: "<<st[i].get_mother()<<" ";
                    cout<<"birthday: "<<st[i].get_birthday()<<" ";
                    cout<<endl<<endl;
                }//end of if for privacy checking of student.
                else
                    cout<<"type: YES"<<endl;

            }//end of else if for matching input for search.
        }//end of for loop for searching a member.
        if(flag==0)
            cout<<"sorry!"<<endl<<"the student you are looking for does not stay here!"<<endl;
    }//end of else if for search option of id or name.
}//end of search function.
void dlt_entry(student St[],int n)
{
    int index=0,i;
    string id;
    cout<<"enter the ID of student's entry you want to delete: "<<endl;
    cin>>id;
    for(i=0; i<n; i++)
    {
        if(id==St[i].get_id())
        {
            index=i;
            break;
        }
        else
        {
            cout<<" Sorry! There is no student in here with the ID you entered!"<<endl;
            return;
        }
    }
    cout<<"are you sure you are going to delete entry of student "<<index<<" ?"<<endl;
    cout<<"If you are,type: YES"<<endl;
    string ans;
    cin>>ans;
    if(ans=="YES")
    {
        for(i=index; i<n; i++)
        {
            St[i].set_name(St[i+1].get_name());
            St[i].set_id(St[i+1].get_id());
            St[i].set_gender(St[i+1].get_gender());
            St[i].set_room(St[i+1].get_room());
            St[i].set_father(St[i+1].get_father());
            St[i].set_mother(St[i+1].get_mother());
            St[i].set_birthday(St[i+1].get_birthday());
            St[i].set_depertment(St[i+1].get_depertment());
            St[i].set_semester(St[i+1].get_semester());
        }//end of for loop to delete every data of the index which to be deleted.
    }//end of are you sure to delete if.
}//end of delete function.
 void Add_student(student new_comer[],int total_std){//who are new comer student.
	student newstd;
	string n,id,g,fn,mn,b,s;
	cout<<"enter a new student name:"<<endl;
	cin>>n;
	newstd.set_name(n);
	cout<<"enter a new student id:"<<endl;
	cin>>id;
	newstd.set_id(id);
	cout<<"enter a new student gender:"<<endl;
	cin>>g;
	newstd.set_gender(g);
	cout<<"enter a new student's father name:"<<endl;
	cin>>fn;
	newstd.set_father(fn);
	cout<<"enter a new student's mother name:"<<endl;
	cin>>mn;
	newstd.set_mother(mn);
	cout<<"enter a new student's birthday:"<<endl;
	cin>>b;
	newstd.set_birthday(b);
	cout<<"enter a new student's semester:"<<endl;
	cin>>s;
	newstd.set_semester(s);

	write_to_file(newstd);


	new_comer[total_std]=newstd;//saving student info in an array.
	STUDENT++;//INCREASED IN TOTAL NUMBER OF STUDENT.
	cout<<"garnd total current number of student: "<<STUDENT++<<endl;
	cout<<"succesfully added a new student."<<endl;
}




int main()
{
    int choice;
    student Stud[SEAT];
    while( 1 )
    {
        show_menu();
        cout<<"Please don't  mixture of upper and lower case syntax during the whole proccess"<<endl;
        cout<<"now,which is your choice?"<<endl<<"choose an option and press enter:"<<endl;
        cin>>choice;
        if
        (choice==1)
        {
            studentData(Stud,STUDENT);//load from file
        }
        else if
        (choice==2)
        {
            showdata(Stud,SEAT);
        }
        else if
        (choice==3)
        {
            searchstd(Stud,STUDENT);
        }
        else if
        (choice==4)
        {
            dlt_entry(Stud,STUDENT);
        }
        else if
        (choice==5)
        {

        }
        else if
            (choice==6)
        {
            Add_student(Stud,STUDENT);
        }
    }
    return 0;
}

