### Folder generator tool for your planned streak
This is a script I made to automate the process of creating 4 folders with 100 subdirectories each for each day of a 100 days long coding challenge.
It can be run directly from the CLI in different ways.

### Getting started
Clone this repo locally
```
git clone https://github.com/tee-stark/streak-folder-gen
```

`cd` into the newly cloned directory, and compile the source file there:
```
g++ gen_script.cpp -o streak-gen
```
Nothing much more, your script is ready to use!
You can add it to your PATH variable so that you can run it from any where on your machine.

### Usage
This tool can be used in 3 ways:
1. An interactive tool:
  You can simply start the tool in your terminal using the command `./streak_gen` on UNIX machines or `streak_gen on Windows`, this will open up the interactive interface, where you enter the name of the folder you want to create, and how many days your challenge runs for. This will then create the Folder and give it the number of subdirectories as the number of days you have specified.

2. A command:
  - It can work as a command that takes in `2 <= x <= 10` arguments. That is it can take in 2 or more arguments(not more than 10 though), where the first argument is the number of days your challenge runs for, and the remaining arguments are the folders to create. E.g:
  ```
  ./streak-gen 10 First Second Third
  ```
  This command can be interpreted as: "Create 2 folders First and Seond, and give them 10 subdirectories each (i.e Day_1, Day_2,...Day_10).
  
More features are likely to come soon. This could be the start of just another great CLI tool. Enjoy!
