#pragma once

#include "ClockServer.h"
#include "ClockClient.h"
#include "Exceptions.h"
#include "VariableFrequencyClock.h"
#include "HighResolutionClock.h"
#include "PhaseLockedClock.h"

#include <memory>
#include <string>

namespace ofxTimeSync {
	using dex::timestamp_t;

	inline std::string to_string(timestamp_t t) {
		return dex::Timestamp::timestampToString(t);
	}
}
