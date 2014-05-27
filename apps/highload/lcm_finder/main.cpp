/*
 * main.cpp
 *
 *  Created on: May 26, 2014
 *      Author: ingener
 */

#include <map>
#include <deque>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include <memory>
#include <future>
#include <cstdint>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <condition_variable>

using namespace std;

/*
 * expand to prime numbers
 */
vector<uint64_t> expand(uint64_t n)
{
    vector<uint64_t> multipliers;
    uint64_t m = 2;
    while (n != 1)
    {
        if (n % m)
        {
            if (++m == n)
            {
                multipliers.push_back(m);
                break;
            }
        }
        else
        {
            n /= m;
            multipliers.push_back(m);
            m = 2;
        }
    }
    return multipliers;
}

int main(int argc, char **argv)
{
    try
    {
        cout << "lcm finder" << endl;

        /*
         * main deque
         */
        deque<uint64_t> md;
        mutex mdm;
        condition_variable mdc;
        /*
         * stop flag
         */
        bool stop = false;

        /*
         * number of threads
         */
        const int N = 4;

        /*
         * futures for async tasks
         */
        future<map<uint64_t, uint64_t>> futures[N];

        for (auto &f : futures)
        {
            /*
             * creating async tasks
             */
            f = async(launch::async, [&]()
            {
                map<uint64_t, uint64_t> res;
                for(;;)
                {
                    uint64_t nok = 0;
                    {
                        unique_lock<mutex> lock(mdm);
                        if(md.empty())
                        {
                            mdc.wait(lock);
                        }
                        else if(stop)
                        {
                            return res;
                        }
                        nok = md.front();
                        md.pop_front();
                    }

                    auto r = expand(nok);
                    for(auto &prime: r)
                    {
                        res[prime]++;
                    }
                }
            });
        }

        /*
         * getting numbers from stdin
         */
        string line;
        while (cin >> line)
        {
            uint64_t inputNumber;
            stringstream inputStream;
            inputStream << line;
            inputStream >> inputNumber;
            {
                unique_lock<mutex> lock(mdm);
                md.push_back(inputNumber);
                mdc.notify_one();
            }
        }

        /*
         * stopping all threads
         */
        stop = true;
        mdc.notify_all();

        /*
         * collect all the eggs in one basket :)
         */
        map<uint64_t, uint64_t> nok;
        for (auto &f : futures)
        {
            auto r = f.get();

//            cout << "thread " << endl;
            for (auto& p : r)
            {
//                cout << "prime is " << p.first << " power " << p.second << endl;
                if(p.second > nok[p.first])
                    nok[p.first] = p.second;
            }
        }

        /*
         * print result
         */
        cout << "lcm" << endl;
        for(auto &n: nok){
            cout << "prime " << n.first << " power " << n.second << endl;
        }
    }
    catch (const std::exception& e)
    {
        cerr << "error: " << e.what() << endl;
    }
    return 0;
}

