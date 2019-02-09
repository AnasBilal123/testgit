#ifndef IEDITOR_H
#define IEDITOR_H
#include"CString.h"
class IEditor
{
private:
	CString fileName;
	CString **data;
	int currentLines;
	int noOfLine;
	int capacity;
public:
	IEditor(CString fn = "file1") :fileName(fn)
	{
		currentLines = 0;
		noOfLine= 0;
		capacity = 100;
		data = new CString*[capacity];
		for (int i = 0; i < capacity; i = i + 1)
		{
			data[i] = 0;
		}
	}
	void start();
};
#endif