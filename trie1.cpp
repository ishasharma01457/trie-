#include <bits/stdc++.h>
#include <iostream>
#include<conio.h>
using namespace std;

const int ALPH_SIZE = 26;
struct TrieNode
{
	struct TrieNode *child[ALPH_SIZE];
	bool isEndOfWord;
};
struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPH_SIZE; i++)
		pNode->child[i] = NULL;

	return pNode;
}
void insert(struct TrieNode *root, string value)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < value.length(); i++)
	{
		int index = value[i] - 'a';
		if (!pCrawl->child[index])
			pCrawl->child[index] = getNode();

		pCrawl = pCrawl->child[index];
	}
	pCrawl->isEndOfWord = true;
}
bool search(struct TrieNode *root, string value)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < value.length(); i++)
	{
		int index = value[i] - 'a';
		if (!pCrawl->child[index])
			return false;

		pCrawl = pCrawl->child[index];
	}

	return (pCrawl->isEndOfWord);
}
int main()
{
	string values[] = {"the", "a", "this",
					"answer", "any", "by",
					"bye", "your" };
	int n = sizeof(values)/sizeof(values[0]);

	struct TrieNode *root = getNode();
	for (int i = 0; i < n; i++)
		insert(root, values[i]);
	search(root, "the")? cout << "Yes\n" :
						cout << "No\n";
	search(root, "these")? cout << "Yes\n" :
						cout << "No\n";
	search(root, "why")? cout << "Yes\n" :
						cout << "No\n";
	search(root, "there")? cout << "Yes\n" :
						cout << "No\n";
	return 0;
}


