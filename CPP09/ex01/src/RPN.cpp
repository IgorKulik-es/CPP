/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 22:33:09 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/28 22:33:09 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool	checkSign( char c );
static bool executeOp( std::stack<int>& numbers, char op );

int	executeRPN( const std::string& input )
{
	std::string::const_iterator	iter;
	std::stack<int>			numbers;

	iter = input.begin();
	while (iter != input.end())
	{
		while (iter != input.end() && isblank(*iter))
			iter++;
		if (iter == input.end())
			break ;
		if (isdigit(*iter))
			numbers.push(*iter - '0');
		else if ((!checkSign(*iter)) || (!executeOp(numbers, *iter)))
		{
			std::cerr << "Error" << std::endl;
			return (EXIT_FAILURE);
		}
		iter++;
	}
	if (numbers.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return (EXIT_FAILURE);
	}
	std::cout << numbers.top() << std::endl;
	return (EXIT_SUCCESS);
}

static bool	checkSign( char c )
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

static bool executeOp( std::stack<int>& numbers, char op )
{
	int	first;
	int	second;
	
	if (numbers.size() < 2)
		return (false);
	second = numbers.top();
	numbers.pop();
	first = numbers.top();
	numbers.pop();
	switch (op)
	{
	case '+':
		numbers.push(first + second);
		break ;
	case '-':
		numbers.push(first - second);
		break ;
	case '*':
		numbers.push(first * second);
		break;
	case '/':
		if (second == 0)
			return (false);
		numbers.push(first / second);
		break;	
	default:
		break;
	}
	return (true);
}
