#include<iostream>
using namespace std;
#include"IEditor.h"

void IEditor::start()
{
	fileName.dsiplay(); cout << endl;
	for (int i = 0; i < 3; i = i + 1)
	{
		cout << i+1<<">";
		data[i] =new CString();
		data[i]->input();
		currentLines = currentLines + 1;
	}
	int line = currentLines-1;
	CString temp;
	CString temp2;
	for (int i = 0; i < 20; i = i + 1)
	{
		char a;
		cin >> a;
		if (a == 'l' || a == 'L')
		{
			for (int i = 0; i < 3; i = i + 1)
			{
				data[i]->dsiplay();
			}
		}
		else if(a=='A'||a=='a')
		{
			temp.input();
			*data[line]=(*(data[line]))+temp;
		}
		else if (a == 'i' || a == 'I')
		{
			currentLines = currentLines - 1;
			temp2.input();
			data[currentLines] = &(temp+temp2);
		}
	}
}
