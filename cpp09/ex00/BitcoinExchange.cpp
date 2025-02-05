/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:16:27 by fshields          #+#    #+#             */
/*   Updated: 2024/11/27 10:26:38 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    if (!init("data.csv"))
        throw std::runtime_error("Database error");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) { data = rhs.data; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) { data = rhs.data; return *this; }

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::init(std::string databasePath)
{
    std::ifstream file;
    std::string line;
    std::string date;
    std::string price;
    
    file.open(databasePath, std::ios::in);
    if (!file.is_open())
        return false;
    while (std::getline(file, line))
    {
        date = line.substr(0, line.find(','));
        price = line.substr(line.find(',') + 1, line.size());
        if (validDate(date))
            data.insert({date, std::stof(price)});
    }
    file.close();
    return true;
}

void BitcoinExchange::processAndDisplay(std::string line)
{
    if (!line.compare("date | value") || line.empty())
        return ;
    std::string date = line.substr(0, line.find(" | "));
    if (!validDate(date)) {
        std::cerr << "Error: bad input => " << line.substr(0, line.find(" | ")) << std::endl;
        return ;
    }
    if (line.size() <= date.size()) {
        std::cerr << "Error: where's the rest of the line?!!" << std::endl;
        return ;
    }
    line.erase(0,  line.find(" | ") + 3);
    size_t dotCount = 0;
    for (auto it = line.begin(); it != line.end() ; it++)
    {
        if (!((*it >= '0' && *it <= '9') || *it == '.') || dotCount > 1)
        {
            if (it == line.begin() && *it == '-')
                continue;
            std::cerr << "Error: bad input => " << line << std::endl;
            return ;
        }
        if (*it == '.')
            dotCount ++;
    }
    if (line.empty()) {
        std::cerr << "Error: amount missing." << std::endl;
        return ;
    }
    float amount = std::stof(line);
    if (amount < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return ;
    }
    if (amount > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return ;
    }
    for (auto it = data.rbegin(); it != data.rend(); it ++)
    {
        if (it->first <= date)
        {
            std::cout << date << " => " << amount << " = " << it->second * amount << std::endl;
            return ;
        }
    }
    std::cout << date << " => " << amount << " = " << "0" << std::endl;
}

void BitcoinExchange::parse(std::string filePath)
{
    std::ifstream file;
    std::string line;
    
    file.open(filePath, std::ios::in);
    if (!file.is_open())
        throw (std::runtime_error("Unable to open file: " + filePath));
    while (std::getline(file, line))
        processAndDisplay(line);
    file.close();
}

bool BitcoinExchange::validDate(std::string& date)
{
    size_t hyphon_count = 0;
    for (auto it = date.begin(); it != date.end(); it++) {
        if (!((*it >= '0' && *it <= '9') || *it == '-'))
            return false;
        if (*it == '-')
            hyphon_count ++;
    }
    if (hyphon_count != 2 || date[0] == '-' || date.find("--") != std::string::npos
    || date[date.size() - 1] == '-' || date.find('-') == std::string::npos)
        return false;
    unsigned int year = (unsigned int) std::stoi(date.substr(0, date.find('-')));
    date.erase(0, date.find('-') + 1);
    if (date.find('-') == std::string::npos)
        return false;
    std::string monthStr = date.substr(0, date.find('-'));
    
    unsigned int month = (unsigned int) std::stoi(date.substr(0, date.find('-')));
    date.erase(0, date.find('-') + 1);
    unsigned int day = (unsigned int) std::stoi(date);
    if (year < 2009 || year > 2024 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        if (day > 30)
            return false;
    if (month == 2 && year % 4 == 0 && year % 100 != 0) {
        if (day > 29)
            return false;
    }
    else if (month == 2) {
        if (day > 28)
            return false;
    }
    date.clear();
    date = std::to_string(year) + "-";
    if (month < 10)
        date += "0";
    date += std::to_string(month) + "-";
    if (day < 10)
        date += "0";
    date += std::to_string(day);
    if (date > TODAY)
        return false;
    return true;
}