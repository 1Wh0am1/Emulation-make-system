#pragma once

#include <iostream>
#include <fstream>

#include "target.h"

class makefile
{
private:
	std::vector<target> _targets;
	std::vector<target> _completedTargets;

public:
	
	void parse(std::string);
	int32_t run(std::string name = "all");
	void printTarget(target&);
	void addTarget(target&);
};

enum class errors
{
	miss_file,
	recursion,
	target_limit
	
};
