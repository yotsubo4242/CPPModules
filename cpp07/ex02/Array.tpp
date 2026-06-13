template <typename T>
Array<T>::Array() : array(NULL), n(0) {
}

template <typename T>
Array<T>::Array(const unsigned int n) : array(NULL), n(n) {
    if (this->n == 0)
        return;
    this->array = new T[this->n]();
}

template <typename T>
Array<T>::Array(const Array &other) : array(NULL), n(0) {
    *this = other;
}

template <typename T>
Array<T>::~Array() {
    delete[] array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this == &other)
        return *this;

    T *newArray = NULL;
    if (other.n != 0) {
        newArray = new T[other.n];
        for (unsigned int i = 0; i < other.n; i++)
            newArray[i] = other.array[i];
    }

    delete[] this->array;
    this->array = newArray;
    this->n = other.n;
    return *this;
}

template <typename T>
T &Array<T>::operator[](const unsigned int i) {
    if (i >= n)
        throw std::out_of_range("Array index out of range");
    return array[i];
}

template <typename T>
const T &Array<T>::operator[](const unsigned int i) const {
    if (i >= n)
        throw std::out_of_range("Array index out of range");
    return array[i];
}

template <typename T>
unsigned int Array<T>::size() const {
    return n;
}
