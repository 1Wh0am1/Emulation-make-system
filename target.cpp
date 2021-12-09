#include "target.h"
#include <iostream>


void target::parseTargets(std::string& line)
{
	int32_t pos = line.find(':');
	for (int32_t i = 0; i < pos; i++)
	{
		_name.push_back(line[i]);
	}
	std::string dependency;
	for (int32_t i = pos + 1; i <= line.size(); i++)
	{
		if (!(line[i] == ' ') && i != line.size())
		{
			dependency += line[i];
		}
		else
		{
			if (dependency.empty()) continue;
			_dependencies.push_back(dependency);
			dependency.clear();
		}
	}
}

void target::parseActions(std::string& line)
{
	_actions = line;
}

std::string target::getActions()
{
	return _actions;
}

std::vector<std::string> target::getDependencies()
{
	return _dependencies;
}

std::string target::getName()
{
	return _name;
}


