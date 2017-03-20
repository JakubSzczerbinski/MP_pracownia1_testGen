
#include "generator.hpp"

generator::generator(size_t maxLength_,
                     size_t minLength_,
                     size_t numberOfVars_,
                     size_t numberOfClauses_,
                     std::mt19937& randomGenerator_)
    : maxLength(maxLength_),
      minLength(minLength_),
      numberOfVars(numberOfVars_),
      numberOfClauses(numberOfClauses_),
      randomGenerator(randomGenerator_) {}

ClauseSet generator::generate() const {
  ClauseSet result;

  for (size_t i = 0; i < numberOfClauses; i++) {
    auto clause = generateClause();
    result.insert(clause);
  }

  return result;
}

Clause generator::generateClause() const {
  Clause result;
  std::uniform_int_distribution<size_t> sizeOfClause(minLength, maxLength);
  size_t length = sizeOfClause(randomGenerator);

  std::uniform_int_distribution<int> varGen(-numberOfVars, numberOfVars);

  for (size_t i = 0; i < length; i++) {
    int var = varGen(randomGenerator);
    while (var == 0) {
      var = varGen(randomGenerator);
    }
    result.push_back(var);
  }

  return result;
}