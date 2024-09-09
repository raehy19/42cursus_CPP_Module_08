/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:30:01 by rjeong            #+#    #+#             */
/*   Updated: 2024/09/08 10:30:02 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main() {
	// Test with integer stack
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	// Iterate through stack using standard iterators
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "MutantStack elements:" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	// Test with reverse iterators
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	std::cout << "MutantStack elements in reverse:" << std::endl;
	while (rit != rite) {
		std::cout << *rit << std::endl;
		++rit;
	}

	// Copy constructor and assignment operator test
	MutantStack<int> copyStack(mstack);
	MutantStack<int> assignedStack;
	assignedStack = mstack;

	std::cout << "Copied stack elements:" << std::endl;
	for (MutantStack<int>::iterator cit = copyStack.begin(); cit != copyStack.end(); ++cit) {
		std::cout << *cit << std::endl;
	}

	std::cout << "Assigned stack elements:" << std::endl;
	for (MutantStack<int>::iterator ait = assignedStack.begin(); ait != assignedStack.end(); ++ait) {
		std::cout << *ait << std::endl;
	}

	return 0;
}
