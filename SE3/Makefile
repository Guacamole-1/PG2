SE1_dep = ../SE1/prog22_func.o ../SE1/prog24_func.o 
SE2_dep = ../SE2/prog1_func.o

%.o: %.c
	gcc -g -Wall -c $< -o $@

prog1: prog1.h
	gcc -g -Wall -c $< -o $@

teste: teste.o $(SE1_dep) vecs.o dyns.o $(SE2_dep)
	gcc -g -Wall $^ -o $@



#.PHONY: run
#run: 
	