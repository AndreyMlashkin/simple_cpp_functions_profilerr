#include <iostream>
#include <chrono>

using namespace std;

class TimeTracker
{
private:
    long millis()
    {
        return (std::chrono::system_clock::now().time_since_epoch().count());
    }
    long m_startTime = millis();
    const char* m_func_name;
public:
    TimeTracker(const char* func_name)
        : m_func_name(func_name)
    {
        std::cout << ("->") << m_func_name << '\n';
    }

    ~TimeTracker()
    {
        std::cout << ("<-") << m_func_name << " exited in " << (millis() - m_startTime) << '\n';
    }

    void operator()( )
    {}
};

#define TRACK TimeTracker function_profiler( __func__ )

void someFun()
{
    TRACK;
    std::cout << "function body\n";
}

void nestedFunction()
{
    TRACK;
    auto lambda = []()
    {
        TRACK;
        std::cout << "lambda body\n";
    };
    std::cout << "nestedFunction body\n";
}

int main()
{
    someFun();
    nestedFunction();

    cout << "Hello World!" << endl;
    return 0;
}
