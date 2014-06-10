/*
 * main.cpp
 *
 *  Created on: Apr 30, 2014
 *      Author: pavel
 */

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <memory>

class Dummy
{
};

class IWarrior
{
public:
    using Ptr = std::shared_ptr<IWarrior>;
    using Hit = int;

    virtual ~IWarrior()
    {
    }

    virtual Hit fight() = 0;
    virtual IWarrior::Ptr clone() = 0;

    static IWarrior::Ptr createWarrior(const std::string& type)
            throw (std::runtime_error)
    {
        if (reg.find(type) == reg.end())
            throw std::runtime_error(type + " - Unknown warrior type");
        return reg[type]->clone();
    }

protected:
    static void Register(const std::string& type, IWarrior::Ptr warrior)
    {
        reg[type] = warrior;
    }
    IWarrior()
    {
    }

private:
    static std::map<std::string, IWarrior::Ptr> reg;
};
std::map<std::string, IWarrior::Ptr> IWarrior::reg;

/*
 * Concrete prototype
 */
class Soldat: public IWarrior, public std::enable_shared_from_this<Soldat>
{
public:
    virtual ~Soldat()
    {
    }
    Hit fight()
    {
        return 10;
    }
    virtual IWarrior::Ptr clone()
    {
        return IWarrior::Ptr(new Soldat);
    }

private:
    Soldat(Dummy)
    {
        Register("Soldat", _prototype = IWarrior::Ptr(new Soldat));
    }
    Soldat()
    {
    }
    static Soldat::Ptr _prototype;
};
Soldat::Ptr Soldat::_prototype = IWarrior::Ptr(new Soldat(Dummy()));

/*
 * another concrete class
 */
class Bug: public IWarrior, public std::enable_shared_from_this<Bug>
{
public:
    virtual ~Bug()
    {
        std::cout << "~Bug()" << std::endl;
    }
    virtual Hit fight()
    {
        return 33;
    }
    virtual IWarrior::Ptr clone()
    {
        return IWarrior::Ptr(new Bug());
    }

private:
    Bug(Dummy)
    {
        std::cout << "Bug(Dummy)" << std::endl;
        _prototype = IWarrior::Ptr(new Bug);
        Register("Bug", _prototype);
    }
    Bug()
    {
        std::cout << "Bug()" << std::endl;
    }
    static Bug::Ptr _prototype;
};
Bug::Ptr Bug::_prototype = IWarrior::Ptr(new Bug(Dummy()));

int main_prototype_class_based(int argc, char **argv) {
    std::cout << "main" << std::endl;
    try
    {
        auto warrior1 = IWarrior::createWarrior("Soldat");

        std::cout << "warrior hit " << warrior1->fight() << std::endl;

        auto warrior2 = IWarrior::createWarrior("Bug");

        std::cout << "warrior hit " << warrior2->fight() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "exception: " << e.what() << std::endl;
    }
    return 0;
}

int main(int argc, char **argv) {

    main_prototype_class_based(argc, argv);

    return 0;
}


