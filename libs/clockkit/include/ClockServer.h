//----------------------------------------------------------------------------//
#ifndef DEX_CLOCK_SERVER_H
#define DEX_CLOCK_SERVER_H
//----------------------------------------------------------------------------//
#include <Poco/Net/DatagramSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/Thread.h>
#include <Poco/Runnable.h>
#include "Clock.h"
#include <string>
#include <map>

//----------------------------------------------------------------------------//
using namespace std;

namespace dex {
//----------------------------------------------------------------------------//


/**
 * A network server for a local clock.
 * The server accpts and answers requests on a UDP port.
 * It also stores responses from the clients on the state of their
 * synchronization.
 *
 * The server will not start untill it's thread is started.
 * To start up the server, call start().
 */
class ClockServer : public Poco::Thread, Poco::Runnable
{
private:
	Poco::Net::IPAddress addr_;
	int port_;
    Clock& clock_;
    
    struct Entry
    {
        timestamp_t time;
        int offset;
        int rtt;
    };
    
    map<string, Entry> ackData_;
    bool log_;
    
    static const timestamp_t SYSTEM_STATE_PURGE_TIME;
    timestamp_t lastUpdate_;

public:
    
    /** 
     * Create a new ClockServer.  The server will bind to the provided
     * InetAddress and port.  To bind to ANY local address, then set the
     * InetAddress to 0.0.0.0 .  The server will then use the provided clock
     * to answer requests for time.
     */
    ClockServer(Poco::Net::IPAddress addr, int port, Clock& clock);

    
    void setLogging(bool log);
    
	void start() { Poco::Thread::start(*this); }

protected:
    
    /**
     * The thread calls this run method, which is responsible for
     * all network operations.
     */
    void run();
    
    void updateEntry(string addr, int offset, int rtt);
    
};

//----------------------------------------------------------------------------//
} // namespace dex

//----------------------------------------------------------------------------//
#endif //DEX_CLOCK_SERVER_H

