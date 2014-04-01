rm a
rm *.txt
g++ -Wall -W -s -pedantic-errors *.cpp -o a

./a inputGen.txt output4b.txt 1 g 4 4
./a inputGen.txt output4as.txt 2 b

./a inputGen.txt output5b.txt 1 g 5 5
./a inputGen.txt output5as.txt 2 b

./a inputGen.txt output6b.txt 1 g 6 6
./a inputGen.txt output6as.txt 2 b

./a inputGen.txt output7b.txt 1 g 7 7
./a inputGen.txt output7as.txt 2 b

./a inputGen.txt output8b.txt 1 g 8 8
./a inputGen.txt output8as.txt 2 b

./a inputGen.txt output9b.txt 1 g 9 9
./a inputGen.txt output9as.txt 2 b

./a inputGen.txt output10b.txt 1 g 10 10
./a inputGen.txt output10as.txt 2 b

./a inputGen.txt output11b.txt 1 g 11 11
./a inputGen.txt output11as.txt 2 b

./a inputGen.txt output12b.txt 1 g 12 12
./a inputGen.txt output12as.txt 2 b

./a inputGenexp.txt outputexpb.txt 1 g 4 12
./a inputGenexp.txt outputexpas.txt 2 b
