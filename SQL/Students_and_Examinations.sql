/*
------------------------------------------------------------
Problem : Students and Examinations (LeetCode #1280)
Pattern : SQL + CROSS JOIN + LEFT JOIN + GROUP BY + COUNT

Time Complexity : Execution-plan dependent; typically O(S × U + E)
                  where S = students, U = subjects, E = examinations.
Space Complexity : Execution-plan dependent; intermediate result
                   can contain up to S × U rows.

Idea:
- Use CROSS JOIN between Students and Subjects to generate
  every possible student-subject combination.
- Use LEFT JOIN with Examinations to match attended exams
  for each student and subject.
- COUNT(C.subject_name) to count the matching examination records.
- GROUP BY student_id, student_name, and subject_name
  to calculate attendance for each combination.
- ORDER BY student_id and subject_name for the required output.

Key Insight:
- CROSS JOIN creates the Cartesian product:
  Every student is paired with every subject.
- LEFT JOIN preserves combinations even when a student
  has not attended an exam for that subject.
- COUNT(column) ignores NULL values, so combinations
  without examinations correctly return 0.
- COUNT(C.subject_name) is important here:
  COUNT(*) would incorrectly count unmatched LEFT JOIN rows.

------------------------------------------------------------
*/

SELECT 
    A.student_id, 
    A.student_name, 
    B.subject_name,
COUNT(C.subject_name) AS attended_exams
FROM Students A
CROSS JOIN Subjects B
LEFT JOIN Examinations C
ON A.student_id = C.student_id
AND B.subject_name = C.subject_name
GROUP BY
    A.student_id,
    A.student_name,
    B.subject_name
ORDER BY
    A.student_id, 
    B.subject_name;