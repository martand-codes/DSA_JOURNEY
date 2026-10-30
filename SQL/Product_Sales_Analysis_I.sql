/*
------------------------------------------------------------
Problem : Product Sales Analysis I (LeetCode 1068)
Pattern : SQL + INNER JOIN

Time Complexity : O(N + M) with appropriate hash-based
                  join execution
Space Complexity : O(N + M) for the join operation
                    (execution-plan dependent)

Idea:
- Retrieve product_name from the Product table.
- Retrieve year and price from the Sales table.
- Use INNER JOIN to combine both tables using product_id.
- Match records where A.product_id = B.product_id.
- Return the product name, sales year, and price.

Key Insight:
INNER JOIN returns only records that have matching
product IDs in both tables.

    Sales A
    INNER JOIN Product B
    ON A.product_id = B.product_id

The Product table provides product details, while
the Sales table provides transaction information.

A product can have multiple sales records across
different years, so its name may appear multiple times.

------------------------------------------------------------
*/


SELECT B.product_name, A.year, A.price 
FROM Sales A
INNER JOIN Product B
ON A.product_id = B.product_id;