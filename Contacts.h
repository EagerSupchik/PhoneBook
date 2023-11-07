#pragma once
#include <fstream>
#include <vector>

class Contacts
{
private:
	char* fullname;
	int homep;
	int workp;
	int mobilep;
	char* adds;

public:
	Contacts()
	{
		fullname = nullptr;
		std::cout << fullname;
		homep = 0;
		workp = 0;
		mobilep = 0;
		adds = nullptr;
	}

	Contacts(const char* name, int h, int w, int m, const char* add)
	{
		fullname = new char[strlen(name) + 1];
		strcpy_s(fullname, strlen(name)+1, name);
		homep = h;
		workp = w;
		mobilep = m;
		adds = new char[strlen(add) + 1];
		strcpy_s(adds, strlen(add)+1, add);
	}

	~Contacts()
	{
		delete[] fullname;
		delete[] adds;
	}

	inline void setname(const char* name) 
	{
		delete[] fullname;
		fullname = new char[strlen(name) + 1];
		strcpy_s(fullname, strlen(name)+1, name);
	}

	inline void sethp(int phone) 
	{
		homep = phone;
	}

	inline void setwp(int phone) 
	{
		workp = phone;
	}

	inline void setmp(int phone) 
	{
		mobilep = phone;
	}

	inline void setadds(const char* add)
	{
		delete[] adds;
		adds = new char[strlen(add) + 1];
		strcpy_s(adds, strlen(add)+1, add);
	}


	inline const char* getname() const
	{ 
		return fullname; 
	}

	inline int gethp() const 
	{
		return homep;
	}

	inline int getwp() const 
	{
		return workp;
	}

	inline int getmp() const
	{
		return mobilep;
	}

	inline const char* getadds() const
	{
		return adds;
	}

};