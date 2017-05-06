#pragma once

#include<iostream>

using namespace std;

extern char *geneBuffer;

class InputOutput {
public:

	string input(char *inputPath);
	int alphabetParse(char *alphabetFile);
};