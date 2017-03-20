require('socket')

io.write("Choose a server > ");
server = io.read();
io.write("Choose a port > ");
port = io.read();
client = socket.connect(server, port);
if client then
	io.write("Successfully connected!\n");
	while true do
		io.write("Send a message >");
		client:send(io.read().."\n");
		reply = client:receive();
		io.write(reply .. "\n");
	end
end
