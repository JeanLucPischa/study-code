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
        }
        ~Note()
        {
            delete text;
            text = NULL;
            std::cout << "Memory released" << std::endl;
        };
        void display()
        {
            std::cout << *text << std::endl;
        };
};

int main()
{
    Note note1("This is a note");
    note1.display();

    Note note2(note1);
    note2.display();

    return 0;
}