#include "ChatClient.h"

#define ADDRESS = "Someaddress";
#define PORT = 1234;
#define KEYPATH = "somepath";
#define MAX_MESSAGE_TYPE = 255;
#define PART = '/part';
#define SAYROOM = '/say';
#define MSGUSER = '/msg';
#define LISTUSERS = '/list';


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
	_clientSocket->send(listcmd, listcmd.length());
	_clientSocket->send(roomname, roomname.length());
}

void ChatClient::registerMessageListener(std::IClientListener* listener)
{    
	ChatClient::_clientListeners.push_front(listener);

}

void ChatClient::unregisterListener(std::IClientListener* listener)
{
	ChatClient::_clientListeners.pop_front(slistener);
}

void ChatClient::readUntil(ISocket* socket, char untilThis, int maxLength)
{
	int bytesRead = 0;
	char buffer = '\0';
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
	
	message = readUntil(_clientSocket, ' ', MAX_MESSAGE_TYPE)
	
	switch (message)
	{
			case PART:
			
			partHandler();
			
			break;
			
			case LISTUSERS:
			
			listUsersHandler();
			
			break;
			
			case SAYROOM:
			
			sayRoomHandler();
			
			break;
			
			case MSGUSER:
			
			msgUserHandler();
			
			break;
	
	}

}

void partHandler()
{

	
	
}

void listUsersHandler()
{

	
	
}
	
void sayRoomHandler()
{

	
	
}

void msgUserHandler()
{

	

}