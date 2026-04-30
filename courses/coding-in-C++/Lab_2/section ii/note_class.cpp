#include <iostream>
#include <string>

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
        Note(const Note& note)
        {
            text = new std::string;
            *text = *note.text;
            std::cout << "copy constructor triggered" << std::endl;
        }
        ~Note()
        {
            delete text;
            text = NULL;
            std::cout << "Memory released" << std::endl;
        };
        void display()
        {
            std::cout << std::endl << *text << std::endl;
        };
};

int main()
{
    Note note1("This is a note");
    note1.display();

    Note note2(note1);
    note2.display();

    Note note3("This is also a note with very intellectual value");
    note3.display();

    Note note4 = note2;
    note4.display();
    return 0;
}