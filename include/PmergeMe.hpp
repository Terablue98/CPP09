#ifndef PMergeMe_HPP
#define PMergeMe_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <fstream>

template<typename container>
void fordjohnsonSort(container &container);

template<typename container>
void PairandSort(container &container);

std::vector<int> JacobsthalSequencing(size_t size);

#endif