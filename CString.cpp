#include<iostream>
#include"CString.h"
using namespace std;
CString::CString()
{
	size = 0;
	data = nullptr;
}
CString::CString(const char c)
{
	data = new char[2]{ c,'\0' };
	size = 2;
}
CString::CString(const char *a)
{
	int length = getLengthString(a);
	{
		size = length + 1;
		data = new char[size];
		copyString(data, a);
	}
}
CString::CString(const char & a)
{
	int length = getLengthString(&a);
	size = length + 1;
	data = new char[size];
	copyString(data, &a);
}
CString::~CString()
{
	if (data)
	{
		delete[]data;
		data = nullptr;
		size = 0;
	}
}

CString::CString(const CString & obj)
{
	if (obj.data == 0)
	{
		data = nullptr;
		size = 0;
	}
	else
	{
		size = obj.size;
		data = new char[size];
		copyString(data, obj.data);
	}
}

void CString::input()
{

	char a = 0;
	int i = 10;
	int j = 0;
	if (data)
	{
		~CString();
	}
	size = i;
	data = new char[size];
	
	do
	{
		j = j + 1;
		cin.get(a);
		if (size>= j)
		{

			reSize(size * 2);
		}

		data[j - 1] = a;
	
	} while (a != '\n');

	data[j] = '\0';
	
}
void CString::shrink()
{
	int LengthOfData = getLengthString(data);
	reSize(LengthOfData);
}
int CString::getLengthString(const char*a)const
{
	int i = 0;
	while (a[i] != '\0')
	{
		i = i + 1;
	}
	return i;
}
char & CString::operator[](int index)const
{
	char a;
	a = data[index];
	return a;
}
bool CString::isEmpty()
{
	if (size >= 0)
	{
		if (data[0] == '\0')
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}
int CString::getLength()const
{
	int i = 0;
	while (data[i] != '\0')
	{
		i = i + i;
	}
	return i;
}
void CString::dsiplay()const
{
	int i = 0;
	while (data[i] != '\0')
	{
		cout << data[i];
		i = i + 1;
	}
}
int CString::find(CString * subStr, int start)
{
	int i = 0;
	int j = 0;
	int locationPoint;
	int value = getLengthString(data);
	int length = getLengthString(subStr->data);
	while (data[i] != '\0')
	{

		if (data[i] == subStr->data[j])
		{
			locationPoint = i;
			while (subStr->data[j] != '\0')
			{
				if (data[locationPoint] == subStr->data[j])
				{
					start = start + 1;
				}
				locationPoint = locationPoint + 1;
				j = j + 1;
			}
			if (start == length)
			{

				return i;
			}
			else
			{
				start = 0;
				j = 0;
			}
		}

		i = i + 1;
	}
	return 0;



}
void CString::insert(int index, CString*subStr)
{
	int i = 0;
	int j = 0;
	int value = getLengthString(subStr->data);
	int length = getLengthString(data);
	size = size + value;
	reSize(size + 1);
	while (data[i] != '\0')
	{
		if (i == index)
		{
			while (length > 0)
			{
				data[length + value] = data[length];
				length = length - 1;
			}
			while (subStr->data[j] != '\0')
			{
				data[i] = subStr->data[j];
				j = j + 1;
				i = i + 1;
			}

		}
		i = i + 1;
	}
	data[i] = '\0';
}
void CString::trim()
{
	trimLeft();
	trimRight();
}
void CString::makeUpper()
{
	int i = 0;
	int data_Length = getLengthString(data);
	while (data[i] != '\0')
	{
		if (97 <= data[i] && data[i] <= 122)
		{
			data[i] = data[i] - 32;
		}

		i = i + 1;
	}
}
void CString::makeLower()
{
	int i = 0;
	int data_Length = getLengthString(data);
	while (data[i] != '\0')
	{
		if (65 <= data[i] && data[i] <= 90)
		{
			data[i] = data[i] + 32;
		}

		i = i + 1;
	}

}
void CString::remove(int index, int count)
{
	int i = 0;
	while (data[i] != '\0')
	{
		if (i == index)
		{
			while (count > 0)
			{
				while (data[i] != '\0')
				{
					data[i] = data[i + 1];
					i = i + 1;
				}
				count = count - 1;
				i = index;
			}

		}
		i = i + 1;
	}
	data[i] = '\0';
}
void CString::copyString(char * destination, const char * source)
{

	int i = 0;
	int value = getLengthString(source);
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i = i + 1;
	}
	destination[value] = '\0';

}
void CString::copyDelim(char * destination, const char * source, int count)
{
	int i = 0;
	while (count > 0)
	{
		destination[i] = source[i];
		i = i + 1;
		count = count - 1;
	}
	destination[i] = '\0';

}
void CString::reSize(int newCapacity)
{
	if (data)
	{
		char *temp = new char[newCapacity];
		int i = 0;
		while (i < newCapacity&&i < size)
		{
			temp[i] = data[i];
			i = i + 1;
		}

		temp[i] = '\0';
		delete[] data;
		data = 0;
		size = newCapacity;
		data = temp;
	}
	else
	{	
		size = newCapacity;
		data = new char[size];
		data[0] = '\0';
	}

}
int CString::replace(CString *old, CString * newSubStr)
{
	char *a = new char[50];
	int i = 0;
	int j = 0;
	if (old->size > newSubStr->size)
	{
		newSubStr->reSize(old->size);
	}
	else if (old->size < newSubStr->size)
	{
		old->reSize(newSubStr->size);
	}
	while (old->data[i] != '\0' || newSubStr->data[i] != '\0')
	{
		a[i] = old->data[i];
		old->data[i] = newSubStr->data[i];
		newSubStr->data[i] = a[i];
		i = i + 1;
	}
	newSubStr->data[i] = '\0';
	old->data[i] = '\0';

	delete[]a;
	a = nullptr;
	return 0;
}
CString & CString::operator=(const CString & ref)
{
	if (this == &ref)
	{
		return *this;
	}
	if (!ref.data)
	{
		data = nullptr;
		size = 0;
	}
	data = new char[ref.size];
	for (int i = 0; i < ref.size; i = i + 1)
	{
		data[i] = ref.data[i];
	}
	return *this;
}
void CString::trimLeft()
{
	int i = 0;
	int count = 0;
	while (data[i] != '\0')
	{
		if (data[i] != ' ')
		{
			count = 1;
		}
		if (count == 0)
		{
			while (data[i] == ' ')
			{
				remove(i, 1);
			}
		}
		size = size - 1;
		i = i + 1;
	}
	data[i + 1] = '\0';


}

void CString::trimRight()
{
	int i = 0;
	int value = getLengthString(data);
	int c = 0;
	while (data[i] != '\0')
	{
		if (data[value - 1] == ' ')
		{
			c = c + 1;
			value = value - 1;
		}
		else
		{
			data[value] = '\0';
		}
		i = i + 1;
	}

}
int CString::compare(CString s2)const
{
	int count = 0;
	int i = 0;
	int data_Length = getLengthString(data);
	int s2_length = getLengthString(s2.data);
	if (data_Length == s2_length)
	{
		while (s2.data[i] != '\0')
		{
			if (data[i] == s2.data[i])
			{
				count = count + 1;
			}
			i = i + 1;
		}
	}
	if (count == s2_length)
	{
		return 0;
	}
	else
	{
		cout << "Not equal" << endl;
		return 1;
	}
}
CString CString::left(int count)
{
	int i = 0;
	int j = 0;
	int Length = getLengthString(data);
	while (count > 0)
	{
		while (data[j] != '\0')
		{
			data[j] = data[j + 1];
			j = j + 1;
		}
		j = 0;
		i = i + 1;
		Length = Length - 1;
		count = count - 1;
	}
	data[Length] = '\0';
	return data;
}
void CString::reverse()
{
	int i = 0;
	int value = getLengthString(data);
	char temp = 0;
	while (data[i] != '\0')
	{
		if (value - 1 > i)
		{
			temp = data[i];
			data[i] = data[value - 1];
			data[value - 1] = temp;
			value = value - 1;

		}
		i = i + 1;
	}
}
CString CString::right(int count)
{
	int i = 1;
	int j;
	j = i;
	int Length = getLengthString(data);
	int value = Length;
	while (count >= 0)
	{
		data[Length] = '\0';
		Length = Length - 1;
		count = count - 1;
	}
	return data;
}
int CString::tolnteger() const
{
	int i = 0;
	int total = 0;
	int num = 0;

	while (data[i] != '\0')
	{
		num = (int)data[i];
		total = total * 10 + (num - 48);
		i = i + 1;
	}
	return total;
}

float CString::tofloat() const
{

	int i = 0;
	float total = 0;
	float num = 0;
	float value = 0;
	while (data[i] != '\0')
	{
		while (data[i] != '.')
		{
			num = (int)data[i];
			total = total * 10 + (num - 48);
			i = i + 1;
		}
		while (data[i] != '\0')
		{
			num = (int)data[i];
			value = (value + (num - 48)) / 10;
			i = i + 1;
		}

	}
	return (total + value);


}
CString CString::operator+(CString s2)const
{
	int i = 0;
	int j = 0;
	int length = getLengthString(data);
	int value = getLengthString(s2.data);
	int copy1 = length;
	int copy2 = value;
	int total = length + value + 1;
	char *temp;
	temp = new char[total];
	while (length > 0)
	{
		temp[i] = data[i];
		i = i + 1;
		length = length - 1;
	}
	while (value > 0)
	{
		temp[i] = s2.data[j];
		i = i + 1;
		j = j + 1;
		value = value - 1;
	}
	CString d;
	d.size = total;
	d.data = temp;

	d.data[total-1] = '\0';
	return d;
}

void CString::concatEqual(CString s2)
{
	int i = 0;
	int length = getLengthString(data);
	int value = getLengthString(s2.data);
	size = size + value;
	reSize(size);
	while (s2.data[i] != '\0')
	{
		data[length] = s2.data[i];
		length = length + 1;
		i = i + 1;
	}
	data[length] = '\0';

}
CString CString::tokenzie(CString delim)
{
	int i = 0;
	int j = 0;
	int value = 0;
	int getLength = getLengthString(data);
	while (data[i] != '\0')
	{
		while (delim.data[j] != '\0')
		{
			if (data[i] == delim.data[j])
			{
				value = i + 1;
				delim.data[j + 1] = '\0';
			}
			j = j + 1;
		}
		j = 0;
		i = i + 1;
	}
	delim.reSize(100);
	copyDelim(delim.data, data, value);
	left(value);
	//reSize(getLength - value);
	delim.operator+(delim.data);

	return delim;

}
CString::operator int()
{
	return this->tolnteger();
}
CString & CString::operator++()
{
	*this = (*this + *this);
	return *this;

}
CString CString::operator++(int a)
{
	CString t(*this);
	*this = *this + *this;
	return t;
}
CString::operator float()
{
	return this->tofloat();
}
//bool & CString::operator<=(CString & a)
//{	
//	if (this->data == a.data)
//	{
//		return true;
//	}
//	if (this->data <= a.data)
//	{
//		return true;
//	}
//	if (this->data > a.data)
//	{
//		return false;;
//	}
//
//}
//bool & CString::operator>=(CString & a)
//{
//
//	if (this->data == a.data)
//	{
//		return true;
//	}
//	if (this->data >= a.data)
//	{
//		return true;
//	}
//	if (this->data < a.data)
//	{
//		return false;;
//	}
//}
//bool & CString::operator==(const CString & a)
//{
//	if (this->data == a.data)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
bool CString::operator>(const CString & a)
{
	if (this->data > a.data)
		return true;
	else
		return false;
}
bool CString::operator<(const CString & a)
{
	if (this->data < a.data)
		return true;
	else
		return false;
}
CString & CString::operator+=(int a)
{
	CString temp(*this);
	for (int i = 0; i < a; i = i + 1)
	{
		temp = temp + *this;
	}
	return temp;
}
ostream & operator<<(ostream &x, const CString & ref)
{
	ref.dsiplay();
	return cout;
}
istream & operator>>(istream &x, CString & ref)
{
	ref.input();
	return cin;
}