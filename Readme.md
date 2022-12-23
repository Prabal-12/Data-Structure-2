# DS Project - Tries

## What has been implemented: Tries Application using Tries Data Structure
Trie, also known aa a digital tree or prefix tree, is a type of k-ary search tree, a tree data structure used for locating specific keys from within a set. These keys are often strings, with links between nodes defined not by the entire key but by individual characters. To access a key (to recover its value, change it, or remove it), the trie is traversed depth-first, following the links between nodes, representing each character in the key.

## Why Tries?
Observe that all the tree structures we covered in the class focus on the storage of integers or, more generally, numerical values. Tries are useful data structures when it comes to the storage of strings which can be visualised as a tree. Hence, it is worth taking a look at. They represent the “Retrieval” of data. Tries also have several advantages over Hash Tables.

It has a wide variety of applications in data compression, computational biology, the longest prefix-matching algorithm used for routing tables for IP addresses, implementation of the dictionary, pattern searching, storing/querying XML documents, etc

## Applications of Tries
1. Conduct Search Operations 
2. Conduct insert Operations
3. Conduct Delete Operations 

## Instructions to run the code 
Step 1: Input words to the Tries structure. Add n numbers of words by copy-pasting function (root = Tries_node_insert_element(root, "WORD");) for every word that you want to add.

Step 2: Check function by inputting words which you need to check whether those exist in tries by using function : (check_element_search(root, "WORD");). For every word - copy-paste it and it will individual result for every word.

Step 3: Check root = tries_node_element_delete(root, "Word"); For every word - copy-paste it and it will individual result for every word.


## How to implement a Trie Data Structure?
Create a root node with the help of TrieNode() constructor.
Store a collection of strings that have to be inserted in the trie in a vector of strings say, arr.
Inserting all strings in Trie with the help of the insert() function,
Search strings with the help of search() function.


## How your code has been tested 
Step 1 : Preparing the Node by add data to the nodes in tries Data structure form 

    root = Tries_node_insert_element(root, "Sesquipedalian");
    root = Tries_node_insert_element(root, "Onomatopoeia");
    root = Tries_node_insert_element(root, "Supercalifragilisticexpialidocious");
    root = Tries_node_insert_element(root, "antediluvian");
    root = Tries_node_insert_element(root, "apocryphal");

    So, Tries data structure has data about 5 words from the dictionary which has been added to the Node using Tries_node_insert_element function 

Step 2 : Checking All functions using just to final function to see if the final result to as per what is desired 

    Input the word to be searched in the nodes in the function (check_element_search) which works on condition based on another function (Tries_node_search_element). If the output for check_element_fucntion is right, thats mean - Other function are also correctly working and thus even the final answer is right 

    I have 7 test case 

        check_element_search(root, "circumlocution"); // Word not present case
        check_element_search(root, "antediluvian"); // Word present case
        check_element_search(root, "Supercalifragilistice"); // half of the word is used
        check_element_search(root, "Onomatopoeia"); // Word present case
        check_element_search(root, "apocryphal"); // Word present case
        check_element_search(root, "contravene"); // Word not present case
        check_element_search(root, "SESQUIPEDALIAN"); // Capital letters of the word that is present 

    Result : 

        Searching for circumlocution: Word not found
        Searching for antediluvian: Word found
        Searching for Supercalifragilistice: Word not found
        Searching for Onomatopoeia: Word found
        Searching for apocryphal: Word found
        Searching for contravene: Word not found
        Searching for SESQUIPEDALIAN: Word not found

Step3 : Checking the delete function on tries 

    Take intial (root) value which has all elements 
    using functin (tries_node_element_delete) to remove the given word from root

    Before -  -> a -> n -> t -> e -> d -> i -> l -> u -> v -> i -> a -> n -> p -> o -> c -> r -> y -> p -> h -> a -> l ->
    root = tries_node_element_delete(root, "apocryphal");

    After -  -> a -> n -> t -> e -> d -> i -> l -> u -> v -> i -> a -> n -> 

Its producing right results.

Hence, it would be concluded that the program is working correctly.

## Time Complexity of individul function:
1. Tries_node_search_element - O(n) -> N
2. Tries_node_insert_element - O(n) -> N
3. tries_node_element_delete - O(a*n) -> a

    n is the length of the input word





