# simple_shell 

# Description
This project is a simple shell command-line interpreter designed in the C programming language. It allows users to interact with the operating system by executing commands and performing various operations. The shell   provides a user-friendly interface for executing commands, managing processes, and navigating the file system.         

# Features          
• Command Execution: Users can enter commands in the shell, and the interpreter will execute them. It supports executing both built-in commands and external programs.        
• Built-in Commands: The shell supports a set of built-in commands such as cd (change directory), ls (list files and directories), mkdir (create a directory), rm (remove a file or directory), and exit (exit the         shell).       
• Input/Output Redirection: Users can redirect the input and output of commands using symbols such as < (input redirection) and > (output redirection). This allows users to read input from a file or write output to a   file.(❌ Not Implemented yet)            
• Pipeline Commands: The shell supports executing a sequence of commands in a pipeline, where the output of one command is used as the input for the next command.(❌ Not Implemented yet)        
• Signal Handling: The shell handles signals such as Ctrl+C and Ctrl+Z to terminate or suspend the currently running command.       
• Handle Comments: The shell can handle comments in the input by ignoring any text after the # symbol on a line.         
• Handle Variable Replacement: The shell supports variable replacement. Users can define and use variables in commands using the $ symbol. For example, $var will be replaced with the value of the variable var.     
• Handle $? Variable: The shell supports the $? variable, which represents the exit status of the previous command. Users can access this variable to check the success or failure of the last executed command.       
• Handle $$ Variable: The shell supports the $$ variable, which represents the process ID (PID) of the shell itself. Users can use this variable to uniquely identify the shell process.         
• Handle && and || Shell Logical Operators: The shell supports the && and || logical operators to execute commands conditionally. The command following && is executed only if the previous command succeeds (returns 0),   while the command following || is executed only if the previous command fails (returns a non-zero value).        
• Handle Commands Separator ;: The shell supports the command separator ;, which allows users to execute multiple commands sequentially on a single line.        
# Installation
1. Clone the repository to your local machine:  
  git clone https://github.com/kaleabendrias/simple_shell.git   
2. Navigate to the project directory:  
   cd simpleshell/
3. Compile the source code using a C compiler:   
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
4. Run the shell:  
   ./shell  
  # Usage
1. Launch the shell by executing the compiled binary.

2. Enter commands in the shell prompt, and press Enter to execute them.

3. Use the supported features such as input/output redirection, pipeline commands, variable replacement, and logical operators as needed.

4. To exit the shell, enter the exit command or press Ctrl+D.

![Screenshot 2023-05-23 091112](https://github.com/kaleabendrias/simple_shell/assets/125442134/a29ba852-04f7-4455-89ed-6f3463f7edcc)


# Contributing
 Contributions are welcome! If you would like to contribute to this project, please follow these steps:

1. Fork the repository.

2. Create a new branch for your feature or bug fix.

3. Make your changes and test them thoroughly.

4. Commit your changes and push the branch to your forked repository.

5. Submit a pull request, describing your changes in detail and explaining why they should be merged.
# Authors
Yalelet Dessalegn | Kaleab Endrias
