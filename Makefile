# Created by Kyle Carey on 3/06/2025 with the help of Google Gemini

CC = g++
CFLAGS = -Wall -std=c++11
E_DIR = execs

SOURCES := $(wildcard *.cc)
HEADERS := $(wildcard *.h)
OBJECTS := $(patsubst %.cc, $(E_DIR)/%.o, $(SOURCES)) # Object files in execs/


a.out: $(OBJECTS)
		$(CC) $(CFLAGS) $(OBJECTS) -o a.out

gdb: $(OBJECTS)
		$(CC) $(CFLAGS) -g $(OBJECTS) -o gdb.out

$(E_DIR)/%.o: %.cc $(HEADERS) | $(E_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

$(E_DIR):
		mkdir -p $(E_DIR)

clean:
		rm -rf $(E_DIR) *.o *.out

.PHONY: clean