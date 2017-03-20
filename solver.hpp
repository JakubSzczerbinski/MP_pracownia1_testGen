
#pragma once

#include <map>
#include <set>
#include <vector>
#include <algorithm>

#include "clause.hpp"

typedef std::map<int, bool> Evaluation;
typedef std::set<int> Vars;

struct Solution {
  Evaluation eval;
  Vars loose_vars;
  size_t numberOfSolutions() const { return (1 << loose_vars.size()); }
};
typedef std::vector<Solution> Solutions;

size_t numberOfSolutions(const Solutions& solutions);

struct Solver {
  Solutions solve(const ClauseSet& clauses) const;
  Solutions internal_solve(const ClauseSet& clauses, Vars vars) const;
  ClauseSet filterClauses(const ClauseSet& clauses, int var) const;
};

Solutions solve(const ClauseSet& clauses);
