#include <iostream>
#include <unordered_map>

int main()
{
	std::unordered_map<std::string, int> ages;

	// insertion key-value pair
	ages["Alice"] = 25; //O(1)
	ages["Charlie"] = 22;
	ages["Bob"] = 30;

	// Access by key
	std::cout << "Bob is " << ages["Bob"] << " years old\n";	//O(1)

	//Traversal (not sorted by key)
	for (const auto& nameAgePair : ages) {
		std::cout << nameAgePair.first << " -> "
			<< nameAgePair.second << "\n";
	}

	return 0;
}
