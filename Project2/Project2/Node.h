#pragma once

struct Node
{
public:
	int id;
	int beginLabel;
	int endLabel;
	int stringDepth;
	int numChild;
	Node *parent;
	Node **child;
	Node *suffixLink;
	bool visited;
};