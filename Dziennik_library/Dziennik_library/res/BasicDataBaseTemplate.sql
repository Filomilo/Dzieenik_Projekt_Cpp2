CREATE TABLE `Attendacne`
(
 `Attendacne_id`  NOT NULL ,
 `Date`          date NOT NULL ,
 `Lesson_num`    int NOT NULL ,
 `Teacher_id`    integer NOT NULL ,
 `Student_id`    int NOT NULL ,
 `Status`        int NOT NULL ,

PRIMARY KEY (`Attendacne_id`)
);

--END

CREATE TABLE `Grades`
(
 `Id`          NOT NULL ,
 `Student_id` text NOT NULL ,
 `Subject_id` int NOT NULL ,
 `Grade`      int NOT NULL ,

PRIMARY KEY (`Id`)
);

--END

CREATE TABLE `Students`
(
 `Pesel`     text NOT NULL ,
 `Name`      text NOT NULL ,
 `Surname`   text NOT NULL ,
 `Birthsday` date NOT NULL ,

PRIMARY KEY (`Pesel`)
);

--END

CREATE TABLE `Subjects`
(
 `Suvject_id`  NOT NULL ,
 `name`       text NOT NULL ,

PRIMARY KEY (`Suvject_id`)
);

--END

CREATE TABLE `Teachers`
(
 `Pesel`      text NOT NULL ,
 `Name`       text NOT NULL ,
 `Surname`    text NOT NULL ,
 `Birthsday`  date NOT NULL ,
 `Subject_id` int NOT NULL ,

PRIMARY KEY (`Pesel`)
);
--END