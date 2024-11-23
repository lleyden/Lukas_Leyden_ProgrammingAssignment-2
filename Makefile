# Lukas Leyden
# 11/21/2024
# CS33211

#Menu
msg:
	@echo 'Targets are: '
	@echo ' banker'
	@echo '	utility'
	@echo ' run'
	@echo  ' clean'


util: ./source/utility.cpp
	g++ -c "./source/utility.cpp" -o ./out/utility.o

banker: ./source/banker.cpp ./source/utility.cpp
	make utility
	g++ -c "./source/banker.cpp" -o ./out/banker.o
	g++ "./out/banker.o" "./out/utility.o" -o ./out/banker
	
run: ./source
	make banker
	clear
	./out/banker "./table/resource.txt"

clean:
	rm -f ./out/banker
	rm -f ./out/utility
	rm -f ./out/*.o
