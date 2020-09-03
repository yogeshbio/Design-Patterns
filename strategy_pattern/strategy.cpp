#include <iostream>
using namespace std;

/*
    Stragtegy pattern is similar to the OCP open close principle
    Strategy: Sort behavior with Algorithm interface sort()
     Context: Collection class where you can set the algorithm you want to choose.
              Aggregation is used here using pointer to the Strategy class

            It helps to switch between different algorithms or strategies at run time.

*/
// Stragtegy
class SortBehavior
{
    public:
        virtual void sort() const = 0;   //Is the Algorithm interface()
};

class Merge: public SortBehavior        // Concrete strategy A
{
    public:
        virtual void sort() const {
            cout << "Merge sort()\n";
        }
};

class Quick: public SortBehavior {         // Concrete strategy B
    public:
        virtual void sort() const {
            cout << "Quick sort()\n";
        }
};

class Heap: public SortBehavior             // Concrete strategy C
{
    public:
        virtual void sort() const {
            cout << "Heap sort()\n";
        }
};


// Context

class Collection
{
    private:
        SortBehavior* m_sort;     // Aggregation using pointer to SortBehavior
    public:
        Collection(){}
        void set_sort(SortBehavior* s){
            m_sort = s;
        }
       void sort() const {    // Context Interface()
            m_sort->sort();
        }
};

int main(int argc, char *argv[])
{
    Merge merge;
    Quick quick;
    Heap heap;

    Collection colA;
    colA.set_sort(&merge);     // At run time select which sorting algorithm you want
    colA.sort();

    colA.set_sort(&quick);
    colA.sort();

    colA.set_sort(&heap);
    colA.sort();

    return 0;
}