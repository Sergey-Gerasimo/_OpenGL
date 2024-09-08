#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <iostream>
template <class T>
class Singleton 
{
protected:
	Singleton(){};
	Singleton(const Singleton&);

public:
	static T& ()
	{
		static T instance;

		return instance;
	}
};

#endif