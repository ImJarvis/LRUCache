# LRUCache
LRU Cache implementation in C++

This repo is my attempt towards implementing the LRU cache in C++.
Here I have implemented it using two different apporach. First implentation is very raw one, where I have implemented my own Double Linked list while in the second one I have used 
STL list for the same.

The basic requirement with LRU is that they give constant time O(1) for both put() and get(). And if the size goes out of bound it should simply remove the least recently used elemnt
in O(1) time and put the new one at the front. So definitely we need a HashMap for constant time lookup but that doesnt provide us update and delete in constant time. So for that
we will use Double Linked List. Since Double Link list gives O(1) time complexity with updation and delete.

I am using a hashmap to store the <Key> and the <address> as a pair. And finally list will also store pair of KEY and VALUE.
