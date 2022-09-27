//You may not have covered this material in your lecture sections.
//Complete as best as you are able.  Refer to the prelab reading for assistance.

//Add code where requested to complete the program.

#include <iostream>
#include <fstream>


using namespace std;

struct Dog
{
    string name;
    string breed;
    char sex;
    int age;
};

int main()
{
	// TODO - Create a Dog object named "dog1", and initialize its name to
	//        "Sparky", sex to 'M', age to 5, and breed to "Collie".
    Dog dog1;

    dog1.name = "Sparky";
    dog1.sex = 'M';
    dog1.age = 5;
    dog1.breed = "Collie";

        // TODO - Create a Dog object named "dog2".

    Dog dog2;
	// TODO - Prompt the user to enter the dog's name, age, sex, and breed,
	//        and assign them to the "dog2" object.
        //        Assume the dog name and breed are entered as a single word
        //        so that both will work with cin statements.
    cout << "Please enter your dog's name" << endl;
    cin >> dog2.name;
    cout << "Please enter your dog's age" << endl;
    cin >> dog2.age;
    cout << "Please enter your dog's sex" << endl;
    cin >> dog2.sex;
    cout << "Please enter your dog's breed" << endl;
    cin >> dog2.breed;
	// TODO - Print "dog1" and "dog2" objects to the console. E.g.
	//        "Name: Sparky, Sex: M, Age: 5, Breed: Collie"

    cout << "Name: " << dog1.name << endl;
    cout << "Age: " << dog1.age << endl;
    cout << "Sex: " << dog1.sex << endl;
    cout << "Breed: " << dog1.breed << endl;

    cout << "Name: " << dog2.name << endl;
    cout << "Age: " << dog2.age << endl;
    cout << "Sex: " << dog2.sex << endl;
    cout << "Breed: " << dog2.breed << endl;




    return 0;
}
