/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:43:26 by ikulik            #+#    #+#             */
/*   Updated: 2025/08/02 14:43:26 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>

int	chekc_files(int argc, char **argv, std::ifstream &infile, std::ofstream &outfile);
void	ft_replace(std::ifstream &infile, std::ofstream &outfile, std::string find, std::string replace);

#endif