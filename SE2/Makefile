SE1_dep = ../SE1/prog22_func.o ../SE1/prog24_func.o 


%.o: %.c
	gcc -c $< -o $@

prog13:  prog13.c $(SE1_dep) prog1_func.o
	gcc -Wall $^ -o $@

prog15:  prog15.c $(SE1_dep) prog1_func.o
	gcc -Wall $^ -o $@

prog24:  prog24.c $(SE1_dep) prog1_func.o prog2_func.o
	gcc -Wall  $^ -o $@
	
prog210:  prog210.c $(SE1_dep) prog1_func.o prog2_func.o
	gcc -Wall  $^ -o $@


#.PHONY: run
#run: 
	