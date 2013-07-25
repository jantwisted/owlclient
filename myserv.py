import socket

HOST = '127.0.0.1'                 # ip 
PORT = 9000              # port
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen(1)
while 1:
        conn, addr = s.accept()
        print 'Connected by', addr
        #f = open("foo.txt",'r')
        f = open("foo.xml",'r')
        while 1:
                line = f.read()
                print line
                if not line: break
                conn.send(line)
        conn.close()

