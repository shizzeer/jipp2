//
// Created by KSZ on 2021-12-03.
//

#ifndef JIPP2_NOTEDIRECTOR_H
#define JIPP2_NOTEDIRECTOR_H
#include "Note.h"


class NoteDirector {
private:
    Note* notesList[100];
    int used = 0;
public:
    void printAll();
    void addNote(std::string noteType, std::string* newContent, std::string title, int len);
    void deleteNote(int noteIdx);
    void editNote(int noteIdx, int beginningOfEdition);
    void clearNotesList();
};


#endif //JIPP2_NOTEDIRECTOR_H
