-- write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.

SELECT DISTINCT people.name
FROM people
JOIN stars  AS  stars_kevin   ON people.id = stars_kevin.person_id
JOIN movies AS  movies_kevin  ON stars_kevin.movie_id = movies_kevin.id
JOIN stars  AS  stars_others  ON movies_kevin.id = stars_others.movie_id
JOIN people AS  people_others ON stars_others.person_id = people_others.id
WHERE people_others.name = 'Kevin Bacon';

SELECT DISTINCT name FROM people
WHERE id IN (SELECT person_id FROM stars   -- give all the person_id who starred in the movie_id where Kevin Bacon starred
             WHERE movie_id IN (SELECT movie_id FROM stars   -- give all the movie_id where Kevin Bacon starred
                                WHERE person_id IN (SELECT id FROM people   -- give id of Kevin Bacon
                                                    WHERE name = 'Kevin Bacon')));

