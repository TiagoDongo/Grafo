SRC = src/*.c
INCLUDES = -Iheader

main: $(wildcard $(SRC))
	gcc -o main $(SRC) $(INCLUDES)

run: main
	./main