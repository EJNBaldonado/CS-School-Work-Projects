# Lab 8

## Student information

* Full name: Eugene Baldonado
* E-mail: ebald009@ucr.edu
* UCR NetID: ebald009
* Student ID: 862070316

## Answers

* (Q1) What is the result?

  ```text
  # 5
  ```

* (Q2) Which query did you use and what is the answer?
  
  ```sql
SELECT DISTINCT(primary_type)
FROM ChicagoCrimes
WHERE location_description="GAS STATION";
  ```

  ```text
[
        {
                "primary_type": "DECEPTIVE PRACTICE"
        },
        {
                "primary_type": "ROBBERY"
        },
        {
                "primary_type": "THEFT"
        },
        {
                "primary_type": "BATTERY"
        },
        {
                "primary_type": "MOTOR VEHICLE THEFT"
        }
]
  ```

* (Q3) Include the query in your README file

  ```sql
SELECT year, COUNT(*)
FROM ChicagoCrimes
GROUP BY year
  ```

* (Q4) Which `district` has the most number of crimes? Include the query and the answer in the README file.

  ```sql
SELECT district, COUNT(*) as NumCrimes
FROM ChicagoCrimes
GROUP BY district
ORDER BY NumCrimes DESC
LIMIT 1
  ```

  ```text
[
        {
                "district": 18,
                "NumCrimes": 108587
        }
]
  ```

* (Q5) Include the query in your submission.

  ```sql
SELECT year_month, count(*) AS count 
FROM (
  SELECT print_datetime(parse_datetime(date_value, "MM/DD/YYYY hh:mm:ss a"), "YYYY/MM") AS year_month
  FROM ChicagoCrimes
) AS y_m
GROUP BY year_month
ORDER BY year_month;
  ```

* (Q6) What is the total number of results produced by this query (not only the shown ones)?
# 232