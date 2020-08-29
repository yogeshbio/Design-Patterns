#include <iostream>
#include <string>
#include <memory>
using namespace std;

/*

Product: is the Parser, XML and HTML are concrete products that need to instantiated
Creator: ParserFactory class with factory method to create Product
Concrete Creator: ConcreteParserFactory class in this example. We can have multiple such creators at different places of the program
                  which instantiate the actual product class in different ways.
*/

enum class ParserType {
		XML,
		HTML,
	};


class Parser         // end product
{
    public:
    virtual void parseFile() const = 0;
};

class XMLparser:public Parser   // concrete parser products XML and HTML
{
    public:
    virtual void parseFile() const
    {
        cout << "Parsing XML file\n";
    }
};
class HTMLparser:public Parser
{
    public:
    virtual void parseFile() const
    {
        cout << "Parsing HTML file\n";
    }
};

class ParserFactory  // Creator factory Abstract interface
{
    public:
    virtual unique_ptr<Parser> parserFactory(ParserType) = 0;
};

class ConcreteParserFactory: public ParserFactory   // Concrete Creator Factory, you can have mulitple such creators
{
    public:
    virtual unique_ptr<Parser> parserFactory(ParserType parsertype)
    {
        switch(parsertype)
        {
            case ParserType::XML:
                    return make_unique<XMLparser>();
            case ParserType::HTML:
                    return make_unique<HTMLparser>();
        }
    }
};
int main()
{
    ParserFactory *pFactory = new ConcreteParserFactory();
    // decision to do html stuff
    unique_ptr<Parser> parser = pFactory->parserFactory(ParserType::HTML);
    parser->parseFile();

    //now decision to do xml stuff
    parser = pFactory->parserFactory(ParserType::XML);
    parser->parseFile();
}