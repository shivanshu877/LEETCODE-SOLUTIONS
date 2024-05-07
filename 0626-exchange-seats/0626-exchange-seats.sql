select s.id , 
  CASE
  WHEN id = (select max(id) from seat) AND mod( (select count(*) from seat ), 2) = 1    THEN s.student 
  WHEN mod(id,2) = 1 THEN ( select student from seat where id = s.id+1) 
  ELSE ( select student from seat where id = s.id-1)
  END as student
  FROM seat s
  ORDER BY id 
  ;
   