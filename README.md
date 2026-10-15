# StudyFlow - Academic Task Manager (C++17)

**Stage:** Initial working prototype (v0.1)  
**Course:** Advanced Programming  
**Team:** Individual project  
**Student:** [REPLACE WITH YOUR FULL NAME]  
**Repository:** [REPLACE WITH YOUR GITHUB REPOSITORY URL]

StudyFlow is a console-based C++ program designed to help university students organize academic assignments.

## Currently implemented

- Add assignments with a course name, title, and priority (low, medium, high).
- Give each assignment an automatically generated numeric ID.
- View pending assignments and all assignments.
- Mark an assignment as completed using its ID.
- Validate menu choices, priorities and mandatory text fields.

## How to compile and run (Linux)

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o studyflow
./studyflow
```

## Design

- `Task` class: stores an assignment's attributes and completion state.
- `TaskManager` class: keeps `vector<Task>` and manages operations.
- The `main` function: displays the console menu and handles user input.

## Example usage

1. Choose `1`; enter `Calculus II`, `Homework 3`, and priority `3`.
2. Choose `2` to see the pending assignment.
3. Choose `4` and enter the ID printed in the task list.
4. Choose `3` to see the task marked `DONE`.

## Limitations and next steps

**Important:** This initial version stores data only in memory, so assignments do not persist after the program is closed. Saving/loading, due dates, sorting, and statistics are **planned but not yet implemented**.
