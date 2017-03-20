
#pragma once 

#include <memory>
#include <functional>
#include <vector>

#include "generator.hpp"
#include "clause.hpp"

std::shared_ptr<generator>& getGen();

ClauseSet defaultFunction();

std::vector<std::string> defaultNames();