# corewar
Final project of algorithmic branch

The principle of the project and my explanation of the code are in the wiki part of this repo 

How to exec:
You will need the following dependencies installed on your shell 
- GNU Make
- GNU Compiler (gcc)
- Sdl2 (a checker les dependancies sur mon mac)
- Git
To compile the code, clone the repo, enter the repo cloned and insert make

To execute the programs either enter asm or vm directories and follow the pattern :
- Asm : ./asm <sourcefile.s>
 
 Ex : ./asm ../ressources/barriere.s

- VM : ./corewar [-vg] [-d nbr_cycles][-n number]champion.cor (Max: 4) 

Ex : ./corewar -g -v 31 ../ressources/cor/gateau.cor ../ressources/cor/doge.cor ../ressources/cor/casimir.cor

where -g = visual mode , -v verbose mode that you can combine (1, 3, 7, 15, 31), -n set champion number

Those flags are not compulsory for the execution of the code but they help understand what's going on

