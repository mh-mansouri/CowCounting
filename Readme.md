This challenge starts with a field, a matrix of NxN, where M cows are scattered randomly. Each cow has its number, which is assumed to be the cow's identity. This project aims to fulfill two requested tasks: 1) the number of cows in the corners and 2) the number of cows that are neighbors.
The program receives the field size, N, and number of cows, M, and then randomly distributes cows on the NxN size field. The cows also are numbered randomly. It means that cow number 1 might be much closer to the down button than cow number M. It should be noted that M is always less than or equal to NxN.

EX: 

Please enter the field size: 3
Please enter the cow number: 5


The field size is: 3

The cow no is: 5

Initializing the cowplace array with all zero

Distribute the cows randomly

Diplay the cows on the field
3       X       4
X       2       5
X       X       1


No. of cows in the corners are: 3
No. of adjacent cows are: 6

It should be noted that the program is not a forward counter but a backward counter. It means if cow A has a neighbor on its right block, cow B, and cow B has a neighbor on his left block, cow A, there are two cows in each neighborhood.

The program is designed and developed using the CodeBlocks IDE; however, you can build and run it using any C/C++ compiler. 

