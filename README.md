# Infosec-Coding-Project
This project introduces a bug into the TinyCC compiler. The bug is introduced by a variation of Ken Thompson's "Trusting Trust"
attack. The source for the TinyCC compiler can be found at https://github.com/TinyCC/tinycc and is licensed under the GNU Lesser General Public License.
## Testing our project
1. Start with a fresh instalation of tcc on your system.
2. Compile test.c and run it multiple times with various passwords
```
tcc -o test.out test.c
./test.out <password>
```
3. You should notice that the program fails to authorize you unless you enter 'password123'
4. If the above steps worked, then you can see that with a safe compiler, our program functions as intended
5. Next, within our project, move libtcc_bugged.c into the tinycc directory and rename it to libtcc.c
6. Within the tinycc directory, make and install our bugged compiler
```
make clean
./configure
make
make test
sudo make install
```
7. Now, replace libtcc.c with its original, unmodified source code provided in the base directory of the project
8. Within the tinycc directory, make and install tcc as many time as you would like
```
make clean
./configure
make
make test
sudo make install
```
9. You can now repeat step 2, you should notice that every string entered is accepted

### Note
The configure and makefile within the tinycc directory we provide are modified to compile with tcc. This is vital for the code to work
as intended. The first time compiling our code with the bugged version, you create a bugged version of tcc that will target test.c and that
will target libtcc.c to reintroduce itself into all preceding versions of the compiler. This bugged version is only designed to compile
the original tcc source code. Do not try compiling the bugged version of libtcc.c with a bugged version of the compiler. Step 8 can
be repeated as many times as you want because the bugged version is continuously reintroducing itself.