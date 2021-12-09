#include "makefile.h"

int main(int argc, char* argv[])
{
	if (argc == 3)
	{
		makefile mf;
		mf.parse(argv[1]);
		mf.run(argv[2]);
	}
	else if (argc == 2)
	{
		makefile mf;
		mf.parse(argv[1]);
		mf.run();
	}
	else
	{
		std::cout << "\nUsage:\nmakefile.exe [File name] [Target]\n"
				  << "makefile.exe [File name]\n"
				  << "\nExample:\nmakefile.exe test_file all\n";
	}
	
	return (0);
}
