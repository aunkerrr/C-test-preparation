.PHONY = all clean

all: one two three

one: one.c
	gcc one.c -o one -pthread

two: two.c
	gcc two.c -o two -pthread

three_one: three_one.c
	gcc three_one.c -o three_one -pthread

three_two: three_two.c
	gcc three_two.c -o three_two -pthread

three_three: three_three.c
	gcc three_three.c -o three_three -pthread

clean:
	rm -f one two three_one three_two three_three
