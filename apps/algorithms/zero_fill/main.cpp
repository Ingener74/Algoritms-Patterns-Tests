#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

struct Mat
{
    int n = 0, m = 0;
    vector<int> d;
    Mat(int n, int m, vector<int> v = vector<int>()) :
            n(n), m(m), d(v.empty() ? vector<int>(n * m) : v)
    {
    }
    virtual ~Mat()
    {
    }
    int getN() const
    {
        return n;
    }
    int getM() const
    {
        return m;
    }
    inline int& operator()(int i, int j)
    {
        return d[i * m + j];
    }
};

ostream& operator<<(ostream& sout, const Mat& m)
{
    sout << "Matrix: " << m.n << " x " << m.m;
    for (int i = 0; i < m.n; ++i)
    {
        sout << endl;
        for (int j = 0; j < m.m; ++j)
        {
            sout << m.d[i * m.m + j] << " ";
        }
    }
    return sout;
}

void fill(Mat& mat)
{
    int rowsToFill = 0;
    for (int i = 0; i < mat.getN(); ++i)
    {
        bool filly = false;
        bool fillx = false;

        for (int j = 0; j < mat.getM(); ++j)
        {
            if (mat(i, j) == 0)
            {
                for (int jj = 0; jj < j; ++jj)
                {
                    mat(i, jj) = 0;
                }
                for (int ii = 0; ii < i; ++ii)
                {
                    mat(ii, j) = 0;
                }
                if (!fillx) rowsToFill++;
                filly = true;
                fillx = true;
            }
            else
            {
                if (fillx)
                {
                    mat(i, j) = 0;
                }
                if (i >= 1 && mat(i - rowsToFill - 1, j) == 0)
                {
                    mat(i, j) = 0;
                }
            }
        }
        if (!filly) rowsToFill = 0;
    }
}

int main(int argc, char* argv[])
{

    {
        Mat m(6, 7,
        {
            1, 1, 1, 1, 1, 1, 1,
            1, 0, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1,
        });

        m(2, 2) = 0;
        m(2, 3) = 0;

        cout << "m = " << endl << m << endl;
    }

    cout << endl << "test 1" << endl;
    {
        Mat m(3, 3,
        {
            0, 0, 0,
            1, 1, 1,
            1, 1, 1
        });
        cout << m << endl;

        fill(m);

        cout << m << endl;
    }

    cout << endl << "test 2" << endl;
    {
        Mat m(3, 3,
        {
            1, 1, 1,
            1, 1, 1,
            1, 1, 1
        });
        cout << m << endl;

        fill(m);

        cout << m << endl;
    }

    cout << endl << "test 3" << endl;
    {
        Mat m(3, 3,
        {
            0, 1, 1,
            1, 1, 1,
            1, 1, 0
        });
        cout << m << endl;

        fill(m);

        cout << m << endl;
    }

    return 0;
}

