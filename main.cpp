#include <cstdlib> // getenv
#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;
namespace fs = filesystem;
vector<string> split(const string &s, char delim)
{

    vector<string> result;
    stringstream ss(s);

    string item;

    while (getline(ss, item, delim))
    {
        if (!item.empty())
        {
            result.push_back(item);
        }
    }

    return result;
}

int main()
{

    string command;
    while (true)
    {

        while (true)
        {

            cout << "$";
            ;
            getline(cin, command);

            if (command.substr(0, 4) == "echo")
            {
                cout << command.substr(5) << endl;
            }

            if (command.substr(0, 4) == "exit")
            {
                break;
            }

            if (command.substr(0, 4) == "type")
            {
                string cmd = command.size() > 5 ? command.substr(5) : "";

                if (cmd == "echo" || cmd == "exit" || cmd == "type")
                {
                    cout << cmd << "is a builtin function" << endl;
                }
            }
            else
            {
                cout << cmd << " is not a builtin function ";
            }
        }
    }
}