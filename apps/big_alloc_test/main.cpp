/*
 * main.cpp
 *
 *  Created on: Apr 29, 2014
 *      Author: ingener
 */

#include <chrono>
#include <iostream>

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
    std::cout << text << " : " << t << " ms." << std::endl;
    return t;
}

template<class F>
int measure_mks(const char * const text, F f)
{
    TimeMeasure m;
    f();
    int t = m.elapsed_mks();
    std::cout << text << " : " << t << " mks." << std::endl;
    return t;
}

int main_big_alloc_speed(int argc, char **argv) {

    const int t = 5;
    const int M[t] = {
            30,
            300,
            3000,
            300000,
            3000000
    };
    const int N[t] = {
            10000000,
            1000000,
            100000,
            1000,
            100
    };

    for (int i = 0; i < t; ++i) {
        [](int m, int n){
            int with = measure_ms("with alloc", [&m, &n](){
                for (int i = 0; i < n; ++i) {
                    uint8_t * p = new uint8_t[m];

                    uint8_t * pp = p;
                    for (int j = 0; j < m; ++j) {
                        *pp++ = j;
                    }

                    delete [] p;
                }
            });

            uint8_t * p = new uint8_t[m];
            int without = measure_ms("without alloc", [p, &m, &n](){
                for (int i = 0; i < n; ++i) {

                    uint8_t * pp = p;
                    for (int j = 0; j < m; ++j) {
                        *pp++ = j;
                    }
                }
            });

            double d = with / double(without) * 100.0;
            std::cout << "m = " << m << ", n = " << n << ", d = " << d << std::endl;

        }(M[i], N[i]);
    }

    return 0;
}


int main(int argc, char **argv) {
    std::cout << "tests" << std::endl;

    main_big_alloc_speed(argc, argv);

    return 0;
}



