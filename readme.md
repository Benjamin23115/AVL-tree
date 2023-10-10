Implement an AVL Tree. Your tree should be a Binary Search tree that is self-balancing. It should use the AVL algorithm as discussed in class, and should be implemented as a template class with the following public methods:

insert - Takes an item of the templated type, and inserts it into the AVL tree, re-balancing if necessary (according to the AVL Tree algorithm). This method should throw an exception if the user attempts to insert a duplicate item.
search - Takes an item of the templated type, and returns the found item of the templated type, or throws an exception if the item is not found
remove - Takes an item of the templated type, and remove the item if found. This method should us the "delete by copy" method for removing items.
count - Returns the number of items that are in the tree.
Your constructor for the class should take a function pointer as a parameter that points to a function that does a comparison between two items. The comparison function should take two items of the type being stored, and should return a -1 if the first item is less than the second, a 0 if they are equal, and a 1 if the first item is larger than the second. You can find out more about function pointers hereLinks to an external site..

Include a driver program that demonstrates inserting items in to the tree and exercises each of the cases for insertion and deletion discussed in class.

Rubric
AVL Tree
AVL Tree
Criteria Ratings Pts
This criterion is linked to a Learning OutcomeInsert method
5 pts
Full Marks
Properly detects cases were remediation is necessary and correctly performs the mitigation
3 pts
Partially correct
Inserts item and at least partially does the correct mediation, or detects the cases correctly, but doesn't do the proper mitigation.
1 pts
Insert works
Inserts the item at the correct location in the tree
0 pts
No Marks
5 pts
This criterion is linked to a Learning OutcomeSearch method
5 pts
Full Marks
Method takes the correct type of item and returns the found item or throws an exception if not found.
3 pts
Search works, but doesn't throw exception
1 pts
Search method doesn't take the correct type or returns the wrong type
0 pts
No Marks
5 pts
This criterion is linked to a Learning OutcomeRemove method
3 pts
Full Marks
Remove method takes a parameter of the templated type and correctly implements the delete by copy for removing the item
0 pts
No Marks
3 pts
This criterion is linked to a Learning OutcomeCount method
2 pts
Full Marks
0 pts
No Marks
2 pts
This criterion is linked to a Learning OutcomeConstructor
5 pts
Full Marks
Constructor takes a comparison method as a function pointer parameter.
1 pts
Default constructor
0 pts
No Marks
5 pts
This criterion is linked to a Learning OutcomeCompiles and runs
3 pts
Full Marks
2 pts
Compiles but has runtime error or segmentation fault
0 pts
No Marks
3 pts
This criterion is linked to a Learning OutcomeDriver program
7 pts
Full Marks
Driver program exercises all the insertion and deletion cases, including symmetric cases
4 pts
Half
Driver program exercises half of the insertion and deletion cases.
2 pts
Quarter
Driver program exercises 1/4 of the cases.
0 pts
No Marks
7 pts
Total Points: 30
