SELECT distinct(name) FROM movies, stars, people
WHERE movies.id = stars.movie_id
AND stars.person_id = people.id
AND name = "Johnny Depp" AND "Helena Bonhman Carter";