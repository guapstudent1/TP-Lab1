#include <iostream>
#include <cstring>
using namespace std;

class Student{
	int group;
	int mark[5];
	string fullname;
	
public: 
	Student();
		
	void SetMark(int, int);
	int GetMark(int);
	float CalcAverage();
	
	void SetFullname(string);
	string GetFullname();

	void SetGroup(int);
	int GetGroup();
};