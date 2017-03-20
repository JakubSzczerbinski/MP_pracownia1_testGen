
#pragma once

#include <string>
#include <sstream>
#include <iostream>

#include "clause.hpp"
#include "solver.hpp"
#include "modify.hpp"

std::string varName(int i);

std::ostream& operator<<(std::ostream& os, const Clause& clause);

std::ostream& operator<<(std::ostream& os, const ClauseSet& clauses);

std::ostream& operator<<(std::ostream& os, const Vars& vars);

std::ostream& operator<<(std::ostream& os, const Evaluation& eval);

void write_solution(std::stringstream& ss, const Solutions& sols);


std::string generate_test(const ClauseSet& clauses,
                          const std::string& stringName,
                          size_t testDuration);

void generate_tests(std::string name,
                    size_t n,
                    size_t time_limit_ms);