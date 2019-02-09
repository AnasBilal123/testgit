#include<iostream>
using namespace std;
#ifndef CSTRING_H
#define CSTRING_H
class CString
{
	friend ostream & operator<<(ostream &x, const CString & ref);
	friend istream & operator>>(istream &x, CString & ref);
private:
	char *data;
	int size;
	int getLengthString(const char*) const;
	void copyDelim(char * destination, const char * source, int count);

public:
	CString();
	CString(char c);
	CString(const char *);
	CString(const char &);
	CString(const CString &obj);
	CString(int);
	void input();
	void shrink();
	char &operator[](int index) const;
	bool isEmpty();
	int getLength() const;
	void dsiplay() const;
	int find(CString * subStr, int start = 0);
	void insert(int index, CString *subStr);
	void remove(int index, int count);
	int replace(CString *old, CString * newSubStr);
	CString & operator=(const CString &ref);
	//CString &operator[]
	void trimLeft();
	void trimRight();
	void trim();
	void makeUpper();
	void makeLower();
	void reverse();
	void reSize(int);
	int compare(CString s2) const;
	CString left(int count);	CString right(int count);	int tolnteger() const;	float tofloat() const;	CString operator +(CString s2)const;	void concatEqual(CString s2);
	CString tokenzie(CString delim);	operator int();	CString & operator++();
	CString operator++(int a);
	operator float();
	bool & operator<=(CString &);
	bool & operator >= (CString &);
	bool & operator ==(const CString &);
	bool operator>(const CString &);
	bool operator <(const CString &);	CString & operator+=(int);	void copyString(char * destination, const char * source);
	~CString();
};
#endif