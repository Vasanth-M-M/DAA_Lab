# DAA Lab - Week 1 Assignment
**Student Name:** M M Vasanth
**Reg No:** CH.SC.U4CSE24227

---

## 1. Sum of First n Natural Numbers
**Interpretation:**
To solve this, I used a standard `for` loop that iterates from `1` to `n`. In each iteration, I added the current number `i` to a cumulative `sum` variable. This approach has a time complexity of O(n) because the loop runs exactly n times.

---

## 2. Sum of Squares of First n Natural Numbers
**Interpretation:**
The logic here is similar to the first problem. I iterated from `1` to `n`, but instead of adding `i` directly, I calculated the square (`i * i`) and added that result to the `sum`. This effectively calculates the mathematical summation Σ(i^2).

---

## 3. Sum of Cubes of First n Natural Numbers
**Interpretation:**
For this problem, I modified the accumulation logic to add the cube of the current index (`i * i * i`) to the `sum` variable. The loop still runs `n` times, maintaining linear time complexity O(n).

---

## 4. Factorial using Recursive Function
**Interpretation:**
I used the concept of Recursion where the function calls itself.
1. **Base Case:** If `n` is 0 or 1, return 1.
2. **Recursive Step:** Return `n * factorial(n-1)`.
This creates a stack of calls until the base case is reached, then unwinds to calculate the final product.

---

## 5. Transpose of a 3x3 Matrix
**Interpretation:**
A transpose flips a matrix over its diagonal. I used a nested `for` loop to traverse the 2D array. The core logic swaps the indices: `transpose[j][i] = original[i][j]`. This effectively turns the rows of the original matrix into the columns of the new matrix.

---

## 6. Fibonacci Series
**Interpretation:**
The Fibonacci series generates the next number by adding the previous two. I used two variables `t1` and `t2` to store the last two terms. Inside the loop, I calculated `nextTerm = t1 + t2`, printed `t1`, and then shifted the values (`t1` becomes `t2`, `t2` becomes `nextTerm`) for the next iteration.
