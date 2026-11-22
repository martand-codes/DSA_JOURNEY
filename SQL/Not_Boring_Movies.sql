/*
------------------------------------------------------------
Problem : Not Boring Movies (LeetCode 620)

Pattern : SQL / Filtering / WHERE Clause /
          Modulo Operator / Sorting

Time Complexity :
Filtering : O(N)
Sorting  : O(N log N)

Space Complexity : O(N) worst case for sorting

Idea:
Retrieve all movies that satisfy the given filtering
conditions and arrange them in descending order
of their ratings.

- Use SELECT * to retrieve all columns from the Cinema
  table.
- Use the WHERE clause to filter movies:
  - Exclude movies whose description is 'boring'
    using description != 'boring'.
  - Select only movies with odd IDs using
    id % 2 != 0.
- Combine both conditions using the AND operator
  so that both conditions must be satisfied.
- Use ORDER BY rating DESC to arrange the qualifying
  movies from highest rating to lowest rating.

Finally:
- Return all matching movie records sorted by
  rating in descending order.

Key Insight:
The modulo operator (%) calculates the remainder
after division.

For an odd integer:
id % 2 != 0

For an even integer:
id % 2 == 0

The != operator excludes movies with the description
'boring'.

The AND operator ensures that a movie must satisfy
both filtering conditions.

ORDER BY with DESC sorts the results in descending
order based on rating.

N represents the total number of rows in the Cinema
table.

Filtering requires O(N) time because every row must
be evaluated.

Sorting the qualifying rows requires O(N log N)
time in the worst case.

The database may use additional memory for sorting,
requiring O(N) space in the worst case.

------------------------------------------------------------
*/


SELECT *
FROM Cinema
WHERE Cinema.description != 'boring' AND Cinema.id % 2 != 0
ORDER BY rating desc;