
#pragma once

#include <random>

#include "clause.hpp"

struct generator {
  size_t maxLength;
  size_t minLength;
  size_t numberOfVars;
  size_t numberOfClauses;
  generator(size_t maxLength_,
            size_t minLength_,
            size_t numberOfVars_,
            size_t numberOfClauses_,
            std::mt19937& randomGenerator_);
  ClauseSet generate() const;
 private:
  Clause generateClause() const;
  std::mt19937& randomGenerator;
};