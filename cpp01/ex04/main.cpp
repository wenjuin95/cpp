/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 06:57:45 by welow             #+#    #+#             */
/*   Updated: 2024/12/20 18:24:46 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream> //for file stream

static void	ft_replace_line(std::string fileName, std::string s1, std::string s2)
{
    std::string     ReadFileName;
    std::string     WriteFileName;
	std::ifstream	ReadFile;
	std::ofstream	WriteFile;
	std::string		line;
	std::string		tempLine;
	size_t			linePosition;


    ReadFileName = fileName;
    WriteFileName = fileName + ".replace";
    ReadFile.open(ReadFileName.c_str());
	if (ReadFile.is_open() == false)
		std::cout << "The input file could not be opened" << std::endl;
	WriteFile.open(WriteFileName.c_str());
	if (WriteFile.is_open() == false)
		std::cout << "The output file could not be opened" << std::endl;
    /**
     * "getline(file, line)" reads a line from the file
     * file : the file to read from
     * line : the string where the line will be stored
     */
	while (getline(ReadFile, line))
	{
		int	position = 0;
        /**
         * "find(s, position)" returns the position of the substring (like strstr in C)
         * s : the substring to be searched
         * position : the position from where the search should start
         * "std::string::npos" means the end of the string
         * this function returns the position of the first occurrence of the substring
        */
	   	// std::cout << "orignal line: " << line << std::endl;//visualize
		while ((linePosition = line.find(s1, position)) != std::string::npos)
		{
            /**
             * "substr(position, length)" returns a new string which is a substring
             * position : the starting position of the substring
             * length : the length of the substring
             * "linePosition + s1.size()"
            */
			tempLine = line.substr(linePosition + s1.size()); //remove the string that you want to replace and get the unwanted string
			// std::cout << std::endl << "after remove with s1: " << tempLine << std::endl;//visualize
			line.resize(linePosition); //get the string with the position the rest will be removed
			// if (line == "") //visualize
			// 	std::cout << "[ line: \"\"" << " ] + ";//visualize
			// else//visualize
			// 	std::cout << "[ line: " << line << " ] + ";//visualize
			// std::cout << "[ s2: " << s2 << " ] + ";//visualize
			// std::cout << "[ tempLine: " << tempLine << " ]" << std::endl;//visualize
			line = line + s2 + tempLine;
			// std::cout << "Modified line: " << line << std::endl << std::endl;//visualize
			position = linePosition + s2.size();
		}
		WriteFile << line;
		if (ReadFile.eof() == false) //if the end of the file is not reached
			WriteFile << std::endl; //write a new line in the file
	}
	ReadFile.close();
	WriteFile.close();
}


int main(int ac, char **av)
{

    if (ac != 4)
    {
        std::cout << "wrong argument number" << std::endl;
		std::cout << "Usage: ./replace [filename] [string to replace] [string to replace with]" << std::endl;
        return (1);
    }
    else
        ft_replace_line(av[1], av[2], av[3]);
    return 0;
}
