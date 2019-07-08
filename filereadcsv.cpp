//This record program can handle upto 10000000 lines of data

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include"filehash.h"
#include"filerecord.h"

using namespace std;

vector<string>v[10000000];

void removeDupWord(string str,int j)
{
     istringstream ss(str);

    do {

        string word;
        ss >> word;

       if(ss)
	v[j].push_back(word);

    } while (ss);
}
string find_department(string s)
{	string s1=s.substr(2,2);
	map<string,string>mp;
	mp["CS"]="COMPUTER SCIENCE AND ENGINEERING";
	mp["CE"]="CIVIL ENGINEERING";
	mp["CH"]="CHEMICAL ENGINEERING";
	mp["BT"]="BIOTECHNOLOGY";
	mp["CY"]="CHEMISTRY";
	mp["EC"]="ELECTRONICS AND COMMUNICATION ENGINEERING";
	mp["EE"]="ELECTRICAL ENGINEERING";
	mp["ES"]="EARTH AND ENVIRONMENTAL STUDIES";
	mp["HS"]="HUMANITIES AND SOCIAL SCIENCE";
	mp["MA"]="MATHMATICS";
	mp["ME"]="MECHANICAL ENGINEERING";
	mp["MM"]="METALLURGICAL AND MATERIAL ENGINEERING";
	mp["MS"]="MANAGEMENT STUDIES";
	mp["PH"]="PHYSICS";
	return mp[s1];
}
int find_yr(string roll)
{
	string s1=roll.substr(0,2);
	int y=2000;
	y=y+(s1[0]-'0')*10+(s1[1]-'0');
	return y;
}
int find_sem(string roll)
{
	int i=find_yr(roll);
	//here it can based on user how u r taking input or not
	int curr_yr=2019;
	int diff=curr_yr-i;
	return diff*2;
}


int main()
{
	fstream f2;
	f2.open("STUDENT_RECORDS.csv",ios::in);
	fstream f1;
	//f1.open("maurya.csv",ios::out|ios::app);
	string s1;
	int j=0;
	while(getline(f2,s1))
	{
		removeDupWord(s1,j);
		j++;

	}
	int size=j;
	//cout<<"size="<<size<<endl;
	string g1,s2,s3;
	Hash<record> hlist,hlist2;


	for(int i=0;i<size;i++)
	{	//a=new record;
		int l1=v[i][0].find(',');
		g1=v[i][0].substr(0,l1);//for roll no
		v[i][0].erase(0,l1+1);
		int l2=v[i][0].find(',');
		s2=v[i][0].substr(0,l2);//for reg no
		v[i][0].erase(0,l2+1);
		s3=v[i][0].substr(0,v[i][0].size());//for name
		string s4=find_department(g1);
		int y=find_yr(g1);
		int se=find_sem(g1);
		if(v[i].size()==2)
		{
			record a(s3,v[i][1],s4,y,s2,g1,se);
			//cout<<a<<endl;
			hlist.insert(a);
			hlist2.insert1(a);
		}
		else
		{

			record a(s3,v[i][2],s4,y,s2,g1,se);
			//cout<<a<<endl;
			hlist2.insert1(a);
			hlist.insert(a);
		}


	}
	cout<<"FOR FIRST TYPE DISPLAY SORTED ACCORDING TO THEIR FIRST NAME"<<endl;
	cout<<setw(16)<<"Firstname"<<" "<<setw(17)<<"Lastname"<<setw(30)<<"Department"<<setw(20)<<"yr_adm"<<setw(8)<<"regno"<<setw(10)  <<"rollno"<<setw(12)<<"semester"<<endl;
	hlist.display();
	cout<<"FOR SECOND TYPE SORTED ACCORDING TO THEIR LAST NAME"<<endl;
	//cout<<setw(15)<<"firstname"<<" "<<setw(15)<<"lastname"<<setw(40)<<"department"<<setw(10)<<"yr_adm"<<setw(10)<<"regno"<<setw(10)  <<"rollno"<<setw(10)<<"semester"<<endl;
	cout<<setw(16)<<"Firstname"<<" "<<setw(17)<<"Lastname"<<setw(30)<<"Department"<<setw(20)<<"yr_adm"<<setw(8)<<"regno"<<setw(10)  <<"rollno"<<setw(12)<<"semester"<<endl;
	hlist2.display();

}

