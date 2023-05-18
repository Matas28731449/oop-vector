#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <memory>

template <class T>
class Vector {
    public:
// MEMBER TYPES
        typedef T *iterator;
        typedef const T *const_iterator;
        typedef T value_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
// MEMBER FUNCTIONS
    // CONSTRUCTORS
        Vector() { create(); }
        explicit Vector(size_type n, const T &value = T{}) { create(n, value); }
        Vector(const Vector &v) { create(v.begin(), v.end()); }
    // DESTRUCTOR
        ~Vector() { uncreate(); }
    // OPERATORS
        Vector &operator=(const Vector &other) {
            if(&other != this) {
                uncreate();
                create(other.begin(), other.end());
            }
            return *this;
        }
        Vector &operator=(Vector &&other) noexcept {
            if(&other != this) {
                uncreate();
                std::swap(other.data, data);
                std::swap(other.avail, avail);
                std::swap(other.limit, limit);
            }
            return *this;
        }
    // ITERATORS
        iterator begin() { return data; }
        const_iterator begin() const { return data; }
        iterator end() { return avail; }
        const_iterator end() const { return avail; }
        iterator rbegin() {
            iterator it = limit;
            return -- it;
        }
        const_iterator rbegin() const {
            iterator it = limit;
            return -- it;
        }
        iterator rend() {
            iterator it = data;
            return ++ it;
        }
        const_iterator rend() const {
            iterator it = data;
            return ++ it;
        }
    // ELEMENT ACCESS
        reference front() { return data[0]; }
        const_reference front() const { return data[0]; }
        reference back() { return data[size() - 1]; }
        const_reference back() const { return data[size() - 1]; }
        reference operator[](size_type i) { return data[i]; }
        const_reference operator[](size_type i) const { return data[i]; }
        reference at(size_type n) { return n < size() ? data[n] : throw std::out_of_range("Out of range: Vector::at()"); }
        const_reference at(size_type n) const { return n < size() ? data[n] : throw std::out_of_range("Out of range: Vector::at()"); }
    //
        size_type size() const { return avail - data; }
        size_type max_size() const { return std::numeric_limits<size_type>::max(); }
        size_type capacity() const { return limit - data; }
        bool empty() const { return data == nullptr ? true : false; }
        void reserve(size_type n) { if(n > capacity()) grow(n); }
        void shrink_to_fit() { limit = avail; }
    // MODIFIERS
        void clear() {
            uncreate();
        }
        void pop_back() {
            iterator it = avail;
            alloc.destroy(-- it);
            avail = it;
        }
        void push_back(const T &value) {
            if(avail == limit) grow();
            unchecked_append(value);
        }
        iterator erase(const_iterator value) {
            iterator it = const_cast<iterator>(value);
            std::copy(it + 1, avail, it);
            alloc.destroy(-- avail);
            return it;
        }
        iterator insert(const_iterator position, const T &value) {
            if(avail == limit) grow(); // if there is no space for insert then increase
            iterator it = const_cast<iterator>(position);
            std::copy_backward(it, avail, avail + 1); // copy to the right
            *it = value; // insert into vacated space
            avail ++;
            return it;
        }
        void resize(size_type n, value_type value = T()) {
            if(n > size()) {
                size_type new_size = n;
                iterator new_data = alloc.allocate(new_size);
                iterator it = std::uninitialized_copy(data, avail, new_data);
                std::uninitialized_fill(it, new_data + new_size - 1, value);
                iterator new_avail = new_data + new_size;
                iterator new_limit;
                capacity() < new_avail - new_data ? new_limit = new_avail : new_limit = new_data + capacity();
                
                uncreate();

                data = new_data;
                avail = new_avail;
                limit = new_limit;
            }
            else if(n < size()) {
                size_type new_size = n;
                iterator new_data = alloc.allocate(new_size);
                iterator new_avail = std::uninitialized_copy(data, data + n, new_data);
                iterator new_limit = new_data + capacity();

                uncreate();

                data = new_data;
                avail = new_avail;
                limit = new_limit;
            }
        }
    private:
        iterator data;
        iterator avail;
        iterator limit;

        std::allocator<T> alloc;

        void unchecked_append(const T &value) {
            alloc.construct(avail ++, value);
        }
        void create() {
            data = avail = limit = nullptr;
        }
        void create(size_type n, const T &value) {
            data = alloc.allocate(n);
            limit = avail = data + n;
            std:uninitialized_fill(data, limit, value);
        }
        void create(const_iterator i, const_iterator j) {
            data = alloc.allocate(j - i);
            limit = avail = std::uninitialized_copy(i, j, data);
        }
        void uncreate() {
            if(data) {
                iterator it = avail;
                while(it != data) {
                    alloc.destroy(-- it);
                }
                alloc.deallocate(data, limit - data);
            }
            data = avail = limit = nullptr;
        }
        void grow() {
            size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));
            iterator new_data = alloc.allocate(new_size);
            iterator new_avail = std::uninitialized_copy(data, avail, new_data);

            uncreate();

            data = new_data;
            avail = new_avail;
            limit = data + new_size;
        }
        void grow(int n) {
            size_type new_size = n;
            iterator new_data = alloc.allocate(new_size);
            iterator new_avail = std::uninitialized_copy(data, avail, new_data);

            uncreate();

            data = new_data;
            avail = new_avail;
            limit = data + new_size;
        }
};

#endif