#ifndef member_h
#define member_h
class Member {
protected:
	char name[30];
	char lastname[30];
	int telephone;
	char email[50];
public:
	Member();
	Member(char*, char*, int, char*);
	~Member();
	Member& operator=(const Member& std);
	void setname(char*);
	void setlastname(char*);
	void settelephone(int);
	void setemail(char*);
	char* getname();
	char* getlastname();
	int get_telephone();
	char* getemail();
	void print_info();
};



#endif
