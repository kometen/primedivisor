primedivisor
============

Find prime divisors for a number. It's for another program I'm writing that find primenumbers.
So in an effort to optimize it I wanted to get the prime divisors for any given squareroot.

Example:

In order to check whether a number is prime you only need to loop through two up to the
squareroot of that number, cast it to an integer.

The first optimization is to start the loop at three for any number greater than three.

Is 101 a prime? The squareroot is 10. So the loop will be from 3 to 10, including those two.
If the modulus on 101 and any given number between 3 and 10 is zero, it's not a prime.

    101 % 3 = 2
    101 % 4 = 1
    101 % 5 = 1
    101 % 6 = 5
    101 % 7 = 3
    101 % 8 = 5
    101 % 9 = 2
    101 % 10 = 1

Yes, it's a prime.

The second optimization is to only check for odd numbers, which is done by adding two to each
step starting with three. So 3, 5, 7, 9 and so forth.

How about 111? Is that a prime? Squareroot is still 10.

    111 % 3 = 0
    111 % 5 = 1
    111 % 7 = 6
    111 % 9 = 3

No, it's not a prime since 111 is divisible by 3.

The reason I wrote this program, which many others have done before me, was to get more into
programming. I originally tried to write it in Apple's Swift, but I got some strange errors
when looping and I have always been fascinated by C++ but done little in this language.

This book is what got me started. http://www.springer.com/mathematics/book/978-3-319-05653-1
