/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:57:22 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/23 19:15:09 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BtcData.hpp>

int main(int argc, char** argv)
{
	BtcData	price_table;
	std::map<std::string, float>::const_iterator	iter;

	if (price_table.readCsv("data.csv"))
		return (EXIT_FAILURE);
	(void)argv;
	if (argc <= 1)
		std::cerr << "Error: too few arguments" << std::endl;
	return (price_table.printValues(argv[1]));
}
