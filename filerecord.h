#include<iostream>
#include<iomanip>
//#include"singlylink.h"
using namespace std;
class record
{
	public:
		string firstname;
		string lastname;
		string department;
		int yr_adm;
		string regno;
		string rollno;
		int semester;
		record()
		{
			//cout<<"in default constructor";
		}
		record( string &fname,string &lname,string &de, int  &x,string &reg,string &roll, int & sem)
		{
			firstname=fname;
			lastname=lname;
			for(std::string::iterator it=de.begin();it!=de.end();it++)
			{
				department.push_back(*it);
			}
			yr_adm=x;
			regno=reg;
			rollno=roll;
			semester=sem;
		}
		~record()
		{
			//cout<<"in destructor"<<endl;
		}
		friend ostream& operator<<(ostream &x,record &s)
		{	//cout<<"in friend operator";
			cout<<setw(15)<<s.firstname<<" "<<setw(15)<<s.lastname<<setw(40)<<s.department<<setw(10)<<s.yr_adm<<setw(10)<<s.regno<<setw(10)  <<s.rollno<<setw(10)<<s.semester<<endl;
return cout;
}

};
