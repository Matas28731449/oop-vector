#include "headers/library.h"
#include "headers/references.h"

int main() {
    unsigned int size = 100000000;

    vector<int> std_vector;
    int         alloc_count = 0,
                tmp_capacity = 0;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= size; ++ i) {
        if (std_vector.capacity() != tmp_capacity) {
            tmp_capacity = std_vector.capacity();
            alloc_count ++;
        }
        std_vector.push_back(i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    cout << "std::vector time: " << diff.count() << "\n";
    cout << "std::vector total allocations: " << alloc_count << "\n";



    alloc_count = 0;
    tmp_capacity = 0;
    Vector<int> my_vector;

    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= size; ++ i) {
        if (my_vector.capacity() != tmp_capacity) {
            tmp_capacity = my_vector.capacity();
            alloc_count ++;
        }
        my_vector.push_back(i);
    }
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;

    cout << "my vector time: " << diff.count() << "\n";
    cout << "my vector total allocations: " << alloc_count << "\n";

    // vector<student> arr;       // array
    // string          opt = " "; // option
    // //----------INPUT----------
    // auto start = std::chrono::high_resolution_clock::now();
    // input(arr, opt);
    // //----------OUTPUT----------
    // output(arr, opt);
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> difference = end - start;
    // cout << "Program time: " << difference.count() << " s\n";

    return 0;
}
