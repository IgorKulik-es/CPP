/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 18:18:05 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/18 19:41:43 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){};

Base* generate(void)
{
	srand(time(0));
	switch (rand() % 3)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	case 2:
		return (new C);
	default:
		break;
	}
	return (0);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer to class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer to class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer to class C" << std::endl;
	else
		std::cerr << "Invalid pointer!" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference to class A" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference to class B" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference to class C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Not a child class: " << e.what() << std::endl;
	}
}

