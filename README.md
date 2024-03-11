
# Caesar Cipher Decryptor

## Introduction
This project implements a Caesar Cipher decryption tool that uses frequency analysis to break the encryption. It's designed to be a straightforward, command-line application that reads encrypted text, either input by the user or specified in a file, and attempts to decrypt it based on the distribution of letters in the English language.

## Features
- Decrypt text encrypted with a Caesar cipher without needing the key.
- Frequency analysis based on a predefined distribution of English letters.
- Input encrypted text through the command line.

## Getting Started

### Prerequisites
- C++ compiler (e.g., GCC, Clang, MSVC)
- Make (optional for build automation)

### Building the Project
1. Clone the repository to your local machine:
   ```
   git clone https://your-repository-url.git
   ```
2. Navigate to the project directory:
   ```
   cd caesar-cipher-decryptor
   ```
3. Compile the project. If you're using `g++` (GNU Compiler Collection), you can compile the project with the following command:
   ```
   g++ -o decryptor main.cpp -std=c++11
   ```
   Adjust the command according to your setup and compiler.

### Running the Application
After compiling, you can run the application with:
```
./decryptor
```
Follow the on-screen instructions to input encrypted text and decrypt it.

## Usage
1. **Decrypt Caesar's Cipher**: Select this option and follow the prompts to enter your encrypted text. The program will attempt to decrypt it and display the result.
2. **Exit**: Terminate the application.
