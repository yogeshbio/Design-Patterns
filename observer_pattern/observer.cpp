#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    Subject - interface or abstract class defining the operations for attaching and de-attaching observers to the client. In the GOF book this class/interface is known as Subject.
    ConcreteSubject - concrete Observable class. It maintain the state of the object and when a change in the state occurs it notifies the attached Observers.
    Observer - interface or abstract class defining the operations to be used to notify this object.
    ConcreteObserverA, ConcreteObserver2 - concrete Observer implementations.
*/
class ObserverInterface
{
public:
	virtual ~ObserverInterface() {}       // Observer abstract class
	virtual void update(int message) = 0;
};

class SubjectInterface
{
public:                                         // Subject Interface class (It can be an abstract class)
	virtual ~SubjectInterface();
	virtual void subscribe(ObserverInterface *);
	virtual void unsubscribe (ObserverInterface *);
	virtual void notify(int message);
private:
	vector<ObserverInterface *> mObservers;
};

SubjectInterface::~SubjectInterface()
{}

void SubjectInterface::subscribe(ObserverInterface *observer)
{
	mObservers.push_back(observer);
}

void SubjectInterface::unsubscribe(ObserverInterface *observer)
{
	int count = mObservers.size();
	int i;

	for (i = 0; i < count; i++)
    {
		if(mObservers[i] == observer)
		mObservers.erase(mObservers.begin() + i);
	}
}

void SubjectInterface::notify(int msg)
{
	int count = mObservers.size();

	for (int i = 0; i < count; i++)
		(mObservers[i])->update(msg);
}

class Subject : public SubjectInterface    // Extended class of subject interface
{
public:
	enum Message {ADD, REMOVE};
};

class ConcreteObserver : public ObserverInterface
{
public:
	explicit ConcreteObserver(const string &str) : name(str) {}
	void update(int message)
	{
		cout << name << " Got message " << message << endl;
	}
private:
	string name;
};

int main()
{
    // Create objects of observers
	ConcreteObserver observerA("observerA");
	ConcreteObserver observerB("observerB");
	ConcreteObserver observerC("observerC");

	Subject subject;   // Create object of the subject under observation

    // Add the observers
	subject.subscribe(&observerA);
	subject.subscribe(&observerB);
	subject.subscribe(&observerC);

    // Notify the change of state
	subject.notify(Subject::ADD);
	subject.notify(Subject::REMOVE);

    // remove the observer B, now only A and C should receive notifications
    subject.unsubscribe(&observerB);
    subject.notify(Subject::ADD);
	subject.notify(Subject::REMOVE);
	return 0;
}