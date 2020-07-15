// 1.
// Gn === >>> number of labeled graphs with n vertices
// Gn = 2 ^ ( n(n−1)2 )

// 2.
// Cn === >>> No. of connected graph with n vertices
// Cn = Gn − (1/n) ∑ (k = 1 to n−1) of ( k * (ncr(n , k)) * Ck * Gn−k )


// 3.
// Labeled graphs with k connected components
// D[i][j] = the number of labeled graphs with i vertices and j components
// - for each i≤n and j≤k
// D[n][k] = ∑ (s = 1 to n) of ( (ncr(n - 1 , s - 1)) * Cs * D[n−s][k−1] )