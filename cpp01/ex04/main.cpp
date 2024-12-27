/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 06:57:45 by welow             #+#    #+#             */
/*   Updated: 2024/12/27 16:19:27 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream> //for file stream

static void	process_line(std::ofstream &WriteFile, std::ifstream &ReadFile, std::string s1, std::string s2, std::string line)
{
	size_t		position = 0;
	size_t		linePosition;
	std::string	tempLine;

	//check if the file is not end of file and give each of the line a new line
	if (ReadFile.eof() == false)
		line += '\n';

	//check if the string to replace is empty
	if (s1 == "")
	{
		WriteFile << line;
		return ;
	}

	/********************************************************************************/
    /* "find(s, position)" returns the position of the substring (like strchr in C) */
    /* s : the substring to be searched                                             */
    /* position : the position from where the search should start                   */
    /* "std::string::npos" means the end of the string                              */
    /* this function returns the position of the first occurrence of the substring  */
    /********************************************************************************/
	//std::cout << "orignal line: " << line << std::endl;//visualize
	while ((linePosition = line.find(s1, position)) != std::string::npos)
	{

		//remove the string that you want to replace and get the unwanted string
        /************************************************************************/
        /* "substr(position, length)" returns a new string which is a substring */
        /* position : the starting position of the substring                    */
        /* length : the length of the substring                                 */
        /* "linePosition + s1.size()"                                           */
        /************************************************************************/
		tempLine = line.substr(linePosition + s1.size());
		//std::cout << std::endl << "after remove with s1: " << tempLine << std::endl;//visualize

		//get the string with the position the rest will be removed
		line.resize(linePosition);
		// if (line == "") //visualize
		// 	std::cout << "[ line: \"\"" << " ] + ";//visualize
		// else//visualize
		// 	std::cout << "[ line: " << line << " ] + ";//visualize
		// std::cout << "[ s2: " << s2 << " ] + ";//visualize
		// std::cout << "[ tempLine: " << tempLine << " ]" << std::endl;//visualize
		//line = line + s2 + tempLine;
		// std::cout << "Modified line: " << line << std::endl << std::endl;//visualize

		//update the position
		position = linePosition + s2.size();
	}

	//write the modified line in the output file
	WriteFile << line;
}

static void	ft_replace_line(std::string fileName, std::string s1, std::string s2)
{
    std::string     ReadFileName;
    std::string     WriteFileName;
	std::ifstream	ReadFile;
	std::ofstream	WriteFile;
	std::string		line;
	std::string		tempLine;


    ReadFileName = fileName;
    WriteFileName = fileName + ".replace";

	//open the input file
    ReadFile.open(ReadFileName.c_str());
	if (ReadFile.is_open() == false)
		std::cout << "The input file could not be opened" << std::endl;

	//create the output file
	WriteFile.open(WriteFileName.c_str());
	if (WriteFile.is_open() == false)
		std::cout << "The output file could not be opened" << std::endl;

	//check if the file is empty
	/****************************************************************************/
	/* peek() :: check next character in input stream without extracting it     */
	/* if the file is empty, it will return "std::ifstream::traits_type::eof()" */
	/****************************************************************************/
	if (ReadFile.peek() == std::ifstream::traits_type::eof() && s1 == "")
	{
		std::cout << "The input file is empty" << std::endl;
		WriteFile << s2;
	}

    /****************************************************/
    /* "getline(file, line)" reads a line from the file */
    /* file : the file to read from                     */
    /* line : the string where the line will be stored  */
    /****************************************************/
	while (getline(ReadFile, line))
		process_line(WriteFile, ReadFile, s1, s2, line);

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
