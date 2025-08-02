/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:09:59 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/02 17:09:59 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!" << std::endl;
}
void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level)
{
	void		(Harl::*funcs[NB_FUNCS])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	func_names[NB_FUNCS] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < NB_FUNCS; i++)
	{
		if (func_names[i] == level)
		{
			(this->*funcs[i])();
			return ;
		}
	}
	std::cerr << level << ": Function not found" << std::endl;
}