/*
------------------------------------------------------------
Problem : Replace Employee ID With The Unique Identifier
          (LeetCode 1378)
Pattern : SQL + LEFT JOIN

Time Complexity : O(N + M) with appropriate hash-based
                  join execution
Space Complexity : O(N + M) for the join operation
                    (execution-plan dependent)

Idea:
- Retrieve the employee name from the Employees table.
- Retrieve the corresponding unique_id from EmployeeUNI.
- Use a LEFT JOIN to combine both tables using employee ID.
- Match records where A.id = B.id.
- Return the employee name along with their unique ID.

Key Insight:
LEFT JOIN preserves every record from the left table
(Employees), even when no matching record exists in
EmployeeUNI.

If an employee has no corresponding unique ID,
the unique_id column returns NULL.

    Employees A
    LEFT JOIN EmployeeUNI B
    ON A.id = B.id

This ensures that no employee is excluded from the result.

------------------------------------------------------------
*/

SELECT A.name, B.unique_id
FROM Employees A 
LEFT JOIN EmployeeUNI B
ON A.id = B.id;