//
// Created by KSZ on 2021-12-03.
//

#include "ListNote.h"

std::string ListNote::getContent()
{
    std::cout << "NOTATKA W FORMIE LISTY\n";
    std::string parsedContent = "";
    for (int i = 0; i < size; i++) {
        parsedContent += (char)254;
        parsedContent += ' ';
        parsedContent += content[i];
        parsedContent += '\n';
    }
    return parsedContent;
}

void ListNote::setContent(std::string* newContent, int len)
{
    if (len < 100) {
        for (int i = 0; i < len; i++) {
            content[i] = newContent[i];
        }
    }
    size = len;
}