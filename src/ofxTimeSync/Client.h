#pragma once

#include "ofxTimeSync/Common.h"

namespace ofxTimeSync {

	class Client
	{
	public:

		void connect(const std::string& addr, int port);

		void setTimeout(int msec);

		timestamp_t getLocalTimestamp();
		std::string getLocalTimestampString();

		timestamp_t getTimestampPhase();
		std::string getTimestampPhaseString();

		timestamp_t getTimestamp();
		std::string getTimestampString();

	private:

		std::unique_ptr<dex::ClockClient> client;
		std::unique_ptr<dex::PhaseLockedClock> clock;
	};

}