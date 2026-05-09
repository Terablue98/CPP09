#ifndef PMergeMe_HPP
#define PMergeMe_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <climits>


template<typename container>
void fordjohnsonSort(container &ex);

template<typename container>
container FJSort(container T);

std::vector<int> JacobsthalSequencing(size_t size);

bool is_duplicated(const std::vector<int> &vec, int value);

void parseInput(int argc, char **argv, std::vector<int> &vec, std::deque<int> &deq);

template<typename container>
void printcontainer(const container& ex);

bool is_positive_num(int a);

#include "PMergeMe.tpp" 


#endif

