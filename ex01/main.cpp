/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 09:44:32 by rjeong            #+#    #+#             */
/*   Updated: 2024/09/08 09:44:33 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
	// Basic test with a small Span
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	try {
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// Test with a larger range of numbers (10,000 numbers)
	Span largeSpan(10000);
	for (int i = 0; i < 10000; ++i) {
		largeSpan.addNumber(i);
	}

	try {
		std::cout << "Shortest Span in largeSpan: " << largeSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span in largeSpan: " << largeSpan.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// Edge case test: Adding numbers beyond the limit
	try {
		sp.addNumber(42);  // This should throw an exception as the Span is full.
	} catch (const std::exception& e) {
		std::cerr << "Caught an exception while adding a number to a full Span: " << e.what() << std::endl;
	}

	// Test with a very small Span (only 2 elements)
	Span smallSpan(2);
	smallSpan.addNumber(10);
	smallSpan.addNumber(20);

	try {
		std::cout << "Shortest Span in smallSpan: " << smallSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span in smallSpan: " << smallSpan.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// Test with a range of numbers using iterators from std::vector
	Span rangeSpan(6);
	std::vector<int> range;
	range.push_back(100);
	range.push_back(200);
	range.push_back(300);

	try {
		rangeSpan.addRange(range.begin(), range.end());
		rangeSpan.addNumber(10);
		rangeSpan.addNumber(20);
		rangeSpan.addNumber(30);

		std::cout << "Shortest Span in rangeSpan: " << rangeSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span in rangeSpan: " << rangeSpan.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// Test with a range of numbers using iterators from std::list
	Span listRangeSpan(5);
	std::list<int> listRange;
	listRange.push_back(500);
	listRange.push_back(1000);
	listRange.push_back(1500);

	try {
		listRangeSpan.addRange(listRange.begin(), listRange.end());
		listRangeSpan.addNumber(600);
		listRangeSpan.addNumber(700);

		std::cout << "Shortest Span in listRangeSpan: " << listRangeSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span in listRangeSpan: " << listRangeSpan.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// Test with Span containing only one number (should throw exception)
	Span singleNumberSpan(1);
	singleNumberSpan.addNumber(42);

	try {
		std::cout << "Trying to find span in singleNumberSpan (only one number): " << std::endl;
		std::cout << "Shortest Span: " << singleNumberSpan.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
