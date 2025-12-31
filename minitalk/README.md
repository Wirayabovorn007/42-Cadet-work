*This project has been created as part of the 42 curriculum by wiboonpr.*

# Minitalk

## Description
**Minitalk** is a 42 School UNIX programming project that challenges students to create a communication program in the form of a client and a server. The catch? The only method of communication allowed is UNIX signals.

This project implements a custom Binary Protocol using only two signals: **SIGUSR1** and **SIGUSR2**. The client deconstructs the input string into bits (0s and 1s) and transmits them one by one. The server listens for these signals, reconstructs the bits into bytes, and prints the resulting characters. The project handles Unicode characters seamlessly by treating data as a raw byte stream and includes a Handshake mechanism (in the bonus part) where the server acknowledges every received message to ensure data integrity and speed.

## Instructions

### Compilation
The project uses a `Makefile` for compilation. To compile the executable, run the following command at the root of the repository:

```bash
make
```
This will generate the `client` `server`
executables. 

To compile the bonus version (with acknowledgement and enhanced signal handling):
```bash
make bonus
```

Other available commands:
```bash
make clean: Removes object files.
```
```bash
make fclean: Removes object files and the executable.
```
```bash
make re: Recompiles the project from scratch.
```
### Execution
The server must be started first to obtain its Process ID (PID).
**1. Start the Server:**
```Bash
./server
```
Output:
```output
Server PID: 12345
```
**2. Run the Client:** Open a new terminal window and run the client using the PID printed by the server and the string you wish to send.
```Bash
./client 12345 "Hello, World!"
```
**Unicode Support:** You can send emojis or other UTF-8 characters:
```Bash
./client 12345 "Testing Unicode: 😀🚀"
```

## Resources

### References
- [Minitalk Tutorial](https://medium.com/@digitalpoolng/42-minitalk-building-a-simple-client-server-communication-program-in-c-a5e6d96c97ec)

- [Bitwise Operators in C](https://www.geeksforgeeks.org/c/bitwise-operators-in-c-cpp/)

- [Unix Signals (man page)](https://man7.org/linux/man-pages/man7/signal.7.html)


## AI Usage
Artificial Intelligence was used in this project for the following tasks:

- Code Review & Debugging: To identify critical logic errors in bitwise reconstruction (MSB vs LSB ordering) and to fix syntax errors in the Makefile.

- Concept Explanation: To understand the mapping of SIGUSR1/SIGUSR2 to binary 0 and 1, and why they act as a custom protocol.
