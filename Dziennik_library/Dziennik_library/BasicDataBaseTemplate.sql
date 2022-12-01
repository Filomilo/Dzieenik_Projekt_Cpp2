CREATE TABLE `Attendacne`
(
 `Attendacne_id` INTEGER NOT NULL ,
 `Date`          date NOT NULL ,
 `Lesson_num`    INTEGER NOT NULL ,
 `Teacher_id`    text NOT NULL ,
 `Student_id`    text NOT NULL ,
 `Status`        INTEGER NOT NULL ,

PRIMARY KEY (`Attendacne_id`)
);

--END

CREATE TABLE `Students`
(
 `Pesel`     text NOT NULL ,
 `Name`      text NOT NULL ,
 `Surname`   text NOT NULL ,
 `Birthday` date NOT NULL ,

PRIMARY KEY (`Pesel`)
);

--END

CREATE TABLE `Grades`
(
 `Grade_Id`         INTEGER  NOT NULL ,
 `Student_id` text NOT NULL ,
 `Subject_id` int NOT NULL ,
 `Grade`      int NOT NULL ,

PRIMARY KEY (`Grade_Id`)
 FOREIGN KEY(Student_id) REFERENCES Students(Pesel)
);

--END

CREATE TABLE `Subjects`
(
 `Suvject_id` INTEGER  NOT NULL ,
 `Name`       text NOT NULL ,

PRIMARY KEY (`Suvject_id`)
);

--END

CREATE TABLE `Teachers`
(
 `Pesel`      text NOT NULL ,
 `Name`       text NOT NULL ,
 `Surname`    text NOT NULL ,
 `Birthday`  date NOT NULL ,
 `Subject_id` int NOT NULL ,
PRIMARY KEY (`Pesel`)
);
--END


CREATE TABLE `Users`
(
 `User_Id`      INTEGER NOT NULL ,
 `Nick`       text UNIQUE NOT NULL ,
 `Password`    text NOT NULL ,
 `Acccount_Type`  int NOT NULL ,
 `Id_in_db` text DEFAULT NULL,

 PRIMARY KEY (`User_Id`)

);
--END



