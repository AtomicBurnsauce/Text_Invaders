build:
	g++ -w -std=c++14 -Wfatal-errors \
	./*.cpp \
	-o TextInvaders \
	-lncurses;

clean:
	rm ./TextInvaders;

run:
	./TextInvaders;