#pragma once
#include<string>
using namespace std;

class Base
{
private:
	string _firma;
public:
	Base();
	Base(string __f) { _firma = __f; };
	~Base();
	string getFirma();
};

