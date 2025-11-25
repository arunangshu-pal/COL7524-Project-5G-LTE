extractCSV.out: extractCSV.o mystrings.o mydate.o
	g++ extractCSV.o mystrings.o mydate.o -o extractCSV.out

extractCSV.o: extractCSV.cpp
	g++ -c extractCSV.cpp

mystrings.o: mystrings.cpp
	g++ -c mystrings.cpp

mydate.o: mydate.cpp
	g++ -c mydate.cpp
