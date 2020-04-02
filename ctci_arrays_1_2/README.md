# Check permutation
**Problem definition**: Given two strings, write a method to decide if one is a permutation of the other  

# Input and Output format  
Input:
  string1 - sequence of characters (assume ASCII encoding)
  string2 - sequence of characters (assume ASCII encoding)
Output: true or false  

# Example
string1 = "straw"  
string2 = "artsw"  
isPermutation(string1, string2) = true  

string1 = "staws"  
string2 = "seqfw"  
unique(string1, string2) = false  

# Clarifications
Should check be performed case sensitive or not?  
Are whitespaces significant?  

# How to run
Java code should be compiled using:
```java
java myClass.java
```
And run with `-ea` flag (to enable assertions) like in example below:
```java
java -ea MyClass
```
