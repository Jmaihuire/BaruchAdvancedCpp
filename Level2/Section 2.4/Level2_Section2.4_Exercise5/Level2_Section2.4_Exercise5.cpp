// Level2_Section2.4_Exercise5.cpp :
// Fiona Ross - 02-28-2022
/*
 Exercise 5: Custom Deleter
 Shared and unique pointers support deleters.
 A deleter is a callable object that executes some code before an object goes out of scope.
 A deleter can be seen as a kind of callback function. We first give a simple example to show what we mean:
 we create two-dimensional points as smart pointers.
 Just before a point goes out of scope a callback delete function will be called:

*/

#include <functional>
#include <iostream>
#include <fstream>


//// Point Example 
//// Deleter
//auto deleter = [](Point* pt)-> void
//{ std::cout << "Bye:" << *pt; };

//using SmartPoint = std::shared_ptr<Point>;
//SmartPoint p1(new Point(), deleter);


// The goal of this exercise is to open a file, write some data to the file 
// and then close it when we are finished writing. 
// Under normal circumstances we are able to close the file. 
// However, if an exception occurs before the file can be closed the file pointer will still be open and hence it cannot be accessed. 
// In order to ensure exception safety we employ a shared pointer with a delete function in the constructor, 
// for example by using a function object:

//Part A: 
struct FileFinalizer {
	void operator() (FILE* myFile) {
		std::cout << "Bye from function object:" << std::endl;
		fclose(myFile);
	};
};

//Part B:
//stored lambda deleter
auto removeFile = [](FILE* myFile) {
	std::cout << "Bye from stored lambda" << std::endl;
	fclose(myFile);
};

//free function deleter
void deleteFile(FILE* myFile) {
	std::cout << "Bye from free function" << std::endl;
	fclose(myFile);
}


int main()
{
	try {
		FILE* myFile;
		fopen_s(&myFile, "myFile1.txt", "w"); // opening the file and writing to it

		// Part A: 
		// testing myFile with function object 
		std::shared_ptr<FILE> mySharedFile(myFile, FileFinalizer());

		// Part C:
		// testing myFile with lambda function 
		std::shared_ptr<FILE> mySharedFile2(myFile, removeFile);

		// testing myFile free function 
		std::shared_ptr<FILE> mySharedFile3(myFile, deleteFile);

		throw - 1;
	}

	catch (const int err)
	{
		FILE* myFile2; // creating file instance
		fopen_s(&myFile2, "myFile1.txt", "w"); //opening the file & writing to it
		std::cout << "reopened file";
		fclose(myFile2);
	}

	// Part C Try/Catch 
	try {
		for (int i = 0; i < 3; ++i)
		{

			std::ofstream myFile3("myFile.txt");
			myFile3 << "Printing to file";
			std::ofstream* myFile_P = &myFile3;
			throw - 1;
			myFile3.close();
			std::cout << "closed file";
		}
	}
	catch (const int err2)
	{
		FILE* myFile4;
		fopen_s(&myFile4, "myfile.txt", "w");
	}

	std::ofstream outFile("myFile2.txt");
	outFile << "This prints to the file 2";
	outFile.close();

	// We are able to open the file. We can open the file even after the error is sent. 

}


