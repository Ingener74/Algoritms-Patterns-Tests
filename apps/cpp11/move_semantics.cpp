/*
 * move_semantics.cpp
 *
 *  Created on: 27 февр. 2015 г.
 *      Author: pavel
 */

#include <vector>
#include <chrono>
#include <iostream>
#include <stdexcept>

using namespace std;

class TimeMeasure {
public:
    TimeMeasure() {
        start();
    }
    void start() {
        m_start = now();
    }
    int elapsed_ms() const {
        return elapsed<chrono::milliseconds>();
    }
    int elapsed_mks() const {
        return elapsed<chrono::microseconds>();
    }

private:
    template<class D>
    int elapsed() const {
        return chrono::duration_cast<D>(now() - m_start).count();
    }
    const chrono::system_clock::time_point now() const {
        return chrono::system_clock::now();
    }
    chrono::system_clock::time_point m_start;
};

template<class F>
int measure_ms(const string& text, F f) {
    TimeMeasure m;
    f();
    int t = m.elapsed_ms();
    cout << text << " : " << t << " ms." << endl;
    return t;
}

template<class F>
int measure_mks(const string& text, F f) {
    TimeMeasure m;
    f();
    int t = m.elapsed_mks();
    cout << text << " : " << t << " mks." << endl;
    return t;
}

void foo1(const vector<double>& v) {
    double sum = 0.0;
    for (size_t i = 0; i < v.size(); ++i) {
        sum += v [ i ];
    }
}

void foo2(vector<double> v) {
    double sum = 0.0;
    for (size_t i = 0; i < v.size(); ++i) {
        sum += v [ i ];
    }
}

void foo3(vector<double> && v) {
    double sum = 0.0;
    for (size_t i = 0; i < v.size(); ++i) {
        sum += v [ i ];
    }
}

vector<double> genVector() {
    vector<double> v;
    v.resize(10000000);
    for (int i = 0; i < v.size(); ++i) {
        v [ i ] = i;
    }
    return move(v);
}

int main(int argc, char **argv) {

    cout << genVector().size() << endl;

    try {
        measure_ms("foo1", []() {
            foo1(genVector());
        });

        measure_ms("foo2", []() {
            foo2(genVector());
        });

        measure_ms("foo3", []() {
            foo3(genVector());
        });

        cout << endl;

        measure_ms("foo4", []() {
            auto t = genVector();
            foo1(t);
        });

        measure_ms("foo5", []() {
            auto t = genVector();
            foo2(t);
        });

//        measure_ms("foo6", []() {
//            auto t = genVector();
//            foo3(t);
//        });

    } catch (exception const & e) {
        cerr << e.what() << endl;
    }
}

