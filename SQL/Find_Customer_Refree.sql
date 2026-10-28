/*
------------------------------------------------------------
Problem : Find Customer Referee (LeetCode 584)
Pattern : SQL + Filtering + NULL Handling

Time Complexity : O(N)
Space Complexity : O(1) auxiliary space

Idea:
- Retrieve the name column from the Customer table.
- Exclude customers whose referee_id is 2.
- Include customers whose referee_id is NULL.
- Use the OR operator to satisfy either condition.

Key Insight:
SQL NULL values cannot be compared using ordinary
comparison operators such as = or !=.

Therefore, use:

    referee_id != 2 OR referee_id IS NULL

The IS NULL condition ensures that customers without
a referee are included in the result.

------------------------------------------------------------
*/

SELECT name FROM Customer
WHERE referee_id != 2 OR referee_id IS NULL;