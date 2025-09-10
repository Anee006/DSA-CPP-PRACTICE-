//SUBTREE OF ANOTHER TREE (LeetCode 572)

//Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of 
//subRoot and false otherwise.


//LOGIC:
//1. find the root of subtree (i.e subroot) in the main tree.
//2. If subroot exists in the main tree then check for the rest of the part of the subroot i.e, check whether both subroots are identical or not
// (use the logic of "isSame Tree" Q to check whether subroot we found inside main tree and the original subroot are identical)

//first check if root (of main tree) = subroot, then try to find subroot in the left subtree and then try finding it in right sub tree.
