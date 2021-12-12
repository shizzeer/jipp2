//
// Created by KSZ on 2021-12-03.
//

#ifndef JIPP2_NOTE_H
#define JIPP2_NOTE_H
#include <iostream>

class Note {
protected:
    std::string title;
    int size;
public:
    std::string getTitle();
    void setTitle(std::string title);
    virtual std::string getContent() = 0;
    virtual void setContent(std::string* newContent, int len) = 0;
    virtual ~Note() = default;
};


#endif //JIPP2_NOTE_H
