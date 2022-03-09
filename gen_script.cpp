#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>


bool makeDir(std::string dirName);
bool makeSubDirs(std::string dirName, int n);

int main(int argc, char** argv) {
    try
    {
        /* code */
        if (argc == 1)
        {
            // throw std::invalid_argument("Invalid number of arguments");
            std::cout << "Enter the name of the user I\'m creating a directory for: ";
            std::string userName;
            std::getline(std::cin, userName);
            std::cout << "Enter number of days of challenge: " ;
            int days;
            std::cin >> days;
            if(days < 1 || days > 200)
            {
                std::cout << "Days must be anything from 1 to 200!" << std::endl;
                return 2;
            }
            std::string dirName = "./" + userName;
            if(makeDir(dirName)){
                std::cout << "Siuuuu!!! Directory created successfully for " << dirName << std::endl;
                if(makeSubDirs(dirName, days)){
                    std::cout << "Yippee! Subdirectories created successfully for " << dirName << std::endl;
                }
                else{
                    std::cout << "Gaah! Subdirectories could not be created for " << dirName << std::endl;
                }
            }
            else{
                std::cout << "Unfortunately! Directory could not be created for " << dirName << std::endl;
            }
        }
        else if (argc == 2)
        {
            std::string dirName = argv[1];
            if(makeDir(dirName)){
                std::cout << "Siuuuu!!! Directory created successfully for " << dirName << std::endl;
                if(makeSubDirs(dirName, 1)){
                    std::cout << "Yippee! Subdirectories created successfully for " << dirName << std::endl;
                }
                else{
                    std::cout << "Gaah! Subdirectories could not be created for " << dirName << std::endl;
                }
            }
            else{
                std::cout << "Unfortunately! Directory could not be created for " << dirName << std::endl;
            }
        }
        else if (argc == 3)
        {
            int days = std::stoi(argv[1]);
            std::string dirName = argv[2];
            if(makeDir(dirName)){
                std::cout << "Siuuuu!!! Directory created successfully for " << dirName << std::endl;
                if(makeSubDirs(dirName, days)){
                    std::cout << "Yippee! Subdirectories created successfully for " << dirName << std::endl;
                }
                else{
                    std::cout << "Gaah! Subdirectories could not be created for " << dirName << std::endl;
                }
            }
            else{
                std::cout << "Unfortunately! Directory could not be created for " << dirName << std::endl;
            }
        }
        else if (argc > 3 && argc <= 10)
        {
            int days = std::stoi(argv[1]);
            for(int i = 2; i < argc; i++)
            {
                std::string dirName = argv[i];
                if(makeDir(dirName)){
                    std::cout << "Siuuuu!!! Directory created successfully for " << dirName << "!" << std::endl;
                    if(makeSubDirs(dirName, days)){
                        std::cout << "Yippee! Subdirectories created successfully for " << dirName << std::endl;
                    }
                    else{
                        std::cout << "Gaah! Subdirectories could not be created for " << dirName << std::endl;
                    }
                }
                else{
                    std::cout << "Unfortunately! Directory could not be created for " << dirName << std::endl;
                }
            }
        }
        else
        {
            std::cout << "Invalid number of arguments!" << std::endl;
            return 1;
        }
        std::cout << "We're done here!" << std::endl;
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Errr! That's an error comrade! " << e.what() << std::endl;
        return 1;
    }
    
}
// function to check if directory exists
bool dirExists(const std::string& dirName_in)
{
    struct stat info;
    if (stat(dirName_in.c_str(), &info) != 0)
        return false;
    else if (info.st_mode & S_IFDIR)
        return true;
    else
        return false;
}

// function to make new directory in present working directory
bool makeDir(std::string dirName)
{
    try {
        // check if directory exists
        if (dirExists(dirName))
        {
            std::cout << "Directory already exists!" << std::endl;
            return false;
        }
        // create new directory
        std::string command = "mkdir " + dirName;
        system(command.c_str());

        return true;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return false;
    }
}

// function to make n subdirectories in given directory
bool makeSubDirs(std::string dirName, int n)
{
    try {
        // create n subdirectories
        for (int i = 1; i <= n; i++) {
            std::string subDirName = dirName + "/Day_" + std::to_string(i);
            if(dirExists(subDirName))
            {
                std::cout << "Subdirectory already exists!" << std::endl;
                continue;
            }
            makeDir(subDirName);
        }
        return true;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return false;
    }
}
