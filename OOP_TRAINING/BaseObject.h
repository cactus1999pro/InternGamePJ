#pragma once
#include<iostream>
using namespace std;
#ifndef _base_object_h
#define _base_object_h
class BaseObject
{
public:
	int id;
	string name;
	int x;
	int y;

	BaseObject();
	BaseObject(int id, string name, int x, int y);
	~BaseObject();
	void setId(int id);
	int getId();
	void setName(string name);
	string getName();
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();
	virtual void printPosition();

	void move();
	virtual void move(int x, int i);
};
#endif
