#include <iostream>


#include "./base/Loader.cpp"
#include "./base/util/StringUtils.cpp"
#include "./base/Builder.cpp"

using namespace std;

int main() {
    string text = "Simple Example by %author% \n while run it by %compiler%";

    Builder builder(text);

    cout << "Before: \n" << text << "\n";  

    string modifiedText = builder.build();  
    cout << "After: \n" << modifiedText << "\n";  

    int x;
    cout << "Press any key to close the program!\n";
    cin >> x;  

    return 0;
}
