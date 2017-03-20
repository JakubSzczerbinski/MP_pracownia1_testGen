
#pragma once

#include <vector>
#include <functional>
#include <string>

#include "clause.hpp"
#include "defaults.hpp"

inline ClauseSet generateClauseSet() {
	return defaultFunction();
}

inline std::vector<std::string>& variableNames()
{
	static auto names = defaultNames();
	return names;
}