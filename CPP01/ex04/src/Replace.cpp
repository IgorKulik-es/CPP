/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:09:36 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/08 18:03:17 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Replace.hpp"

int	check_files(int argc, char **argv, std::ifstream &infile, std::ofstream &outfile)
{
	std::string		file_name;
	if (argc != 4)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (1);
	}
	file_name = argv[1];
	infile.open(file_name.c_str(), std::ios::in);
	if (!(infile.is_open()))
	{
		std::cerr << file_name << ": Error openning input file" << std::endl;
		return (1);
	}
	file_name.append(".replace");
	outfile.open(file_name.c_str(), std::ios::out | std::ios::trunc);
	if (!(outfile.is_open()))
	{
		std::cerr << file_name << ": Error openning output file" << std::endl;
		return (1);
	}
	return (0);
}

void	ft_replace(std::ifstream &infile, std::ofstream &outfile, std::string find, std::string replace)
{
	std::string	line;
	size_t		index_find;

	index_find = 0;
	while (std::getline(infile, line))
	{
		index_find = line.find(find, index_find);
		while (index_find != std::string::npos)
		{
			line.erase(index_find, find.length());
			line.insert(index_find, replace);
			index_find += replace.length();
			index_find = line.find(find, index_find);
		}
		outfile << line << std::endl;
		index_find = 0;
	}
}
