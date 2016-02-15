#pragma once

#include "ofxTimestamp/Common.h"

namespace ofxTimestamp {
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