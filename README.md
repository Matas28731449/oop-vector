# oop-vector

**Function analysis**

- Compared to `std::vector`, my realised functions in `my vector` class work just as same :

resize()
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

insert()
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

erase()
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

push_back()
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

pop_back()
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