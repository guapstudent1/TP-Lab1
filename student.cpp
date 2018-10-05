#include "student.h"

Student::Student()
{}

void Student::SetMark(int index, int value)
{
	mark[index] = value;
}

int Student::GetMark(int index)
{
	return mark[index];
}

float Student::CalcAverage()
{
	return float(mark[0] + mark[1] + mark[2] + mark[3] + mark[4]) / 5.0f;
}

void Student::SetFullname(string fname)
{
	fullname = fname;
}

string Student::GetFullname()
{
	return fullname;
}

void Student::SetGroup(int gnum)
{
	group = gnum;
}

int Student::GetGroup()
{
	return group;
}