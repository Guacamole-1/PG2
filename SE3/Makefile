SE1_dep = ../SE1/prog22_func.o ../SE1/prog24_func.o 
SE2_dep = ../SE2/prog1_func.o

%.o: %.c
	gcc -g -Wall -c $< -o $@

main: main.o $(SE1_dep)  $(SE2_dep) vecs.o dyns.o linked_list.o bin_tree.o
	gcc -g -Wall $^ -o $@


#.PHONY: run
#run: 
	