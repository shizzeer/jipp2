//
// Created by KSZ on 2021-12-03.
//

#include <iostream>
#include "Note.h"
#include "TextNote.h"
#include "ListNote.h"
#include "NoteDirector.h"

int main()
{
    NoteDirector noteDirector;

    /* Dodawanie zwyklej notatki */
    std::string content = "Ala ma kota\nKot ma Ale";
    noteDirector.addNote("zwykla", &content, "Tytul", 0);
    // noteDirector.printAll();

    /* Dodawanie notatki jako listy */
    std::string line;
    int numberOfLines;
    std::cout << "Ile linii chcesz dodac: ";
    std::cin >> numberOfLines;
    if (numberOfLines > 100 || numberOfLines <= 0) {
        std::cout << "Ilosc linii do wpisania musi byc dodatnia oraz niewieksza niz 100.\n";
        noteDirector.clearNotesList();
        return -1;
    }
    std::string lineNoteContent[100];
    scanf("%*c", NULL);
    for (int i = 0; i < numberOfLines; i++) {
        std::cout << "Linijka " << i + 1 << ": ";
        std::getline(std::cin, line);
        lineNoteContent[i] = line;
    }
    // std::cout << lineNoteContent << '\n';
    noteDirector.addNote("lista", lineNoteContent, "Lista", numberOfLines);
    std::cout << "--------------------------------------------------------\n";
    noteDirector.printAll();

    noteDirector.deleteNote(1);
    std::cout << "Po usunieciu: " << '\n';
    noteDirector.printAll();
    noteDirector.clearNotesList();

    return 0;
}
