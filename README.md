# Infosec-Coding-Project
This project introduces a bug into the TinyCC compiler. This bug targets typicaly safe code and makes it vulnerable.
The source for the TinyCC compiler can be found at https://github.com/TinyCC/tinycc and is licensed under the GNU Lesser General Public License.
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
