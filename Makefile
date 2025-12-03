TARGET = ic
SRC = ic.c

CFLAGS = -Wall -Wextra -g `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

run: $(TARGET)
	cat sample_640×426.ppm | ./$(TARGET)

clean:
	rm -f $(TARGET)
