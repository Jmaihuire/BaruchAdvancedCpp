#ifndef Singleton_hpp
#define Singleton_hpp

// Forward reference for singleton
template<class TYPE> class Singleton; 

template<class TYPE> 
class Destroyer 
{ // Class which is responsible for the destruction of another type TYPE

	friend class Singleton<TYPE>;	// Singleton is friend of mine

private:
	TYPE* doomed_object;			// The object that is to be destructed 
	
	// Prevent users doing funny things (e.g. double deletion)
//	Destroyer();													// Default constructor
	Destroyer(TYPE* t);												// Constructor with a pointer to the doomed object
	Destroyer(const Destroyer<TYPE>& source);						// Copy constructor
	Destroyer<TYPE>& operator = (const Destroyer<TYPE>& source);	// Assignment operator

	// Modifier
	void doomed(TYPE* t);

public:
	// Destructor 
	virtual ~Destroyer();	

	// Somehow the default constructor must be public else we got a compiler error in class ctype
	Destroyer();													// Default constructor
};


template<class TYPE> 
class Singleton
{ // Templated Singleton class

private:
	static TYPE* ins;
	static Destroyer<TYPE> des;

protected:
	Singleton();
	Singleton(const Singleton<TYPE>& source);
	virtual ~Singleton();
	Singleton<TYPE>& operator = (const Singleton<TYPE>& source);

public:
	static TYPE* instance();
};


#ifndef Singleton_cpp
#include "Singleton.cpp"
#endif

#endif // Singleton_hpp