template<class T>
Stack<T>::Stack() {
    m_array = new T[m_size];
}

template<class T>
Stack<T>::Stack(const Stack<T>& other) {
    *this = other;
}

template<class T>
Stack<T>::Stack(Stack&& other) {
    *this = std::move(other);
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
    if (&other == this) {
        return *this;
    }
    
    if (m_array) {
        delete [] m_array;
    }

    m_size = other.m_size;
    m_array = new T [m_size];
    std::memcpy(m_array, other.m_array, sizeof(T) * m_size);

    return *this;
}

template<class T>
Stack<T>& Stack<T>::operator=(Stack<T>&& other) {
    if (&other == this) {
        return *this;
    }

    if (m_array) {
        delete [] m_array;
    }

    m_size = std::exchange(other.m_size, DEFAULT_SIZE);
    m_array = std::exchange(other.m_array, nullptr);

    return *this;
}

template<class T>
void Stack<T>::copyArray(T* dest, const T* src, const unsigned int& size) {
	for (unsigned int i = 0; i < size; i++) {
		*(dest + i) = *(src + i);
	}
}

template<class T>
void Stack<T>::autoAlloc() {
    if (m_top == m_size) {
        T* newArray = new T [2 * m_size];
        copyArray(newArray, m_array, m_size);
        m_size *= 2;
        delete [] m_array;
        m_array = newArray;
    }
}

template<class T>
void Stack<T>::autoDealloc() {
    if (m_top <= m_size / 2 && m_size > DEFAULT_SIZE) {
        T* newArray = new T [m_size / 2];
        copyArray(newArray, m_array, m_top);
        m_size /= 2;
        delete [] m_array;
        m_array = newArray;
    }
}

template<class T>
void Stack<T>::push(const T& item) {
    autoAlloc();
    m_array[m_top++] = item;
}

template<class T>
void Stack<T>::pop() {
    if (!m_top) {
        return;
    }
    m_top--;
    autoDealloc();
}

template<class T>
const T& Stack<T>::getTop() const {
    return m_array[m_top - 1];
}

template<class T>
bool Stack<T>::isEmpty() const {
    if (!m_top) {
        return true;
    }
    return false;
}

template<class T>
const unsigned int& Stack<T>::getSize() const {
    return m_size;
}

template<class T> Stack<T>::~Stack() {
    if (m_array) {
        delete [] m_array;
    }
}
