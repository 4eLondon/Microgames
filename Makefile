input = pong.c
output = pong

all:
	gcc $(input) -lraylib -o $(output)
    
