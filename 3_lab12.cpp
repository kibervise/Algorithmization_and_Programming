#include <iostream>
#include <string>
using namespace std;

void WorkFunc(char *song, char *letters)
{
    char a = strlen(letters);
    for (char *text = strtok(song, " "); text; text = strtok(NULL, " "))
    {
        char b = strlen(text);
        for (int i = 0; i<a; i++)
        {
            if (text[b - 1] == letters[i])
                printf("%s ", text);
        }
    }
}

void Sentence()
{
    char A[] = "AaEeIiOoUuYy";
    char Z[] = "BbCcDdFfGgHhJjKkLlMmNnPpQqRrSsTtVvWwXxZz";
    char song[] = "I got my red dress on tonight\nDancing in the dark in the pale moonlight ";
    cout << "TEXT:\n" << song << "\n" << endl;
    const int N = sizeof(song);
    char song2[N];
    strcpy(song2, song);
    
    cout << "Vowels:" << endl;
    WorkFunc(song, Z);
    cout << "\n\nConsonants:" << endl;
    WorkFunc(song2, A);
    cout << endl;
}


int main()
{
    Sentence();
}


