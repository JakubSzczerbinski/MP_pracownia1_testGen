
#include "solver.hpp"

size_t numberOfSolutions(const Solutions& solutions) {
  size_t result = 0;
  for (auto& sol : solutions) {
    result += sol.numberOfSolutions();
  }
  return result;
}

Solutions Solver::solve(const ClauseSet& clauses) const {
  Vars vars;
  for (auto& clause : clauses) {
    for (auto& var : clause) {
      vars.insert(abs(var));
    }
  }
  return internal_solve(clauses, vars);
}
Solutions Solver::internal_solve(const ClauseSet& clauses, Vars vars) const {
  if (clauses.empty()) {
    return {{{}, vars}};
  }
  auto it = vars.begin();
  if (it == vars.end()) {
    return {};
  }
  auto var = *it;
  vars.erase(it);
  ClauseSet positiveClauses = filterClauses(clauses, var);
  ClauseSet negativeClauses = filterClauses(clauses, -var);

  auto solutionTrue = internal_solve(positiveClauses, vars);
  auto solutionFalse = internal_solve(negativeClauses, vars);
  Solutions result;
  std::for_each(solutionTrue.begin(), solutionTrue.end(),
                [&](const Solution& sol) {
                  Solution newSol = sol;
                  newSol.eval[var] = true;
                  result.push_back(newSol);
                });
  std::for_each(solutionFalse.begin(), solutionFalse.end(),
                [&](const Solution& sol) {
                  Solution newSol = sol;
                  newSol.eval[var] = false;
                  result.push_back(newSol);
                });
  return result;
}
ClauseSet Solver::filterClauses(const ClauseSet& clauses, int var) const {
  ClauseSet result;
  std::for_each(clauses.begin(), clauses.end(), [&](const Clause& clause) {
    auto it = std::find(clause.begin(), clause.end(), var);
    if (it != clause.end()) {
      return;
    }

    Clause newClause;
    newClause.resize(clause.size());

    std::copy_if(clause.begin(), clause.end(), newClause.begin(),
                 [&](int i) { return i != -var; });

    result.insert(newClause);
  });
  return result;
}

Solutions solve(const ClauseSet& clauses) {
  Solver s;
  return s.solve(clauses);
}
