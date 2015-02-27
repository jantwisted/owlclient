COM=common.h
CC=gcc

all: owlclient

owlclient: error.o owl_client.o owl_echo.o owl_wrap.o owl_term.o owl_cmd.o owl_run.o owl_task.o wrapstdio.o owl_read.o owl_help.o owl_write.o owl_file_read.o conf_manager.o
	$(CC) -o owlclient error.o owl_client.o owl_echo.o owl_wrap.o owl_term.o owl_cmd.o owl_run.o owl_task.o wrapstdio.o owl_read.o owl_help.o owl_write.o owl_file_read.o conf_manager.o

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

owl_help.o: owl_help.c $(COM)
	$(CC) -c $^

owl_write.o: owl_write.c $(COM)
	$(CC) -c $^

owl_file_read.o: owl_file_read.c $(COM)
	$(CC) -c $^

conf_manager.o: conf_manager.c $(COM)
	$(CC) -c $^

clean:
	rm -f *.o
	rm -f *.gch
	rm -f owlclient
