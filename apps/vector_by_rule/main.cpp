/*
 * main.cpp
 *
 *  Created on: Jul 16, 2014
 *      Author: ingener
 */

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

template <typename T1, typename T2, typename F>
auto vector_by_rule( const vector<T1>& v1, const vector<T2>& v2, F&& rule ) -> vector<decltype(rule(v1[0], v2[0]))>
{
    if ( v1.empty() ) throw runtime_error("vector_by_rule: v1 empty");
    if ( v2.empty() ) throw runtime_error("vector_by_rule: v2 empty");
    if ( v1.size() != v2.size() ) throw runtime_error("vector_by_rule: v1 and v2 have different size");

    vector<decltype(rule(v1[0], v2[0]))> result;
    for ( size_t i = 0; i < v1.size(); ++i )
    {
        result.push_back(rule(v1[ i ], v2[ i ]));
    }
    return result;
}

int main( int argc, char **argv )
{
    try
    {
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

        auto longitudes = vector_by_rule(test1, coords, [](const string& city, const pair<double, double>& coord)
        {
            return pair<string, double>(city, coord.second);
        });

        for(auto& i: longitudes){
            cout << "city " << right << setw(14) << i.first << ", destination " << i.second << endl;
        }
    }
    catch ( exception const & e )
    {
    }
    return 0;
}

