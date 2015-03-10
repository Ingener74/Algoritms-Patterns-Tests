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
#include <list>

using namespace std;

class Machine {
    class State* current = nullptr;
public:
    Machine();
    virtual ~Machine();

    void setCurrent(State* s);
    void on();
    void off();
};

class State {
public:
    virtual ~State() {
    }

    virtual void on(Machine* machine);

    virtual void off(Machine* machine);
};

class ON: public State {
public:
    virtual void off(Machine* machine);
};

class OFF: public State {
public:
    virtual void on(Machine* machine);
};

int main(int argc, char **argv) {
    try {
        Machine m;

        m.on();
        m.on();

        m.off();
        m.off();

        m.on();
        m.off();

    } catch (const std::exception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }
    return 0;
}

inline Machine::Machine() :
    current(new OFF) {
}

inline Machine::~Machine() {
    delete current;
}

inline void Machine::setCurrent(State* s) {
    current = s;
}

inline void Machine::on() {
    cout << "machine on" << endl;
    current->on(this);
}

inline void Machine::off() {
    cout << "machine off" << endl;
    current->off(this);
}

inline void State::on(Machine* machine) {
    cout << "already ON" << endl;
}

inline void State::off(Machine* machine) {
    cout << "already OFF" << endl;
}

inline void ON::off(Machine* machine) {
    cout << "set state to OFF" << endl;
    machine->setCurrent(new OFF);
    delete this;
}

inline void OFF::on(Machine* machine) {
    cout << "set state to ON" << endl;
    machine->setCurrent(new ON);
    delete this;
}
