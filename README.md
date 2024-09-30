# CS3113 Project 1: Shared Memory

This project/lab provides a general overview of how shared memory is implemented and cooperates between processes on a Linux System

## Installation
**'NOTE: THE IMPLEMENTATION OF THIS CODE IS ONLY FEASIBLE ON LINUX SYSTEMS, THIS IS DENOTED BY THE <UNISTD.H> LIBRARY'**

To install and run the C code provided in the repository we will do the following:
1. download and unzip the CS3113HW_1 file in any directory, using the terminal we will navigate to the directory and to do so we use the "cd <file_name>" command:
  
<img width="161" alt="Example" src="https://github.com/user-attachments/assets/56969e54-5b59-4b59-911f-ee0258b221e5">

Helpful Tip: Use "ls", shorthand for list services, to determine which directory you are in. Depending on where you are on your local computer you may have to use multiple "cd <file_name>" commands in order to reach the right directory!

2. Once we are in the right directory, this should be the CS3113_HW1 folder, do "ls" again and identify the "memory.c" folder in the directory. This is the file we will be compiling!

<img width="160" alt="Example" src="https://github.com/user-attachments/assets/bb84c74f-0d8c-4a32-9003-46a70e26cddd">

3. Once you've found the "memory.c" file, we will use the command ```gcc memory.c -o <EXE_FILENAME_HERE>``` to compile our code and create the executable for the respective code we are compiling!

<img width="273" alt="Example" src="https://github.com/user-attachments/assets/4bf812a3-881b-4bf8-a256-99a4c77e75e1">

In the above snippet, I've decided to name my executable "memory". Once you run the compilation command, use the "ls" command to see your files. The executable file will be colored green and I've circled it above as reference to what it should look like in the terminal

Once you've compiled the C file on your machine, we will use the terminal command ```./``` which is the executable command for linux systems. To use this command type in the terminal ```./<EXE_FILENAME_HERE>``` to run the generated program file. For the example shown above that command will look like: ```./memory```. After doing so, you will have successfully run the memory.c file from the executable.
