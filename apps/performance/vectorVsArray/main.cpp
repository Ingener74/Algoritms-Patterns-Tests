/*
 * main.cpp
 *
 *  Created on: Jun 19, 2014
 *      Author: ingener
 */

#include <chrono>
#include <vector>
#include <iostream>

using namespace std;

class TimeMeasure
{
public:
    TimeMeasure()
    {
        start();
    }
    void start()
    {
        m_start = now();
    }
    int elapsed_ms() const
    {
        return elapsed<std::chrono::milliseconds>();
    }
    int elapsed_mks() const
    {
        return elapsed<std::chrono::microseconds>();
    }

private:
    template<class D>
    int elapsed() const
    {
        return std::chrono::duration_cast<D>(now() - m_start).count();
    }
    const std::chrono::system_clock::time_point now() const
    {
        return std::chrono::system_clock::now();
    }
    std::chrono::system_clock::time_point m_start;
};

template<class F>
int measure_ms(const char * const text, F f)
{
    TimeMeasure m;
    f();
    int t = m.elapsed_ms();
//    std::cout << text << " : " << t << " ms." << std::endl;
    return t;
}

template<class F>
int measure_mks(const char * const text, F f)
{
    TimeMeasure m;
    f();
    int t = m.elapsed_mks();
//    std::cout << text << " : " << t << " mks." << std::endl;
    return t;
}

int main(int argc, char **argv)
{
    try
    {
        cout << "vector vs. c array" << endl;

        const int N = 10000000, M = 100;

        int *c_array = new int[N];
        vector<int> vector_(N);

        vector<int> c_arr, vec_;

        for(int j = 0; j < M; ++j){
            c_arr.push_back(
                measure_ms("c array access speed test: ", [&]()
                {
                    for(int i = 0; i < N; ++i)
                    {
                        int n = c_array[i];
                    }
                })
            );
            vec_.push_back(measure_ms("vector access speed test:  ", [&]()
                {
                    for(int i = 0; i < N; ++i)
                    {
                        int n = vector_[i];
                    }
                })
            );
        }

        int average_c_array = 0, average_vector = 0;
        for(int i = 0; i < M; ++i){
            average_c_array += c_arr[i];
            average_vector  += vec_[i];
        }

        average_c_array /= M;
        average_vector  /= M;

        cout << "c_array average speed = " << average_c_array << " ms" << endl;
        cout << "vector  average speed = " << average_vector << " ms" << endl;

        cout << "C array vs. vector    = " << double(average_c_array) / double(average_vector) << endl;
        cout << "vector  vs. C array   = " << double(average_vector)  / double(average_c_array) << endl;

        delete[] c_array;
    }
    catch (exception const & e)
    {
        cout << "error: " << e.what() << endl;
    }
    return 0;
}

