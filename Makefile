all: one two three clean

one: one.c
  gcc one.c -o one -pthread

two: two.c
  gcc two.c -o two -pthread

three: three.c
  gcc three.c -o three -pthread

clean:
  rm -f one two three
