## Learned concepts:

**Encapsulation**

Encapsulation is the concept of bundling data (variables) and the functions (methods) that operate on that data into a single unit (class). It also refers to restricting direct access to some of the object's components, which is usually done using access specifiers (private, protected, public).

**Data hiding** is part of encapsulation. It specifically refers to preventing external code from directly accessing internal object data. This is done using private or protected members in a class.
```
class BankAccount {
  private:
    int balance;
  public:
    void deposit(int);
};
```
***
**Abstraction**

Abstraction is the concept of showing only essential features of an object and hiding the complex implementation details. In C++, this is often done using abstract classes or interfaces (pure virtual functions). It means using abstract methods that are defined in a parent class (abstract class), but implemented in child classes.

**Abstract Class** is class that cannot be instantiated, and includes at least one pure virtual function ```(virtual void foo() = 0;).``` Used to define interfaces or base functionality that must be implemented in derived classes.

An **interface** in C++ is typically modeled using a class that contains only pure virtual functions. All functions are abstract, and the class serves solely to enforce a structure for other classes to follow.

```
class CoffeeMachine {
public:
    void makeEspresso() {
        grindBeans();
        heatWater();
        brew();
    }

private:
    void grindBeans() { /* complex logic */ }
    void heatWater() { /* complex logic */ }
    void brew() { /* more logic */ }
};

```

***
**Inheritance**

Inheritance allows a class (child/derived class) to inherit properties and behavior (methods and variables) from another class (base class). It promotes code reuse and logical hierarchy.
- Single Inheritance
One class inherits from one base class.
Example: class Dog : public Animal {}

- Multilevel Inheritance
Inheritance in a chain.
Example: A → B → C, where C inherits from B, and B inherits from A.

- Multiple Inheritance
One class inherits from multiple base classes.
Example: class RobotDog : public Machine, public Animal {}

- Hierarchical Inheritance
Multiple classes inherit from one common base class.
Example: class Cat : public Animal {}; class Dog : public Animal {};

- Hybrid Inheritance
A combination of more than one type of inheritance (e.g., multiple + multilevel).

***
**Polymorphism**

Polymorphism means "many forms". It lets one interface be used for a variety of types. In C++, it's achieved by:

 - Compile-time polymorphism: via function overloading and operator overloading

 - Runtime polymorphism: via virtual functions

The same method name can behave differently depending on the class it's called on, even though the method signature is the same. This is often achieved through method overriding in subclasses.

***
&nbsp;
## Subject:

**CPP00**
The biggest challenge in this module was to built a simple phonebook software mimicking the technology of the 80s. I've learned about classes, member functions, and basic C++ concepts such as namespaces, initialization lists, and more. By implementing the PhoneBook and Contact classes, I've gained hands-on experience in class design, encapsulation, and managing data in arrays.

**CPP01** introduced me to memory allocation strategies in C++, particularly the stack and heap.

**CPP02**
The most interesting assignment was BSP where I've applied geometric algorithms, showcasing practical applications of class design and object-oriented programming.

**CPP03**
The module introduces the concept of inheritance and polymorphism in C++ through the creation of the ClapTrap class and its derived class, DiamondTrap, FragTrap and ScavTrap. The task aims to simulate the characteristics of a robot in a gaming environment, where different types of traps possess unique attributes and behaviors.

**CPP04** extends the exploration of inheritance and polymorphism by introducing the Animal base class and its derived classes: Dog and Cat. These classes represent different types of animals, each with its own unique characteristics and behaviors.

**CPP05**
I gained a deeper understanding of abstract base classes (like AForm) and how concrete classes (such as ShrubberyCreationForm, RobotomyRequestForm, and PresidentialPardonForm) inherit from them, implementing specific functionalities. I learned how to handle exceptions using custom exceptions (GradeTooHighException, GradeTooLowException) 

**CPP06**
I learned how to convert a string literal into various scalar types (char, int, float, double) and handle edge cases like NaN or infinity.  I worked with raw memory addresses, converting pointers to uintptr_t and back, which taught me how to manipulate memory safely. I learned the importance of virtual destructors in polymorphic classes and how to use inheritance and polymorphism to identify object types at runtime without typeinfo.

**CPP07**
In this assignment, I implemented function templates for swap, min, and max to work with any type that supports comparison operators. 

**CPP08**
I worked with C++ templates and advanced container manipulation. I implemented a function template easyfind that searches for the first occurrence of an integer in a container, throwing an exception or returning an error if not found. I also developed a Span class that stores a maximum of N integers, with functions for adding numbers and calculating the shortest and longest spans between the stored numbers. Furthermore, I created a MutantStack class, which extends std::stack to make it iterable by adding iterators. 
