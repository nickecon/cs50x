SELECT distinct(name) FROM movies, ratings, directors, people
WHERE movies.id = directors.movie_id
AND movies.id = ratings.movie_id
AND directors.person_id = people.id
AND rating < 8.9;