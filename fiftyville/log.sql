-- Keep a log of any SQL queries you execute as you solve the mystery
--July 28,2021 (7/28/2021) , Humphrey Street

--check crime scene
--SELECT * FROM crime_scene_reports;

--check bakery security logs
--SELECT * FROM bakery_security_logs;

--check people & total number of initial suspects
--SELECT * FROM people; COUNT = 200

--start checking the license plates of day crime occured (failed to find connections)
--SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28
--UNION
--SELECT license plate IN people ORDER BY lincese_plate;

--join bakery logs w/ people and license plates
--SELECT * FROM bakery_security_logs JOIN people ON bakery_security_logs.license_plate = people.license_plate;

--grab count of individuals who were at bakery on the date of crime
--SELECT COUNT(*) FROM bakery_security_logs JOIN people ON bakery_security_logs.license_plate = people.license_plate WHERE month = 7 and day = 28; COUNT = 74 (37 individual persons)

--same as above , different order
--SELECT * FROM bakery_security_logs JOIN people ON bakery_security_logs.license_plate = people.license_plate WHERE month = 7 and day = 28 ORDER BY license_plate;

--failed code
--SELECT * FROM passengers JOIN people ON passengers.passport_number = people.passport_number JOIN people ON bakery_security_logs.license_plate = people.license_plate WHERE month = 7 and day = 28;

--cross check passengers with the 37 from above, brought back one passport number
--SELECT * FROM passengers WHERE passport_number = (SELECT passport_number FROM bakery_security_logs JOIN people ON bakery_security_logs.license_plate = people.license_plate WHERE month = 7 and day = 28);

--check info of passport number , alice id:809194 , phone number : (031) 555-9915
--SELECT * FROM people WHERE passport_number = 1679711307;

--check flights from passport number, flight 16,(seat 3A) & flight 52,(seat 5B)
--SELECT * FROM passengers WHERE passport_number = 1679711307;

--check flights
--SELECT * FROM flights WHERE id = 16; (origin, 8),(dest, 2)
--SELECT * FROM flights WHERE id = 52; (o, 3) (dest, 8)

-- 8 = fiftyville , 2 = beijing, 3 = lax
--SELECT * FROM airports WHERE id = 8;
--SELECT * FROM airports WHERE id = 2;
--SELECT * FROM airports WHERE id = 3;

--SELECT * FROM interviews WHERE name = "Alice";

--37
--SELECT COUNT(*) FROM atm_transactions WHERE atm_location = "Humphrey Lane" AND month = 7 AND day = 28; (37)

--check bank accounts for alice (bank account number: 37033371)
--SELECT * FROM bank_accounts WHERE person_id = 809194;

--(770) 555-1861 | 2021 | 7     | 26  | 575      |
--(420) 555-5821 | 2021 | 7     | 31  | 218      |
--(496) 555-2096 | 2021 | 7     | 31  | 85       |
--SELECT * FROM phone_calls WHERE caller = "(031) 555-9915";

-- (789) 555-8833 | 2021 | 7     | 27  | 282      |
-- (956) 555-1395 | 2021 | 7     | 30  | 433      |
-- (122) 555-4581 | 2021 | 7     | 31  | 484      |
-- clues arent leading to much right now
--SELECT * FROM phone_calls WHERE receiver = "(031) 555-9915";

--search thru transactions of location and day/month
--SELECT * FROM atm_transactions WHERE amount AND month = 7 AND day = 28 AND atm_location = "Humphrey Lane";

--check flights from day and day after crime
--SELECT * FROM flights WHERE day = 28 OR day = 29 AND origin_airport_id = 8 ORDER BY day, hour;

--cross reference names of people with passport numbers from flights of day(28) and day after(29) and day after(30)
--Betty(28)
--Gloria(29)
--SELECT name FROM people WHERE passport_number = (SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE day = 28));


-- 580086 | Betty | (233) 555-0473 | 2400516856 | 47KK91C
--SELECT * FROM people WHERE name = "Betty";

-- 788911 | Gloria | (973) 555-3809 | 2835165196 | O010420
-- SELECT * FROM people WHERE name = "Gloria";

--check who betty was in contact with
--SELECT * FROM phone_calls WHERE receiver = "(233) 555-0473" OR caller = "(233) 555-0473";

--betty
--SELECT * FROM bakery_security_logs WHERE license_plate = "47KK91C";

--bank account : 45096649
--betty
--SELECT * FROM bank_accounts WHERE person_id = 580086;

--betty
--SELECT * FROM atm_transactions WHERE account_number = 45096649;


--SELECT * FROM phone_calls WHERE receiver = "(973) 555-3809" OR caller = "(973) 555-3809";

--gloria
--SELECT * FROM bakery_security_logs WHERE license_plate = "O010420";

--gloria , bank account : 32747120
--SELECT * FROM bank_accounts WHERE person_id = 788911;

--gloria
--SELECT * FROM atm_transactions WHERE account_number = 32747120;

--SELECT * FROM interviews WHERE name = "Gloria";

--10:15am at the Humphrey Street bakery. Interviews, three witnesses, transcripts mentions the bakery.
--SELECT * FROM crime_scene_reports WHERE street = "Humphrey Street";

--Ruth | within ten minutes of the theft, saw thief get in car in bakery parking lot and drive away.
--look for cars that left the parking lot in that time frame(10:15am).

--Eugene | don't know thief's name, someone I recognized. Earlier this morning, before I arrived at Emma's bakery,
--I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

--Raymond | As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
--I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow(7/29).
--The thief then asked the person on the other end of the phone to purchase the flight ticket.
--SELECT * FROM interviews WHERE month = 7 and day = 28;

--SELECT * FROM bakery_security_logs WHERE month = 7 AND day = 28 and hour = 10;

--Eugene licenseplate: 47592FJ
--SELECT * FROM people WHERE name = "Eugene";

--no clues
--SELECT * FROM bakery_security_logs WHERE license_plate = "47592FJ";

--SELECT * FROM atm_transactions WHERE atm_location = "Leggett Street" AND day = 28;
--SELECT * FROM bakery_security_logs WHERE month = 7 AND day = 28 and hour = 10;


--SELECT license_plate FROM bakery_security_logs WHERE license_plate = ()

--94KL13X Bruce
--322W7JE Diana
--1106N58 Taylor
--SELECT * FROM bakery_security_logs WHERE activity = "exit" AND license_plate IN (SELECT license_plate FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = "Leggett Street" AND transaction_type = "withdraw" AND day = 28)));

--SELECT * from bank_accounts ORDER BY account_number;
--bruce, taylor, diana,
--SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND caller IN (SELECT phone_number FROM people WHERE license_plate = "94KL13X" OR license_plate = "4328GD8" OR license_plate = "L93JTIZ" OR license_plate = "322W7JE" OR license_plate = "1106N58");

--check flights of next day and find earliest flight , flight : 36
--SELECT * FROM flights WHERE month = 7 AND day = 29 AND origin_airport_id = 8 ORDER BY hour;

Bruce (367) 
Taylor (286)
were on same flight
SELECT * FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36);