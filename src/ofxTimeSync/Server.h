#pragma once

#include "ofxTimeSync/Common.h"

namespace ofxTimeSync {
	class Server
	{
	public:

		void init(int port);

		timestamp_t getTimestamp();
		std::string getTimestampString();

	private:

		std::unique_ptr<dex::ClockServer> server;
	};
}