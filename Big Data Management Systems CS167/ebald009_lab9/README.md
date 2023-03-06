# Lab 9

## Student information

* Full name: Eugene Baldonado
* E-mail: ebald009@ucr.edu
* UCR NetID: ebald009
* Student ID: 862070316

## Answers

* (Q1) What is the schema of the file after loading it as a Dataframe

    ```text
  root
  |-- Timestamp: string (nullable = true)
  |-- Text: string (nullable = true)
  |-- Latitude: double (nullable = true)
  |-- Longitude: double (nullable = true)
    ```

* (Q2) Why in the second operation, convert, the order of the objects in the  tweetCounty RDD is (tweet, county) while in the first operation, count-by-county, the order of the objects in the spatial join result was (county, tweet)?

    ```text
    # The order of the product matters, the spatial join for convert produces the order of the object (tweet, county) in the RDD due to the join being tweet and county, but in county by county the order of the product is county and tweet so the spatial join result is (county,tweet).
    ```

* (Q3) What is the schema of the tweetCounty Dataframe?

    ```text
  root
  |-- Timestamp: string (nullable = true)
  |-- Text: string (nullable = true)
  |-- Latitude: double (nullable = true)
  |-- Longitude: double (nullable = true)
  |-- geometry: geometry (nullable = true)
  |-- CountyID: string (nullable = true)

    ```

* (Q4) What is the schema of the convertedDF Dataframe?

    ```text
  root
  |-- CountyID: string (nullable = true)
  |-- Longitude: double (nullable = true)
  |-- Latitude: double (nullable = true)
  |-- keywords: array (nullable = true)
  |    |-- element: string (containsNull = true)
  |-- Timestamp: string (nullable = true)
    ```

* (Q5) For the tweets_10k dataset, what is the size of the decompressed ZIP file as compared to the converted Parquet file?

    | Size of the original decompressed file | Size of the Parquet file |
    | - | - |
    |  771 KB | 503 KB |

* (Q6) (Bonus) Write down the SQL query(ies) that you can use to compute the ratios as described above. Briefly explain how your proposed solution works.

    ```SQL
            SELECT CountyID, count(*) / (SELECT count(*) FROM tweets WHERE array_contains(keywords, "$keyword")) as count
            FROM tweets
            WHERE array_contains(keywords, "$keyword")
            GROUP BY CountyID
  //This will be saved a view keyword_normalized_counts
            SELECT CountyID, NAME, g, count
            FROM keyword_normalized_counts, counties
            WHERE CountyID = GEOID
    ```

    ```text
    Similar to the first prior query we will take the total count of tweets from each County that contains the keyword but then we will divide it by the total tweets that contain the keyword to get the ratio of the total tweets per county. From there we will perform the same query except on the normalized counts to get the ratio of total tweets with the keyword instead of total volume. 
    ```
