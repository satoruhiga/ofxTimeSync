#include "Client.h"

namespace ofxTimestamp {
		
	void Client::connect(const std::string& addr, int port)
	{
		client = std::make_unique<dex::ClockClient>(Poco::Net::IPAddress(addr), port);
		client->setAcknowledge(true);
		setTimeout(100);

		clock = std::make_unique<dex::PhaseLockedClock>(dex::HighResolutionClock::instance(), *client.get());
		clock->setPhasePanic(5000);
		clock->setUpdatePanic(5000000);
	}

	dex::timestamp_t Client::getLocalTimestamp()
	{
		return dex::HighResolutionClock::instance().getValue();
	}

	std::string Client::getLocalTimestampString()
	{
		return to_string(getLocalTimestamp());
	}

	dex::timestamp_t Client::getTimestampPhase()
	{
		return client->getPhase(dex::HighResolutionClock::instance());
	}

	std::string Client::getTimestampPhaseString()
	{
		return to_string(getTimestampPhase());
	}

	dex::timestamp_t Client::getTimestamp()
	{
		return client->getValue();
	}

	std::string Client::getTimestampString()
	{
		return to_string(getTimestamp());
	}

	void Client::setTimeout(int msec)
	{
		client->setTimeout(msec * 1000);
	}

}