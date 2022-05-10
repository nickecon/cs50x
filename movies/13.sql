SELECT name FROM movies, stars, people
WHERE movies.id = stars.movie_id
AND stars.person_id = people.id
AND title IN (SELECT title FROM movies, stars, people
WHERE movies.id = stars.movie_id
AND stars.person_id = people.id
AND name = "Kevin Bacon"
AND birth = 1958);