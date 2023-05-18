#include "headers/library.h"
#include "headers/references.h"

int main() {
    // resize()
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

    // // insert()
    // Vector<int> tmp;

    // tmp.push_back(6);
    // tmp.push_back(5);
    // tmp.push_back(7);
    // for(auto i : tmp) {
    //     cout << i << " ";
    // }
    // cout << "\n";

    // tmp.insert(tmp.begin() + 2, 0);
    // for(auto i : tmp) {
    //     cout << i << " ";
    // }

    // // erase()
    // Vector<int> tmp;

    // tmp.push_back(6);
    // tmp.push_back(5);
    // cout << "Value: " << tmp.front() << ", size: " << tmp.size() << "\n";

    // Vector<int>::iterator it = tmp.begin();

    // tmp.erase(it);
    // cout << "Value: " << tmp.front() << ", size: " << tmp.size() << "\n";

    // // push_back()
    // Vector<int> tmp;

    // tmp.push_back(5);
    // cout << "Value: " << tmp.back() << ", size: " << tmp.size() << "\n";

    // tmp.push_back(7);
    // cout << "Value: " << tmp.back() << ", size: " << tmp.size() << "\n";

    // // pop_back()
    // Vector<int> tmp;

    // tmp.push_back(6);
    // cout << "Value: " << tmp.back() << ", size: " << tmp.size() << "\n";

    // tmp.pop_back();
    // cout << "Value: " << tmp.back() << ", size: " << tmp.size() << "\n";
    
    // vector<student> arr;       // array
    // string          opt = " "; // option
    // //----------INPUT----------
    // auto start = std::chrono::high_resolution_clock::now();
    // input(arr, opt);
    // //----------OUTPUT----------
    // output(arr, opt);
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> difference = end - start;
    // cout << "\nProgram time: " << difference.count() << " s\n";

    return 0;
}
