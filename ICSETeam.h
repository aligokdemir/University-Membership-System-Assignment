#ifndef ICSE_TEAM
#define ICSE_TEAM
#include "academic.h"
#include "student.h"
#include "member.h"
#include "admin.h"

class ICSETeam {
protected:
	char teamname[30];
	int noofac;  // these 3 int are here because the number of academic, student and admin members are different.
	int noofstu; // if i used linked lists i wouldnt need those.
	int noofadmin;
	academicMember* teamleader;
	academicMember* academics;
	studentMember* students;
	adminMember* admins;
public:
	int getnoofac();
	int getnoofstu();
	int getnoofadmin();
	ICSETeam();
	void setteamname(char*);
	char* getteamname();
	void setteamleader(char*, char*, int, char*, int, char*, int);
	void addacademicmember(academicMember*);
	void addstudentmember(studentMember*);
	void addadminmember(adminMember*);
	academicMember* getteamleader();
	void listmembers();
	void calculatecost(int,ICSETeam*);
	void search(int,int,ICSETeam*);
	academicMember* getacademics();
	studentMember* getstudent();
	adminMember* getadmins();


};


#endif
