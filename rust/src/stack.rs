#[path ="../src/linked_list.rs"] mod linked_list;
use linked_list::*;
#[allow(dead_code)]
pub struct Stack<T: Copy>{
    stack: LinkedList<T>
}
#[allow(dead_code)]
impl<T: Copy> Stack<T>{
    pub fn new() -> Stack<T> {
        Stack::<T> {
            stack: LinkedList::<T>::new()
        }
    }

    pub fn push(&mut self, data: T) -> bool {
        self.stack.add(0, data)
    }

    pub fn pop(&mut self) -> T {
        self.stack.remove(0).unwrap()
    }

    pub fn is_empty(&mut self) -> bool {
        self.stack.is_empty()
    }

    pub fn peek(&mut self) -> T {
        self.stack.get(0).unwrap()
    } 

    pub fn len(&mut self) -> usize {
        self.stack.len()
    }
}