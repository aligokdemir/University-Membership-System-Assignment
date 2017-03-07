#ifndef ADMIN_H
#define ADMIN_H
#include "member.h"
class adminMember : public Member {
private:
	int employeeID;
	int adminType; //1 for manager, 2 for secretary.
	int socialType; // 1 for all magazines, 2 for game geek.
public:
	adminMember();
	adminMember(char*, char*, int, char*, int, int, int);
	void setemployeeID(int);
	void setadminType(int);
	void setsocialType(int);
	int getemployeeID();
	int getadminType();
	int getsocialType();
	int feecalculator();
	void printer();
};


#endif
