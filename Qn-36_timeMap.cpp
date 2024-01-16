#include <iostream>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

class TimeMap
{
private:
    unordered_map<string, map<int, string>> data;

public:
    TimeMap()
    {
        //constructor to initialize
    }

    void set(string key, string value, int timestamp)
    {
        data[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        if(data.find(key) == data.end())
        {
            return "";
        }

        map<int, string> tempMap = data[key];

        string result = "";

        for(const auto& entry : tempMap)
        {
            if(entry.first> timestamp)
            {
                break;
            }
            result = entry.second;
        }

        return result;

    }
};

int main()
{
    TimeMap object;
   // [[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
    object.set("alm", "high1", 1);  //timestamp as 1
    object.set("alm", "high2", 2);  //timestamp as 2

    cout << object.get("alm",1) << endl;
    cout << object.get("alm",3) << endl;

    return 0;   
}