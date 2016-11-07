EXE=server_main client_main
CC=g++
FLAG=-lhiredis -levent -pthread -Wformat
OBJ=redis_publisher.o publisher.o redis_subscriber.o subscriber.o

all:$(EXE)

$(EXE):$(OBJ)
	$(CC) -o publisher redis_publisher.o publisher.o $(FLAG)
	$(CC) -o subscriber redis_subscriber.o subscriber.o $(FLAG)

redis_publisher.o:redis_publisher.h
redis_subscriber.o:redis_subscriber.h

publisher.o:publisher.cc
	$(CC) -c publisher.cc

subscriber.o:subscriber.cc
	$(CC) -c subscriber.cc

clean:
	rm publisher subscriber *.o
