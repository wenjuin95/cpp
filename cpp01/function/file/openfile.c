#include <iostream>
#include <fstream>

// ifstream :: use to read file
// ofstream :: use to create and write file
// fstream  :: combination of ifstream and ofstream (read and write)

int main()
{
    std::ifstream file;
    file.open("test.txt"); //read file
    std::ofstream file2;
    file2.open("test2.txt"); //create and write file

    std::string line;
    while (std::getline(file, line)) //read line by line from the read file
    {
        file2 << line << std::endl; //input the line to the write file
    }
    file.close();
    file2.close();
    return 0;
}

// int main()
// {
//     std::fstream readfile;
//     readfile.open("test.txt", std::ios::in); //read file
//     std::fstream writefile;
//     writefile.open("test2.txt", std::ios::out); //create and write file

//     std::string line;
//     while (std::getline(readfile, line)) //read line by line from the read file
//     {
//         writefile << line << std::endl; //input the line to the write file
//     }
//     readfile.close();
//     writefile.close();
//     return 0;
// }

