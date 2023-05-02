#pragma once

#include <iostream>
using namespace std;

class ObjBase
{
public:
	virtual ~ObjBase();
	virtual string toString() const = 0;
};

ostream& operator << (ostream&, const ObjBase&);



