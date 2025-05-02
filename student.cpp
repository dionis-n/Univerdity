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

	int fl;
	std::string line;
	while (std::getline(file, line))
	{
		fl = 0;
		second_name = std::substr(0, line.find(" "));
		line = std::substr(line.find(" ")+1, line.size());
		for (auto sn : info)
		{
			if (sn == second_name)
			{
				fl = 1;
				break;
			}
		}
		if (fl == 0)
		{
			number = atoi(std::substr(0, line.find(" ")));
			line = std::substr(line.find(" ")+1, line.size());
			mark = atod(line);
			info[number] = mark;
		}
	}

	for (auto& [key, value] : info)
	{
		std::cout << key << ":" << value << std::endl;
	}

	return 0;
}
