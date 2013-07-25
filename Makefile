COM=common.h
CC=cc

all: owlclient

owlclient: error.o owl_client.o owl_echo.o owl_wrap.o owl_term.o owl_cmd.o owl_run.o owl_task.o wrapstdio.o owl_read.o
	$(CC) -o owlclient error.o owl_client.o owl_echo.o owl_wrap.o owl_term.o owl_cmd.o owl_run.o owl_task.o wrapstdio.o owl_read.o

error.o: error.c $(COM)
	$(CC) -c $^

owl_client.o: owl_client.c $(COM)
	$(CC) -c $^

owl_echo.o: owl_echo.c $(COM)
	$(CC) -c $^

owl_wrap.o: owl_wrap.c $(COM)
	$(CC) -c $^

owl_term.o: owl_term.c $(COM)
	$(CC) -c $^

owl_cmd.o: owl_cmd.c $(COM)
	$(CC) -c $^

owl_run.o: owl_run.c $(COM)
	$(CC) -c $^

owl_task.o: owl_task.c $(COM)
	$(CC) -c $^

wrapstdio.o: wrapstdio.c $(COM)
	$(CC) -c $^

owl_read.o: owl_read.c $(COM)
	$(CC) -c $^

clean:
	rm -f *.o
	rm *.gch
	rm owlclient
