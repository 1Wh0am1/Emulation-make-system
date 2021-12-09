#include "makefile.h"

void makefile::parse(std::string fileName)
{
	try
	{
		std::ifstream file(fileName);
		if (!file.is_open())
		{
			throw errors::miss_file;
		}
		while (!file.eof())
		{
			std::string line;
			target target;
			std::string actions;
			getline(file, line);
			
			if (line.find(':') != -1)
			{
				target.parseTargets(line);
				
				getline(file, line);
				target.parseActions(line);
				addTarget(target);
			}
		}
		
		file.close();
		
		if (_targets.size() >= 1000000)
		{
			throw errors::target_limit;
		}
	}
	catch (errors error)
	{
		switch (error)
		{
			case errors::miss_file:
			{
				std::cerr << "Missing File";
				break;
			}
			case errors::target_limit:
			{
				std::cerr << "Targets limit\n";
				break;
			}
		}
	}
}

void makefile::printTarget(target& target)
{
	std::cout << target.getName() << ": ";
	std::cout << "\n" << target.getActions() << "\n";
}

void makefile::addTarget(target& target)
{
	_targets.push_back(target);
}

int32_t makefile::run(std::string name)
{
	try
	{
		for (target target : _targets)
		{
			if (target.getName() == name)
			{
				bool completed = false;
				for (::target completed_target : _completedTargets)
				{
					if (target.getName() == completed_target.getName())
					{
						if (target.getDependencies().empty())
						{
							completed = true;
							break;
						}
						else
						{
							throw errors::recursion;
						}
					}
				}
				if (completed == false)
				{
					if (target.getDependencies().empty())
					{
						printTarget(target);
						_completedTargets.push_back(target);
						break;
					}
					else
					{
						_completedTargets.push_back(target);
						for (const std::string& dependency : target.getDependencies())
						{
							const int32_t status = run(dependency);
							if (status != 0)
								return status;
						}
						printTarget(target);
					}
				}
			}
		}
		return (0);
	} catch (errors error)
	{
		switch (error)
		{
			case errors::recursion:
			{
				std::cerr << "Recursion detected\n";
				return static_cast<int>(errors::recursion);
			}
		}
	}
}



