#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : vectorTime(0), dequeTime(0), size(0), vectorComparisons(0), dequeComparisons(0), comparisons(0) {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { *this = other;}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		vec = other.vec;
		deq = other.deq;
		numbers = other.numbers;
		vectorTime = other.vectorTime;
		dequeTime = other.dequeTime;
		size = other.size;
		vectorComparisons = other.vectorComparisons;
		dequeComparisons = other.dequeComparisons;
		comparisons = other.comparisons;
	}
	return *this;
}

int PmergeMe::binarySearch(std::vector<int>& c, int value, int high, int& comparisons, int low)
{
	if (high >= static_cast<int>(c.size()))
		high = c.size() - 1;
	if (low > high)
		return low;

	int mid = low + (high - low) / 2;
	comparisons++;

	if (c[mid] < value)
		return binarySearch(c, value, high, comparisons, mid + 1);
	else
		return binarySearch(c, value, mid - 1, comparisons, low);
}

void PmergeMe::replace(std::vector<int>& main, std::vector<int>& pend, std::vector<int>& jacob, int& comparisons)
{
	main.insert(main.begin(), pend[0]);
	std::vector<int> inserted;
	inserted.push_back(1);
	int pendIndex;
	int pos;
	int searchLimit;
	int high = 3;

	std::vector<int>::iterator it = jacob.begin();
	while (it != jacob.end())
	{
		int current_jacob = *it;

		if (it != jacob.begin())
			high = 2 * high + 1;

		int x = current_jacob;
		while (x > 1)
		{
			if (std::find(inserted.begin(), inserted.end(), x) == inserted.end())
			{
				pendIndex = x - 1;
				if (pendIndex < (int)(pend.size()))
				{
					searchLimit = high - 1;
					if (searchLimit > (int)(main.size()))
						searchLimit = main.size();
					pos = binarySearch(main, pend[pendIndex], searchLimit, comparisons, 0);
					main.insert(main.begin() + pos, pend[pendIndex]);
				}
				inserted.push_back(x);
			}
			x--;
		}
		++it;
	}
	for (int i = 1; i < (int)pend.size(); i++)
	{
		if (std::find(inserted.begin(), inserted.end(), i + 1) == inserted.end())
		{
			searchLimit = main.size();
			pos = binarySearch(main, pend[i], searchLimit, comparisons, 0);
			main.insert(main.begin() + pos, pend[i]);
		}
	}
}

void PmergeMe::insertSort(std::vector<int>& main, std::vector<int>& pend)
{
	if (pend.empty())
		return;
	std::vector<int> jacob_seq;
	int i = 3;
	int j_num;
	while (true)
	{
		j_num = jacobsthal(i);
		if (j_num > (int)(pend.size()))
			break;
		jacob_seq.push_back(j_num);
		++i;
	}
	replace(main, pend, jacob_seq, vectorComparisons);
}

std::vector<int> PmergeMe::pmergeSortRecursive(std::vector<int>& data)
{
	size_t i;
	if (data.size() <= 1)
		return data;

	std::vector<int> main_chain, pend_chain;
	int stray = -1;
	bool has_stray = data.size() % 2 != 0;

	if(has_stray)
	{
		stray = data.back();
		data.pop_back();
	}

	i = 0;
	while (i < data.size())
	{
		vectorComparisons++;
		if (data[i] > data[i+1])
		{
			main_chain.push_back(data[i]);
			pend_chain.push_back(data[i+1]);
		}
		else
		{
			main_chain.push_back(data[i+1]);
			pend_chain.push_back(data[i]);
		}
		i += 2;
	}

	std::vector<int> main_chain_unsorted = main_chain;
	std::vector<int> sorted_main = pmergeSortRecursive(main_chain);
	std::vector<int> sorted_pend;

	i = 0;
	while (i < sorted_main.size())
	{
		int val = sorted_main[i];
		size_t j = 0;
		while (j < main_chain_unsorted.size())
		{
			if (main_chain_unsorted[j] == val)
			{
				sorted_pend.push_back(pend_chain[j]);
				main_chain_unsorted[j] = -1;
				break;
			}
			j++;
		}
		i++;
	}

	if (has_stray)
	{
		sorted_pend.push_back(stray);
	}

	insertSort(sorted_main, sorted_pend);

	return sorted_main;
}

void PmergeMe::fordJohnsonSort(std::vector<int>& container)
{
	container = pmergeSortRecursive(container);
}


int PmergeMe::binarySearch(std::deque<int>& c, int value, int high, int& comparisons, int low)
{
	if (high >= static_cast<int>(c.size()))
		high = c.size() - 1;
	if (low > high)
		return low;
	int mid = low + (high - low) / 2;
	comparisons++;
	if (c[mid] < value)
		return binarySearch(c, value, high, comparisons, mid + 1);
	else
		return binarySearch(c, value, mid - 1, comparisons, low);
}

void PmergeMe::replace(std::deque<int>& main, std::deque<int>& pend, std::deque<int>& jacob, int& comparisons)
{
	main.insert(main.begin(), pend[0]);
	std::vector<int> inserted;
	inserted.push_back(1);
	int pendIndex;
	int pos;
	int searchLimit;
	int high = 3;

	std::deque<int>::iterator it = jacob.begin();
	while (it != jacob.end())
	{
		int current_jacob = *it;

		if (it != jacob.begin())
			high = 2 * high + 1;

		int x = current_jacob;
		while (x > 1)
		{
			if (std::find(inserted.begin(), inserted.end(), x) == inserted.end())
			{
				pendIndex = x - 1;
				if (pendIndex < (int)(pend.size()))
				{
					searchLimit = high - 1;
					if (searchLimit > (int)(main.size()))
						searchLimit = main.size();
					pos = binarySearch(main, pend[pendIndex], searchLimit, comparisons, 0);
					main.insert(main.begin() + pos, pend[pendIndex]);
				}
				inserted.push_back(x);
			}
			x--;
		}
		++it;
	}

	for (int i = 1; i < (int)pend.size(); i++)
	{
		if (std::find(inserted.begin(), inserted.end(), i + 1) == inserted.end())
		{
			searchLimit = main.size();
			pos = binarySearch(main, pend[i], searchLimit, comparisons, 0);
			main.insert(main.begin() + pos, pend[i]);
		}
	}
}

void PmergeMe::insertSort(std::deque<int>& main, std::deque<int>& pend)
{
	if (pend.empty())
		return;
	std::deque<int> jacob_seq;
	int i = 3;
	int j_num;
	while (true)
	{
		j_num = jacobsthal(i);
		if (j_num > (int)(pend.size()))
			break;
		jacob_seq.push_back(j_num);
		++i;
	}
	replace(main, pend, jacob_seq, dequeComparisons);
}

std::deque<int> PmergeMe::pmergeSortRecursive(std::deque<int>& data)
{
	size_t i = 0;
	if (data.size() <= 1)
		return data;

	std::deque<int> main_chain, pend_chain;
	int stray = -1;
	bool has_stray; 
	has_stray = data.size() % 2 != 0;

	if(has_stray)
	{
		stray = data.back();
		data.pop_back();
	}

	while (i < data.size())
	{
		dequeComparisons++;
		if (data[i] > data[i+1])
		{
			main_chain.push_back(data[i]);
			pend_chain.push_back(data[i+1]);
		}
		else
		{
			main_chain.push_back(data[i+1]);
			pend_chain.push_back(data[i]);
		}
		i += 2;
	}

	std::deque<int> main_chain_unsorted = main_chain;
	std::deque<int> sorted_main = pmergeSortRecursive(main_chain);
	std::deque<int> sorted_pend;

	i = 0;
	while (i < sorted_main.size())
	{
		int val = sorted_main[i];
		size_t j = 0;
		while (j < main_chain_unsorted.size())
		{
			if (main_chain_unsorted[j] == val)
			{
				sorted_pend.push_back(pend_chain[j]);
				main_chain_unsorted[j] = -1;
				break;
			}
			j++;
		}
		i++;
	}

	if (has_stray)
	{
		sorted_pend.push_back(stray);
	}

	insertSort(sorted_main, sorted_pend);

	return sorted_main;
}

int PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}
void PmergeMe::fordJohnsonSort(std::deque<int>& container)
{
	container = pmergeSortRecursive(container);
}

void PmergeMe::printContainer(const std::vector<int>& container)
{
	std::vector<int>::const_iterator it = container.begin();
	while (it != container.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

void PmergeMe::printContainer(const std::deque<int>& container)
{
	std::deque<int>::const_iterator it = container.begin();
	while (it != container.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

bool PmergeMe::parseInput(char *arg)
{
	std::string input = arg;
	std::stringstream ss(input);
	int n;

	while (*arg)
	{
		while (*arg == '\r' || *arg == '\t' || *arg == ' ')
			arg++;
		if (*arg == '\0')
			break;
		if (!isdigit(*arg))
			return false;
		arg++;
		while (*arg == '\r' || *arg == '\t' || *arg == ' ')
			arg++;
	}
	while (ss >> n)
	{
		if (n <= 0)
			return false;
		numbers.push_back(n);
	}
	if (!ss.eof())
		return false;
	return true;
}

bool PmergeMe::isDup()
{
	for (int i = 0; i < (int)numbers.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (numbers[i] == numbers[j])
				return false;
		}
	}
	return true;
}

void PmergeMe::run(char** argv)
{
	int i = 1;
	while (argv[i])
	{
		if (!parseInput(argv[i]))
		{
			std::cerr << "Error" << std::endl;
			return;
		}
		i++;
	}
	if (!isDup())
	{
		std::cerr << "Error" << std::endl;
		return;
	}
	if (numbers.size() < 2)
	{
		std::cerr << "Error" << std::endl;
		return;
	}
	for (size_t j = 0; j < numbers.size(); j++)
	{
		vec.push_back(numbers[j]);
		deq.push_back(numbers[j]);
	}
	size = vec.size();
	std::cout << "Before: ";
	printContainer(vec);
	clock_t start = clock();
	fordJohnsonSort(vec);
	clock_t end = clock();
	vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	start = clock();
	fordJohnsonSort(deq);
	end = clock();
	dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "After:  ";
	printContainer(vec);
	std::cout << "Time to process a range of " << size << " elements with std::vector: " << vectorTime << " us" << std::endl;
	std::cout << "Number of comparisons with std::vector: " << vectorComparisons << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::deque:  " << dequeTime << " us" << std::endl;
	std::cout << "Number of comparisons with std::deque:  " << dequeComparisons << std::endl;
}
