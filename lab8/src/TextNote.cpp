//
// Created by KSZ on 2021-12-03.
//

#include "TextNote.h"

std::string TextNote::getContent()
{
    std::cout << "NOTATKA ZWYKLA\n";
    return content;
}

void TextNote::setContent(std::string* newContent, int len)
{
    content = *newContent;
}
