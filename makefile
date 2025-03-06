.DEFAULT_GOAL := run

CC?=clang

SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:%.c=%.o)

%.o: %.c
	$(CC) -c -o $@ $<

clean:
	rm -rf $(OBJECTS) tests

tests: ./t/tests.c $(OBJECTS)
	$(CC) -o $@ $<


run: clean $(OBJECTS) tests
	./tests
