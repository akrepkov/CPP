

#include "Array.hpp"

Array::Array() {
}

Array::~Array() {
}

Array& Array::operator=(const Array& copy) {
	if (this != &copy) {
	}
    return *this;
}

Array::Array(const Array& copy) {
	*this = copy;
}
