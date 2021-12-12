//
// Created by KSZ on 2021-12-03.
//

#include <iostream>
#include "NoteDirector.h"
#include "Note.h"
#include "TextNote.h"
#include "ListNote.h"

void NoteDirector::addNote(std::string noteType, std::string* newContent, std::string title, int len)
{
    if (used < 100) {
        if (noteType == "zwykla") {
            notesList[used] = new TextNote;
            notesList[used]->setContent(newContent, 0);
            notesList[used]->setTitle(title);
            used++;
        }
        else if (noteType == "lista") {
            notesList[used] = new ListNote;
            notesList[used]->setContent(newContent, len);
            notesList[used]->setTitle(title);
            used++;
        }
    }
}

void NoteDirector::printAll()
{
    for (int i = 0; i < used; i++)
        std::cout << notesList[i]->getContent() << '\n';
}

void NoteDirector::clearNotesList()
{
    for (int i = 0; i < used; i++)
        delete notesList[i];
}

void NoteDirector::deleteNote(int noteIdx)
{
    if (noteIdx >= 0 && noteIdx < used) {
        delete notesList[noteIdx];
        /* Przesuwamy wszystkie obiekty w tablicy o jedno miejsce w lewo */
        if (noteIdx < 99 && noteIdx < used - 1) {
            for (int i = noteIdx + 1; i > 0; i--) {
                notesList[i - 1] = notesList[i];
            }
        }
        used--;
    }
}

/*
void NoteDirector::editNote(int noteIdx, int beginningOfEdition)
{
    if (noteIdx >= 0 && noteIdx < used) {
        std::string contentCopy = notesList[noteIdx]->getContent();
        size_t contentLen = contentCopy.length();
        std::string newContent;
        if (beginningOfEdition >= 0) {
            if(beginningOfEdition < contentLen) {
                std::cout << "Podaj zawartosc do wpisania: ";
                std::cin >> newContent;
                int j = 0;
                for (int i = beginningOfEdition; i < contentLen; i++) {
                    contentCopy[i] = newContent[j];
                    j++;
                }
                notesList[noteIdx]->setContent(&contentCopy, 0);
            }
        }
    }
}*/
