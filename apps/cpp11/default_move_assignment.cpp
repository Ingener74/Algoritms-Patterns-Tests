/*
 * default_move_assingment.cpp
 *
 *  Created on: 17 марта 2015 г.
 *      Author: pavel
 */

#include <iostream>
#include <vector>

using namespace std;

class Foo {
public:
    int testInt = 0;
    vector<int> test;

    Foo(int s) :
        testInt(s), test(s) {
    }

    friend ostream& operator<<(ostream& out, const Foo& r) {
        return out << r.testInt << " " << r.test.size();
    }
};

void foo(Foo t) {

    Foo temp = move(t);

    std::cout << __PRETTY_FUNCTION__ << " " << t << std::endl;
    std::cout << __PRETTY_FUNCTION__ << " " << temp << std::endl;
}

int main(int argc, char **argv) {
    try {
        cout << "default move assignment" << endl;

        foo(Foo { 100 });

    } catch (exception const & e) {
        cerr << e.what() << endl;
    }
}

