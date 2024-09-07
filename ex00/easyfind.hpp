/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 03:57:13 by rjeong            #+#    #+#             */
/*   Updated: 2024/09/08 03:57:15 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <exception>
#include <algorithm>  // for std::find

/**
 * @brief Exception thrown when a value is not found in the container.
 */
class ValueNotFoundException : public std::exception {
	public:
		/**
		 * @brief Returns an error message when the exception is thrown.
		 * @return const char* Error message.
		 */
		const char* what() const throw() {
			return "Value not found";
		}
};

/**
 * @brief Template function to find an integer in a non-const container.
 *
 * This function template searches for a given integer in the provided non-const container.
 * If the integer is found, it returns an iterator to the first occurrence. If the
 * integer is not found, it throws an exception.
 *
 * @tparam T Type of the container, which should support iterators.
 * @param container The container of integers to search through.
 * @param value The integer value to find in the container.
 * @return typename T::iterator Iterator to the found integer.
 * @throw ValueNotFoundException If the value is not found in the container.
 */
template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw ValueNotFoundException();
	}
	return it;
}

/**
 * @brief Template function to find an integer in a const container.
 *
 * This function template searches for a given integer in the provided const container.
 * If the integer is found, it returns a const_iterator to the first occurrence. If the
 * integer is not found, it throws an exception.
 *
 * @tparam T Type of the container, which should support const_iterators.
 * @param container The const container of integers to search through.
 * @param value The integer value to find in the container.
 * @return typename T::const_iterator Const_iterator to the found integer.
 * @throw ValueNotFoundException If the value is not found in the container.
 */
template <typename T>
typename T::const_iterator easyfind(const T &container, int value) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw ValueNotFoundException();
	}
	return it;
}

#endif
