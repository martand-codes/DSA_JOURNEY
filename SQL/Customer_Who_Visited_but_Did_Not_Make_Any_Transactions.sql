/*
------------------------------------------------------------
Problem : Visits Without Transactions (LeetCode 1581)
Pattern : SQL + LEFT JOIN + NULL Filtering + GROUP BY

Time Complexity : O(V + T) with appropriate hash-based
                  join execution
Space Complexity : O(V + T) for the join operation
                    (execution-plan dependent)

Idea:
- Start with the Visits table.
- Perform a LEFT JOIN with Transactions using visit_id.
- Filter records where transaction_id IS NULL.
  These represent visits that had no transaction.
- Group the remaining records by customer_id.
- Count the number of visits for each customer.
- Return customer_id and the count of visits without
  transactions.

Key Insight:
LEFT JOIN preserves all visits, even when no matching
transaction exists.

When a visit has no corresponding transaction, the
transaction_id from the Transactions table becomes NULL.

    WHERE B.transaction_id IS NULL

identifies visits without transactions.

GROUP BY customer_id groups these visits by customer,
while COUNT(A.visit_id) counts their individual visits.

------------------------------------------------------------
*/

SELECT A.customer_id, COUNT(A.visit_id) AS count_no_trans
FROM Visits A
LEFT JOIN Transactions B
ON A.visit_id = B.visit_id
WHERE B.transaction_id IS NULL
GROUP BY A.customer_id;