/*
 * main.cpp
 *
 *  Created on: Jun 30, 2014
 *      Author: ingener
 */

#include <iostream>

using namespace std;

class Pony
{
public:
	Pony()
	{
	}
	virtual ~Pony()
	{
	}

	friend ostream& operator<<( ostream& out, const Pony& rho );

private:
	string pony_name_ = "Little Pony";
};
ostream& operator<<( ostream& out, const Pony& rho )
{
	out << rho.pony_name_;
	return out;
}

template <typename T>
void foo( T t )
{
	cout << t << endl;
}

template <typename T, typename ... Args>
void foo( T t, Args ... args )
{
	cout << t << endl;
	foo(args...);
}

namespace st
{

template <typename ... Args>
struct tuple;

template <typename Head, typename ... Tail>
struct tuple<Head, Tail...> : tuple<Tail...>
{
	tuple( Head h, Tail ... tail ) :
			tuple<Tail...>(tail...), head_(h)
	{
	}

	using base_type = tuple<Tail...>;
	using value_type = Head;

	base_type& base_ = static_cast<base_type&>(*this);
	Head head_;
};

template <>
struct tuple<>
{
};

}  // namespace st

int main( int argc, char **argv )
{
	try
	{
		foo("One", 2, "Three", Pony());

		st::tuple<double, const char*, const char*, int> testTuple(3.1415926, "Pi", "In america", 4);

		cout << testTuple.head_ << " " << testTuple.base_.head_ << " " << testTuple.base_.base_.head_ << " "
				<< testTuple.base_.base_.base_.head_ << endl;
	}
	catch ( exception const & e )
	{
		cerr << "Error: " << e.what() << endl;
	}
	return 0;
}

