# oop-vector

**v1.5 program analysis**

- Replaced `std::vector` with `my vector` class and performed a `performance analysis` (used `-O3` optimization `flag`);

- `Until ~100.000` elements, `my vector` performed `faster` :

| Vector / Size | 100.000 | 1.000.000 |
|---------------|---------|-----------|
| std::vector   | 1.54949 | 8.71595   |
| my vector     | 1.49537 | 16.3424   |

**Allocation analysis**

- With *int* and *student* data types `allocation count` is the `same` when working with `100.000.000 elements` :

| Vector / Type | int | student |
|---------------|-----|---------|
| std::vector   | 28  | 28      |
| my vector     | 28  | 28      |

**Performance analysis**

- With or without `optimization flags` `my vector` class is almost `2x faster` than `std::vector` :

*Without any flag*

| Type / Size | 10.000      | 100.000    | 1.000.000 | 10.000.000 | 100.000.000 |
|-------------|-------------|------------|-----------|------------|-------------|
| std::vector | 0.0016222   | 0.00851272 | 0.0690605 | 0.806923   | 7.77426     |
| my vector   | 0.000698528 | 0.00354708 | 0.0256397 | 0.290584   | 3.61772     |

*With -O3 flag*

| Type / Size | 10.000      | 100.000     | 1.000.000  | 10.000.000 | 100.000.000 |
|-------------|-------------|-------------|------------|------------|-------------|
| std::vector | 0.000168982 | 0.00140116  | 0.00962612 | 0.105263   | 1.26109     |
| my vector   | 0.000127047 | 0.000941742 | 0.00447087 | 0.0806293  | 1.24686     |

**Function analysis**

- Compared to `std::vector`, my realised functions in `my vector` class work just as same :

*resize()*
```
Vector<int> tmp;

tmp.push_back(6);
for(auto i : tmp) {
    cout << i << " ";
}
cout << "\n";

tmp.resize(5);
for(auto i : tmp) {
    cout << i << " ";
}

OUTPUT:
6
6 0 0 0 0
```

*insert()*
```
Vector<int> tmp;

tmp.push_back(6);
tmp.push_back(5);
tmp.push_back(7);
for(auto i : tmp) {
    cout << i << " ";
}
cout << "\n";

tmp.insert(tmp.begin() + 2, 0);
for(auto i : tmp) {
    cout << i << " ";
}

OUTPUT:
6 5 7
6 5 0 7
```

*erase()*
```
Vector<int> tmp;

tmp.push_back(6);
tmp.push_back(5);
cout << "Value: " << tmp.front() << ", size: " << tmp.size() << "\n";

Vector<int>::iterator it = tmp.begin();

tmp.erase(it);
cout << "Value: " << tmp.front() << ", size: " << tmp.size() << "\n";

OUTPUT:
Value: 6, size: 2
Value: 5, size: 1
```

*push_back()*
```
Vector<int> tmp;

tmp.push_back(5);
cout << "Value: " << tmp.back() << ", size: " << tmp.size() << "\n";

tmp.push_back(7);
cout << "Value: " << tmp.back() << ", size: " << tmp.size() << "\n";

OUTPUT:
Value: 5, size: 1
Value: 7, size: 2
```

*pop_back()*
```
Vector<int> tmp;

tmp.push_back(6);
cout << "Value: " << tmp.back() << ", size: " << tmp.size() << "\n";

tmp.pop_back();
cout << "Value: " << tmp.back() << ", size: " << tmp.size() << "\n";

OUTPUT:
Value: 6, size: 1
Value: 0, size: 0
```