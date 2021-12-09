#pragma once

#include <string>
#include <vector>


class target
{
private:
	std::string _name;
	std::string _actions;
	std::vector <std::string> _dependencies;

public:
	
	void parseTargets(std::string&);
	void parseActions(std::string&);
	std::vector<std::string> getDependencies();
	std::string getActions();
	std::string getName();
};
