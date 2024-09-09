/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 04:29:41 by rjeong            #+#    #+#             */
/*   Updated: 2024/09/08 04:29:43 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

/**
 * @brief Main function to test easyfind with both vector and list of integers.
 *
 * This function creates a vector and a list of integers, then attempts to find specific values
 * using the easyfind function. If the value is found, it prints it. If the value is
 * not found, it catches an exception and prints an error message.
 *
 * It also demonstrates usage with both const and non-const containers.
 *
 * @return int Returns 0 upon successful execution.
 */
int main() {
	// Test with std::vector
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	// Non-const vector example
	try {
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Vector Value found: " << *it << std::endl;
		it = easyfind(vec, 7);
		std::cout << "Vector Value found: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	// Const vector example
	const std::vector<int> constVec = vec;
	try {
		std::vector<int>::const_iterator it = easyfind(constVec, 3);
		std::cout << "Const Vector Value found: " << *it << std::endl;
		it = easyfind(constVec, 7);
		std::cout << "Const Vector Value found: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	// Test with std::list
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	// Non-const list example
	try {
		std::list<int>::iterator it = easyfind(lst, 30);
		std::cout << "List Value found: " << *it << std::endl;
		it = easyfind(lst, 35);
		std::cout << "List Value found: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	// Const list example
	const std::list<int> constLst = lst;
	try {
		std::list<int>::const_iterator it = easyfind(constLst, 30);
		std::cout << "Const List Value found: " << *it << std::endl;
		it = easyfind(constLst, 35);
		std::cout << "Const List Value found: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
