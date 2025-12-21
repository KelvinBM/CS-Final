/////////////// OpenFrameworks /// Library //
/////////////*
////////////    visual usage and manipulation of c++ code
////////////*/
////////////
////////////
////////////
////////////// have header file that lists functions
////////////// ----Defines functions----call when running
////////////// have file with functions decalred(those that are defined on header file)
////////////// 
////////////
///////////////  assert() --> macro | branching  ///
/////////////*
////////////    assert() is a macro (similar to a function) that prints an error message and exits the program if assert()'s input expression is false.
////////////    ---> #include <cassert>
////////////        ---> Using assert requires first including the cassert library, part of the standard library
////////////    ---> assert(HrMinToMin(0, 0)  == 0);
////////////    ---> error message includes the current line number and the expression (a nifty trick enabled by using a macro rather than an actual function)
////////////
////////////    ---> branches, you may recognize that each assert statement in main() could be replaced by an if statement
////////////        ---> but assert is more compact
////////////
////////////
////////////
////////////
////////////*/
////////////
///////////////  Header Files  ///
/////////////*
////////////    header files:
////////////        ["don't need extension of .h, can be whatever extension, but 'h' helps know their designation"]
////////////        [Any file can be included into any other file, but convention is to use .h as the suffix.]
////////////
////////////        ---> Instead of typing the declarations directly above main(), a programmer can provide the function declarations
////////////             in a header file, such as the threeintsfcts.h
////////////        ---> Include the contents of that file into a source file via the line: #include "threeintsfcts.h" (within main)
////////////
////////////        ---> The .h file could contain function definitions rather than just function declarations, eliminating the
////////////             need for two files (one for declarations, one for definitions)
////////////
////////////
////////////        ---> the .h file serves as a brief summary of all functions available. A second advantage is that the main file's
////////////             copy does not become exceedingly large during compilation, which can lead to slow compilation.
////////////
////////////
////////////        ---> Multiple inclusion commonly can occur when one header file includes another header file, e.g., the main file
////////////             includes file1.h and file2.h, and file1.h also includes file2.h -- thus, file2.h would get included twice
////////////             into the main file.
////////////
////////////             ---> Header file guards: The solution is to add some additional preprocessor directives, known as header file guards, to the .h file
////////////                  as follows. *header file guards are preprocessor directives, which cause the compiler to only include the contents of the header file once.*
////////////
////////////                  EX: *within header file*
////////////                  _________________________________
////////////
////////////                        #ifndef FILENAME_H
////////////                        #define FILENAME_H
////////////
////////////                        // Header file contents
////////////
////////////                        #endif
////////////                  _________________________________
////////////                        #ifndef THREEINTSFCTS_H
////////////                        #define THREEINTSFCTS_H
////////////
////////////                        int ThreeIntsSum(int num1, int num2, int num3);
////////////                        int ThreeIntsAvg(int num1, int num2, int num3);
////////////
////////////                        #endif
////////////                  _________________________________
////////////                    ---> consideration that must be dealt with is that a header file could get included
////////////                         multiple times, causing the compiler to generate errors indicating an item
////////////                         defined in that header file is defined multiple times (the above header files
////////////                         only declared functions and didn't define them, but other header files may
////////////                         define functions, types, constants, and other items).
////////////    */
////////////
////////////    ///  Preprocessor and include  ///
////////////    /*
////////////
////////////        [Any line starting with # is known as a preprocessor directive.]
////////////        [The quotes "" tell the preprocessor to look in the current folder/directory.]
////////////        [The brackets <> tell the processor to look within the system's standard library folder/directory]
////////////
////////////        The preprocessor is a tool that scans the file from top to bottom looking for any lines that begin with #, known as a hash symbol.
////////////        Each such line is not a program statement, but rather directs the preprocessor to modify the file in some way before compilation
////////////        continues, each such line being known as a preprocessor directive. The directive ends at the end of the line, no semicolon is used
////////////        at the end of the line.
////////////
////////////        Perhaps the most commonly-used preprocessor directive is #include, known as an include directive. #include directs the compiler to
////////////        replace that line by the contents of the given filename.
////////////
////////////        _________________________________
////////////
////////////        Good practice is to use a .h suffix for any file that will be included in another file. The h is short for header,
////////////        to indicate that the file is intended to be included at the top (or header) of other files. Although any file can
////////////        be included in any other file, convention is to only include .h files.
////////////
////////////        The characters surrounding the filename determine where the preprocessor looks for the file.
////////////        _________________________________
////////////
////////////        #include "myfile.h" -- A filename in quotes causes the preprocessor to look for the file in the same folder/directory as the including file.
////////////        #include <stdfile> -- A filename in angle brackets causes the preprocessor to look in the system's standard library folder/directory.
////////////                              Programmers typically use angle brackets only for standard library files, using quotes for all other include files.
////////////                              Note that nearly every previous example has included at least one standard library file, using angle brackets.
////////////
////////////        Include directives:
////////////            #include "filename"
////////////            #include <filename>
////////////
////////////    */
////////////
////////////
////////////    ///  MISC ///
////////////    /*
////////////
////////////        iostream for cin and cout to read from input and output tableArea.
////////////        iomanip for the fixed and setprecision() manipulators to format floating point numbers in output.
////////////        cmath for the sqrt() function to compute the square root of a value.
////////////
////////////    */
////////////#include <iostream>
////////////#include <iomanip>
////////////#include <string>
////////////#include <cstdlib> // for rand() - random numbers
////////////#include <cmath> // for regular math functions
////////////#include <corecrt_math_defines.h> // for M_PI (value of pi)
////////////#include <ctime> // for time(0) function
////////////#include <vector>
////////////
////////////
//////////////#include "test.cpp" // used to bring in other file(to place functions within other files) // files need to stand alone in its code(need to include libraries and namespace used)
////////////    // need to run by including the main.cpp and extra files in the console
////////////
////////////    //#inlcude <unistd.h> // for usleep(time in nanoseconds) --> to make program wait
////////////
////////////using namespace std;
////////////
/////////////*****     EULER problems     *****/
////////////
////////////int classNotes() {
////////////    std::cout << "Hello World" << endl;// without std library
////////////    std::abs(-15);// works with floats and ints, use fabs() function to make the operation clear
////////////    cout << "Hello World2" << endl;
////////////
////////////    int numA, numB, numC;
////////////    cin >> numA >> numB >> numC;// inputting all at once
////////////
////////////    string name = "My Name";
////////////    char a = 'a';
////////////    cout << name + a << endl;
////////////
////////////    //at(): The notation someString.at(x) accesses the character at index x of a string.
////////////    name.at(0);
////////////    name.size();// length of string
////////////    name.length();
////////////    name.push_back('?');// appends char to end of str
////////////    name.append("fgh");// appends to en string, using '+' operator returns a new string
////////////
////////////
////////////    // string.find(item) returns the index of the first occurrence of item in string. If no occurrence is found, then the function returns string::npos.
////////////    // str.replace(indx, n, "") replaces the n characters starting at index indx of str with an empty string.
////////////    // The insert() function inserts text into a string. Ex: s1.insert(startIndex, newText) inserts newText into s1 before the character at index startIndex.
////////////    // The replace() function replaces text in a string. Ex: s1.replace(startIndex, numCharacters, newText) replaces the substring of s1 starting at index startIndex and having numCharacters characters with newText.
////////////    // substr() function is used to get a substring of a string. Ex: Given a string s1, s1.substr(startIndex, numCharacters) 
////////////    // find() function is used to find a string or character inside a string. Ex: Given a string s1, s1.find(textToFind) returns the index of the first occurrence of textToFind within s1, or string:npos if not found. textToFind can be a string or character. string::npos is a special value representing "no position".
////////////
////////////
////////////    double number = 2.5;
////////////    cout << fixed << setprecision(2) << number << endl;// set floating-point precision
////////////
////////////    cout << M_PI << endl;// #include <corecrt_math_defines.h> // pie value
////////////
////////////    cout << fabs(-20.34) << " " << abs(-20.2) << endl;// absolute value of floating point
////////////
////////////    cout << 2.0 + 3 << endl;// implicit casting // the value on the left is used to convert to attributed type
////////////    cout << static_cast<double>(3 + 4) << endl;// type cast // explicit conversion
////////////
////////////    int two = 2;
////////////    cout << static_cast<double>(two + 3) << endl;
////////////
////////////    string name2;
////////////    cout << "Enter Name: ";
////////////    getline(cin, name2); // gets entire line until '\n' character
////////////
////////////
////////////    // combining cin and getline(cin, varName)
////////////    string listName;
////////////    string listItem1;
////////////    string listItem2;
////////////    string listItem3;
////////////
////////////    getline(cin, listName);
////////////    cin >> listItem1;
////////////    cin >> listItem2;
////////////    cin >> listItem3;
////////////
////////////    cout << listName << ":" << endl;
////////////    cout << listItem1 << endl;
////////////    cout << listItem2 << endl;
////////////    cout << listItem3 << endl;
////////////
////////////    // generating random numbers with <cstdlib> //
////////////    /*
////////////        rand() function generates "pseudo-random" sequence of values because of its default
////////////        seed --> srand(1) --> changing this seed each iteration results in unique sequences of values
////////////
////////////        although the rand() function returns a random number, because of the default seed(1) it starts
////////////        with it can provide the same sequence of values every time the program is ran.
////////////
////////////            - change its seed using srand(int value) ::::: ex -> srand(2)
////////////                - changing the seed before each program run results in unique random number sequences
////////////
////////////            - making seed equal to current time(value in seconds) always gives unique sequence
////////////                - time(0) // time since jan 1, 1970
////////////                    - srand(time(0));
////////////
////////////    */
////////////    // generating random numbers with <random> //
////////////    /*
////////////
////////////        The <random> number library provides greater control of the random-number generation.
////////////        Using the library, a programmer may specify the engine used to produce the numbers and
////////////        the distribution of the numbers. Trivial random-number sequences may still be generated
////////////        using <cstdlib> library functions srand() and rand().
////////////
////////////    */
////////////
////////////    // comparing floating point numbers //
////////////    /*
////////////        avoid using '==' operator and instead use approximation (close enough values)
////////////        - Ex: If (x - y) < 0.0001, x and y are deemed equal.
////////////              Because the difference may be negative, the absolute value is used: fabs(x - y) < 0.0001.
////////////              fabs() is a function in the math library. The difference threshold indicating that
////////////              floating-point numbers are equal is often called the epsilon
////////////
////////////        - subtract each value from each other and use a threshold close to zero(0.0001) to see if their subtraction is close to it
////////////            fabs(num1 - num2) < 0.0001
////////////                order of subtraction doesn't mnatter
////////////                this compares if values are the same
////////////
////////////    */
////////////
////////////
////////////
////////////    int randNum1 = rand();// random number using RAND_MAX from library imported
////////////    int randNum2 = rand() % 10;//  generates 10 random numbers // 0 - 9
////////////    // random number within range // range is MaxVal - MinVal + 1 [15 - 10 + 1 = 6] // starts at 10
////////////    int randNum3 = (rand() % 6) + 10;// adding 10 to (rand() % 6) makes range start at 10
////////////
////////////    int minVal, maxVal;
////////////    cin >> minVal;// enter minimum value of range
////////////    cin >> maxVal;// enter maximum value of range
////////////    int numRange = maxVal - minVal + 1;
////////////    int randNum4 = (rand() % (numRange)) + minVal;
////////////
////////////    // changing seed(first stored value within rand() function)
////////////    // having a unique seed for each program run makes it so that 
////////////    srand(2);// seed changed to 2
////////////    srand(time(0));// always gives unique seed
////////////
////////////
////////////    /*
////////////
////////////        #include <string>  ---> string myString = "asdads";
////////////        #include <cstring> ---> char myString[] = "asdasd";
////////////        //
////////////            char nameArr[5];
////////////
////////////            nameArr[0] = 'A';
////////////            nameArr[1] = 'l';
////////////            nameArr[2] = 'a';
////////////            nameArr[3] = 'n';
////////////            nameArr[4] = '\0'; // Null character
////////////
////////////        //
////////////
////////////
////////////        strcpy() --> for copying string char array to another variable
////////////
////////////        Arrays: declared as int myList[10], accessed as myList[i].
////////////        Vectors: declared as vector<int> myList(10), accessed as myList.at(i).
////////////
////////////        Arrays have a simpler syntax than vectors, but vectors are safer to use. Thus, using vectors rather than arrays is good practice.
////////////
////////////        Char arrays were the only kinds of strings in C++'s predecessor language C, and thus are sometimes called C strings to distinguish them from C++'s string type.
////////////        --> An example is: char movieTitle[20] = "Star Wars";.
////////////        --> Because a string can be shorter than the character array,
////////////        --> a string in a char array must end with a special character known as a null character, written as '\0'.
////////////        // Given a string literal like "Star Wars", the compiler automatically appends a null character.
////////////
////////////
////////////        a char array is initialized when declared, then the char array's size may be omitted, as in char userName[] = "Hellen"; . The compiler determines the size from the string literal, in this case 6 + 1 (for the null character), or 7
////////////
////////////        // An array of characters ending with a null character is known as a null-terminated string
////////////        --> A programmer can traverse a string using a loop that stops when reaching the null character.
////////////        --> **** A common error is to loop for the string's array size rather than stopping at the null character. ****
////////////    */
////////////    // vectors (lists) //
////////////    /*
////////////        a vector is an ordered list of items of a given data type.
////////////        Each item in a vector is called an element
////////////            Each element is a variable
////////////            and can be read and assigned
////////////            like any other variables. 'numList.at(0) = 1'
////////////
////////////        1) push_back() --> appends a new element to the end of an existing vector.
////////////        2) at() --> accesses a vector element at the index specified within the parentheses.
////////////
////////////        vector<dataType> vectorName;
////////////
////////////        A vector can also be initialized by specifying the initial values in braces {} separated by commas. Ex: vector<int> carSales = {5, 7, 11};
////////////
////////////        vector<int> gameScores(4); declares a vector gameScores with 4 integer elements// each element equals to zero unless reassigned
////////////
////////////        size() --> returns the number of vector elements
////////////
////////////        resize(#num) --> setting vector's size or changing it while a program executes using resize(N).
////////////                        Ex: highScore.resize(10) resizes the highScores vector to have 10 elements.
////////////
////////////
////////////        back() --> returns las element of a vector(vector remains unchanged)
////////////
////////////        pop_back() --> removes last element
////////////
////////////        vector copy operation ---> = operator conveniently performs an element-by-element copy of a vector
////////////        // list1 = list2;
////////////
////////////
////////////        vector equality operation -->  == operator conveniently compares vectors element-by-element
////////////    */
////////////    vector<string> stringList;// declares an empty vector capable of storing an unspecified number of elements
////////////    vector<int> numbers;
////////////    vector<int> carSales = { 5, 7, 11 }; // declared with initially given values
////////////    vector<int> withLength(4);
////////////
////////////    stringList.push_back("Hello");
////////////    numbers.push_back(1);
////////////
////////////    stringList.at(0);
////////////    numbers.at(0);
////////////    numbers.size();
////////////
////////////    // #include <cctype> //  common functions for working with characters // ctype is short for "character type". 
////////////    //--- http://www.cplusplus.com/reference/cctype/ ---//
////////////    /*
////////////
////////////        isalpha(char) ---> returns true if char is 'a-z' or 'A-Z' --> alphabetic
////////////        isdigit(char) ---> returns true if char is numeric digit '0-9'
////////////        isalnum(char) ---> returns true if char is alphabetic or numeric digit
////////////        isspace(char) ---> returns true if char is whitespace
////////////        islower(char) ---> returns true if char is lowercase letter 'a-z'
////////////        isupper(char) ---> returns true if char is uppercase letter 'A-Z'
////////////        isblank(char) ---> returns true if char is blank character(tabs, spaces, etc.)
////////////        isxdigit(char) --> returns true if char is hexadecimal digit: 0-9, a-f, A-F.
////////////        ispunct(char) ---> returns true if char is punchtion character (Punctuation characters include: !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~)
////////////        isprint(char) ---> returns true if char is printable character. Printable characters include alphanumeric, punctuation, and space characters.
////////////        iscntrl(char) ---> returns true if char is control character. Control characters are all characters that are not printable.
////////////
////////////
////////////        toupper(char) ---> If c is a lowercase alphabetic character (a-z), returns the uppercase version (A-Z). If c is not a lowercase alphabetic character, just returns c.
////////////        tolower(char) ---> If c is an uppercase alphabetic character (A-Z), returns the lowercase version (a-z). If c is not an uppercase alphabetic character, just returns c.
////////////    */
////////////
////////////    /// OOP & Classes ///
////////////    /*
////////////        "." is known as a member access operator (used to invoke operations of class)
////////////            --> EX: classObject.FunctionOfClass();
////////////
////////////        creating object of class:
////////////            --> Ex: ClassName objectName
////////////
////////////
////////////        creating class and methods: vectors of class objects
////////////
////////////            --> Ex:
////////////                    class Movies {
////////////                        // default: private // anything not within public declaration is private
////////////
////////////
////////////                        string title;
////////////                        string rating; // private // mutator variable
////////////
////////////
////////////                        vector<Movies> myMovies;
////////////
////////////                        public:
////////////                            string title;//accessible from outside
////////////                            int year;
////////////
////////////
////////////                            // declaring functions //
////////////                            void serRating(string stars); // mutator function
////////////                            string getRating(); // accessor function
////////////
////////////                            // can also perform inline function definition //
////////////                            string GetTitle() {
////////////                                return title;
////////////                            }
////////////
////////////                        private: // private
////////////                            string protagonist;
////////////
////////////                    }
////////////
////////////
////////////                    // defining class functions //
////////////                    void Movie::setRating(string stars) { // method that can only be accessed through Movies class //
////////////                        rating = stars;
////////////                    }
////////////    */
////////////
////////////    // const //
////////////    /*
////////////        --> Accessor functions usually are defined as const to make clear that data members won't be changed.
////////////        --> const after a member function's name and parameters causes a compiler error if the function modifies a data member. If a const member function calls another member function, that function must also be const.
////////////        -->  If a const member function calls another member function, that function must also be const.
////////////        Ex:
////////////            string GetName() const; // Accessor
////////////
////////////        Ex:
////////////            string Restaurant::GetName() const {
////////////            return name;
////////////            }
////////////
////////////    */
////////////
////////////    // Public And Private Data Members //
////////////    /*
////////////        --> In addition to public member functions, a class definition has private data members: variables that member functions can access but class users cannot. Private data members appear after the word "private:" in a class definition.
////////////        Ex:
////////////            class Restaurant {  // Keeps a user's review of a restaurant
////////////
////////////                public:
////////////                    void SetName(string restaurantName);  // Sets the restaurant's name
////////////                    void SetRating(int userRating);       // Sets the rating (1-5, with 5 best)
////////////                    void Print();                         // Prints name and rating on one line
////////////
////////////                private:
////////////                    string name;
////////////                    int rating;
////////////            };
////////////    */
////////////
////////////    // Private helper functions //
////////////    /*
////////////        --> A programmer commonly creates private functions, known as private helper functions, to help public functions carry out tasks.
////////////        --> Any member function (public or private) may call a private member function.
////////////        --> A user of the class can call public member functions, but a user can not call private member functions (which would yield a compiler error).
////////////    */
////////////
////////////    // Data member initialization (C++11)
////////////    /*
////////////        Since C++11, a programmer can initialize data members in the class definition. Any variable declared of that class type will initially have those values.
////////////    */
////////////
////////////    // Constructors //
////////////    /*
////////////        --> The default constructor is called when an object is declared of the class type.
////////////            --> The default constructor is called for each created object
////////////
////////////            Ex:
////////////                The following calls the default constructor 5 times:
////////////                vector<Seat> seats(5);
////////////
////////////                The vector definition creates 5 elements, each being a Seat object. Thus, the Seat constructor is called 5 times.
////////////
////////////                sometimes initializations are more complicated, in which case a constructor is needed, instead of directly assigning variables with default values
////////////
////////////        --> C++ has a special class member function, a constructor, called automatically when a variable of that class type is declared, and which can initialize data members. A constructor callable without arguments is a default constructor, like the Restaurant constructor below.
////////////
////////////        --> A constructor has the same name as the class. A constructor function has no return type, not even void. Ex: Restaurant::Restaurant() {...} defines a constructor for the Restaurant class.
////////////
////////////        --> If a class has no programmer-defined constructor, then the compiler implicitly defines a default constructor having no statements.
////////////
////////////        --> If a programmer defines any constructor, the programmer should also define a default constructor. Here, the default constructor is missing.
////////////
////////////        --> Because the constructor can be called without arguments, the constructor serves as a default constructor.
////////////            Ex:
////////////                YourClass(string name = "", int num = 0); // acts as default constructor
////////////
////////////
////////////    */
////////////
////////////    // Classes and vectors/classes //
////////////    /*
////////////        --> #include <vector>
////////////        --> can create vectors of objects
////////////
////////////    */
////////////
////////////
////////////    // separating programs between two files //
////////////    /*
////////////        Programmers typically put all code for a class into two files, separate from other code.
////////////
////////////        ClassName.h contains the class definition, including data members and member function declarations.
////////////        ClassName.cpp contains member function definitions.
////////////
////////////
////////////        A file that uses the class, such as a main file or ClassName.cpp, must include ClassName.h. The .h file's contents are sufficient to allow compilation, as long as the corresponding .cpp file is eventually compiled into the program too.
////////////
////////////
////////////        Sometimes multiple small related classes are grouped into a single file to avoid a proliferation of files. But for typical classes, good practice is to create a unique .cpp and .h file for each class.
////////////
////////////        //////////////////////////////////////////////////
////////////        Just the class definition appears in the .h. All the function definitions appear in a .cpp file.
////////////
////////////
////////////        //////////////////////////////////////////////////
////////////         faster compilation results. Consider making a change to a single file in a program with 20 files; separate files means only the changed file needs recompiling, not all 20.
////////////
////////////    */
////////////
////////////
////////////    // namespaces // name conflicts
////////////    /*
////////////        --> A namespace defines a region (or scope) used to prevent name conflicts.
////////////        --> The scope resolution operator :: allows specifying in which namespace to find a name, as in: auditorium::Seat concertSeat; and airplane::Seat flightSeat;
////////////        --> A namespace helps avoid name conflicts among classes, functions, and other items in a program.
////////////
////////////
////////////        --> Scope resolution operator (::): A programmer can use the scope resolution operator to specify the std namespace before C++ standard library items. Ex: std::cout << "Hello"; or std::string userName;
////////////        --> Namespace directive: A programmer can add the statement using namespace std; to direct the compiler to check the std namespace for any names later in the file that aren't otherwise declared. Ex: For string userName;, the compiler will check namespace std for string.
////////////
////////////        Ex:
////////////            namespace auditorium {
////////////                class Seat {
////////////                    ...
////////////                };
////////////            }
////////////
////////////
////////////        Ex:
////////////            #include "auditorium.h"
////////////            #include "airplane.h"
////////////
////////////            int main() {
////////////                auditorium::Seat concertSeat;
////////////                airplane::Seat flightSeat;
////////////
////////////                // ...
////////////
////////////                return 0;
////////////            };
////////////
////////////    */
////////////
////////////    // Static //
////////////    /*
////////////        --> The keyword static indicates a variable is allocated in memory only once during a program's execution. Static variables are allocated memory once and reside in the program's static memory region for the entire program. Thus, a static variable retains a value throughout the program.
////////////
////////////        --> In a class, a static data member is a data member of the class instead of a data member of each class object. Thus, static data members are independent of any class object, and can be accessed without creating a class object.
////////////
////////////        --> A static data member is declared inside the class definition, but must also be defined outside the class declaration. Within a class function, a static data member can be accessed just by variable name. A public static data member can be accessed outside the class using the scope resolution operator: ClassName::variableName.
////////////    */
////////////
////////////    // Recursion //
////////////    /*
////////////        --> Recursion may be direct, such as f() itself calling f(), or indirect, such as f() calling g() and g() calling f().
////////////        --> A function may call other functions, including calling itself. A function that calls itself is a recursive function.
////////////
////////////    */
////////////
////////////    // Vector ADT (Abstract Data Type) //
////////////    /*
////////////        --> The standard template library (STL) defines classes for common Abstract Data Types (ADTs).
////////////        --> A vector is an ADT of an ordered, indexable list of items.
////////////
////////////        --> The vector ADT is implemented as a class (actually a class template that supports different types such as vector<int> or vector<string>, although templates are discussed elsewhere).
////////////
////////////        --> For the commonly-used vector member functions below, assume a vector is declared as:
////////////            vector<T> vectorName();
////////////
////////////        --> where T represents the vector's element type, such as:
////////////            vector<int> teamNums(5);
////////////
////////////
////////////        --> The vector class has several private data members. However, to use a vector, a programmer only needs to know the public abstraction of the vector ADT.
////////////
////////////
////////////        Vector Insert & Erase Member Functions:
////////////        --> vector's insert() and erase() member functions
////////////        --> The insert() function takes a position argument indicating where the new element should be inserted. However, position is not just a number like 1, but is rather: myVector.begin() + 1.
////////////        --> The reason is beyond our scope here, but has to do with iterators that can be useful when iterating through a vector in a loop. The erase() function is similar.
////////////
////////////
////////////            --> A common use of insert() is to insert a new item in sorted order.
////////////
////////////    */
////////////
////////////    //  Adding output statements for debugging //
////////////
////////////    // Searching and algorithms //
////////////    /*
////////////        --> An algorithm is a sequence of steps for accomplishing a task. Linear search is a search algorithm that starts from the beginning of a list, and checks each element until the search key is found or the end of the list is reached.
////////////        --> An algorithm's runtime is the time the algorithm takes to execute. If each comparison takes 1 µs (1 microsecond), a linear search algorithm's runtime is up to 1 s to search a list with 1,000,000 elements, 10 s for 10,000,000 elements, and so on
////////////
////////////        --> An algorithm typically uses a number of steps proportional to the size of the input.
////////////
////////////
////////////            Insertion Sort
////////////            Merged Sort
////////////            Selection Sort
////////////
////////////        */
////////////
////////////
////////////        // Linked List //
////////////        /*
////////////            --> linked list consists of items that contain both data and a pointer (or link) to the next list item. Inserting a new item between two existing items just requires a few operations to update each item's pointer.
////////////                --> The new item's next pointer is assigned to point to the item at the front of the list. The new item then becomes the front of the list. No shifting of other items is required.
////////////
////////////        */
////////////
////////////        // Pointer //
////////////        /*
////////////
////////////
////////////            Dereferencing:
////////////                prefixing pointer with (*) after calling it, returns value held at address
////////////
////////////                example:
////////////
////////////                        int n = 50;
////////////
////////////                        int& pointer;
////////////                        pointer = nullptr;
////////////
////////////                        pointer = n; // holds address of variable
////////////                        *pointer = 32;// changes value at memory address // n = 32 instead of 50
////////////
////////////
////////////                        int pointer2 = &n;// stores address
////////////
////////////
////////////
////////////
////////////            --> A pointer is a variable that holds a memory address, rather than holding data like most variables.
////////////            --> A pointer is declared by including * before the pointer's name.
////////////
////////////
////////////            --> The 'delete' operator, deallocates memory allocated with the 'new' operator.
////////////
////////////
////////////            --> When an object is dynamically allocated, the 'new' operator calls the class' constructor after allocating memory for the class' member variables.
////////////
////////////            --> The 'new' operator allocates memory for the given type and returns a pointer to the allocated memory.
////////////            --> If the type is a class, the 'new' operator calls the class' constructor after allocating memory for the object.
////////////                Ex:
////////////
////////////                    Sleep* sleepRecord;
////////////                    sleepRecord = new Sleep;// same as calling "new Sleep();"
////////////
////////////
////////////                    // OR //
////////////
////////////
////////////                    Sleep* sleepRecord1;
////////////                    Sleep* sleepRecord2;
////////////
////////////                    sleepRecord1 = new Sleep();// default constructor
////////////                    sleepRecord2 = new Sleep(4, 37);// 4 hrs, 37 mins
////////////
////////////
////////////            --> The 'new' operator returns a pointer to the allocated memory
////////////        */
////////////
////////////
////////////        // Member access operator (->) //
////////////        /*
////////////        --> When using a pointer to an object, the member access operator (->) allows access to the object's members with the syntax a->b.
////////////            Ex:
////////////                If sleepRecord is a pointer to a Sleep object, then sleepRecord->Print() calls the Print() member function.
////////////
////////////            Ex:
////////////                Sleep* sleepRecord;// points to sleep object
////////////
////////////                sleepRecord = new Sleep;
////////////                sleepRecord->Print();// points to object's print function
////////////
////////////                // or //
////////////
////////////                sleepRecord -> Print();// points to object's print function
////////////        */
////////////
////////////        // Deference operator (*) //
////////////        /*
////////////            -->  dereference operator (*) is prepended to a pointer variable's name to retrieve the data to which the pointer variable points.
////////////
////////////            --> The * operator and the . operator may be combined to access a dynamically allocated object's members as in (*a).b instead of a->b.
////////////                Ex:
////////////                    (*sleepRecord).Print(); // which is the same as "sleepRecord->Print();"
////////////
////////////
////////////                Ex:
////////////                // Why the * operator is used as (*pointerName).MemberFunction();
////////////                --> The . operator has precedence over the * operator. So, sleepRecord.PrintInMinutes() is evaluated first.
////////////                --> Since sleepRecord is a pointer to a sleep object, the compiler reports an error. To dereference pointer sleepRecord first, parentheses are needed, as in "(*sleepRecord)" before ".PrintInMinutes()"
////////////        */
////////////
////////////
////////////        // Delete operator //
////////////        /*
////////////            --> The 'delete' operator deallocates a block of memory that was allocated with the 'new' operator
////////////                --> the delete operator deallocates the object pointed to
////////////            Ex:
////////////                    Sleep* sleepRecord;
////////////                    sleepRecord = new Sleep();
////////////
////////////                    delete sleepRecord;
////////////
////////////
////////////            --> The statement 'delete sleepRecord;' deallocates a memory block pointed to by sleepRecord.
////////////            --> If sleepRecord is null, delete has no effect.
////////////                --> Calling delete with a pointer that was not previously set by the new operator has undefined behavior and is a logic error.
////////////
////////////
////////////            --> After the delete, the program should not attempt to dereference sleepRecord since sleepRecord points to a memory location that is no longer allocated for use by sleepRecord.
////////////
////////////            --> Dereferencing a pointer whose memory has been deallocated is a common error and may cause strange program behavior that is difficult to debug.
////////////        */
////////////
////////////        // Null for pointers (nullptr) //
////////////        /*
////////////            --> When declaring a null pointer variable, assign the the variable with 'nullptr'
////////////        */
////////////
////////////
////////////        // Parameters // pass-by-value and bass-by-reference parameters //
////////////        /*
////////////            Pass-by-value: GOOD TO AVOID
////////////            --> pass by value, meaning the argument's value is copied into a local variable for the parameter
////////////                --> parameter used variables, variables declared by functions arguments(parameters) and used locally when function is called
////////////
////////////            --> Although a pass-by-value parameter creates a local copy, good practice is to avoid assigning such a parameter. The following code is correct but bad practice.
////////////
////////////
////////////
////////////            Pass-by-reference: USE SPARINGLY
////////////            --> A pass-by-reference parameter does not create a local copy of the argument, but rather the parameter refers directly to the argument variable's memory location.
////////////            --> Appending & to a parameter's data type makes the parameter pass-by-reference type.
////////////
////////////            --> C++ supports another kind of parameter that enables updating of an argument variable. A pass-by-reference parameter does not create a local copy of the argument, but rather the parameter refers directly to the argument variable's memory location.
////////////            --> Appending & to a parameter's data type makes the parameter pass-by-reference type.
////////////                Ex:
////////////                    void ConvHrMin(int timeVal, int& hrVal, int& minVal) { // & indicates that the hrVal and minVal parameters are pass-by-reference parameters.
////////////                        hrVal = timeVal / 60;
////////////                        minVal = timeVal % 60;
////////////                    }
////////////
////////////                    // A pass-by-reference parameter refers to the associated argument's memory location. Updates to hrVal and minVal update usrHr and usrMin.
////////////
////////////
////////////            // For the case of two return values, commonly a programmer should instead create two functions. For example, defining two separate functions int StepsToFeet(int baseSteps) and int StepsToCalories(int baseSteps) is better than a single function void StepsToFeetAndCalories(int baseSteps, int& baseFeet, int& totCalories).
////////////            // The separate functions support modular development, and enables use of the functions in an expression as in if (StepsToFeet(mySteps) < 100).
////////////            // Using multiple pass-by-reference parameters makes sense when the output values are intertwined, such as computing monetary change, whose function might be void ComputeChange(int totCents, int& numQuarters, int& numDimes, int& numNickels, int& numPennies)
////////////
////////////
////////////
////////////            // pass-by-reference variables should be used sparingly //
////////////            // parameters with the '&' sign after their type are not required and are still modified through the function //
////////////
////////////        */
////////////
////////////
////////////        // Make separate functions to have modular approach // CAN BE EASILY IMPLEMENTED AND MODIFIED //
////////////
////////////
////////////        // Reference Variables //
////////////        /*
////////////            --> A programmer can also declare a reference variable. A reference is a variable type that refers to another variable.
////////////                Ex:
////////////                    int& maxValRef declares a reference to a variable of type int.
////////////
////////////            --> The programmer must initialize each reference with an existing variable, which can be done by initializing the reference variable when the reference is declared. Ex: int& maxValRef = usrInput3;
////////////                Ex:
////////////                    int usrValInt;
////////////                    int& usrValRef = usrValInt;  // Refers to usrValInt
////////////
////////////                    // when updating usrValInt, usrValRef will hold the new value // also holds vice versa
////////////
////////////
////////////                Ex: for string modification method
////////////
////////////                    // the string parameter must be pass by reference, achieved using &, so that the function modifies the original string argument (userStr) and not a copy.
////////////
////////////            *--> Sometimes a programmer defines a vector or string parameter as pass by reference even though the function does not modify the parameter, to prevent the performance and memory overhead of copying the argument that would otherwise occur.
////////////
////////////        */
////////////
////////////        // const //
////////////        /*
////////////            --> the 'const' keyword can be prepended to a function's vector or string parameter to prevent the function from modifying the parameter.
////////////
////////////            Remember:
////////////                --> Define a function's output or input/output parameters as pass by reference.
////////////                    --> But create output parameters sparingly, striving to use return values instead.
////////////                --> Define input parameters as pass by value.
////////////                    --> Except for large items (perhaps 10 or more elements); use constant pass by reference for those.
////////////
////////////            --> vectors should be const and not pass by ref. if they shouldn't be modified
////////////            --> vectors should be pass by ref. if they should be modified
////////////                --> if vector is large, use pass by ref. and const if its never getting modified(avoids creating local copy of large vector)
////////////
////////////
////////////            // const pass by reference variables //
////////////            --> A reader might wonder why all input parameters are not defined as constant pass by reference parameters: Why make local copies at all? The reason is efficiency. For parameters involving just a few memory locations, making a local copy enables the compiler to generate more efficient code, in part because the compiler can place those copies inside a tiny-but-fast memory inside the processor called a register file
////////////        */
////////////
////////////
////////////
////////////
////////////        /// Memory regions: Heap/Stack ///
////////////        /*
////////////            A program's memory usage typically includes four different regions:
////////////
////////////                -> Code — The region where the program instructions are stored.
////////////                -> Static memory — The region where global variables (variables declared outside any function) as well as static local variables (variables declared inside functions starting with the keyword "static") are allocated. Static variables are allocated once and stay in the same memory location for the duration of a program's execution.
////////////                -> The stack — The region where a function's local variables are allocated during a function call. A function call adds local variables to the stack, and a return removes them, like adding and removing dishes from a pile; hence the term "stack." Because this memory is automatically allocated and deallocated, it is also called automatic memory.
////////////                -> The heap — The region where the "new" operator allocates memory, and where the "delete" operator deallocates memory. The region is also called free store.
////////////
////////////        */
////////////
////////////
////////////
////////////        // Dynamically allocating an array of objects //
////////////        /*
////////////            --> A programmer can use the new operator to create a dynamically allocated array of objects by specifying the class name followed by desired array length within square brackets.
////////////            --> A contiguous block of memory is allocated for the array, and then the default constructor is called for each object in the array.
////////////            --> A compiler error occurs if the class does not have a default constructor.
////////////
////////////
////////////
////////////
////////////        */
////////////
////////////
////////////
////////////
////////////        // 'this' implicit parameter //
////////////        /*
////////////
////////////            --> An object's member function is called using the syntax object.Function(). The object variable before the function name is known as an implicit parameter of the member function because the compiler converts the call syntax object.Function(...) into a function call with a pointer to the object implicitly passed as a parameter. Ex: Function(object, ...).
////////////
////////////            --> Within a member function, the implicitly-passed object pointer is accessible via the name this. In particular, a member can be accessed as this->member. The -> is the member access operator for a pointer, similar to the "." operator for non-pointers.
////////////
////////////            --> Using this-> makes clear that a class member is being accessed and is essential if a data member and parameter have the same identifier. In the example below, this-> is necessary to differentiate between the data member sideLength and the parameter sideLength.
////////////
////////////            --> The this->numYears refers to the object's data member.
////////////
////////////
////////////            --> When an object's member function is called, the object's memory address is passed to the function via the implicit "this" parameter. An access in SetTime() to this->hours first goes to the object's address, then to the hours data member.
////////////
////////////        */
////////////
////////////
////////////        // Destructor //
////////////        /*
////////////            --> A destructor is a special class member function that is called automatically when a variable of that class type is destroyed. When a C++ class object uses dynamically allocated data, such data is commonly deallocated in the class' destructor.
////////////
////////////            --> The syntax for a class' destructor function is similar to a class' constructor function, but with a "~" (called a "tilde" character) prepended to the function name. A destructor has no parameters and no return value. Ex: The ActivityTracker class destructor is declared as ~ActivityTracker();.
////////////
////////////
////////////
////////////            --> When an array of objects is deallocated using delete[], the destructor is called on each object in the array. Ex: The Activity destructor is not required, but is implemented below to illustrate when the Activity destructor is called.
////////////            --> If an object is dynamically allocated using the new operator, using delete on the object calls the object's destructor. If an object is not dynamically allocated, the object's destructor is called automatically when the object goes out of scope.
////////////        */
////////////
////////////
////////////        // Memory Leaks //
////////////        /*
////////////            --> Deleting an object allows it to be reassigned if desired (not advised however)
////////////            --> Memory leaks occur at the program level, so when a program terminates, all memory allocated by the program is freed.
////////////
////////////            --> A memory leak occurs when a program that allocates memory loses the ability to access the allocated memory, typically due to failure to properly destroy/free dynamically allocated memory. A program's leaking memory becomes unusable, much like a water pipe might have water leaking out and becoming unusable.
////////////            --> A memory leak may cause a program to occupy more and more memory as the program runs, which slows program runtime. Even worse, a memory leak can cause the program to fail if memory becomes completely full and the program is unable to allocate additional memory.
////////////
////////////
////////////            // Garbage collection //
////////////
////////////                --> Some programming languages, such as Java, use a mechanism called garbage collection wherein a program's executable includes automatic behavior that at various intervals finds all unreachable allocated memory locations (e.g., by comparing all reachable memory with all previously-allocated memory), and automatically frees such unreachable memory.
////////////                --> Some non-standard C++ implementations also include garbage collection. Garbage collection can reduce the impact of memory leaks at the expense of runtime overhead. Computer scientists debate whether new programmers should learn to explicitly free memory versus letting garbage collection do the work.
////////////
////////////
////////////
////////////
////////////            // Tersm: //
////////////
////////////                --> [Unusable Memory] Memory locations that have been dynamically allocated but can no longer be used by a program.
////////////                --> [Memory Leaks] Occurs when a program allocates memory but loses the ability to access the allocated memory.
////////////                --> [Garbage COllection] Automatic process of finding and freeing unreachable allocated memory locations.
////////////
////////////
////////////            // Destructors //
////////////
////////////                --> Destructors are needed when destroying an object involves more work than simply freeing the object's memory. Such a need commonly arises when an object's data member, referred to as a sub-object[pointer types], has allocated additional memory.
////////////                --> Freeing the object's memory without also freeing the sub-object's memory results in a problem where the sub-object's memory is still allocated, but inaccessible, and thus can't be used again by the program.
////////////        */
////////////
////////////
////////////
////////////
////////////}
