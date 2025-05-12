#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <utility>
#include <fstream>

int main()
{
	std::map<std::string, std::pair<int, double>> info;
	int number;
	double mark;
	std::string second_name;

	std::fstream file("test.txt");

	if (!file)
	{
		return 1;
	}

	std::fstream line;
    int fl = 0;
	while (file >> second_name >> number >> mark)
	{
        std::map<std::string, std::pair<int, double>>::iterator it = info.begin();
        for (it; it != info.end(); it++)
        {
            if (it -> first == second_name)
            {
                fl = 1;
                break;
            }
        }
        if (fl == 0)
        {
		    info.emplace(second_name, std::make_pair(number, mark));
        }
        it = info.begin();
        for (it; it != info.end(); it++)
        {
            if (it -> second.second < 3.0)
            {
                it = info.erase(it);
            }
        }
	}

    for (const auto& _info : info)
    {
        std::cout << _info.first << " " << _info.second.first << " " << _info.second.second << std::endl; 
    }

	return 0;
}
