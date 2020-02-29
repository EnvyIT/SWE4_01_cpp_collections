// file: utils.h

#pragma once

#include <cctype> // c functions which provide information about single characters
#include <string>
#include <fstream>

bool is_punct(char ch);
bool is_digit(char ch);
bool is_alpha(char ch);

char to_lower(char ch);

std::string normalize(std::string word);
void open_stream(int argc, char *argv[], std::ifstream &fin);