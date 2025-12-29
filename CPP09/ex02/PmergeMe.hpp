#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <utility>
#include <iterator>
#include <climits>

class PmergeMe
{
	private:
		std::vector<int>	vec;
		std::deque<int>		deq;
		std::vector<int>	numbers;
		double				vectorTime;
		double				dequeTime;
		int					size;
		int					vectorComparisons;
		int					dequeComparisons;
		int					comparisons;

		bool parseInput(char *arg);
		void printVector();
		bool isDup();
		int binarySearch(int lo, int hi, int target);

	//----------------------------------------------------------------------vector----------------------------------------------------------------------
		void fordJohnsonSort(std::vector<int>& container);
		std::vector<int> pmergeSortRecursive(std::vector<int>& data);
		void insertSort(std::vector<int>& main, std::vector<int>& pend);
		void replace_ref(std::vector<int>& main, std::vector<int>& pend, std::vector<int>& jacob, int& comparisons);
		int binarySearch(std::vector<int>& c, int value, int high, int& comparisons, int low);

	//----------------------------------------------------------------------deque----------------------------------------------------------------------
		void fordJohnsonSort(std::deque<int>& container);
		std::deque<int> pmergeSortRecursive(std::deque<int>& data);
		void insertSort(std::deque<int>& main, std::deque<int>& pend);
		void replace_ref(std::deque<int>& main, std::deque<int>& pend, std::deque<int>& jacob, int& comparisons);
		int binarySearch(std::deque<int>& c, int value, int high, int& comparisons, int low);

		void printContainer(const std::vector<int>& container);
		void printContainer(const std::deque<int>& container);


	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		static int jacobsthal(int n);
		void run(char** argv);
};


#endif