# Placeholders
i was try thing with cpp (it trash project don't bully me)

# Example 

```cpp

int main() {
  string text = "Simple Example by %author%";

  PlaceholderBuilder builder(text);

  cout << "before : \n" << text << "\n";

  cout << "after : \n" << builder.build() << "\n";

  int x;

  cout << "Press any key to close program !\n";

  cin >> x;

  return 0;
}

```
![image](https://github.com/a8kj7sea/Placeholders/assets/104179839/c78ea5ab-b641-4c80-af67-3c0ee7e317f1)

