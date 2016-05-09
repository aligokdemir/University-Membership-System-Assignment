#ifndef ICSE_MEMBERSHIP_SYSTEM
#define ICSE_MEMBERSHIP_SYSTEM
#include "ICSETeam.h"
class University_ICSE_Memberships: public ICSETeam {
private:
	ICSETeam teams[50];
	int noofteams;
public:
	
	University_ICSE_Memberships();
	int getnoofteams();
	void addnewteam(ICSETeam*);
	void search(int, int);
	void printer(ICSETeam*);
	int listtotalcost(ICSETeam*);
	void listteammembers(ICSETeam*, char*);
	int teamtotalcost(ICSETeam*, char*);
};



#endif
