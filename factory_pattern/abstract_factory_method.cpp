#include <iostream>
#include <string>
#include <memory>
using namespace std;

/*
    product A and B can be grouped as they are related and can be instantiated using multiple factory methods
    product A: UI button
    product B: Theme color
    Abstract Creator: Abstract Factory class with multiple factory methods to create product A and B that are related
    Concrete Abstract Creator : Windows, Linux and MacOS creators which actually implement Abstract creator
*/

class UIButton          // Product A
{
    public:
    virtual void create_ui_button() = 0;
};

class Theme             // Product B
{
    public:
    virtual void color_theme() = 0;
};

class ConcreteUIButton:public UIButton  //concrete Product A
{
    public:
    ConcreteUIButton(string button, string pc):m_button(button),m_pc(pc){}
    virtual void create_ui_button()
    {
        cout <<m_pc <<":\t" <<"UI-Button type:" << m_button <<"\n";
    }
    private:
    string m_button;
    string m_pc;
};

class ConcreteTheme: public Theme             // concrete Product B
{
    public:
    ConcreteTheme(string theme,string pc):m_theme(theme),m_pc(pc){}
    virtual void color_theme()
    {
        cout <<m_pc <<":\t" <<"Color Theme type:" <<m_theme <<"\n";
    }
    private:
    string m_theme;
    string m_pc;
};

class Screen_Abstract_Factory     // abstract factory can group relevant products, multiple abstract factories is possible
{                                 // that can group relevant products and instantaite them using multiple factory methods
    public:
    virtual unique_ptr<UIButton> UIButtonFactory() = 0;  //product A
    virtual unique_ptr<Theme> ThemeFactory() = 0;     // product B

    virtual ~Screen_Abstract_Factory(){};
};

class WinConcreteFactory:public Screen_Abstract_Factory   // Concrete Abstract Factory for Windows
{
    public:
    virtual unique_ptr<UIButton> UIButtonFactory()
    {
        return make_unique<ConcreteUIButton>("square","Win");
    }
    virtual unique_ptr<Theme> ThemeFactory()
    {
        return make_unique<ConcreteTheme>("white","Win");
    }
    virtual ~WinConcreteFactory()
    {
        cout << "win factory destructor" <<"\n";
    }
};

class LinuxConcreteFactory:public Screen_Abstract_Factory   // Concrete Abstract Factory for Linux
{
    public:
    virtual unique_ptr<UIButton> UIButtonFactory()
    {
        return make_unique<ConcreteUIButton>("round","Linux");
    }
    virtual unique_ptr<Theme> ThemeFactory()
    {
        return make_unique<ConcreteTheme>("black","Linux");
    }
    virtual ~LinuxConcreteFactory()
    {
        cout << "linux factory destructor" <<"\n";
    }
};
class MacOSConcreteFactory:public Screen_Abstract_Factory   // Concrete Abstract Factory for MacOS
{
    public:
    virtual unique_ptr<UIButton> UIButtonFactory()
    {
        return make_unique<ConcreteUIButton>("rectangle","MacOS");
    }
    virtual unique_ptr<Theme> ThemeFactory()
    {
        return make_unique<ConcreteTheme>("yellow","MacOS");
    }
    virtual ~MacOSConcreteFactory()
    {
        cout << "maocOS factory destructor" <<"\n";
    }
};

int main()
{
    // do windows stuff
    unique_ptr<Screen_Abstract_Factory>screen = make_unique<WinConcreteFactory>();
    unique_ptr<UIButton> button =  screen->UIButtonFactory();
    unique_ptr<Theme> theme     =  screen->ThemeFactory();
    button->create_ui_button();
    theme->color_theme();

/*
    When we change the unique pointer to point to another class, the previous allocated memory is destroyed
    and hence destructor gets called.
    There is no memory leak here, the assignment will deallocate the resources associated with the first allocation.
    Move assignment operator is called when 2nd  or further assignments are done with make_unique.
    Internally move assignment does a reset, which will deallocate previous resources


*/
    // do linux stuff
    screen = make_unique<LinuxConcreteFactory>();
    button = screen->UIButtonFactory();
    theme  = screen->ThemeFactory();
    button->create_ui_button();
    theme->color_theme();

    // do MacOS stuff
    screen = make_unique<MacOSConcreteFactory>();
    button = screen->UIButtonFactory();
    theme  = screen->ThemeFactory();
    button->create_ui_button();
    theme->color_theme();
}