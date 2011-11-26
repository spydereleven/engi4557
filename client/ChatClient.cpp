#include "ChatClient.h"

#define ADDRESS = "Someaddress";
#define PORT = 1234;
#define KEYPATH = "somepath";
#define MAX_MESSAGE_TYPE = 255;
#define PART = "/part";
#define SAYROOM = "/say";
#define MSGUSER = "/msg";
#define LISTUSERS = "/list";


ChatClient();
~ChatClient();

void ChatClient::connect(std::string username, std::string password)
{
    Client_clientSocket->connect(ADDRESS, PORT);
        
    std::string authcmd = "/auth ";
    std::string space = " ";
    _clientSocket->send(authcmd, authcmd.length());
    _clientSocket->send(username, username.length());
    _clientSocket->send(space, space.length());
    _clientSocket->send(password, password.length());
}
    
void ChatClient::connect(std::string username, std::string keyPath)
{
    throw std::logic_error("To do");
    
}
    
void ChatClient::disconnect()
{
    IClientListener->disconnect;
}
    
void ChatClient::sendToRoom(std::string roomname, std::string message)
{
    std::string saycmd = "/say ";
    std::string space = " ";
    _clientSocket->send(saycmd, saycmd.length());
    _clientSocket->send(roomname, roomname.length());
    _clientSocket->send(space, space.length());
    _clientSocket->send(message, message.length());
            
}
    
void ChatClient::sendToUser(std::string username, std::string message)

{
    std::string msgcmd = "/msg ";
    std::string space = " ";
    _clientSocket->send(msgcmd, msgcmd.length());
    _clientSocket->send(username, username.length());
    _clientSocket->send(space,space.length());
	_clientSocket->send(message, message.length());             
}

void ChatClient::sendRaw(std::string message)
{
	_clientSocket->send(message,message.length());	
}

void ChatClient::getRoomList()
{    
	throw std::logic_error("To do");
}
				 
void ChatClient::getRoomUserList(std::string roomname)
{
	std::string listcmd = "/list ";
	_clientSocket->send(listcmd.c_str(), listcmd.length());
	_clientSocket->send(roomname, roomname.length());
}

void ChatClient::registerMessageListener(std::IClientListener* listener)
{    
	ChatClient::_clientListeners.push_front(listener);

}

void ChatClient::unregisterListener(std::IClientListener* listener)
{
	ChatClient::_clientListeners.pop_front(listener);
}

void ChatClient::readUntil(ISocket* socket, char untilThis, int maxLength)
{
	int bytesRead = 0;
	char buffer = ' ';
	std::stringstream ss; 
	
	for (bytesRead = 0; bytesRead < maxLength; bytesRead++)
	{
		bytesRead += socket->recv(&buffer, 1); 
		
		// Read until first space
		if (buffer == untilThis)
		{   
			break;
		}   
		
		ss << buffer; 
	}
	
	if (bytesRead == maxLength)
	{
		throw std::runtime_error("Maximum read length reached.");
	}
	
	return ss.str();
}

void ChatClient::waitForServerMessage()
{    
	std::string message;
	
	message = readUntil(_clientSocket, buffer, MAX_MESSAGE_TYPE);
	
	int messagenum = 0;
	
	if (message = "/part")
	{
		
		messagenum = 1;
		
	}
	
	else if (message = "/list)
			 
	{
	
		messagenum = 2;
	
	}
	
			 
	else if (message = "/say")
			 
	{
	
		messagenum = 3;
		
	}
	
	else if (message = "/msg")
			 
	{
	
		messagenum = 4;
		
	}
	
			 
	switch (messagenum)
	{
			case 1:
			
			partHandler();
			
			break;
			
			case 2:
			
			listUsersHandler();
			
			break;
			
			case 3:
			
			sayRoomHandler();
			
			break;
			
			case 4:
			
			msgUserHandler();
			
			break;
	
	}

}

void partHandler()
{

	std::string roomname = readUntil(_clientSocket, " ", roomname);
	std::string reason = readUntil(_clientSocket, "/0", reasonmsg);
	
}

void listUsersHandler()
{

	readUntil(_clientSocket, " ", );
	
}
	
void sayRoomHandler()
{

	std::string roomname = readUntil(_clientSocket, " ", room);
	std::string username = readUntil(_clientSocket, " ", user);
	std::string message = readUntil(_clientSocket, "/0", sayToRoom);
	
}

void msgUserHandler()
{

	std::string username = readUntil(_clientSocket, " ", user);
	std::string message = readUntil(_clientSocket, "/0",msgToUser);

}