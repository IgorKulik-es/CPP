/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:42:12 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/02 14:42:12 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Replace.hpp"

int	main( int argc, char **argv)
{
	
	if (chekc_files(argc, argv, infile, outfile) != 0)
		return (1);
	find = argv[2];
	replace = argv[3];
	ft_replace(infile, outfile, find, replace);
	return (0); 
}
