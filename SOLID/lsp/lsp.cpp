#include <iostream>
#include <assert.h>
using namespace std;

/*
    Class design methods must be done in such a way that any applications or clients
    using any subtype of parent class must not result in modifications of parent or subtype class
*/
class Rectangle
{
    public:
    Rectangle(double height,double width):itsHeight(height),itsWidth(width)
    {
    }
    virtual void SetWidth(double w) {itsWidth=w;}
    virtual void SetHeight(double h) {itsHeight=h;}
    double GetHeight() const {return itsHeight;}
    double GetWidth() const {return itsWidth;}
    private:
    double itsHeight;
    double itsWidth;
};

class Square : public Rectangle
{
    public:
    Square(double size):Rectangle(size, size){}
    virtual void SetWidth(double w);
    virtual void SetHeight(double h);
};

void Square::SetWidth(double w)
{
    Rectangle::SetWidth(w);
    Rectangle::SetHeight(w);
}

void Square::SetHeight(double h)
{
    Rectangle::SetHeight(h);
    Rectangle::SetWidth(h);
}

void g(Rectangle& r)
{
    r.SetWidth(5);   //since its virtual, setwidth() and setheight() of the square gets called if square is passed as an argument
    r.SetHeight(4);
    cout <<r.GetWidth() << "\t" <<r.GetHeight() <<endl;
    assert((r.GetWidth() * r.GetHeight()) == 20); // getheight() and getwidth() of base class rectangle will get called
}

int main()
{
    Rectangle r{3.0, 4.0};
    g(r);
    Square s{5.0};
    g(s);
}
