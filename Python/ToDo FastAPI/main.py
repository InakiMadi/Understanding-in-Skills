from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
from typing import List

app = FastAPI()

# BaseModel validates. For example, task must be a string.
class TodoItem(BaseModel):
    id: int
    task: str
    completed: bool = False  # Default value


# In-memory "database" (simply, a list)
todos = []

@app.get("/todos", response_model=List[TodoItem])
def get_todos():
    return todos

@app.post("/todos", response_model=TodoItem)
def add_todo(task: str):
    new_id = len(todos) + 1
    new_todo = TodoItem(id=new_id, task=task)
    todos.append(new_todo)
    return new_todo

# Toggle a to-do
@app.put("/todos/{todo_id}", response_model=TodoItem)
def toggle_todo(todo_id: int):
    for todo in todos:
        if todo.id == todo_id:
            todo.completed = not todo.completed  # Toggle True/False
            return todo
    raise HTTPException(status_code=404, detail="To-do not found")

@app.delete("/todos/{todo_id}")
def delete_todo(todo_id: int):
    global todos
    todos = [todo for todo in todos if todo.id != todo_id]
    return {"message": "To-do deleted"}