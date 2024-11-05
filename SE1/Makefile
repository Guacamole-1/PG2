# Bruno Soares 51832 
# Duarte Santos 51764
# Pedro Alves 51451
file1 = prog14
file2 = prog22
file3 = prog24
file4 = filter

.DEFAULT_GOAL := help

prog14: $(file1).c 
	@printf "gcc $(file1).c -o $(file1) && ./$(file1)\n\n"
	@gcc $(file1).c -o $(file1) && ./$(file1)
	
prog22: $(file2).c $(file2).h
	@printf "gcc $(file2).c -o $(file2) && ./$(file2)\n\n"
	@gcc $(file2).c -o $(file2) && ./$(file2)

prog24: $(file3).c $(file3).h
	@printf "gcc $(file3).c -o $(file3) && ./$(file3) window $$(echo '$$(cat palavras.txt)')\n\n"
	@gcc $(file3).c -o $(file3) && ./$(file3) window $$(cat palavras.txt)

filter: $(file4).c $(file3).h $(file2).h
	@printf "gcc $(file4).c -o $(file4) && ./$(file4) 1 primeiro \n\n"
	@gcc $(file4).c -o $(file4) && ./$(file4) 1 primeiro

help:
	@printf "Uso: make ($(file1)|$(file2)|$(file3)|$(file4))\n"