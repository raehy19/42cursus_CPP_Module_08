/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 09:44:39 by rjeong            #+#    #+#             */
/*   Updated: 2024/09/08 09:44:40 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/**
 * @brief Constructor for the Span class.
 *
 * Initializes a Span object that can store a maximum of `n` integers.
 *
 * @param n The maximum number of integers that can be stored in the Span.
 */
Span::Span(unsigned int n) : N(n) {}

/**
 * @brief Adds a number to the Span.
 *
 * Adds a single integer to the Span. If the Span is already full, an exception is thrown.
 *
 * @param number The number to be added to the Span.
 * @throw SpanFullException If the Span already contains `N` numbers.
 */
void Span::addNumber(int number) {
	if (numbers.size() >= N) {
		throw SpanFullException();
	}
	numbers.push_back(number);
}

/**
 * @brief Calculates the shortest span between any two numbers in the Span.
 *
 * This function sorts the numbers in ascending order and calculates the smallest
 * difference between consecutive numbers.
 *
 * @return int The shortest span between any two numbers in the Span.
 * @throw NoSpanFoundException If the Span contains fewer than two numbers.
 */
int Span::shortestSpan() const {
	if (numbers.size() < 2) {
		throw NoSpanFoundException();
	}

	std::vector<int> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int minSpan = sortedNumbers[1] - sortedNumbers[0];
	for (size_t i = 1; i < sortedNumbers.size() - 1; ++i) {
		int span = sortedNumbers[i + 1] - sortedNumbers[i];
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

/**
 * @brief Calculates the longest span between the smallest and largest numbers in the Span.
 *
 * This function finds the minimum and maximum elements in the Span and returns their difference.
 *
 * @return int The longest span between the smallest and largest numbers in the Span.
 * @throw NoSpanFoundException If the Span contains fewer than two numbers.
 */
int Span::longestSpan() const {
	if (numbers.size() < 2) {
		throw NoSpanFoundException();
	}

	int minElement = *std::min_element(numbers.begin(), numbers.end());
	int maxElement = *std::max_element(numbers.begin(), numbers.end());

	return maxElement - minElement;
}
