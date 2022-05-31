#include <iostream>

int main() {
	try {

	}
	catch (std::invalid_argument ia) {
		std::cout << ia.what() << std::endl;
	}
}