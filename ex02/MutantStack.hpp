/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:29:47 by rjeong            #+#    #+#             */
/*   Updated: 2024/09/08 10:29:48 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

/**
 * @brief MutantStack class which extends std::stack and adds iterator support.
 *
 * The class inherits from std::stack and allows iteration over its elements.
 * The underlying container used by std::stack is expected to support iterators.
 * By default, std::deque is used as the underlying container, which supports iterators.
 *
 * @tparam T The type of elements stored in the stack.
 * @tparam Container The underlying container type (default: std::deque).
 */
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		// Typedefs for iterator types based on the container type
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;

		// Constructor
		MutantStack() : std::stack<T, Container>() {}

		// Copy constructor
		MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}

		// Assignment operator
		MutantStack &operator=(const MutantStack &other) {
			if (this != &other) {
				std::stack<T, Container>::operator=(other);
			}
			return *this;
		}

		// Destructor
		virtual ~MutantStack() {}

		// Iterator functions
		iterator begin() {
			return this->c.begin();
		}
		const_iterator begin() const {
			return this->c.begin();
		}

		iterator end() {
			return this->c.end();
		}

		const_iterator end() const {
			return this->c.end();
		}

		reverse_iterator rbegin() {
			return this->c.rbegin();
		}

		const_reverse_iterator rbegin() const {
			return this->c.rbegin();
		}

		reverse_iterator rend() {
			return this->c.rend();
		}

		const_reverse_iterator rend() const {
			return this->c.rend();
		}
};

#endif

