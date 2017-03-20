#include <iostream>
#include <random>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>

#include "clause.hpp"
#include "generator.hpp"
#include "test_gen.hpp"

namespace po = boost::program_options;

int main(int argc, char** argv) {
  size_t n, minClauseLength, maxClauseLength, numberOfVars, numberOfClauses,
      time_limit;
  std::string testName;
  po::options_description desc("Test options");
  desc.add_options()("help", "show help")(
      "number_of_test_cases,n", po::value<size_t>(&n)->default_value(1),
      "number of test cases")(
      "min_clause,s", po::value<size_t>(&minClauseLength)->default_value(2),
      "minimal clause length")(
      "max_clause,l", po::value<size_t>(&maxClauseLength)->default_value(5),
      "maximal clause length")(
      "amount_of_literlas,v",
      po::value<size_t>(&numberOfVars)->default_value(4),
      "number of variables")(
      "amount_of_clauses,c",
      po::value<size_t>(&numberOfClauses)->default_value(4),
      "number of clauses")("time_limit,t",
                           po::value<size_t>(&time_limit)->default_value(500),
                           "time limit of testcase")(
      "name,d", po::value<std::string>(&testName)->default_value("testcase"),
      "name of testcase");
  po::variables_map vm;
  po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);
  po::notify(vm);
  if (vm.count("help")) {
    std::cout << desc << std::endl;
    return 0;
  }
  std::random_device rd;
  std::mt19937 randomGenerator(rd());
  getGen() = std::make_shared<generator>(maxClauseLength, minClauseLength,
                                    numberOfVars, numberOfClauses,
                                    randomGenerator);
  generate_tests(testName, n, time_limit);
}