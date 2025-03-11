CC=gcc
CFLAGS=-Wall -Wextra -std=c99
TARGET=traffic_light
TEST_TARGET=test_traffic_light

all: $(TARGET)

$(TARGET): traffic_light.c
	$(CC) $(CFLAGS) -o $(TARGET) traffic_light.c

run: all
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): test_traffic_light.c traffic_light.c
	$(CC) $(CFLAGS) -DTESTING -o $(TEST_TARGET) test_traffic_light.c traffic_light.c

clean:
	rm -f $(TARGET) $(TEST_TARGET) traffic_light.o

