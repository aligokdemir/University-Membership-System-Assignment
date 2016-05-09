#ifndef academicMember_H
#define academicMember_H
#include "member.h"

class academicMember :public Member {
private:
	int employeeID;
	char title[30];
	int date;
public:
	academicMember();
	academicMember(char*, char*, int, char*, int, char*, int);
	~academicMember();
	//academicMember& operator = (const academicMember&);
	void setemployeeID(int);
	void settitle(char*);
	void setdate(int);
	int getemployeeID();
	char* gettitle();
	int getdate();
	int feecalculator(); //take the infos from the class itself.
	void printer();

};


#endif