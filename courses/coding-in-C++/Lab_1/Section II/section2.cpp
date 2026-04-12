#include <iostream>
#include <cstdint>
#include <limits>

#define MIN_AGE_ADULT 18
#define MIN_AGE_SENIOR 65
#define MAX_AGE 120

namespace validation
{
    bool isAdult(std::uint8_t age){
        return age >= MIN_AGE_ADULT;
    }

    bool isSenior(std::uint8_t age){
        return age >= MIN_AGE_SENIOR;
    }
}

int main()
{
    int age = 0;

    std::cout << '\n' << "Please enter your age: " << std::endl;
    
    //check the input for validity
    while(true) 
    {
        if(!(std::cin >> age)) 
        {
            std::cout << "Error: please type in valid age." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (age <= 0)
        {
            std::cout << "Error: Your input is either 0 or negative. Please type in a valid age." << std::endl;
        }
        else if (age > MAX_AGE)
        {
            std::cout << "Error: Your input is above the maximum age which is " << static_cast<int>(MAX_AGE) << ". Please type in valid age." << std::endl;
        }
        else
        {
            //exit infinitively running loop if given input was valid
            break;
        }
    }
    
    //print results
    std::cout << "You are " << age << " years old." << std::endl;

    if ((validation::isAdult(age)) && !(validation::isSenior(age)))
    {
        std::cout << "That means you are an adult." << std::endl;
    }
    else if (validation::isSenior(age))
    {
        std::cout << "That means you are a senior citizen." << std::endl;
    }
    else if (!(validation::isAdult(age)))
    {
        std::cout << "That means that you are still a kid or a teenager." << std::endl;
    }

    return 0;
}

/*Questions
    What exactly is the problem when using uint8_t for storing the entered age of the user?
    Which other portable data types would make sense in this example?
*/