#include "headers/library.h"
#include "headers/references.h"

int main() {
    // unsigned int size = 100000000;

    // vector<int> std_vector_int;
    // int         alloc_count = 0,
    //             tmp_capacity = 0;

    // auto start = std::chrono::high_resolution_clock::now();
    // for (int i = 1; i <= size; ++ i) {
    //     if (std_vector_int.capacity() != tmp_capacity) {
    //         tmp_capacity = std_vector_int.capacity();
    //         alloc_count ++;
    //     }
    //     std_vector_int.push_back(i);
    // }
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> diff = end - start;

    // cout << "std::vector<int> time: " << diff.count() << "\n";
    // cout << "std::vector<int> total allocations: " << alloc_count << "\n";



    // alloc_count = 0;
    // tmp_capacity = 0;
    // Vector<int> my_vector_int;

    // start = std::chrono::high_resolution_clock::now();
    // for (int i = 1; i <= size; ++ i) {
    //     if (my_vector_int.capacity() != tmp_capacity) {
    //         tmp_capacity = my_vector_int.capacity();
    //         alloc_count ++;
    //     }
    //     my_vector_int.push_back(i);
    // }
    // end = std::chrono::high_resolution_clock::now();
    // diff = end - start;

    // cout << "my vector<int> time: " << diff.count() << "\n";
    // cout << "my vector<int> total allocations: " << alloc_count << "\n";

    // std_vector_int.clear();
    // my_vector_int.clear();

    // vector<student> std_vector_student;
    //                 alloc_count = 0,
    //                 tmp_capacity = 0;

    // start = std::chrono::high_resolution_clock::now();
    // for (int i = 1; i <= size; ++ i) {
    //     if (std_vector_student.capacity() != tmp_capacity) {
    //         tmp_capacity = std_vector_student.capacity();
    //         alloc_count ++;
    //     }
    //     std_vector_student.push_back(student());
    // }
    // end = std::chrono::high_resolution_clock::now();
    // diff = end - start;

    // cout << "std::vector<student> time: " << diff.count() << "\n";
    // cout << "std::vector<student> total allocations: " << alloc_count << "\n";



    // alloc_count = 0;
    // tmp_capacity = 0;
    // Vector<student> my_vector_student;

    // start = std::chrono::high_resolution_clock::now();
    // for (int i = 1; i <= size; ++ i) {
    //     if (my_vector_student.capacity() != tmp_capacity) {
    //         tmp_capacity = my_vector_student.capacity();
    //         alloc_count ++;
    //     }
    //     my_vector_student.push_back(student());
    // }
    // end = std::chrono::high_resolution_clock::now();
    // diff = end - start;

    // cout << "my vector<student> time: " << diff.count() << "\n";
    // cout << "my vector<student> total allocations: " << alloc_count << "\n";

    // std_vector_student.clear();
    // my_vector_student.clear();

    Vector<student> arr;       // array
    string          opt = " "; // option
    //----------INPUT----------
    auto start = std::chrono::high_resolution_clock::now();
    input(arr, opt);
    //----------OUTPUT----------
    output(arr, opt);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> difference = end - start;
    cout << "Program time: " << difference.count() << " s\n";

    return 0;
}
