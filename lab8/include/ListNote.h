//
// Created by KSZ on 2021-12-03.
//

#ifndef JIPP2_LISTNOTE_H
#define JIPP2_LISTNOTE_H
#include <iostream>
#include "Note.h"

class ListNote : public Note {
private:
    std::string content[100];
public:
    std::string getContent();
    void setContent(std::string* newContent, int len);
};


#endif //JIPP2_LISTNOTE_H
