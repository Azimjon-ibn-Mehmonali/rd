g++ -std=c++17 -DDEBUG -o main main.cpp;
for i in {01..10};
do
	./main < $i.in > $i.out;
done;
