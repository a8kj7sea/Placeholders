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

## Output 

```
before : 
Simple Example by %author%
after : 
Simple Example by a8kj

Press any key to close program !
```


