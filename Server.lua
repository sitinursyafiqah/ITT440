require('socket');

port = 80;

server = socket.bind('*', port);
io.write("Waiting at the door "..port.."\n");
cnx = server:accept();
io.write("Connection made: ")
while true do
	msg = cnx:receive();
	io.write(msg .. "\n");
	io.write("Your answer > ");
	cnx:send(io.read() .. "\n");
end
io.read();
