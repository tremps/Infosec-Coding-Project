# Infosec-Coding-Project
Introducting a compiler bug to the TinyCC compiler.
## Getting started with our project
1. In a terminal, cd into the tinycc directory.
2. Run the following comands:
```
./configure
make
make test
make install
```
	* if make test fails follow the instrctions [here](https://github.com/TinyCC/tinycc/blob/mob/README) to try and debug the problem.
3. cd into the root directory of the project
4. Compile with ```tcc -o test.out test.c```
5. Use: ```./test.out <password>```
	* The expected password is password123, if our exploit is working than a secret key will also be accepted.
