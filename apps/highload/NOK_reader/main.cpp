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
#include <memory>
#include <cstdint>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <condition_variable>

using namespace std;

int main(int argc, char **argv)
{
    try
    {
        deque<uint64_t> md; // main deque
        mutex mdm;
        condition_variable mdc;

        const int N = 4;
        thread threads[N];

        for (auto &t : threads)
        {
            t = thread([&]()
            {
                for(;;){
                    uint64_t nok = 0;
                    {
                        unique_lock<mutex> lock(mdm);
                        mdc.wait(lock);

                        nok = md.front();
                        md.pop_front();
                    }

                    // break;
                }

            });
        }

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

        for (auto &t : threads)
        {
            t.join();
        }
    }
    catch (const std::exception& e)
    {
        cerr << "error: " << e.what() << endl;
    }
    return 0;
}

