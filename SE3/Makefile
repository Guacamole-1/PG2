SE1_dep = ../SE1/prog22_func.o ../SE1/prog24_func.o 


%.o: %.c
	gcc -g -c $< -o $@

prog1:  prog1.c $(SE1_dep) funcs.o
	gcc -g -Wall $^ -o $@



#.PHONY: run
#run: 
	