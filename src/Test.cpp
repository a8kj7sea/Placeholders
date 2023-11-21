#include <iostream>
#include <string>

#include "PlaceholderBuilder.cpp"

using namespace std;

int main () {
	string text = "Simple Example by %author%";
	
	PlaceholderBuilder builder(text);
	
	cout << "before : \n" << text << "\n";
	
	cout << "after : \n" << builder.build() << "\n";
	
	return 0;
	
}
