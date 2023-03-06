# Lab 7

## Student information

* Full name: Eugene Baldonado
* E-mail: ebald009@ucr.edu
* UCR NetID: ebald009
* Student ID: 862070316

## Answers

* (Q1) What is your command?

    ```shell
    mongoimport --collection contacts --jsonArray contacts.json
    ```

* (Q2) What is the output of the above command?

    ```text
    2022-05-18T20:47:32.297-0700    connected to: mongodb://localhost/  
    2022-05-18T20:47:32.496-0700    10 document(s) imported successfully. 0 document(s) failed to import.
    ```

* (Q3) What is your command?

    ```shell
    db.contacts.find().sort({"Name": 1})
    ```

* (Q4) What is your command?

    ```shell
    db.contacts.find({},{"_id":1, "Name":1}).sort({"Name": -1})
    ```

* (Q5) Is the comparison of the attribute `Name` case-sensitive?
    * Yes, the comparison of the attribute `Name` is case-sensitive. A lower case name will be considered first when sorting by name in descending order. This is because it compares the the ascii value's of lowercase against uppercase letters. 
    ```text
    > db.contacts.insert({"Name": "basic name"})
    WriteResult({ "nInserted" : 1 })
    > db.contacts.find({}, {_id: 1, Name: 1}).sort({Name: -1})
    { "_id" : ObjectId("628329690a5df8a4961cab24"), "Name" : "basic name" }
    { "_id" : ObjectId("6282ee6c7531498f871db7cf"), "Name" : "Workman Holloway" }
    { "_id" : ObjectId("6282ee6c7531498f871db7c9"), "Name" : "Susan Graham" }
    { "_id" : ObjectId("6282ee6c7531498f871db7cc"), "Name" : "Sandy Oneil" }
    { "_id" : ObjectId("6282ee6c7531498f871db7cb"), "Name" : "Patrick Thornton" }
    { "_id" : ObjectId("6282ee6c7531498f871db7c8"), "Name" : "Levine Johnston" }
    { "_id" : ObjectId("6282ee6c7531498f871db7ca"), "Name" : "Hayes Weaver" }
    { "_id" : ObjectId("6282ee6c7531498f871db7c7"), "Name" : "Craft Parks" }
    { "_id" : ObjectId("6282ee6c7531498f871db7c6"), "Name" : "Cooke Schroeder" }
    { "_id" : ObjectId("6282ee6c7531498f871db7cd"), "Name" : "Aimee Mcintosh" }
    { "_id" : ObjectId("6282ee6c7531498f871db7ce"), "Name" : "Aguirre Fox" }
    ```

* (Q6) What is your command?

    ```shell
    db.contacts.find({},{"_id":0, "Name":1}).sort({"Name": -1})
    ```

* (Q7) Does MongoDB accept this document while the `Name` field has a different type than other records?
    * Yes.

* (Q8) What is your command?

    ```shell
    db.contacts.insertOne({Name: {First: "David", Last: "Bark"}})
    ```

* (Q9) What is the output of the above command?

    ```text
    {
        "acknowledged" : true,
        "insertedId" : ObjectId("628341960a5df8a4961cab29")
    }
    ```

* (Q10) Where do you expect the new record to be located in the sort?
   * The new record should be before all the other records. The objects in MongoDB are higher ranking compared to strings, so in descending order the new record will be in the first spot.  

* (Q11) What is your command?

    ```shell
    db.contacts.insertOne({Name: ["David", "Bark"]})
    ```

* (Q12) What is the output of the above command?

    ```text
    {
        "acknowledged" : true,
        "insertedId" : ObjectId("6283424e0a5df8a4961cab2a")
    }
    ```

* (Q13) Where do you expect the new document to appear in the sort order. Verify your answer and explain after running the query.
    * "David" is in between "Hayes" and "Craft". The sort is ordering in descending order, considering "Bark" has the highest value in the array will be compared to the other values.
    ```text
    { "_id" : ObjectId("628341960a5df8a4961cab29"), "Name" : { "First" : "David", "Last" : "Bark" } }
    { "_id" : ObjectId("62833fbc0c286d7965225131"), "Name" : "Workman Holloway" }
    { "_id" : ObjectId("62833fbc0c286d7965225136"), "Name" : "Susan Graham" }
    { "_id" : ObjectId("62833fbc0c286d7965225130"), "Name" : "Sandy Oneil" }
    { "_id" : ObjectId("62833fbc0c286d7965225139"), "Name" : "Patrick Thornton" }
    { "_id" : ObjectId("62833fbc0c286d7965225135"), "Name" : "Levine Johnston" }
    { "_id" : ObjectId("62833fbc0c286d7965225133"), "Name" : "Hayes Weaver" }
    { "_id" : ObjectId("6283424e0a5df8a4961cab2a"), "Name" : [ "David", "Bark" ] }
    { "_id" : ObjectId("62833fbc0c286d7965225134"), "Name" : "Craft Parks" }
    { "_id" : ObjectId("62833fbc0c286d7965225137"), "Name" : "Cooke Schroeder" }
    { "_id" : ObjectId("62833fbc0c286d7965225132"), "Name" : "Aimee Mcintosh" }
    { "_id" : ObjectId("62833fbc0c286d7965225138"), "Name" : "Aguirre Fox" }
    ```


* (Q14) Where do you expect the last inserted record, `{Name: ["David", "Bark"]}` to appear this time? Does it appear in the same position relative to the other records? Explain why or why not.
    * Since the command is now sorting ascendingly "Bark" is compared to the other Names in the collection and is in between "Aimee" and "Cooke". It doesn't appear in the same position relative to other records. 
* (Q15) Is MongoDB able to build the index on that field with the different value types stored in the `Name` field?
    * Yes

* (Q16) What is your command?

    ```shell
    db.contacts.createIndex({"Name": 1})
    ```

* (Q17) What is the output of the above command?

    ```text
    {
        "numIndexesBefore" : 1,
        "numIndexesAfter" : 2,
        "createdCollectionAutomatically" : false,
        "ok" : 1
    }
    ```
