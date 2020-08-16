#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class diary
{

    public:
    string m_title;
    vector<string> m_entries;
    explicit diary(const string& title):m_title(title){}  // explicit to not allow any implicit conversions when constructor is called

    void add_entry(const string& entry)
    {
        m_entries.push_back(entry);
    }
// Do not add save as part of diary functionality. Instead use another class for persistency.
    void save(const string& filename)
    {
        ofstream ofs(filename);   // write all entries to some file
        for (auto& s : m_entries)
        ofs << s << endl;
    }
};

class persistency_manager
{
    public:
    static void save(diary& d , const string& filename)
    {
        ofstream ofs(filename);   // write all entries to some file
        for (auto& s : d.m_entries)
        ofs << s << endl;
    }
};

main()
{
    diary d1("my routine");
    d1.add_entry("8am: breakfast");
    d1.add_entry("9am: Arbeit");
    d1.add_entry("10am: kafe");

    // d1.save("routine.txt");    Do not add save as part of the diary.

    persistency_manager pm;     // create a persistency manager class which handles writing data to hardisk
    pm.save(d1, "routine.txt");
}