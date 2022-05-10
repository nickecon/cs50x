SELECT title FROM movies, stars, people
WHERE movies.id = stars.movie_id
AND stars.person_id = people.id
AND name = "Helena Bonham Carter"
AND
(SELECT title FROM movies, stars, people
WHERE movies.id = stars.movie_id
AND stars.person_id = people.id
AND name = "Johnny Depp");

SELECT movies.title
FROM  movies, people
JOIN stars
ON movies.id = stars.movie_id
AND people.id = stars.person_id
WHERE people.name = "Helena Bonham Carter"
 AND stars.movie_id IN
 (SELECT movies.title
FROM movies, people
JOIN stars
ON movies.id = stars.movie_id
AND people.id = stars.person_id
WHERE people.name = "Johnny Depp");