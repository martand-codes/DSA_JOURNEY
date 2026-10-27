/*
------------------------------------------------------------
Problem : Recyclable and Low Fat Products (LeetCode 1757)
Pattern : SQL + Filtering (WHERE Clause)

Time Complexity : O(N)
Space Complexity : O(1) auxiliary space

Idea:
- Retrieve the product_id column from the PRODUCTS table.
- Filter rows where low_fats is 'Y'.
- Also require recyclable to be 'Y'.
- Return the product IDs satisfying both conditions.

Key Insight:
The AND operator ensures that both conditions must be
true for a row to appear in the result.

    low_fats = 'Y' AND recyclable = 'Y'

Only products that are both low-fat and recyclable
are included in the output.

------------------------------------------------------------
*/


SELECT product_id
FROM PRODUCTS
WHERE low_fats = 'Y' AND recyclable = 'Y';