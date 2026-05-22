#include <string>
#include <iostream>

class Note 
{
    private:
        std::string* text;

    public:
        Note(std::string input)
        {
            text = new std::string;
            *text = input;
        };
        Note(const Note& note_ref)
        {
            text = new std::string;
            *text = *note_ref.text;
        }
        ~Note() 
        {
            delete text;
            text = nullptr;
            std::cout << "Memory released." << std::endl;
        };
        void display()
        {
            std::cout << *text << std::endl;
        };
};

int main()
{
    Note n1("test test");
    Note n2(n1);

    n1.display();
    n2.display();

    return 0;
}