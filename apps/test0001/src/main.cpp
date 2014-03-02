
#include <iostream>

#include <boost/smart_ptr.hpp>

class ITest {
public:
    typedef boost::shared_ptr<ITest> ptr;

    virtual ~ITest(){
        std::cout << "ITest::~ITest()" << std::endl;
    }

    virtual void print() = 0;

protected:
    ITest(){}
};

class SimpleTest : public ITest{
public:
    SimpleTest(){}
    virtual ~SimpleTest(){
        std::cout << "SimpleTest::~SimpleTest()" << std::endl;
    }

    virtual void print(){
        std::cout << "SimpleTest->print()" << std::endl;
    }

private:
};

int main(int argc, const char *argv[])
{
    std::cout << "test 0001" << std::endl;

    ITest::ptr test = ITest::ptr(new SimpleTest());
    test->print();

    return 0;
}
