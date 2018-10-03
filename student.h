class Student{
	int group;
	int mark[5];
	char *fullname;
	
public: 
	Student();
	~Student();
	
	void SetMark(int index, int value);
	int GetMark(int index);

	void SetFullname(char *fname);
	char *GetFullname();

	void SetGroupNumber(int n);
	int GetGroupNumber();
};