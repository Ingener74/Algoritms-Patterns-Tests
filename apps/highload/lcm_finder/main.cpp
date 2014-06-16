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
#include <iterator>
#include <stdexcept>
#include <condition_variable>

using namespace std;

/*
 * expand to prime numbers
 *
 * Use this algorithm
 * http://ru.wikipedia.org/wiki/%D0%9C%D0%B5%D1%82%D0%BE%D0%B4_%D0%BA%D0%B2%D0%B0%D0%B4%D1%80%D0%B0%D1%82%D0%B8%D1%87%D0%BD%D0%BE%D0%B3%D0%BE_%D1%80%D0%B5%D1%88%D0%B5%D1%82%D0%B0
 *
 */
vector<uint64_t> expand(uint64_t n)
{
    cout << "expand n = " << n << endl;

    if (n == 0) throw std::runtime_error("expand error");
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
            else
            {
//                cout << "2 n = " << n << " m = " << m << endl;
                continue;
            }
        }
        else
        {
            n /= m;
            multipliers.push_back(m);
            m = 2;
        }
//        cout << "n = " << n << " m = " << m << endl;
    }
    return multipliers;
}

int main(int argc, char **argv)
{
    try
    {
        cout << "lcm finder" << endl;

        if (argc != 2) throw std::runtime_error(""
                "You must pass number of threads\n"
                "Usage: ./lcm_finder <number-of-threads>");

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
        stringstream interpret;
        interpret << argv[1];
        int N = 4;
        interpret >> N;

        /*
         * futures for async tasks
         */
        thread status([&](){
            for(;;)
            {
                {
                    unique_lock<mutex> lock(mdm);
                    if(stop)
                    return;
                    cout << "size of deque " << md.size() << endl;
                }

                this_thread::sleep_for(chrono::seconds(3));
            }
        });

        vector<future<map<uint64_t, uint64_t>>> futures(N);

        for (auto &f : futures)
        {
            /*
             * creating async tasks
             */
            f = async(launch::async, [&]()
            {
                try
                {
                    map<uint64_t, uint64_t> res;
                    for(;;)
                    {
                        uint64_t nok = 0;
                        {
                            unique_lock<mutex> lock(mdm);
//                            if(md.empty())
//                            {
//                                mdc.wait(lock);
//                            }
//                            else if(stop)
//                            {
//                                return res;
//                            }

                            if(md.empty() && stop)
                            {
                                return res;
                            }
                            else if(md.empty())
                            {
                                mdc.wait(lock);
                            }

                            nok = md.front();
                            md.pop_front();
                        }

                        auto r = expand(nok);
                        if(r.empty())throw std::runtime_error("have no primi numbers");
                        for(auto &prime: r)
                        {
                            res[prime]++;
                        }
                    }
                }
                catch (const std::exception& e)
                {
                    cout << "async task error: " << e.what() << endl;
                }
            });
        }

        /*
         * getting numbers from stdin
         */

//        for (string line; cin >> line;)
//        {
//            uint64_t inputNumber;
//            stringstream inputStream;
//            inputStream << line;
//            inputStream >> inputNumber;
//            {
//                unique_lock<mutex> lock(mdm);
//                md.push_back(inputNumber);
//                mdc.notify_one();
//            }
//        }

        {
            unique_lock<mutex> lock(mdm);
            md = deque<uint64_t>((istream_iterator<uint64_t>(cin)),
                    (istream_iterator<uint64_t>()));
            mdc.notify_all();
        }

        cout << "getting all numbers from stdin" << endl;

        /*
         * stopping all threads
         */
        {
            unique_lock<mutex> lock(mdm);
            stop = true;
            mdc.notify_all();
        }

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
                if (p.second > nok[p.first]) nok[p.first] = p.second;
            }
        }

        /*
         * print result
         */
        cout << "lcm" << endl;
        for (auto &n : nok)
        {
            cout << "prime " << n.first << " power " << n.second << endl;
        }
    }
    catch (const std::exception& e)
    {
        cerr << "error: " << e.what() << endl;
    }
    return 0;
}

