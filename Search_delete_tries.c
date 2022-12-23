// Code to implement the search and delete operation on a Trie structure

/* A trie, also known as a prefix tree, is a tree-like data structure that is 
used to store an associative array where the keys are sequences (usually strings). 
The structure of the trie allows for efficient insertion, deletion, and search 
operations.

Each node in a trie represents a single character in a key. For example, 
in a trie that stores words, each node would represent a letter in a word. 
The root node represents the empty string, and the children of a node represent
 the characters that come after the character represented by the parent node.

One of the key benefits of tries is that they can be used to efficiently search 
for keys that have a common prefix. For example, if you have a trie that stores 
words and you want to search for all the words that begin with the prefix "pre", 
you can start at the root and follow the nodes that represent the characters 'p', 
'r', and 'e' in order until you reach a node that has no children. All the keys 
that can be formed by following the path from the root to this node will have the 
prefix "pre".

Tries are often used in applications that require fast prefix searches, such as 
spell-checkers, IP routers, and lexical parsers.*/

//***********************************************************

#include <stdio.h> // Standard input/output library
#include <stdlib.h> // Standard library for memory allocation and other functions like malloc and calloc
#include <string.h> // String library for string functions like strlen

//***********************************************************

// The number of children for each node
// We will construct a N-ary tree and make it
// a Trie
// Since we have 26 english letters, we need
// 26 children per node

//***********************************************************

// Make the structure for the Trie Node and designing how the data is to be stored

//***********************************************************
#define N 26 // 26 letters in the alphabet (lower case letter)

typedef struct TrieNode TrieNode; // Defining the structure of the Trie Node

struct TrieNode {
    // The Trie Node Structure
    // Each node has N children, starting from the root
    // and a flag to check if it's a leaf node
    char data; // Storing for printing purposes only
    TrieNode* children[N]; // The children of the Trie Node
    int is_leaf;           // Flag to check if the node is a leaf node
};

//***********************************************************

// Make the trienode

//***********************************************************
TrieNode* tries_node_construct(char data) { // Function to construct the Trie Node
    // Allocating memory for the Trie Node
    TrieNode* node = (TrieNode*) calloc (1, sizeof(TrieNode)); // Allocating memory for the Trie Node
    for (int i=0; i<N; i++)    // Initializing the children to NULL
        node->children[i] = NULL; // Initializing the children to NULL
    node->is_leaf = 0;            // Initializing the leaf node to 0
    node->data = data;            // Storing the data in the Trie Node
    return node;                  // Returning the Trie Node
}

//***********************************************************

// Free the trienode sequence

//***********************************************************

void Tries_node_free(TrieNode* node) {
    // Free the trienode sequence
    for(int i=0; i<N; i++) {              // Looping through the children
        if (node->children[i] != NULL) {   // If the child exists
            Tries_node_free(node->children[i]); // Free the child
        }
        else {
            continue;           // Else, continue
        }
    }
    free(node);       // Free the node
}

//***********************************************************

// Insert the word into the trie
/*
Function takes a pointer to the root node (topmost node) and inserts a word to the Trie.
The insertion procedure is simple. It iterates through the word character by 
character and evaluates the relative position.

Matching the prefix character by character, and simply initialize a node if it doesn’t exist.

Otherwise, keep moving down the chain, until all matched characters achieved.
*/

//***********************************************************

TrieNode* Tries_node_insert_element(TrieNode* root, char* word) {
    // Inserts the word onto the Trie
    // ASSUMPTION: The word only has lower case characters
    TrieNode* temp = root;      // Temporary pointer to the root

    for (int i=0; word[i] != '\0'; i++) { // Loop through the word
        // Get the relative position in the alphabet list
        int idx = (int) word[i] - 'a';  // Get the relative position in the alphabet list
        if (temp->children[idx] == NULL) {  //  If the corresponding child doesn't exist,
            // If the corresponding child doesn't exist,
            // simply create that child!
            temp->children[idx] = tries_node_construct(word[i]); // Create the child
        }
        else {
            // Do nothing. The node already exists
        }
        // Go down a level, to the child referenced by idx
        // since we have a prefix match
        temp = temp->children[idx]; // Go down a level, to the child referenced by idx
    }
    // At the end of the word, mark this node as the leaf node
    temp->is_leaf = 1; // At the end of the word, mark this node as the leaf node
    return root;    // Return the root

}

//***********************************************************

/*To search for a key in a trie, you start at the root and follow the nodes that 
represent the characters in the key, one by one, until you either reach a node 
that has no children or you find the key that you are looking for. 
If you reach a node that has no children, it means that the key is not present 
in the trie.

For example, suppose you have a trie that stores the words "hello", "help", and "heap".
If you want to search for the key "heap", you would start at the root and 
follow the nodes that represent the characters 'h', 'e', 'a', and 'p' in order.
When you reach the node that represents the character 'p', you would check to see 
if it is marked as the end of a key. If it is, it means that the key "heap" is present 
in the trie. If it is not marked as the end of a key, it means that the key is not 
present in the trie.*/

//***********************************************************

// Search the trie for a word

/* 

Matching the string character by character, using the same prefix matching strategy as above.

Onces reached the end of the chain and haven’t yet found a match, that means that the string does not exist, as a complete prefix match is not done.

For this to return correctly, the pattern of word must exactly match, and after finish matching, we will get leaf node.

*/

//***********************************************************
int Tries_node_search_element(TrieNode* root, char* word)
{
    // Searches for word in the Trie
    TrieNode* temp = root; // Temporary pointer to the root

    for(int i=0; word[i]!='\0'; i++)   //   Loop through the word
    {
        int position = word[i] - 'a';  // Get the relative position in the alphabet list
        if (temp->children[position] == NULL) // If the corresponding child doesn't exist,
            return 0; // Return 0
        temp = temp->children[position]; // Go down a level, to the child referenced by idx
    }
    if (temp != NULL && temp->is_leaf == 1) // If the node is a leaf node, return 1
        return 1;             // If the node is a leaf node, return 1
    return 0;                 // Else, return 0
}
//********************************************************** 

// Checks if there is branching at the last character of word
// and returns the largest position in the word where branching occurs

//***********************************************************

int Divergencing_checking(TrieNode* root, char* word) {
    TrieNode* temp = root; // Temporary pointer to the root
    int len = strlen(word); // Get the length of the word
    if (len == 0)           // If the length of the word is 0,
        return 0;           // return 0

    // We will return the largest index where branching occurs
    int last_index = 0;     // Initialize the last index to 0
    for (int i=0; i < len; i++) {  // Loop through the word
        int position = word[i] - 'a';  // Get the relative position in the alphabet list
        if (temp->children[position]) { // If the corresponding child exists,
            // If a child exists at that position
            // we will check if there exists any other child
            // so that branching occurs
            for (int j=0; j<N; j++) { // Loop through the children
                if (j != position && temp->children[j]) { // If the child exists and it is not the same as the current child,
                    // We've found another child! This is a branch.
                    // Update the branch position
                    last_index = i + 1; // Update the branch position
                    break;    // Break out of the loop
                }
            }
            // Go to the next child in the sequence
            temp = temp->children[position]; // Go down a level, to the child referenced by idx
        }
    }
    return last_index; // Return the last index
}

//***********************************************************

// Function to find the longest common prefix substring of word

//***********************************************************
char* long_prefix_locate(TrieNode* root, char* word) { // Function to find the longest common prefix substring of word

    if (!word || word[0] == '\0') // If the word is empty,
        return NULL;              // return NULL
    // Length of the longest prefix // Length of the longest prefix
    int len = strlen(word);         // Length of the word

    // We initially set the longest prefix as the word itself,
    // and try to back-tracking from the deepst position to
    // a point of divergence, if it exists
    char* longest_prefix = (char*) calloc (len + 1, sizeof(char)); // Allocate memory for the longest prefix
    for (int i=0; word[i] != '\0'; i++)        // Loop through the word
        longest_prefix[i] = word[i];           // Copy the word to the longest prefix
    longest_prefix[len] = '\0';                // Add the null character at the end

    // If there is no branching from the root, this
    // means that we're matching the original string!
    // This is not what we want!
    int branch_idx  = Divergencing_checking(root, longest_prefix) - 1; // Get the index of the last branching
    if (branch_idx >= 0) {  // If there is branching,
        // There is branching, We must update the position
        // to the longest match and update the longest prefix
        // by the branch index length
        longest_prefix[branch_idx] = '\0';  // Add the null character at the end
        longest_prefix = (char*) realloc (longest_prefix, (branch_idx + 1) * sizeof(char)); // Reallocate memory for the longest prefix
    }

    return longest_prefix; // Return the longest prefix
}

//***********************************************************

// Function to check if the prefix match of word and root is a leaf node
// Checks if the prefix match of word and root is a leaf node

//***********************************************************

int is_leaf_node(TrieNode* root, char* word) {
    TrieNode* temp = root;  // Temporary pointer to the root
    for (int i=0; word[i]; i++) {  // Loop through the word
        int position = (int) word[i] - 'a'; // Get the relative position in the alphabet list
        if (temp->children[position]) {   // If the corresponding child exists,
            temp = temp->children[position]; // Go down a level, to the child referenced by idx
        }
    }
    return temp->is_leaf; // Return the is_leaf value of the node
}

//***********************************************************

// Function to delete a word from the trie

/*

First finding the longest match, the algorithm will actually greedily match the original string itself. This is not what we want.

We want the longest match that is NOT the input string. So, we must have a check with another method check_divergence().

This will check if there is any branching from the root to the current position, and return the length of the best match which is NOT the input.

If we are in the bad chain, that corresponds to the original string, then there will be no branching from the point! So this is a good way for us to avoid that nasty point, using check_divergence().

*/

//***********************************************************

TrieNode* tries_node_element_delete(TrieNode* root, char* word) { // Function to delete a word from the trie
    // Will try to delete the word sequence from the Trie only it 
    // ends up in a leaf node
    if (!root)     // If the root is NULL,
        return NULL;  // return NULL
    if (!word || word[0] == '\0') // If the word is empty,
        return root;      // return the root
    // If the node corresponding to the match is not a leaf node,
    // we stop
    if (!is_leaf_node(root, word)) {  // If the node corresponding to the match is not a leaf node,
        return root;                  // we stop
    }
    TrieNode* temp = root;
    // Find the longest prefix string that is not the current word
    char* longest_prefix = long_prefix_locate(root, word); // Find the longest prefix string that is not the current word
    //printf("Longest Prefix = %s\n", longest_prefix);
    if (longest_prefix[0] == '\0') {
        free(longest_prefix); // Free the memory
        return root;  //    return the root
    }
    // Keep track of position in the Trie
    int i;
    for (i=0; longest_prefix[i] != '\0'; i++) {
        int position = (int) longest_prefix[i] - 'a';
        if (temp->children[position] != NULL) {
            // Keep moving to the deepest node in the common prefix
            temp = temp->children[position];
        }
        else {
            // There is no such node. Simply return.
            free(longest_prefix);
            return root;
        }
    }
    // Now, we have reached the deepest common node between
    // the two strings. We need to delete the sequence
    // corresponding to word
    int len = strlen(word);   // Length of the word
    for (; i < len; i++) {
        int position = (int) word[i] - 'a'; // Get the relative position in the alphabet list
        if (temp->children[position]) { 
            // Delete the remaining sequence
            TrieNode* rm_node = temp->children[position]; // Get the node to be deleted
            temp->children[position] = NULL;   // Set the pointer to NULL
            Tries_node_free(rm_node); // Free the memory
        }
    }
    free(longest_prefix);
    return root;
}

//***********************************************************

// Function to print the trie

//***********************************************************
void outputing_tries_elements(TrieNode* root) {
    // Prints the nodes of the trie
    if (!root)   // If the root is NULL,
        return;  // return
    TrieNode* temp = root;  // Temporary pointer to the root
    printf("%c -> ", temp->data); // Print the data
    for (int i=0; i<N; i++) {
        outputing_tries_elements(temp->children[i]);  // Recursively call the function
    }
}

//***********************************************************

void check_element_search(TrieNode* root, char* word) { // Function to check if the word is present in the trie
    printf("Searching for %s: ", word);  // Print the word
    if (Tries_node_search_element(root, word) == 0) // If the word is not present,
        printf("Word not found\n"); // Print Not Found
    else
        printf("Word found\n"); // Else, print Found
}

//***********************************************************

int main() {
    // Driver program for the Trie Data Structure Operations
    TrieNode* root = tries_node_construct('\0');
    root = Tries_node_insert_element(root, "Sesquipedalian");
    root = Tries_node_insert_element(root, "Onomatopoeia");
    root = Tries_node_insert_element(root, "Supercalifragilisticexpialidocious");
    root = Tries_node_insert_element(root, "antediluvian");
    root = Tries_node_insert_element(root, "apocryphal");

    printf("\n");
    printf("------------------------------------------------------");
    printf("\n");
    check_element_search(root, "circumlocution");
    check_element_search(root, "antediluvian");
    check_element_search(root, "Supercalifragilistice");
    check_element_search(root, "Onomatopoeia");
    check_element_search(root, "apocryphal");
    check_element_search(root, "contravene");
    check_element_search(root, "SESQUIPEDALIAN");
    printf("\n");
    printf("------------------------------------------------------");
    printf("\n");
    outputing_tries_elements(root);
    printf("\n");
    printf("------------------------------------------------------");
    printf("\n");
    printf("\n");
    root = tries_node_element_delete(root, "apocryphal");
    printf("Deleted'apocryphal'\n");
    outputing_tries_elements(root);
    printf("\n");
    root = tries_node_element_delete(root, "antediluvian");
    printf("Deleted 'antediluvian'\n");
    outputing_tries_elements(root);
    printf("\n");
    printf("------------------------------------------------------");
    printf("\n");

    Tries_node_free(root);
    return 0;
}


//**********************************************************

// END OF PROGRAM: CODE

//***********************************************************