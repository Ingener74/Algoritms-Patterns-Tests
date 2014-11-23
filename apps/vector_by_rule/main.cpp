/*
 * main.cpp
 *
 *  Created on: Jul 16, 2014
 *      Author: ingener
 */

#include <vector>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <algorithm>

#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

template<typename T>
pair<bool, size_t> is_vectors_equal( const vector<T>& v )
{
	return make_pair( true, v.size() );
}
template<typename T, typename... Args>
pair<bool, size_t> is_vectors_equal( const vector<T>& v, const vector<Args>&... vpp)
{
	return make_pair( v.size() == is_vectors_equal(vpp...).second ? true : false, v.size() );
}

template<typename T>
bool is_vector_empty( const vector<T>& v )
{
	return v.empty();
}
template<typename T, typename... Args>
bool is_vector_empty( const vector<T>& v, const vector<Args>&... vwpp )
{
	return v.empty() && is_vector_empty(vwpp...);
}

template<typename F, typename ... Args>
auto vector_by_rule( F&& rule, const vector<Args>&... vpp ) -> vector<decltype(rule(vpp[0]...))>
{
	if ( is_vector_empty( vpp... ) ) throw runtime_error( "vector_by_rule: someone from vectors is empty" );

	auto vs = is_vectors_equal( vpp... );
	if ( !vs.first ) throw runtime_error( "vector_by_rule: vectors have different size" );

	vector<decltype(rule(vpp[0]...))> result;
	for ( size_t i = 0; i < vs.second; ++i )
	{
		result.push_back( rule( vpp[i]... ) );
	}
	return result;
}


string operator"" _str(const char* data, size_t size){
    return string(data);
}

int main( int argc, char **argv )
{
    try
    {
        auto str1 = "bla bla"_str;

        vector<string> test1 {
            "New York",
            "Moscow",
            "London",
            "Tokio"
        };

        vector<pair<double, double> > coords{
            {40.42, 74.00},
            {55.45, 37.36},
            {51.32, 0.5},
            {35.40, 139.45}
        };

        auto longitudes = vector_by_rule([](const string& city, const pair<double, double>& coord)
        {
            return pair<string, double>(city, coord.second);
        }, test1, coords);

        for(auto& i: longitudes){
            cout << "city " << right << setw(14) << i.first << ", destination " << i.second << endl;
        }

		for ( auto &i :
				vector_by_rule(
					[](const string& r, double d)
					{
						return string("Pi in ") + r + " equal " + lexical_cast<string>(d);
					},
					vector<string>{ "Russia", "America"/*, "France" */},
					vector<double>{ /*3.1415, 2.72 */}
				)
			)
		{
			cout << i << endl;
		}

        for(auto i: vector_by_rule([](const string& planet, double size){ return make_pair(planet, size); }, vector<string>{"Mercury", "Venus", "Earth", "Mars", "Jupiter"}, vector<double>{0.3, 0.98, 1.0, 0.5, 11.0})){
            cout << i.first << ", " << i.second << endl;
        }

    }
    catch ( std::exception const & e )
    {
    	cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

