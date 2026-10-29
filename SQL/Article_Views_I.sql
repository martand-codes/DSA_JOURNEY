/*
------------------------------------------------------------
Problem : Article Views I (LeetCode 1148)
Pattern : SQL + Filtering + DISTINCT + Sorting

Time Complexity : O(N log N) in the general case
Space Complexity : O(N) in the general case

Idea:
- Retrieve author_id from the Views table.
- Filter rows where viewer_id equals author_id, meaning
  an author viewed their own article.
- Rename author_id to id using AS.
- Use DISTINCT to eliminate duplicate author IDs.
- Sort the resulting IDs in ascending order.

Key Insight:
An author may view their own articles multiple times.
DISTINCT ensures each qualifying author appears only once.

    WHERE viewer_id = author_id

identifies self-views, while:

    ORDER BY id ASC

returns the IDs in ascending order.

------------------------------------------------------------
*/

SELECT DISTINCT author_id AS id
FROM Views
WHERE viewer_id = author_id
ORDER BY id  ASC;