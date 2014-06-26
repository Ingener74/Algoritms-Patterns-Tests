/*
 * main.cpp
 *
 *  Created on: Jun 23, 2014
 *      Author: pavel
 */

#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <memory>
#include <iterator>

using namespace std;

using Resource = shared_ptr<istream>;

class ResourceFactory
{
public:
    class IFactory
    {
    public:
        using Ptr = shared_ptr<IFactory>;

        virtual ~IFactory()
        {
        }
        virtual Resource create(const string& path) = 0;
    };

    static Resource createResource(const string& path)
    {
        return getRegistry().back()->create(path);
    }
    static void pushResourceFactory(IFactory::Ptr factory)
    {
        getRegistry().push_back(factory);
    }
    static void popResourceFactory()
    {
        if (getRegistry().size() > 1) getRegistry().pop_back();
    }

private:
    ResourceFactory()
    {
    }
    using FactoryRegistry = list<IFactory::Ptr>;

    static FactoryRegistry& getRegistry()
    {
        static FactoryRegistry reg;
        if (reg.empty())
        {
            class ifstream_Factory: public IFactory
            {
            public:
                virtual Resource create(const string& path)
                {
                    return make_shared<ifstream>(path);
                }
            };
            reg.push_back(make_shared<ifstream_Factory>());
        }
        return reg;
    }
};

int main(int argc, char **argv)
{
//    Resource foo = ResourceFactory::createResource("resources/foo.res");
//    Resource bar = ResourceFactory::createResource("resources/bar.res");

    try
    {
        {
            ofstream test_file("test_file", ios::trunc);
            test_file << "Resource concept" << endl;
            test_file.flush();
            test_file.close();
        }

        Resource testResource = ResourceFactory::createResource("test_file");

        string testString((istream_iterator<char>(*testResource)), istream_iterator<char>());

        cout << "test string " << testString << endl;
    }
    catch (exception const & e)
    {
        cerr << "error: " << e.what() << endl;
    }

    return 0;
}

