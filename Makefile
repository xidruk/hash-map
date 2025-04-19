CC = cc

CFLAGS = -Wall -Wextra -g

SRC_DIR = .
HASHING_TOOLS_DIR = hashing_tools
H_PACKE_DIR = h_packe

SRC = $(wildcard $(SRC_DIR)/*.c)
HASHING_TOOLS_SRC = $(wildcard $(HASHING_TOOLS_DIR)/*.c)
H_PACKE_SRC = $(wildcard $(H_PACKE_DIR)/*.c)

OBJ = $(SRC:.c=.o)
HASHING_TOOLS_OBJ = $(HASHING_TOOLS_SRC:.c=.o)
H_PACKE_OBJ = $(H_PACKE_SRC:.c=.o)

TARGET = hash

all: $(TARGET)

$(TARGET): $(OBJ) $(HASHING_TOOLS_OBJ) $(H_PACKE_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(HASHING_TOOLS_DIR)/%.o: $(HASHING_TOOLS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(H_PACKE_DIR)/%.o: $(H_PACKE_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(HASHING_TOOLS_OBJ) $(H_PACKE_OBJ) $(TARGET)

.PHONY: all clean
