#[path ="../src/node.rs"] mod node;
use node::*;

#[allow(dead_code)]
pub struct LinkedList<T: Copy> {
    head: Box<Node<T>>,
    size: usize
}

#[allow(dead_code)]
impl<T: Copy> LinkedList<T> {
    pub fn new() -> LinkedList<T> {
        LinkedList::<T> { head: Box::new(Node{data:None, next: None}), size: 0 }
    }
    pub fn add(&mut self, i: usize, data: T) -> bool {
        if i > self.size {
            false   // Index out of range
        } else {
            self.head.add(i, data);
            self.size = self.size + 1;
            true
        }
    }
    pub fn append(&mut self, data: T){
        self.head.append(data);
        self.size = self.size + 1;
    }
    pub fn remove(&mut self, i: usize) -> Option<T> {
        if i >= self.size {
            None    // Index out of range
        } else {
            self.size = self.size - 1;
            self.head.remove(i)
        }
    }
    pub fn get(&self, i: usize) -> Option<T> {
        self.head.get(i)
    }
    pub fn len(&self) -> usize {
        self.size
    }
    pub fn is_empty(&self) -> bool {
        self.size == 0
    }
}

