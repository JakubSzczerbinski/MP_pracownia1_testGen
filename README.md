# MP_pracownia1_testGen
## Zależności
- Kompilator C++ z obsługą cpp11 (domyślnie g++).
- Biblioteka boost_program_options.

## Jak używać
Odpal program w terminalu. Wygeneruje on zbiór klauzul na podstawie zadanych parametrów oraz rozwiąże go, a następnie wypisze test na standadowe wyjście.
Opcje:
~~~
→ ./test_generator --help                                   
Test options:
  --help                                show help
  -n [ --number_of_test_cases ] arg (=1)
                                        number of test cases
  -s [ --min_clause ] arg (=2)          minimal clause length
  -l [ --max_clause ] arg (=5)          maximal clause length
  -v [ --amount_of_literlas ] arg (=4)  number of variables
  -c [ --amount_of_clauses ] arg (=4)   number of clauses
  -t [ --time_limit ] arg (=500)        time limit of testcase
  -d [ --name ] arg (=testcase)         name of testcase
~~~
Np. :
~~~
→ ./test_generator -n 1 -c 4 -v 10 -s 2 -l 2
tests(testcase0, validity, [~g v c, d v f, e v ~e, j v i], 500, count(54)).
~~~

## Za mało ?
Jeśli standardowe generowanie testów cię nie zatysfakcjonuje możesz zmodyfikować plik modify.hpp, aby zmienić sposób generowania klauzul lub sposób nazewnictwa klauzul.
//TODO examples

## Bugs ?
Jak widzisz jakiś błąd to najlepiej sam go napraw i zgłoś pull requesta. Jak nie umiesz to możesz zgłosić jeszcze issue. Rzucanie wyjątkami przez boosta albo przez inne funkcje jest częścią funkcjonalności i jeśli napotkasz się na nie to źle używasz programu.
