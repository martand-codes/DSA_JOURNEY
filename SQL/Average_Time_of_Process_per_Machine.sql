/*
------------------------------------------------------------
Problem : Average Time of Process per Machine (LeetCode #1661)
Pattern : SQL + SELF JOIN + GROUP BY + AVG Aggregation

Time Complexity : O(N) expected with hash-based join
Space Complexity : O(N) for the join/aggregation operations (execution-plan dependent)

Idea:
- Join the Activity table with itself using machine_id and process_id.
- Use aliases starts and ends to distinguish start and end records.
- Filter for start records in the first alias and end records in the second.
- Subtract start timestamp from end timestamp to calculate each process duration.
- Group by machine_id and calculate the average processing time.
- Round the result to 3 decimal places.

Key Insight:
- A SELF JOIN pairs the start and end records belonging to the same process.
- AVG() calculates the average duration for each machine.
- ::numeric ensures the value can be rounded to the required decimal precision.

------------------------------------------------------------
*/

SELECT 
    starts.machine_id,
    ROUND(AVG(ends.timestamp - starts.timestamp)::numeric, 3) AS processing_time
FROM Activity starts
JOIN Activity ends 
    ON starts.machine_id = ends.machine_id 
    AND starts.process_id = ends.process_id
WHERE starts.activity_type = 'start' 
  AND ends.activity_type = 'end'
GROUP BY starts.machine_id;