#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: No input here." << std::endl;
		return 1;
	}
	try
	{
		PmergeMe pmergeme;
		pmergeme.run(argv);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}