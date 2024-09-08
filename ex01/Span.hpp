/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 09:44:43 by rjeong            #+#    #+#             */
/*   Updated: 2024/09/08 09:44:44 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>

/**
 * @brief Exception thrown when no span can be found.
 */
class NoSpanFoundException : public std::exception {
	public:
		const char* what() const throw() {
			return "No span can be found";
		}
};

/**
 * @brief Exception thrown when a number cannot be added because the span is full.
 */
class SpanFullException : public std::exception {
	public:
		const char* what() const throw() {
			return "Span is already full";
		}
};

/**
 * @brief Class to store a set of integers and calculate the shortest and longest spans.
 */
class Span {
	private:
		unsigned int N;
		std::vector<int> numbers;

	public:
		Span(unsigned int n);
		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;

		// Template function to add a range of numbers using iterators.
		template <typename Iterator>
		void addRange(Iterator begin, Iterator end) {
			if (numbers.size() + std::distance(begin, end) > N)
				throw SpanFullException();
			numbers.insert(numbers.end(), begin, end);
		}
};

#endif
