*This project has been created as part of the 42 curriculum by khaiamsr.*

# Minitalk

## Description
Minitalk is a small data exchange program using UNIX signals.  
The project consists of two executables:
- **server**: prints its PID and displays messages received from clients.
- **client**: sends a string to the server identified by its PID.

Communication is done **exclusively** with **SIGUSR1** and **SIGUSR2**:
- SIGUSR1 represents bit `0`
- SIGUSR2 represents bit `1`

The server reconstructs bytes from incoming signals and prints characters as soon as they are fully received.

## Instructions

### Requirements
- `cc` compiler
- UNIX-like environment (Linux/macOS)
- Norm-compliant code (42 Norm)

### Compile
```bash
make

AI Usage
AI was used for:
Explaining the project requirements and designing a step-by-step implementation plan.
Reviewing the code for compliance with the allowed functions list and Norm constraints.
Drafting this README structure according to the subject requirements.
All code written for the project was reviewed, tested, and fully understood by the author.
