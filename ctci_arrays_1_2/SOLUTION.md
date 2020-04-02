# Solution
Simple brute-force solution is to check if any other character is the same as selected one. For every character. It means that this solution have complexity of **O(n^2)**.  

To improve this solution one can introduce associative array which keeps track of all occuring character. It has O(1) for insertion and O(1) for retrieval of value. We need to do those operations for all N characters in string, so complexity of whole algorithm is O(N*1*1) which is O(N).  

# Solution without additional Data Structures
Brute-force solution is the one without any additional data structures. Neverthless it is slow algorithm. We can improve it by firstly, apply sorting to string, which has complexity O(N*logN) and secondly, check if there are at least 2 consecutive same characters in sorted string. Complexity of this solution is O(N*logN + N) which is O(N*logN)  
