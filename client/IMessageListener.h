#ifndef __IMESSAGELISTENER_H__
#define __IMESSAGELISTENER_H__

#include <string>

class IMessageListener
{
public:
    virtual void onMessageReceived(std::string message) = 0;
};

#endif
