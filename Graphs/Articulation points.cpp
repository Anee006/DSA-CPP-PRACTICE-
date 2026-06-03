// Using Tarjan's algo for finding Articulation point
// A node is an articulation point if removing it increases the number of connected components.

// Conditions for Articulation Point:
// For a node u:

// Case 1: Root node of DFS
// If root has more than 1 child: children > 1 -> u is articulation point.

// Case 2: Non-root node
// If: low[child] >= disc[u] -> u is articulation point.