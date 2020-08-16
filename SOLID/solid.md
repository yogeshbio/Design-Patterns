---
title: "SOLID"
tags: ""
---

### Single Responsibility Principle:

A class should have a single responsibility and this responsibility must be the reason for any change in the class.  
E.g :  
If we have a **Diary** Class with a title and function to add new entry into the diary, it would be a bad idea to add another responsibility in the class of saving the diary contents to a file on harddisk (persistency). This is because if we want to change the persitency functionality from hard disk to database we need to change the save() function in all classes and it would become a mess.  
Solution:  
Use another class called **Persistency Manager** to save it to the harddisk. So any change (to move from hardisk to database) you need to only modify the persistency manager class and the change is at one place only.

### Open Close Principle:

A class must be open for extension but closed for any modifications i.e. the class must be implemented in such a way that you can extend the functionality, however it must not result in modifying the existing code. New requirement can be added without changes in existing code.If existing code undergoes changes then it needs to be retested (time to retest is high) and this is not acceptable.  
E.g :  
It suggests to use inhertance from abstract base classes/interfaces.The existing interface is closed to modifications and new implementations must, at a minimum, implement that interface. Please read ocp.cpp file for more details.  

### Liskov Substitution Principle:

A subclass or inherited class S from T can be substituted for T by the application or client and this should not result in modiying or changing existing class S or T. In other words the args/params and return type of the methods/functions must be such that it must not result in any changes if one replaces any subtype of T in the application.  
E.g :  

1.  Say T is rectangle and S is square i.e. square is inherited from rectangle.Then, now the application can use object of type square and can make some assumptions about the behavior during the method calls without knowing the internals and the functionality must still work. See example lsp.cpp  

2.  Say T=SensorFrequency and S can be multiple sensor types which inherit T. As the operating range of frequencies are different for different sensor types, the application is free to use any sensor type to set the frequency range and it must still work (without asserts or exceptions). In order that it works for different frequency ranges you can provide a method() to know the frequency ranges of different sensors and then the application can set the frequency range for different sensors.

### Interface Segregation Principle:

It advocates for the creation of small and atomic interfaces.
Specifically,it is better to have many single-purpose interfaces, than a single (or few) multi-purpose ones.
This enables our software to be more reusable and customizable since we don't have to rely upon or implement functionality we don't use.  
E.g :
If you have a class called IMachine which supports all three functionalities like print, scan and fax in the same class and then you have a class called Print which inherits IMachine but it has to implement scan and fax even though it does not support them. This gives a wrong impression to the user, hence its better that we segregate the IMachine into three separate classes with virtual interfaces so that you can inherit the class with necessary functionality.  

### Dependency Inversion Principle:

1  High-level modules should not depend on low-level module.Both should depend on abstractions (e.g. interfaces).  
2. Abstractions should not depend on details. Details (concrete implementations) should depend on abstractions.  
E.g :  

If we have a fileuploader to schedule upload to AWS cloud. If fileuploader is made to directly depend on the AWS cloud (depending on low level module directly) it will be a problem if the new requirement is to upload to Google cloud. Hence its better to create an abstract interface and depend on it so that it becomes very flexible. See dip.cpp
