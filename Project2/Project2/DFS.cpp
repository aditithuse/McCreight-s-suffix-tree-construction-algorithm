
#include"SuffixTree.h"
#include<iostream>
#include<fstream>

using namespace std;


void SuffixTree::DFSTraversal(Node *node)
{

	node->visited = true;

	for (int i = 0; i < node->numChild; i++)
	{
		if (node->child[i]->visited == false)
		{
			DFSTraversal(node->child[i]);
		}
	}
}

void SuffixTree::BWTDFSTraversal(Node *node)
{
	for (int i = 0; i < node->numChild; i++)
	{
		if (node->child[i] != NULL)
		{
			BWTDFSTraversal(node->child[i]);
		}
	}


	fstream bwtText;
	bwtText.open("bwtTEXT.txt", fstream::in | fstream::out | fstream::app);
	if (bwtText.is_open())
	{
		//if the node is leaf then it should be inserted in BWT array
		if (node->numChild == 0)
		{
			int val = node->id - 1;
			if (val > 0)
				bwtText << "\n" << geneBuffer[val - 1];
			else //if val becomes 0 then BWT will be the last index of string
				bwtText << "\n" << geneBuffer[geneLen - 1];
		}
		bwtText.close();
	}
	else
	{
		cout << "Error in opening the file";
		exit(EXIT_FAILURE);
	}
	return;
}


