#ifndef STUDENT_H
#define STUDENT_H
#include "member.h"
class studentMember : public Member {
private:
	int studentID;
	int memberType; //1 for full, 2 for competitor.
	int compNumber;
public:
	studentMember();
	studentMember(char*, char*, int, char*, int, int, int);
	void setstudentID(int);
	void setMemberType(int);
	void setcompNumber(int);
	int getstudentID();
	int getMemberType();
	int getcompNumber();
	int feecalculator(); //take the infos from the class itself.
	void printer();
};

#endif
