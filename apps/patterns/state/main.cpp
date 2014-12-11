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

/*
 * IObserver
 */
class IObserver
{
public:
    virtual ~IObserver() = default;

    void update() = 0;

protected:
    IObserver() = default;
};

/*
 * IObservable
 */
class IObservable
{
public:
    virtual ~IObservable() = default;

    void attach(shared_ptr<IObserver> observer)
    {
        observers.push_back(observer);
    }
    void detach(shared_ptr<IObserver> observer)
    {
        observers.remove_if([=](shared_ptr<IObserver> o)
        {
            return o == observer;
        });
    }
    void notify()
    {
        for (auto i : observers)
            i->update();
    }

    IObservable()
    {
    }

protected:
    list<shared_ptr<IObserver>> observers;
};

/*
 * TicketsHistory
 */
class TicketsHistory: public IObservable
{
public:
    TicketsHistory()
    {
    }
    virtual ~TicketsHistory()
    {
    }

    void putTicket(int hash)
    {
        notify();
    }

private:
};

class TicketData{
public:
};

class Role{
public:
};

using DoAfter = function<void()>;

class SceneWithTickets: public IObserver
{
public:

    class SceneWithTickets;

    class State
    {
    public:
        State() = default;
        virtual ~State() = default;

        virtual void play(shared_ptr<SceneWithTickets>, const TicketData&, int, DoAfter) = 0;
    };

    class NextTicketState;

    class FirstTicketState: public State
    {
    public:
        static shared_ptr<FirstTicketState> instance()
        {
            static shared_ptr<FirstTicketState> self(new FirstTicketState);
            return self;
        }
        virtual ~FirstTicketState() = default;

        virtual void play(shared_ptr<SceneWithTickets> context, const TicketData&, int ticketOnScene, DoAfter)
        {
            context->switchState(NextTicketState::instance());
        }

    protected:
        FirstTicketState() = default;
    };

    class NextTicketState: public State
    {
    public:
        static shared_ptr<NextTicketState> instance()
        {
            static shared_ptr<NextTicketState> self(new NextTicketState);
            return self;
        }
        virtual ~NextTicketState() = default;

        virtual void play(shared_ptr<SceneWithTickets> context, const TicketData&, int ticketOnScene, DoAfter)
        {
            context->switchState(FirstTicketState::instance());
        }

    protected:
        NextTicketState() = default;
    };


    SceneWithTickets()
    {
    }
    virtual ~SceneWithTickets()
    {
    }

    virtual void update(/*std::shared_ptr<Role>*/)
    {
    }

    virtual void switchState(std::shared_ptr<State> state)
    {
        SceneWithTickets::state = state;
    }
private:
    shared_ptr<State> state = make_shared<FirstTicketState>();
};

int main(int argc, char **argv)
{
    try
    {

    }
    catch (const std::exception& e)
    {
        std::cerr << "exception: " << e.what() << std::endl;
    }
    return 0;
}

