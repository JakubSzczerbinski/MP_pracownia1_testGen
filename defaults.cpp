
#include "defaults.hpp"

std::shared_ptr<generator>& getGen(){
	static std::shared_ptr<generator> gen;
	return gen;
}

ClauseSet defaultFunction()
{
	return getGen()->generate();
} 

std::vector<std::string> defaultNames()
{
	std::vector<std::string> result;
	for(int i = 0; i < 10000; i++)
	{
		std::string name = "";
		size_t stringNumber = i;
		while(stringNumber != 0)
		{
			unsigned offset = stringNumber % (unsigned)('y' - 'a');
			char a = 'a' + offset;
			if(a == 'v')
				a = 'z';
			stringNumber /= ('y' - 'a');
			name.push_back(a);
		}
		result.push_back(name);
	}
	return result;
}