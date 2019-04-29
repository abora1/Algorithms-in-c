all:clean compile

compile:
	gcc floyd.c -o floyd.out
	gcc tromino.c -o tromino.out -lm
	gcc obst.c -o obst.out -lm

clean:
	rm -rf *.out
