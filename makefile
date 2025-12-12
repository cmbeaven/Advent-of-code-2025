.PHONY:all
all: 01.out

01.out: 01.cpp
	g++ $< -o $@

.PHONY:01
01: 01.out
	./$< < 01.txt

.PHONY:01s
01s: 01.out
	./$< < 01Short.txt