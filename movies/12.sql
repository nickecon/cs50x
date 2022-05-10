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