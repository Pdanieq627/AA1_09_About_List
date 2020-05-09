#pragma once
#include <list>
#include <iostream>

std::list<int> superMerge(const std::list<int> &list1, const std::list<int> &list2)
{
	std::list<int>::iterator it;
	std::list<int> oldList1;
	std::list<int> oldList2;
	oldList1 = list1;
	oldList2 = list2;
	std::list<int> newList;
	int maxNum1 = oldList1.begin;
	int maxNum2 = oldList2.begin;
	while (newList.size() != list1.size() + list2.size())
	{
		for (std::list<int>::iterator it = oldList1.begin; it != oldList1.end(); it++)
		{
			if (maxNum1 < *it)
			{
				maxNum1 = *it;
				oldList1.erase(it);
			}
		}

		for (std::list<int>::iterator it = oldList2.begin; it != oldList2.end(); it++)
		{
			if (maxNum2 < *it)
			{
				maxNum2 = *it;
				oldList2.erase(it);
			}
		}

		if (maxNum1 < maxNum2)
		{
			newList.push_back(maxNum2);
		}
		else if (maxNum1 > maxNum2)
		{
			newList.push_back(maxNum1);
		}
	}
	return newList;
}

void printReverse(const std::list<int> &list)
{
	for (std::list<int>::iterator it = list.cbegin; it != list.cend(); it--)
	{
		std::cout << ' ' << *it;
	}
}

bool isBalanced(const std::list<char> &list)
{
	int leftBar = 0;
	int rightBar = 0;
	for (std::list<char>::iterator it = list.begin; it != list.end(); it++)
	{
		if (*it == '(')
		{
			leftBar++;
		}
		else
		{
			rightBar++;
		}
	}

	return(leftBar == rightBar);
}


