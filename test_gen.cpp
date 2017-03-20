
#include "test_gen.hpp"

std::string varName(int i)
{
	if (i == 0)
		throw std::runtime_error("Null variable not allowed");
	size_t id = abs(i) - 1;
	if(id < variableNames().size())
		return variableNames()[id];
	throw std::runtime_error("No name for variable with index " + std::to_string(id));
}

std::ostream& operator<<(std::ostream& os, const Clause& clause) {
  if (clause.begin() != clause.end()) {
    std::string a = varName(*clause.begin());
    std::string out = (*clause.begin() > 0 ? "" : "~");
    os << out << a;
  }
  for (auto it = clause.begin() + 1; it != clause.end(); it++) {
    std::string a = varName(*it);
    std::string out = (*it > 0 ? "" : "~");
    os << " v " << out << a;
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const ClauseSet& clauses) {
  for (auto& c : clauses) {
    os << c << '\n';
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const Vars& vars) {
  auto it = vars.begin();
  if (it != vars.end()) {
    std::string a = varName(*it);
    os << a;
    it++;
  }
  for (; it != vars.end(); it++) {
    std::string a = varName(*it);
    os << ", " << a;
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const Evaluation& eval) {
  auto it = eval.begin();
  if (it != eval.end()) {
    std::string a = varName(it->first);
    os << "(" << a << ", " << (it->second ? "t" : "f") << ")";
    it++;
  }
  for (; it != eval.end(); it++) {
    std::string a = varName(it->first);
    os << ", "
       << "(" << a << ", " << (it->second ? "t" : "f") << ")";
  }
  return os;
}

void write_solution(std::stringstream& ss, const Solutions& sols) {
  auto numberOfSols = numberOfSolutions(sols);
  if (numberOfSols == 1) {
    const Evaluation& eval = sols.begin()->eval;
    ss << "solution("
       << "[";
    ss << eval;
    ss << "]"
       << ")";
    return;
  }
  ss << "count(" << numberOfSols << ")";
}


std::string generate_test(const ClauseSet& clauses,
                          const std::string& stringName,
                          size_t testDuration) {
  std::string result;
  std::stringstream ss;
  ss << "tests(" << stringName << ", "
     << "validity"
     << ", ";

  ss << "[";
  if (clauses.begin() != clauses.end()) {
    ss << *clauses.begin();
  }
  for (auto it = ++clauses.begin(); it != clauses.end(); it++) {
    ss << ", ";
    ss << *it;
  }
  ss << "]";
  ss << ", " << testDuration << ", ";

  auto solution = solve(clauses);
  write_solution(ss, solution);

  ss << ")"
     << "." << std::endl;

  result = ss.str();
  return result;
}

void generate_tests(std::string name,
                    size_t n,
                    size_t time_limit_ms) {
  if (time_limit_ms < 500) {
    time_limit_ms = 500;
  }
  if (time_limit_ms > 10000) {
    time_limit_ms = 10000;
  }
  for (size_t i = 0; i < n; i++) {
    std::cout << generate_test(generateClauseSet(), name + std::to_string(i),
                               time_limit_ms);
  }
}