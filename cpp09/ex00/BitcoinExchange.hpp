/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:05:07 by fshields          #+#    #+#             */
/*   Updated: 2024/11/27 10:17:36 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# define TODAY "2024-11-27"

# include <map>
# include <iostream>
# include <fstream>

class BitcoinExchange {
    private:
        std::map<std::string, float> data;
        BitcoinExchange(const BitcoinExchange& rhs);
        BitcoinExchange& operator=(const BitcoinExchange& rhs);
        bool init(std::string databasePath);
        void processAndDisplay(std::string line);
        bool validDate(std::string& date);
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        void parse(std::string filePath);
    
};

#endif