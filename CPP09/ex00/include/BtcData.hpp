/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BtcData.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:38:48 by ikulik            #+#    #+#             */
/*   Updated: 2025/09/28 10:38:48 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_DATA_HPP
# define BTC_DATA_HPP
# include <map>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# define DATE_LENGTH 11
# define MIN_YEAR 2009
# define VALUE_FAILURE -1
# define OUT_OF_BOUND -2

class BtcData
{
	private:
		std::map<std::string, float>	data;
		static float	checkValue( const std::string& number );
		static float	checkWithinLimits( const std::string& number );
		static int		checkDateNumeric( const std::string& str );
		static bool		checkDateFormat( std::string& date );
		void			printOneLine( const std::string& line );
		float			findClosestPrice( const std::string& date);
	public:
		BtcData();
		BtcData( const BtcData& copy );
		~BtcData();
		BtcData&				operator=( const BtcData& copy );
		const std::map<std::string, float>&	getData( void ) const;
		bool	readCsv( const char* filename);
		int		printValues( const char* filename);
};

#endif
