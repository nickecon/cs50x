SELECT distinct(name) FROM movies, stars, people
WHERE movies.id = stars.movie_id
AND stars.person_id = people.id
AND year = 2004 ORDER BY birth;

SELECT title FROM movies, stars, people
WHERE movies.id = stars.movie_id
AND stars.person_id = people.id
AND name = "Helena Bonham Carter"
AND id = (SELECT id FROM movies, stars, people
WHERE movies.id = stars.movie_id
AND stars.person_id = people.id
AND name = "Johnny Depp");