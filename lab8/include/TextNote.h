//
// Created by KSZ on 2021-12-03.
//

#ifndef JIPP2_TEXTNOTE_H
#define JIPP2_TEXTNOTE_H
#include <iostream>
#include "Note.h"

class TextNote : public Note {
private:
    std::string content;
public:
    std::string getContent();
    void setContent(std::string* newContent, int len);
};


#endif //JIPP2_TEXTNOTE_H
