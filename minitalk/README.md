*This project has been created as part of the 42 curriculum by khaiamsr.*

# Minitalk

## Description

Minitalk is a small data exchange program using UNIX signals.

The project consists of two executables:

- **server**: prints its PID and displays messages received from clients.
- **client**: sends a string to the server using the server PID.

Communication is done exclusively with two UNIX signals:

- `SIGUSR1` represents bit `0`
- `SIGUSR2` represents bit `1`

The client sends each character bit by bit.  
The server receives the signals, reconstructs each byte, and prints the message.

## Instructions

### Compile mandatory part

```bash
make

AI Usage
AI was used for:
Explaining the Minitalk subject requirements.
Reviewing the implementation logic.
Checking whether the functions used are allowed by the subject.
Helping draft the README structure.
Explaining signal-based communication and bonus acknowledgement behavior.
All generated explanations and suggestions were reviewed, tested, and understood before being included in the project.