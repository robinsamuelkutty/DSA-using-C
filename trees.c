/*
root- topmost node
parent - node which connects to the child
child - node which is connected by another node is its child!
siblings - nodes belonging to the same parent
ancestors/descendents.

leaf node/external node - node having no children /last nodes
internal node - node with atleast one child.

depth - no. of edges from root to that node.
height- no of edges from that node to the deepest leaf.

degree of a node = no of direct children of that node.

degree of a tree is the highest degree of a node among all the nodes present in the tree

binary tree is a tree of degree 2 . i.e. nodes can have 0,1,2 children.
n nodes ->n-1 edges.

Types of Binary trees-
1.Full or strict Binary tree-All nodes have either 0 or 2 children.
2.perfect binary tree- internal nodes have 2 children+all leaf nodes are on same level.
3.complete binary tree- all levels are completely filled except possibly the last level.+last level must have
its keys as left as possible
4.degenerate tree - every parent node has exactly one child.
5.skewed tree - all child are either on left(left skewed) or right(right skewed). 
*/