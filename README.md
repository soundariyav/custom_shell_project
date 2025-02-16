# README - Custom Shell Implementation

## Overview
This project is a simple shell implementation in C++ that supports command execution, changing directories, and background process execution.

## Methods Implemented

### 1. `void printprompt()`
- Prints the shell prompt (`nush$ `) to indicate readiness for user input.

### 2. `void changeDirectory(vector<char*>& args)`
- Handles changing directories using the `cd` command.
- Checks if a directory argument is provided.
- Uses `chdir()` to change the working directory.
- Prints success or failure messages accordingly.

### 3. `bool background_process(vector<char*> args)`
- Checks if a command should be executed in the background by looking for the `&` symbol at the end of the command.
- Currently, the implementation is incomplete and does not return the expected result.

### 4. `int main(int argc, char** argv)`
- Implements the main loop of the shell.
- Prints the shell prompt and waits for user input.
- Parses the input command into a vector of arguments.
- Checks if the command is `exit` and terminates the shell.
- Handles the `cd` command using `changeDirectory()`.
- Forks a new child process to execute other commands using `execvp()`.
- If the command ends with `&`, it runs in the background.
- Waits for the child process to finish unless it is a background process.
- Handles errors such as command not found (`errno == ENOENT`).

## Compilation and Execution
To compile the shell:
```sh
 g++ -o nush shell.cpp
```
To run the shell:
```sh
 ./nush
```

## Features
- Executes shell commands using `execvp()`.
- Changes directories using the `cd` command.
- Supports background processes using `&`.
- Handles command execution errors.

## Future Improvements
- Fix `background_process()` implementation to properly detect background execution.
- Improve error handling for invalid commands.
- Implement additional built-in commands for better shell functionality.

## Author
- Soundariya Vijayakumar

