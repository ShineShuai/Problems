Here contains some problems related to the probabilites.

##### Problem 1 : Black/White Balls

There are 100 white balls and 100 black balls in a bucket. Repeat the following actions:
- Randomly take 2 balls out from the bucket every time.
  - Put 1 black ball into the bucket, if their colors are same.
  - Put 1 white ball into the bucket, if their colors are different.

What is the probability of that the only 1 black ball remains in the bucket?

##### Problem 2 : Random Number Generator

1. Consider a random function f() that returns 0 with a probability of 60% and 1 with a probability of 40%. Implement a function g() using f() such that g() returns 0 and 1 with a probability of 50%.

2. Write a function to generate a random integer between 0 and 4, given a function that generates a random integer between 0 and 2; namely, implement rand5() using rand3().

 Conversely, implement rand3() using rand5().


##### Problem 3 : Reservoir Sampling

Imagine a really large stream of data elements. The size of the stream is unknown in advanced and the indices of data elements are not available. Assume that the stream is accessible only once. How to efficiently return a random sample of m elements evenly distributed from the original stream?

##### Problem 4 : Shuffling

Given an array, provide a method that randomly and efficiently shuffles the elements of the array.
