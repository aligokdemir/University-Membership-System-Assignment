#include "academic.h"
#include "admin.h"
#include "member.h"
#include "student.h"
#include "ICSETeam.h"
#include "University_ICSE_Memberships.h"
#include <iostream>
using namespace std;

int main() {
	char choice;
	University_ICSE_Memberships systemm;
	ICSETeam* team = NULL;
	cout << "Welcome to University ICSE Membership Management System!\n\n";

	do {
		cout << "1.Create a team\n2.Search a member by ID\n3.List all members\n4.List total annual cost\n";
		cout << "5.List all members of a given team\n6.List total annual cost of a given team\n7.Exit\n";
		cout << "Your choice: ";
		cin >> choice;
		
		if (choice == '1') {
			char teamname[30],leadername[30],lastname[30],mail[30],title[30];
			int empid, phone,date;
			team = new ICSETeam();
			
			cout << "Enter the team name: ";
			cin >> teamname;
			cout << "\nEnter the details of the team leader\n";
			cout << "Employee ID: ";
			cin >> empid;
			cout << "\nFirst Name: ";
			cin >> leadername;
			cout << "Last Name: ";
			cin >> lastname;
			cout << "Telephone Number: ";
			cin >> phone;
			cout << "Email Adress: ";
			cin >> mail;
			cout << "Academic Title 'Professor' or 'Associated Professor': ";
			cin >> title;
			cout << "Date membership initiated: ";
			cin >> date;
			team->setteamname(teamname);
			team->setteamleader(leadername, lastname, phone, mail, empid, title, date);
			systemm.addnewteam(team);
			cout << "The team leader has been added to the team!\n\n";
			
			char addnew;
			cout << "Would you like to add a new member to the team(Y/N): ";
			cin >> addnew;
			while (addnew == 'y' || addnew == 'Y') {
				int type;
				cout << "1.Academic Staff\n2.Student\n3.Administrator Staff\nSelect Type: ";
				cin >> type;
				if (type == 1) {
					academicMember* member = new academicMember();
					char membername[30], lastname[30], mail[30], title[30];
					int empid, phone, date;
					cout << "Enter the details of the team member:";
					
					cout << "\nEmployee ID: ";
					cin >> empid;
					member->setemployeeID(empid);
					cout << "First Name: ";
					cin >> membername;
					member->setname(membername);
					cout << "Last Name: ";
					cin >> lastname;
					member->setlastname(lastname);
					cout << "Telephone number: ";
					cin >> phone;
					member->settelephone(phone);
					cout << "Email: ";
					cin >> mail;
					member->setemail(mail);
					cout << "Academic Title: ";
					cin >> title;
					member->settitle(title);
					cout << "Date membership initiated (Enter the year only): ";
					cin >> date;
					member->setdate(date);

					team->addacademicmember(member);
				}
				else if (type == 2) {
					studentMember* member;
					int stuid, phone, stutype,compnumber;
					char firstname[30], lastname[30], mail[30];
					cout << "Enter the detail of the team member:\n";
					cout << "Student ID: ";
					cin >> stuid;
					cout << "First name: ";
					cin >> firstname;
					cout << "Last name: ";
					cin >> lastname;
					cout << "Telephone number: ";
					cin >> phone;
					cout << "Email: ";
					cin >> mail;
					cout << "Student member type (1) Full (2) Competitor: ";
					cin >> stutype;
					if (stutype == 2) {
						cout << "How many competitions will the student join: ";
						cin >> compnumber;
					}
					else compnumber = 0;
					member = new studentMember(firstname, lastname, phone, mail, stuid, stutype, compnumber);
					team->addstudentmember(member);
					cout << "The member added to the team succesfully.\n";
				}
				else if (type == 3) {
					adminMember* member;
					int phone, id, adminty, socialt;
					char name[30], lastname[30], mail[30];
					cout << "Employee ID: ";
					cin >> id;
					cout << "First name: ";
					cin >> name;
					cout << "Last name: ";
					cin >> lastname;
					cout << "Telephone number: ";
					cin >> phone;
					cout << "Email: ";
					cin >> mail;
					cout << "Admin type: (1) Manager (2) Secretary: ";
					cin >> adminty;
					cout << "Game geek monthly: ";
					cin >> socialt;
					member = new adminMember(name, lastname, phone, mail, id, adminty, socialt);
					
					team->addadminmember(member);
					
					cout << "The member added to the team succesfully.";
				}
				cout << "Would you like to add a new member to the team(Y/N): ";
				cin >> addnew;
			}
		}
		else if (choice == '2') {
			int role,id;
			cout << "Please indicate his/her role (1) Academic Staff (2) Student (3) Administrative Staff: ";
			cin >> role;
			cout << "Enter the ID: ";
			cin >> id;
			systemm.search(id, role);
		}
		else if (choice == '3') {
			systemm.printer(team);
		}
		else if (choice == '4') {
			int cost;
			
			cost = systemm.listtotalcost(team);

			cout << "The annual cost is $" << cost << "\n";
		}
		else if (choice == '5') {
			char teamname[30];

			cout << "\nTeam: ";
			cin >> teamname;

			systemm.listteammembers(team, teamname);
		}
		else if (choice == '6') {
			char teamname[30];
			int totalcost;
			cout << "Team name: ";
			cin >> teamname;

			totalcost = systemm.teamtotalcost(team, teamname);
			
			cout << "The annual cost for " << teamname << "is " << "$" << totalcost << "\n";
		}

	} while (choice != '7');
	cout << "\n\nGood Bye !!!";
	
	system("PAUSE");
	return 0;
}