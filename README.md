# CS-300-Module-Eight

1. What was the problem you were solving in the projects for this course?

- The main challenge I tackled was creating a course advising assistance system for ABCU’s Computer Science department. The system had to read and manage course data, enable users to search for specific courses, view prerequisites, and list all courses alphabetically. In Project One, I concentrated on designing pseudocode and analyzing the time complexity of three data structures—vector, hash table, and binary search tree—to identify the most efficient option. Project Two involved using the chosen data structure to build a complete C++ application that accurately loads, displays, and searches course information.

2. How did you approach the problem? Consider why data structures are important to understand.

- I started by pinpointing the essential functionalities required: file parsing, structured data storage, searching, and sorting. Then, I broke down the logic into manageable pseudocode steps for each data component. I evaluated how vectors, hash tables, and trees manage insertion, lookup, and sorting, which was crucial for selecting the best implementation. Grasping data structures was vital because the efficiency of the entire program—especially when searching for a course or printing a sorted list—relies heavily on how data is organized and accessed.

3. How did you overcome any roadblocks you encountered while going through the activities or project?

- One of the main obstacles I faced was parsing the input file and managing courses with or without prerequisites. I addressed this by updating my pseudocode to handle variable-length data lines and creating robust file-handling logic in C++. Another difficulty was choosing the best data structure. After considering the trade-offs based on Big O notation, I initially favored hash tables for quick lookup but ultimately selected a binary search tree due to its balanced performance and built-in sorting support. This shift in approach helped me strengthen both the design and implementation.

4. How has your work on this project expanded your approach to designing software and developing programs?

- This project emphasized the value of planning ahead before coding. Creating detailed pseudocode helped me clearly map out the logic and identify potential problems before coding in C++. It also highlighted the importance of considering not only functional requirements but also performance, scalability, and user interaction from the outset. I now have a greater appreciation for modular design and the importance of selecting appropriate data structures tailored to specific use cases and performance considerations.

5. How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

- In Project Two, I adhered to industry-standard best practices, including descriptive variable names, consistent indentation, inline comments, and input validation. These measures made my code easier to debug and understand. I also organized the program into logical functions such as data loading, menu printing, and course searching, which enhanced modularity and flexibility. This structure ensures that future updates, like changing the data source or adding features, can be implemented with minimal disruption.
