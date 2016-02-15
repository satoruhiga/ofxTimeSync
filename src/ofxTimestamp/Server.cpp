#include "Server.h"

namespace ofxTimestamp {

	void Server::init(int port)
	{
		server = std::make_unique<dex::ClockServer>(Poco::Net::IPAddress("0.0.0.0"), 
			port,
			dex::HighResolutionClock::instance());
		server->start();
	}
	
	timestamp_t Server::getTimestamp()
	{
		return dex::HighResolutionClock::instance().getValue();
	}
	
	std::string ofxTimestamp::Server::getTimestampString()
	{
		return dex::Timestamp::timestampToString(getTimestamp());
	}

}
