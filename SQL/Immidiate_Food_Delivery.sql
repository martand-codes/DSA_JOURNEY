/*
------------------------------------------------------------
Problem : Immediate Food Delivery II (LeetCode 1174)
Pattern : SQL / Subquery / GROUP BY / MIN() / Conditional
          Aggregation / AVG() / Row Comparison / Percentage Calculation

Time Complexity :
Conceptually O(N) for scanning the Delivery table to identify
each customer's first order and calculate the final percentage.

Space Complexity :
Depends on the database execution plan. The GROUP BY operation
and subquery may require additional memory for intermediate
results.

Idea:
1. Identify the first order placed by every customer.
   Use a subquery with GROUP BY customer_id and MIN(order_date):

       SELECT customer_id, MIN(order_date)
       FROM Delivery
       GROUP BY customer_id

2. Use the tuple comparison:

       (customer_id, order_date) IN (...)

   to filter the Delivery table and retain only the first
   order of each customer.

3. For every customer's first order, check whether the
   order_date is equal to customer_pref_delivery_date.

   - If equal, the order is immediate. Return 1.
   - Otherwise, return 0.

4. Use AVG() over the resulting 1s and 0s to calculate
   the proportion of immediate orders.

5. Multiply the average by 100 to convert the proportion
   into a percentage.

6. Use ROUND(..., 2) to round the final percentage to
   two decimal places.

Key Insight:
The problem asks for the percentage of customers whose
first order was an immediate order, not the percentage
across all delivery records.

The subquery ensures that only the first order of each
customer is considered.

Why AVG(CASE WHEN ...)?
Conditional aggregation allows us to calculate the percentage
without explicitly counting immediate and total orders.

For example:

    AVG(1, 0, 1, 1) = 0.75

    Immediate Percentage = 0.75 * 100 = 75.00

Important PostgreSQL Concepts:
- MIN(order_date) identifies each customer's earliest order.
- GROUP BY customer_id creates one first-order date per customer.
- Row-value comparison checks customer_id and order_date
  together against the subquery result.
- CASE WHEN converts the immediate-order condition into
  numeric 1 or 0 values.
- AVG() calculates the proportion of immediate orders.
- ROUND(..., 2) formats the final percentage.

Complexity Variables:
N = Total number of rows in the Delivery table.
C = Number of distinct customers.

Actual query performance depends on indexes, join strategy,
subquery execution, database statistics, and the execution plan.

------------------------------------------------------------
*/

SELECT ROUND(AVG(CASE WHEN order_date = customer_pref_delivery_date THEN 1
                ELSE 0 END)*100, 2) AS immediate_percentage
FROM Delivery
WHERE (customer_id, order_date) IN (
                SELECT customer_id,
                    MIN(order_date)
                    FROM Delivery
                    GROUP BY customer_id
);