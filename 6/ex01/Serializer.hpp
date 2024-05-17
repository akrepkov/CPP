/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:06:26 by akrepkov          #+#    #+#             */
/*   Updated: 2024/05/08 14:38:33 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Serializer_HPP
#define Serializer_HPP
#include "Data.hpp"
#include <cstdint>
/*uintptr_t - an unsigned integer type with the property that any 
valid pointer to void can be converted to this type, 
then converted back to pointer to void, 
and the result will compare equal to the original pointer*/


class Serializer{
	private:
		Serializer(); //// Private constructor to prevent instantiation

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		~Serializer();
		Serializer& operator=(const Serializer& copy);
		Serializer(const Serializer& copy);

};

#endif


/*dynamic cast is not needed to cast from inherited to base, only the other way around. */

/*
Static Cast (static_cast):

    Use: It performs conversions between related types, such as converting pointers or numeric types.
    Examples:

    cpp

    double d = 3.14;
    int i = static_cast<int>(d); // Converts double to int

    Notes: It's safer than C-style casts and is used for most type conversions in modern C++.

Dynamic Cast (dynamic_cast):

    Use: It is used for runtime type identification (RTTI) and is typically used for polymorphic types to perform downcasting safely.
    Example:

    cpp

    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        // Use derivedPtr safely
    }

    Notes: It can only be used with pointers or references to polymorphic types, and it performs a runtime check to ensure the cast is safe.

Const Cast (const_cast):

    Use: It is used to add or remove const or volatile qualifiers from a variable.
    Example:

    cpp

    const int* constPtr = &value;
    int* nonConstPtr = const_cast<int*>(constPtr); // Removes const qualifier

    Notes: Modifying a const object through a non-const pointer obtained by const_cast results in undefined behavior unless the object was originally declared as non-const.

Reinterpret Cast (reinterpret_cast):

    Use: It is used for low-level casting between unrelated types, such as converting between pointers and integers, or between pointers to unrelated classes.
    Example:

    cpp

int value = 10;
void* voidPtr = reinterpret_cast<void*>(&value); // Converts int* to void*

Notes: It's the most dangerous cast and should be used with caution. It's typically used for low-level operations and should be avoided in most cases.
*/