SELECT distinct(name) FROM movies, directors, people
WHERE movies.id = directors.movie_id
AND directors.person_id = people.id;