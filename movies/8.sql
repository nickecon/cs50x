SELECT name FROM movies, stars, people
WHERE movie.id = stars.move_id
AND stars.person_id = people.id and title = "Toy Story";