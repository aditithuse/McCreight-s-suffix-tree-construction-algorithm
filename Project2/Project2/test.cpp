// AditiThuse-Program2.cpp : Defines the entry point for the console application.

#include"InputOutput.h"
#include"SuffixTree.h"
#include"Memory.h"
#include"Node.h"
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<ctime>


using namespace std;

int main(int argc, char *argv[])  //input File
{
	InputOutput io;
	SuffixTree st;
	Node *constructedTree;
	Memory mem;
	string gene = "";
	string alphabet = "";
	int numAlphabets = 0;
	clock_t start, end;
	double duration;
	try
	{
		if (argc != 3)
		{
			cout << "\nNumber of command line argumets are wrong.\nCommands should be\n1. Input file containing both s1 and s2\n2. Alphabet File\n\n";
			exit(EXIT_FAILURE);
		}
		else
		{
			char *executableName = argv[0];
			char *inputPath = argv[1];
			char *alphabet = argv[2];
			gene = io.input(inputPath);
			numAlphabets = io.alphabetParse(alphabet);
		}

		
		mem.detectFreeMemory();

		//construction suffix tree
		start = clock();
		constructedTree = st.suffixTree(gene, numAlphabets);
		end = clock();
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;
		cout << "\nTime in seconds for construction of Suffix tree: " << duration;

		//BWT traversal and time taken for BWT.
		start = clock();
		fstream bwtText;
		bwtText.open("bwtTEXT.txt", std::fstream::out | std::fstream::trunc);
		bwtText.close();
		st.BWTDFSTraversal(constructedTree);
		end = clock();
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;
		cout << "\nTime in seconds for BWT array: " << duration;

		//DFS traversal on randomly selected node
		int option;
		//cout << "Do you want to DFS traverse on a node? If Yes then type 1";
		cin >> option;
		if (option == 1)
			st.DFSTraversal(constructedTree);

		//free memory
		mem.freeMemory(constructedTree);


		getchar();
		exit(EXIT_SUCCESS);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what();
	}
	getchar();
	return 0;

}